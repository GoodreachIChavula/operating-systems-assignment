#include "include/eduos.h"

PCB pcb_table[MAX_PROCESSES];

int pcb_count = 0;

int next_pid = 1;


/* SAVE PCB TABLE TO JSON FILE */
void save_to_json() {

    FILE *file = fopen("pcb_snapshot.json", "w");

    if(file == NULL) {
        printf("Error creating JSON file\n");
        return;
    }

    fprintf(file, "[\n");

    for(int i = 0; i < pcb_count; i++) {

        fprintf(
            file,
            "  {\"pid\": %d, \"name\": \"%s\", \"state\": %d}",
            pcb_table[i].pid,
            pcb_table[i].name,
            pcb_table[i].state
        );

        if(i < pcb_count - 1) {
            fprintf(file, ",");
        }

        fprintf(file, "\n");
    }

    fprintf(file, "]");

    fclose(file);
}


/* CREATE PROCESS */
int edu_fork(char name[]) {

    if(pcb_count >= MAX_PROCESSES) {

        printf("Process table full\n");

        return -1;
    }

    PCB new_process;

    new_process.pid = next_pid;

    strcpy(new_process.name, name);

    new_process.state = READY;

    new_process.priority = 0;

    new_process.burst_time = 10;

    new_process.arrival_time = 0;

    new_process.remaining_time = 10;

    new_process.memory_req_kb = 512;

    new_process.thread_count = 1;

    new_process.creation_time = time(NULL);

    pcb_table[pcb_count] = new_process;

    pcb_count++;

    next_pid++;

    printf(
        "[FORK] Process created: %s (PID %d)\n",
        name,
        new_process.pid
    );

    save_to_json();

    return new_process.pid;
}


/* LOAD PROGRAM INTO PROCESS */
void edu_exec(int pid, char new_name[]) {

    for(int i = 0; i < pcb_count; i++) {

        if(pcb_table[i].pid == pid) {

            strcpy(pcb_table[i].name, new_name);

            pcb_table[i].state = RUNNING;

            printf(
                "[EXEC] PID %d now running %s\n",
                pid,
                new_name
            );

            save_to_json();

            return;
        }
    }

    printf("Process not found\n");
}


/* TERMINATE PROCESS */
void edu_exit(int pid) {

    for(int i = 0; i < pcb_count; i++) {

        if(pcb_table[i].pid == pid) {

            pcb_table[i].state = TERMINATED;

            printf(
                "[EXIT] PID %d terminated\n",
                pid
            );

            save_to_json();

            return;
        }
    }

    printf("Process not found\n");
}


/* DISPLAY PROCESS TABLE */
void edu_ps() {

    printf("\nPROCESS TABLE\n");

    printf("--------------------------------------------------\n");

    for(int i = 0; i < pcb_count; i++) {

        printf(
            "PID: %d | NAME: %s | STATE: %d\n",
            pcb_table[i].pid,
            pcb_table[i].name,
            pcb_table[i].state
        );
    }
}