#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <pthread.h>
#include <time.h>

typedef struct pipe_s {
    int cnt;
    int pos;
    unsigned char buff[1024];
    pthread_mutex_t mtx;
    pthread_cond_t cv;
} pipe_t;

// publich interfaces

pipe_t *open_pipe() {
    pipe_t *p = malloc(sizeof(pipe_t));
    if (p) {
        p->pos = 0;
        p->cnt = 0;
        pthread_mutex_init(&p->mtx, NULL);
        pthread_cond_init(&p->cv, NULL);
    }
    return p;
}

void pipe_close(pipe_t *p) {
    if (p) {
        pthread_mutex_destroy(&p->mtx);
        pthread_cond_destroy(&p->cv);
    }
    free(p);
}

unsigned int write_to_pipe(pipe_t *p, char *buff, size_t size)
{
    struct timespec t1, t2;
    int k = 0;
    int rc = 0;

    clock_gettime(CLOCK_REALTIME, &t1);
    t1.tv_sec += 5;

    pthread_mutex_lock(&p->mtx);
    while (p->cnt == 1024 && rc == 0) {
        rc = pthread_cond_timedwait(&p->cv, &p->mtx, &t1);
    }
    if (p->cnt < 1024) {
        while (size > 0 && p->cnt < 1024) {
            p->buff[p->pos ++] = buff[k ++];
            p->pos = p->pos % 1024;
            p->cnt ++;
            size --;
        }
    } else {
        k = -1;
    }
    pthread_mutex_unlock(&p->mtx);

    pthread_cond_signal(&p->cv);

    return k;
}

int read_from_pipe(pipe_t *p, char *buff, size_t size)
{
    struct timespec t1, t2;
    int k = 0;
    int rc = 0;

    clock_gettime(CLOCK_REALTIME, &t1);
    t1.tv_sec += 5;

    pthread_mutex_lock(&p->mtx);
    while (p->cnt == 0 && rc == 0) {
        rc = pthread_cond_timedwait(&p->cv, &p->mtx, &t1);
    }
    if (p->cnt > 0) {
        while (k < size && p->cnt > 0) {
            buff[k ++] = p->buff[p->pos ++];
            p->pos = p->pos % 1024;
            p->cnt --;
        }
    }
    pthread_mutex_unlock(&p->mtx);

    pthread_cond_signal(&p->cv);

    return k;
}

// private interfaces

void *func_write(void *arg) {
    pipe_t *p = (pipe_t *)arg;

    const int size = 1024 * 10;
    char data[size];
    unsigned int pos = 0;

    int k, i;

    for (i = 0; i < sizeof(data); i ++) {
        data[i] = 'a' + i % 26;
    }

    while (pos < size) {
        k = write_to_pipe(p, &data[pos], size - pos);
        if (k < 0) {
            printf("write fail, pipe full.\n");
            return;
        }
        pos += k;
    }
}


void *func_read(void *arg) {
    pipe_t *p = (pipe_t *)arg;
    char buff[1024];
    int size = 1024;
    int i, k = 0;
    int cnt = 0;

    do {
        k = read_from_pipe(p, buff, size);
        for (i = 0; i < k; i ++) {
             printf("%c", buff[i]);
        }
        fflush(stdout);
        cnt += k;
    } while (k > 0);

    printf("\n");

    printf("%d\n", cnt);
}


int main(int argc, char *argv[])
{
    pipe_t *p;
    pthread_t read_thr, write_thr;
    int rc;
    void *ret;

    p = open_pipe();
    if (!p) {
        printf("failed to open\n");
    }

    rc = pthread_create(&write_thr, NULL, func_write, p);
    if (rc != 0) {
        goto cu0;
    }

    rc = pthread_create(&read_thr, NULL, func_read, p);
    if (rc != 0) {
        goto cu0;
    }

cu0:
    // clean up
    pthread_join(write_thr, &ret);
    pthread_join(read_thr, &ret);

    pipe_close(p);

    return 0;
}
