#include <stdio.h>
#include <unistd.h>

int main() {
int choice;

printf("Current PID: %d\n", getpid());

printf("Do you want to continue?");
scanf("%d", &choice);

if (choice == 1) {
printf("Continuing...\n");
sleep(5);
return 0;
} else {
printf("Exiting");
return 1;
}
}
