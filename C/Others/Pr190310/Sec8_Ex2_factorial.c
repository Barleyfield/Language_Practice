#include <stdio.h>
int factorial(int n);

int main() {
    printf("%d\n", factorial(5));
}

int factorial(int n) {
    if(n<=1) {
        return 1;
    }
    else {
        return n * factorial(n-1);
    }
}