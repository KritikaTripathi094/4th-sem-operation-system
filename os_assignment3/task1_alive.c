#include <stdio.h>
#include<unistd.h>

int main() {
printf("I am starting...\n");
for(int i = 1; i<= 30; i++) {
sleep(1);
}
printf("I am finished.\n");
return 0;
}

