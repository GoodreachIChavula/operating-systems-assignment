# operating-systems-assignment
Name: Goodreach I Chavula
Project Name: EduOS
Project Title: Operating System Assignment
Module Code: 351 CS 2104
Registration Number: 

# EduOS Simulator

EduOS is an educational operating system simulator developed using C and Python.

## Features

- Process Control Block (PCB) simulation
- Process creation and termination
- Threading and mutex synchronization
- Deadlock demonstration
- CPU scheduling algorithms:
  - FCFS
  - SJF
  - Priority Scheduling
  - Round Robin
- JSON serialization
- Python visualization

## Technologies Used

- C
- Python
- pthreads
- matplotlib
- JSON
- 
## Valgrind Analysis

Valgrind support was limited due to the Windows development environment. However manual testing confirmed that dynamically allocated memory was properly released and no runtime crashes related to memory misuse were observed during execution.


## How to Run

### C Simulator

```bash
make
./eduos


