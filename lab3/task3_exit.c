#include <stdio.h>

int main() {
int num;
printf("Enter a num");
scanf("%d", &num);
if (num > 0) {
printf("Success\n");
return 0;
} else {
printf("Failure");
return 1;
}
}

