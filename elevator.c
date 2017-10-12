#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CAPACITY  10
#define MAX_ELEVATORS 16
#define DEFAULT_TOP   32
#define MAX_TOP       128
#define QUEUE_SZ      100

#define ST_IDLE              0
#define ST_GOING_UP          1
#define ST_GOING_DOWN        2
#define ST_PICKING_UP        3
#define ST_PICKING_DOWN      4
#define ST_DOOR_OPEN         5

static char *g_state_str[] = {
    "idle",
    "up",
    "down",
    "pick +",
    "pick -",
    "idle"
};

typedef struct elev_s {
    int   id;
    int   capacity;            // total capacity
    int   persons;             // total persons in the elevator
    int   goal[MAX_TOP];       // goal floor queue
    int   num;                 // num of goal in the queue
    int   flags;               // bit mask flags
    int   state;               // current state
    int   floor;               // current floor
    int   pick_floor;          // pickup floor
} elev_t;

typedef struct evc_s {
    int    total;                // total number of elevators
    int    top;                  // top floor of the elevators can get to
    int    head;                 // head position of request queue
    int    num;                  // number of requests in the queue
    int    request[QUEUE_SZ];    // request queue of floor
    int    dir[QUEUE_SZ];        // request queue of direction
    elev_t elev[MAX_ELEVATORS];  // elevators
} evc_t;

typedef struct cmd_s {
    int op;     // operation
    int arg1;   // elevator id
    int arg2;   // direction
    int arg3;   // start floor
} cmd_t;

#define OP_EXIT    0
#define OP_STATUS  1
#define OP_UPDATE  2
#define OP_PICKUP  3
#define OP_STEP    4
#define OP_HELP    5

evc_t g_elevators = { 0 };       // single thread only

// parse a command parameter
char *parse_int(char *buff, int *arg) {
    int neg = 0, k = 0;

    *arg = 0;
    
    if (*buff && *buff == '-') {
        neg = 1;
        buff ++;
    }
    while (*buff >= '0' && *buff <= '9') {
        k = k * 10 + (*buff) - '0';
        buff ++;
    }
    if (*buff == ' ') buff ++;
    else if (*buff) return "";

    *arg = neg ? 0 - k : k;
    return buff;
}

// parse a command
int parse_cmd(char *buff, cmd_t *cmd) {
    if (!strncmp(buff, "update ", 7)) {
        cmd->op = OP_UPDATE;
        buff += 7;
        buff = parse_int(buff, &cmd->arg1);
        buff = parse_int(buff, &cmd->arg2);
        buff = parse_int(buff, &cmd->arg3);
    } else
    if (!strncmp(buff, "pickup ", 7)) {
        cmd->op = OP_PICKUP;
        buff += 7;
        buff = parse_int(buff, &cmd->arg1);
        buff = parse_int(buff, &cmd->arg2);
    } else
    if (!strcmp(buff, "status")) {
        cmd->op = OP_STATUS;
    } else
    if (!strcmp(buff, "step")) {
        cmd->op = OP_STEP;
    } else
    if (!strcmp(buff, "help")) {
        cmd->op = OP_HELP;
    } else
    if (!strcmp(buff, "exit") ||
        !strcmp(buff, "quit")) {
        cmd->op = OP_EXIT;
    } else {
        return -1;
    }
    return 0;
}

// take user input for commands
void read_cmd(cmd_t *cmd, int n, int t) {
    int i, c;
    char buff[32];
again:
    printf("> ");
    i = 0;
    do {
        c = getchar();
        if (i < 32 &&
            (c != ' ' || (i > 0 && buff[i - 1] != ' '))) {
            buff[i ++] = c;
        }
    } while (c != '\n');

    if (i == 32) {
        printf("Input too long, please try again!\n");
        goto again;
    }

    while (i > 0 &&
           (buff[i - 1] == '\n' ||
            buff[i - 1] == ' ')) {
        i --;
    }

    if (i == 0) goto again;

    buff[i] = 0;

    if (parse_cmd(&buff[0], cmd)) {
        printf("Invalid input, enter help to show all commands!\n");
        goto again;
    }
}

void show_help() {
    printf("status\t - show elevator status.\n");
    printf("step\t - time stepping.\n");
    printf("pickup <floor> <direction>\t - request pickup.\n");
    printf("update <id> <floor> <goal>\t - update elevator when it ready for picking up.\n");
    printf("exit\t - exit application.\n");
}

// print all elevator status and number of pending requests in the queue
void show_status() {
    int i, j;
    elev_t *p;
    printf("ID\tFloor\tState\tFloors\n");
    printf("====================================\n");
    for (i = 0; i < g_elevators.total; i ++) {
        p = &g_elevators.elev[i];
        printf("%d:\t%d\t%s\t", p->id,
                                p->floor,
                                g_state_str[p->state]);
        if ((p->state == ST_PICKING_UP ||
             p->state == ST_PICKING_DOWN) &&
            p->floor != p->pick_floor) {
            printf("[%d] ", p->pick_floor);
        } else {
            for (j = 0; j < g_elevators.top; j ++) {
                if (p->goal[j]) {
                    printf("%d ", j + 1);
                }
            }
        }
        printf("\n");
    }
    printf("Pending pickup requests: %d.\n", g_elevators.num);
}

