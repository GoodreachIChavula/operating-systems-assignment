#include "include/eduos.h"

PCB pcb_table[MAX_PROCESSES];

int pcb_count = 0;

void add_process(int pid, char name[], int state) {

    pcb_table[pcb_count].pid = pid;

    strcpy(pcb_table[pcb_count].name, name);

    pcb_table[pcb_count].state = state;

    pcb_count++;
}

void show_processes() {

    printf("\nPROCESS TABLE\n");

    printf("-------------------------\n");

    for(int i = 0; i < pcb_count; i++) {

        printf(
            "PID: %d | NAME: %s | STATE: %d\n",
            pcb_table[i].pid,
            pcb_table[i].name,
            pcb_table[i].state
        );
    }
}