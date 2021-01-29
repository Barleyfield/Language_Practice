#include <stdio.h>

int main() {
	int lock1=0, lock2=0;
    scanf("%d %d", &lock1, &lock2);
    if(lock2 == (lock1+1)) {
        printf("0\n");
    } else {
        printf("1\n");
    }
	return 0;
}