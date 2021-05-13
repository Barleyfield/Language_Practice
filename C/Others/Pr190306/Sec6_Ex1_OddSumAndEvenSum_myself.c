#include <stdio.h>
int main(void) {
    int a = 10, even = 0, odd = 0;
    for(int i=1; i<=a; i++) {
        if(i%2 == 0) {
            even += i;
        }
        else
        {
            odd += i;
        }
    }
    printf("Sum of Even : %d, Sum of Odd : %d\n", even, odd);
}