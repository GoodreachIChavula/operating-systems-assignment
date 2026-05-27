#include "include/eduos.h"

void add_process(int pid, char name[], int state);

void show_processes();

int main() {

    add_process(1, "Chrome", READY);

    add_process(2, "VSCode", RUNNING);

    add_process(3, "Spotify", WAITING);

    show_processes();

    return 0;
}