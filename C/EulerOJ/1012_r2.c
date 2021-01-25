#include <stdio.h>

int main() {
    int r1 = 0, r2 = 0, s = 0, avg = 0; // s=합계, avg=평균
    scanf("%d %d", &r1, &avg);
    s = avg * 2;
    r2 = s - r1;
    printf("%d\n", r2);
    return 0;
}