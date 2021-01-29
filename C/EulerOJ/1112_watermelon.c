#include <stdio.h>

int main() {
    int w=0;
    scanf("%d", &w);
    // 2개의 짝수로 나눈다 = w는 짝수다
	// 놓친 부분 : 2는 짝수로 나눌 수 없다.
	if(w>2 && w%2==0) {
    //if(w%2 == 0) -> 원래 답안.
        printf("YES\n");
    } else {
        printf("NO\n");
    }

	return 0;
}