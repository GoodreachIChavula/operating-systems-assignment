#include "include/eduos.h"


int edu_fork(char name[]);

void edu_exec(int pid, char new_name[]);

void edu_exit(int pid);

void edu_ps();


int main() {

    int pid1;

    int pid2;


    pid1 = edu_fork("Chrome");

    pid2 = edu_fork("Spotify");


    edu_exec(pid1, "Firefox");


    edu_ps();


    edu_exit(pid2);


    edu_ps();


    return 0;
}