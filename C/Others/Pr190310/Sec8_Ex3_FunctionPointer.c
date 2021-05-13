// C언어에서 함수 이름은 해당 함수가 시작되는 주소!
// 함수 포인터 선언 시 * 붙이고 우선순위를 구분하기 위해 괄호로 묶어주기.
#include <stdio.h>
int add(int i, int j) {
    return i+j;
}

int main() {
    int i=10, j=5, result;
    int (*pf)(int, int);
    pf = add;
    result = pf(i,j);
    printf("%d", result);
}