// compare distance between elevator and pickup floor
int is_closer(elev_t *a, elev_t *b, int floor) {
    int d1, d2;
    d1 = a->floor - floor;
    d1 = d1 > 0 ? d1 : 0 - d1;
    d2 = b->floor - floor;
    d2 = d2 > 0 ? d2 : 0 - d2;

    return d1 < d2 ? 1 : 0;
}

// find an idle elevator and schedule it to run a pick up request
void schedule_run() {
    int i, floor, dir;
    elev_t *p, *idle_p;

start:
    idle_p = NULL;

    if (g_elevators.num == 0) return;

    // take the first request from the queue
    floor = g_elevators.request[g_elevators.head];
    dir = g_elevators.dir[g_elevators.head];

    for (i = 0; i < g_elevators.total; i ++) {
        p = &g_elevators.elev[i];
#if 0
        // pick up on the way
        if (p->floor == floor) {
            // pick up if there is just one on this floor
            if ((p->state == ST_GOING_UP && dir > 0) ||
                (p->state == ST_GOING_DOWN && dir < 0)) {  // FIXME: check load is within capacity
                p->persons ++;		// increase load
                g_elevators.head = (g_elevators.head + 1) % QUEUE_SZ;
                g_elevators.num --;
                goto starts;
            }
        }
#endif
        // find the closest idle one
        if (p->state == ST_IDLE) {
            if (idle_p == NULL ||
                is_closer(p, idle_p, floor)) {
                idle_p = p;
            }
        }
    }

    // schedule the closest idle one to run
    if (idle_p) {
        idle_p->state = dir > 0 ? ST_PICKING_UP : ST_PICKING_DOWN;
        idle_p->pick_floor = floor;
        g_elevators.head = (g_elevators.head + 1) % QUEUE_SZ;
        g_elevators.num --;
        goto start;
    }
}

// optimze running requests to shorten waiting time.
void optimize_requests() {
#if 0
    int i, n;
    int idle_buff[MAX_TOP][MAX_ELEVATORS + 1] = { 0 };
    int pick_buff[MAX_TOP][MAX_ELEVATORS + 1] = { 0 };
    elev_t *p;

    // make elevator buffer on each floor
    for (i = 0; i < g_elevators.total; i ++) {
        p = &g_elevators.elev[i];
        if (p->state == ST_IDLE) {
            n = idle_buff[p->floor][0];
            idle_buff[p->floor][n] = p->id;
            idle_buff[p->floor][0] ++;		// number of idle elevators on this floor
        } else
        if ((p->state == ST_PICKING_UP ||
             p->state == ST_PICKING_DOWN) &&
            p->pick_floor != p->floor) {
            n = pick_buff[p->pick_floor][0];
            pick_buff[p->pick_floor][n] = p->id;
            pick_buff[p->pick_floor][0] ++;	// number of elevators going to pick up on this floor
        }
    }

    // FIXME: sort the buffers and optimize with matching by distance.
#endif
}

// schedule runs and optimize pickup requests
void schedule_and_optimize() {
    schedule_run();
    optimize_requests();
}

void move_up_down(elev_t *p, int step) {
    p->floor += step;
    // someone takes off
    if (p->goal[p->floor - 1]) {
        p->goal[p->floor - 1] = 0;
        p->num --;
    }
    // all are off
    if (p->num == 0) {
        p->state = ST_DOOR_OPEN;
        return;
    }
}

void move_picking_up_down(elev_t *p, int up) {
    if (p->floor == p->pick_floor) {
        if (p->num > 0) {
            // just switch state, not moving, seems like
            // taking one step to close the door.
            p->state = up ? ST_GOING_UP : ST_GOING_DOWN;
        } else {
            // FIXME: switch state to idle if waiting for
            // update times out.
        }
    } else if (p->floor < p->pick_floor) {
        p->floor ++;
    } else {
        p->floor --;
    }
}

void time_stepping() {
    int i, idle = 0;
    elev_t *p;

    // run elevator state machine
    for (i = 0; i < g_elevators.total; i ++) {
        p = &g_elevators.elev[i];
        switch (p->state) {
            case ST_IDLE:
                idle = 1;
                break;
            case ST_GOING_UP:
                move_up_down(p, 1);
                break;
            case ST_GOING_DOWN:
                move_up_down(p, -1);
                break;
            case ST_PICKING_UP:
                move_picking_up_down(p, 1);
                break;
            case ST_PICKING_DOWN:
                move_picking_up_down(p, 0);
                break;
            case ST_DOOR_OPEN:
                p->state = ST_IDLE;
                idle = 1;
                break;
            default:
                break;
        }
    }
    if (idle) {
        // trigger scheduling and optimization when idle elevator is available
        schedule_and_optimize();
    }
}

