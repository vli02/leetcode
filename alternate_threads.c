/*
output 1 - 100
two threads, one prints odd one prints even in order
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
  
#define START_NUMBER 1
#define END_NUMBER 100

pthread_mutex_t mtx;
pthread_cond_t cond;

int seq;
int run_thread;

typedef struct range_s {
  int start;
  int end;
} range_t;
  
int odd_print_one(const int start, const int end) {
  int rc = 0;

  pthread_mutex_lock(&mtx);

  // wait for cond to be singaled by using mtx and cond
  while (run_thread != 1) {
    pthread_cond_wait(&cond, &mtx);
  }
  if (seq > end) {
    rc = -1;
  } else {
    printf("%d ", seq);
    seq ++;
  }
  run_thread = 2;

  // siganl cond variable;
  pthread_cond_signal(&cond);
  pthread_mutex_unlock(&mtx);

  return rc;
}

/* most of code is common with odd_print_one(), they can be
   incooperated as one function, for readability, I keep them
   separated here. */
int even_print_one(const int start, const int end) {
  int rc = 0;
  pthread_mutex_lock(&mtx);

  // wait for cond to be singaled by using mtx and cond
  while (run_thread != 2) {
    pthread_cond_wait(&cond, &mtx);
  }
  if (seq > end) {
    rc = -1;
  } else {
    printf("%d ", seq);
    seq ++;
  }
  run_thread = 1;

  // siganl cond variable
  pthread_mutex_unlock(&mtx);
  pthread_cond_signal(&cond);

  return rc;
}

void *odd_printer(void *args) {
  int rc;
  const int start = ((range_t *)args)->start;
  const int end = ((range_t *)args)->end;
  do {
    rc = odd_print_one(start, end);
  } while (rc == 0);

  return NULL;
}

void *even_printer(void *args) {
  int rc;
  const int start = ((range_t *)args)->start;
  const int end = ((range_t *)args)->end;
  do {
    rc = even_print_one(start, end);
  } while(rc == 0);

  return NULL;
}

int main() {
  pthread_t odd_thread, even_thread;
  int rc;
  void *ret;

  const range_t range = {START_NUMBER, END_NUMBER};

  seq = range.start;
  run_thread = 1;

  pthread_mutex_init(&mtx, NULL);
  pthread_cond_init(&cond, NULL);

  rc = pthread_create(&odd_thread, NULL, odd_printer, (void *)&range);
  if (rc != 0) {
    goto cu1;
  }
  rc = pthread_create(&even_thread, NULL, even_printer, (void *)&range);
  if (rc != 0) {
    pthread_kill(odd_thread, 0);
    goto cu0;
  }
  
  // clean up
  pthread_join(even_thread, &ret);
cu0:
  pthread_join(odd_thread, &ret);

cu1:
  printf("\n");
  pthread_mutex_destroy(&mtx);
  pthread_cond_destroy(&cond);
  
  return rc;
}
