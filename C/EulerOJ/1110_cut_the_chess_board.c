#pragma warning(disable:4996)
#include <stdio.h>

int main() {
    /*
    접근하기 : 먼저 규칙 찾기
    자르기 :   01 02 03 04 05 06 07 08 09 10 ...
    조각 :     02 04 06 09 12 16 20 25 30 36 ...
    increment:  +2 +2 +3 +3 +4 +4 +5 +5 +6 ...
    */
    int i = 1, input = 0, result = 2, increment = 2, increment_count = 0;
    // increment는 result에 계속 더하는 수
    // increment_count는 increment를 2번 더하면 다시 초기화 and increment++로 이어짐.
    scanf("%d", &input);
    if (input == 1) {
        result = 2;
    }
    else {
        for (i = 1; i < input; i++) {
            if (increment_count == 0) {
                if (i != 1) {
                    // i!=1 조건을 넣지 않으면 increment가 2,3,3,4,4로,
                    // 앞에 2를 2번 더해야 하는데 1번만 더하고 바로 3으로 넘어간다.
                    increment_count++;
                }
            }
            else {
                increment_count = 0;
                increment++;
            }
            result += increment;
            // printf("turn = %d, increment = %d, result = %d\n", i, increment, result);
        }
    }
    printf("%d\n", result);
    return 0;
}