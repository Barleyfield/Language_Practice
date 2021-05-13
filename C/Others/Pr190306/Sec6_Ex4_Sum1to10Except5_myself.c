#include <stdio.h>

int main(void) {
    int i = 0, hap = 0;
    
    while(i<10) {
        i++;
        if(i%5 == 0)
            continue;
        hap += i;
    }
    printf("i=%d, hap=%d\n", i, hap);
    return 0;
}