// enqueue a pickup request and trigger schedule
int schedule_pickup(int floor, int dir) {
    int i, idle = 0;
    elev_t *p;

    // validate input
    if (floor < 1 ||
        floor > g_elevators.top ||
        dir == 0 ||
        (floor == 1 && dir < 0) ||
        (floor == g_elevators.top && dir > 0)) {
        printf("Invalid pickup request.\n");
        return -1;
    }

    // if a pick up for this floor is on the way,
    // don't schedule another elevator to run
    for (i = 0; i < g_elevators.total; i ++) {
        p = &g_elevators.elev[i];
        if ((((p->state == ST_PICKING_UP) && dir > 0) ||
             ((p->state == ST_PICKING_DOWN) && dir < 0)) &&
            p->pick_floor == floor) {
            printf("Elevator %d is on the way!\n", p->id);
            return -1;
        }
        if (p->state == ST_IDLE) {
            idle = 1;
        }
    }

    // ignore this request if queue is full
    if (g_elevators.num == QUEUE_SZ) {
        printf("Too many pickup requests, try later.\n");
        return -1;
    }

    // enqueue the request
    i = (g_elevators.head + g_elevators.num) % QUEUE_SZ;
    g_elevators.request[i] = floor;
    g_elevators.dir[i] = dir;
    g_elevators.num ++;

    if (idle) {
        // trigger scheduling and optimization when idle elevator is available
        schedule_and_optimize();
    }

    return 0;
}

// update elevator goal floor when it is ready to pickup
int update_floor(int eid, int floor, int goal) {
    elev_t *p;

    // validate request
    if (eid < 1 || eid > g_elevators.total ||
        floor < 1 || floor > g_elevators.top ||
        goal < 1 || goal > g_elevators.top) {
        printf("Invaid parameters %d, %d, %d.\n", eid, floor, goal);
        return -1;
    }

    p = &g_elevators.elev[eid - 1];

    if (p->state != ST_PICKING_UP &&
        p->state != ST_PICKING_DOWN) {
        printf("Elevator %d is not ready to take the update.\n", eid);
        return -1;
    }
    if (p->pick_floor != floor) {
        printf("Elevator %d not yet arrive at floor %d.\n", eid, floor);
        return -1;
    }
    if ((p->state == ST_PICKING_UP && goal <= floor) ||
        (p->state == ST_PICKING_DOWN && goal >= floor)) {
        printf("Elevator %d is going to other direction.\n", eid);
        return -1;
    }

    // set goal floors if it is not yet set.
    if (p->goal[goal - 1] == 0) {
        p->goal[goal - 1] = 1;
        p->num ++;
    }

    return 0;
}

int main(int argc, char *argv[])
{
    elev_t *p;
    int i, n = MAX_ELEVATORS, c = MAX_CAPACITY, t = DEFAULT_TOP;

    cmd_t cmd;

    if (argc > 1) {
        n = atoi(argv[1]);    // total number of elevators being created
    }
    if (argc > 2) {
        t = atoi(argv[2]);    // top floor of all elevators can get to
    }
    if (argc > 3) {
        c = atoi(argv[3]);    // total capacity of every elevators
    }

    if (n < 1 || n > MAX_ELEVATORS) {
        n = MAX_ELEVATORS;
        printf("Total number of elevator is adjusted to default %d.\n", n);
    }
    if (c < 1 || c > MAX_CAPACITY) {
        c = MAX_CAPACITY;
        printf("Capacity of every elevator is adjusted to default %d.\n", c);
    }
    if (t < 2) {
        t = DEFAULT_TOP;
        printf("Top floor is adjusted to default %d.\n", t);
    } else if (t > MAX_TOP) {
        t = MAX_TOP;
        printf("Top floor is adjusted to max %d.\n", t);
    }

    // initialization
    g_elevators.total = n;
    g_elevators.top = t;
    for (i = 0; i < n; i ++) {
        p = &g_elevators.elev[i];
        p->id = i + 1;
        p->capacity = c;
        // spread out elevator to different floors
        p->floor = 1 + (i * t) / n;
        p->state = ST_IDLE;
    }

    printf("%d elevators are created and run between floor 1 - %d.\n", n, t);
    printf("Enter help to see a list of commands.\n");

    // main loop of command line interface
    read_cmd(&cmd, n, t);
    while (cmd.op != OP_EXIT) {
        switch (cmd.op) {
        case OP_STATUS:
            show_status();
            break;
        case OP_UPDATE:
            update_floor(cmd.arg1, cmd.arg2, cmd.arg3);
            break;
        case OP_PICKUP:
            schedule_pickup(cmd.arg1, cmd.arg2);
            break;
        case OP_STEP:
            time_stepping();
            break;
        case OP_HELP:
            show_help();
            break;
        default:
            break;
        }
        read_cmd(&cmd, n, t);
    }

done:
    return 0;
}
