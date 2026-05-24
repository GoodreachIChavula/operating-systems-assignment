#ifndef EDUOS_H
#define EDUOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>     // for pid_t
#include <time.h>       // for time_t

// Process states
#define NEW        0
#define READY      1
#define RUNNING    2
#define WAITING    3
#define TERMINATED 4

// Maximum number of processes in simulation
#define MAX_PROCESSES 256

// Process Control Block (PCB) structure
typedef struct {
    pid_t pid;                // Process ID (unique per process)
    char name[64];            // Process name
    int state;                // Current state (NEW, READY, etc.)
    int priority;             // Priority (smaller = higher priority)
    int burst_time;           // CPU burst time (total units needed)
    int arrival_time;         // Time when process arrived
    int remaining_time;       // Time left to finish execution
    int memory_req_kb;        // Memory requirement in KB
    int thread_count;         // Number of threads (for future use)
    time_t creation_time;     // Timestamp when process was created
} PCB;

#endif
