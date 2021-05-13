#include <stdio.h>

int main() {
    int a = 15, b;
    if(a>10) {
        b = a-10;
    }
    b = b + (10-b);
    
    printf("%d", b);
    return 0;
}