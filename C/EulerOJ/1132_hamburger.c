#include <stdio.h>

int main() {
	int k=0, n=0, m=0, result=0;
    scanf("%d %d %d", &k, &n, &m);
    result = k*n - m;
    /* 
    k = 햄버거 1개 가격
    n = 사려고 하는 햄버거의 개수
    m = 현재 오일러가 가진 돈
    */

    if(result<0) {
        result = 0;
    }
    printf("%d\n", result);
	return 0;
}