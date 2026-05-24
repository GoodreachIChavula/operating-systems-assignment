#include "eduos.h"

static PCB pcb_table[MAX_PROCESSES];   // Table of all PCBs
static int pcb_count = 0;              // Number of processes in table
static pid_t next_pid = 1;             // Next PID to assign

// Helper: save current PCB table to JSON file
void save_pcb_json() {
    FILE *fp = fopen("pcb_snapshot.json", "w");
    if (!fp) return;
    fprintf(fp, "[\n");
    for(int i = 0; i < pcb_count; i++) {
        fprintf(fp,
            "{\"pid\":%d,\"name\":\"%s\",\"state\":%d}",
            pcb_table[i].pid,
            pcb_table[i].name,
            pcb_table[i].state
        );
        if (i < pcb_count - 1) fprintf(fp, ",");
        fprintf(fp, "\n");
    }
    fprintf(fp, "]\n");
    fclose(fp);
}

// Simulate fork: duplicate parent PCB, create child process
pid_t edu_fork(PCB *parent) {
    if (pcb_count >= MAX_PROCESSES) return -1;
    PCB child = *parent;
    child.pid = next_pid++;
    child.state = READY;
    // Assign child a default name if not already set
    if (strlen(child.name) == 0) {
        snprintf(child.name, sizeof(child.name), "proc%d", child.pid);
    }
    pcb_table[pcb_count++] = child;
    printf("[FORK] Parent %d -> Child %d\n",
           parent->pid, child.pid);
    save_pcb_json();
    return child.pid;
}

// Simulate exec: change program name and reset burst time
void edu_exec(pid_t pid, char *prog_name) {
    for(int i = 0; i < pcb_count; i++) {
        if (pcb_table[i].pid == pid) {
            strcpy(pcb_table[i].name, prog_name);
            pcb_table[i].burst_time = 10;
            pcb_table[i].remaining_time = 10;
            pcb_table[i].state = RUNNING;
            printf("[EXEC] PID %d running %s\n", pid, prog_name);
            save_pcb_json();
            return;
        }
    }
}

// Simulate exit: terminate process with a code
void edu_exit(pid_t pid, int exit_code) {
    for(int i = 0; i < pcb_count; i++) {
        if (pcb_table[i].pid == pid) {
            pcb_table[i].state = TERMINATED;
            printf("[EXIT] PID %d exited with code %d\n", pid, exit_code);
            save_pcb_json();
            return;
        }
    }
}

// List all processes
void edu_ps() {
    printf("PID\tNAME\tSTATE\tPRIORITY\n");
    for(int i = 0; i < pcb_count; i++) {
        printf("%d\t%s\t%d\t%d\n",
            pcb_table[i].pid,
            pcb_table[i].name,
            pcb_table[i].state,
            pcb_table[i].priority
        );
    }
}
