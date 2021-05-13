#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    printf("%f\n", pow(2,3));
    printf("%f\n", sqrt(25));
    printf("%d\n", abs(-20));
    
    char a[] = "ad", b[] = "bc";
    printf("%d\n", strcmp(a,b));

    char c[] = "123", d[] = "456";
    printf("%d\n", atoi(c) + atoi(d));

    char e[] = "12.3";
    char f[] = "45.6";
    printf("%f\n", atof(e) + atof(f));
    return 0;
}
