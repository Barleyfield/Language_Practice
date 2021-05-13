#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n = 0;
    srand(time(NULL));          // seed 설정
    printf("Keep going until 1\n");
    while(n != 1) {
        n = rand() % 6 + 1;     // 1부터 6까지
        printf("%d\n", n);
    }
    printf("End\n");
}