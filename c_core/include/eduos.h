#ifndef EDUOS_H
#define EDUOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PROCESSES 100

#define NEW 0
#define READY 1
#define RUNNING 2
#define WAITING 3
#define TERMINATED 4

typedef struct {
    int pid;
    char name[64];
    int state;
    int priority;
    int burst_time;
    int arrival_time;
    int remaining_time;
    int memory_req_kb;
    int thread_count;
    time_t creation_time;
} PCB;

#endif