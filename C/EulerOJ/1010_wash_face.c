#include <stdio.h>

int main() {
    int n1 = 0, n2 = 0, n3 = 0;
    scanf("%d %d %d", &n1, &n2, &n3);
    if ((n1 + n2) == n3) {
        printf("%d+%d=%d\n", n1, n2, n3);
    }
    else if (n1 == (n2 + n3)) {
        printf("%d=%d+%d\n", n1, n2, n3);
    }
    if ((n1 * n2) == n3) {
        printf("%d*%d=%d\n", n1, n2, n3);
    }
    else if (n1 == (n2 * n3)) {
        printf("%d=%d*%d\n", n1, n2, n3);
    }
    if ((n1 - n2) == n3) {
        printf("%d-%d=%d\n", n1, n2, n3);
    }
    else if (n1 == (n2 - n3)) {
        printf("%d=%d-%d\n", n1, n2, n3);
    }
    if ((n1 / n2) == n3) {
        printf("%d/%d=%d\n", n1, n2, n3);
    }
    else if (n1 == (n2 / n3)) {
        printf("%d=%d/%d\n", n1, n2, n3);
    }


    return 0;
}