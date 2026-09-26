# OS Assignment 3

This folder contains C programs for Operating Systems Lab Assignment 3 covering process management, system calls, standard I/O, and exit codes.

## Files Included

- `task1_alive.c`: Long-running process using sleep.
- `task2_identity.c`: Displays Process ID (PID) and Parent Process ID (PPID).
- `task3_exit.c`: Demonstrates custom exit codes.
- `task4_input.c`: Handles standard I/O streams (stdin, stdout, stderr).
- `task5_control.c`: Demonstrates conditional execution and process control.

## How to Compile and Run

```bash
# Task 1
gcc task1_alive.c -o task1 && ./task1

# Task 2
gcc task2_identity.c -o task2 && ./task2

# Task 3
gcc task3_exit.c -o task3 && ./task3

# Task 4
gcc task4_input.c -o task4 && ./task4

# Task 5
gcc task5_control.c -o task5 && ./task5
