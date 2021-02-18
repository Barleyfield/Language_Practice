#pragma warning(disable:4996)
#include <stdio.h>
int main() {
	int n = 0, i = 0, j = 0, result=0;
	scanf("%d", &n);
	/*
	* 도미노 문제를 뜯어보면 결국은 순서쌍 문제다.
	* 예 : n=2이면 (0,0),(0,1),(0,2),(1,1),(1,2),(2,2)
	*/
	for (i = 0; i <= n; i++) {
		for (j = i; j <= n; j++) {
			result += i;
			result += j;
			// i,j값만 각각 더해주면 된다.
		}
	}
	printf("%d\n", result);
	return 0;
}