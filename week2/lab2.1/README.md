# Lab 2.1: C Libraries, Linking, and ELF Executable Structure
This lab explains how a C program uses the C Standard Library (libc), where the library files are stored on Linux, and how to inspect the compiled executable using readelf and ldd.

# Objectives
- Understand how a C program links to the C Standard Library.
- Find where the C header files and compiled library code are stored on disk.
- Compare static and dynamic linking and inspect the executables.

# Files in this Repository
- procinfo.c: C source code that prints process information
- procinfo: executable compiled with the default gcc command
- procinfo_static: executable compiled with static linking (gcc -static)
- procinfo_dynamic: executable compiled with dynamic linking (default gcc)
- Lab2_Report.docx: Full lab report with screenshots and summaries
- README.md: This file

# Environment
- OS: Ubuntu Linux (VirtualBox)
- Compiler: GCC
- Tools: readelf, ldd, grep, ls, nano

# 1. The C Program (procinfo.c)
The program uses getpid(), getppid(), time(), localtime(), asctime() and printf() to display the process ID, parent process ID and current time.

```
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(void) {
    pid_t my_pid = getpid();
    pid_t my_ppid = getppid();

    time_t current_time = time(NULL);
    struct tm *time_info = localtime(&current_time);

    printf("=== Process Information ===\n");
    printf("My Process ID (PID): %d\n", my_pid);
    printf("Parent Process ID: %d\n", my_ppid);
    printf("Current Time: %s", asctime(time_info));
    printf("Executable Path: /proc/self/exe\n");
    return 0;
}
```

Compile and run:

```
gcc procinfo.c -o procinfo
./procinfo
```

# 2. The C Standard Library
The C Standard Library has two parts:

- Header files (.h): contain declarations and function prototypes, but no machine code. Location: /usr/include/
- Shared library (.so): compiled machine code loaded at runtime. Location: /lib/x86_64-linux-gnu/
- Static library (.a): compiled code copied into the executable at compile time. Location: /usr/lib/x86_64-linux-gnu/

Commands used to check them:

```
ls /usr/include/stdio.h /usr/include/unistd.h
grep -w "printf" /usr/include/stdio.h | head -n 2
grep -w "getpid" /usr/include/unistd.h | head -n 2
ls /lib/x86_64-linux-gnu/libc.so.6
ls /usr/lib/x86_64-linux-gnu/libc.a
```

# 3. Static vs Dynamic Linking

```
gcc -static procinfo.c -o procinfo_static
gcc procinfo.c -o procinfo_dynamic
ls -lh procinfo_static procinfo_dynamic
```

- Static linking: the library code is copied into the executable. It is self-contained but large. My result: 961K.
- Dynamic linking: the executable only references libc.so.6, which is loaded at runtime. It is small and the library is shared in memory. My result: 16K.

# 4. Inspecting the Executable with readelf

```
readelf -h procinfo_dynamic
readelf -l procinfo_dynamic
readelf -d procinfo_dynamic
```

Key findings:
- ELF Header (-h): ELF64, little endian, type DYN (PIE), machine x86-64, entry point 0x1140.
- Program Headers (-l): INTERP uses /lib64/ld-linux-x86-64.so.2. LOAD segments are R, R E (code) and RW (data).
- Dynamic Section (-d): the NEEDED shared library is libc.so.6.

# 5. Tracing Dependencies with ldd

```
ldd procinfo_dynamic
ldd procinfo_static
```

- procinfo_dynamic depends on linux-vdso.so.1, libc.so.6 and /lib64/ld-linux-x86-64.so.2.
- procinfo_static shows "not a dynamic executable" because it has no runtime library dependencies.

# Command Summary
- gcc file.c -o out: compile (dynamic linking by default)
- gcc -static file.c -o out: compile with static linking
- readelf -h: show the ELF header
- readelf -l: show the program headers
- readelf -d: show the dynamic section (needed libraries)
- ldd: show the full path of shared libraries

# Conclusion
Header files in /usr/include/ only declare functions, while the real machine code is in libc (.so and .a). Static linking gives a large, self-contained binary, and dynamic linking gives a small binary that loads libc at runtime. The readelf and ldd tools show how the executable is built and which libraries it needs.
