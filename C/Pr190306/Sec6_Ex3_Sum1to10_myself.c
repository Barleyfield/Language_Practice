#include <stdio.h>

int main() {
    int i = 0, hap = 0;

    do {
        i = i + 1;
        hap = hap + i;
    } while(i<10);
    
    printf("i=%d, hap=%d\n", i, hap);
}