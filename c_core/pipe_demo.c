#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {

    int fd[2];

    char write_msg[] = "Hello from parent process";

    char read_msg[100];

    pipe(fd);

    pid_t pid = fork();

    if(pid > 0) {

        close(fd[0]);

        write(fd[1], write_msg, strlen(write_msg) + 1);

        printf("Parent sent message\n");
    }

    else {

        close(fd[1]);

        read(fd[0], read_msg, sizeof(read_msg));

        printf("Child received: %s\n", read_msg);
    }

    return 0;
}