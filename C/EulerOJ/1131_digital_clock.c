#include <stdio.h>

int main() {
    int h = 0, m = 0, est_h = 0, est_m = 0;    // h=시, m=분, est_h=소요 시간, est_m=소요 분
    scanf("%d %d", &h, &m);
    scanf("%d", &est_m);
    while (est_m >= 60) {
        est_h++;
        est_m -= 60;
    }

    h += est_h;
    m += est_m;
    while (m >= 60) {
        h++;
        m -= 60;
    }
    if (h >= 24) h -= 24;
    printf("%d %d\n", h, m);
    return 0;
}