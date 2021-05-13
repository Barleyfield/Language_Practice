#include <stdio.h>

int main() {
    int i = 250;
    float a = 125.23f;
    float b = 314.1592e+5;

    char c = 'A';
    char dd[] = "Korea";

    printf("10 Decimal i = %d\t, 8 Octal i = %o\n", i, i);
    printf("a = %8.2f, b = %e\n", a, b);
    printf("Variable 'c' is %c in character, %d in ASCII.\n", c, c);
    printf("%-10s, %10s\n\r", dd, dd);

}