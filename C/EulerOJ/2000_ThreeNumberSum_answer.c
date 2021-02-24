// https://ideone.com/lE9iQb
/*
답안 오류! n=15일 때 
15
1 4 10
1 5 9
1 6 8
2 3 10
2 4 9
2 5 8
2 6 7
3 4 8
3 5 7
4 5 6
10
10개만 출력. 하지만 실제로는 12개이다.
*/
#pragma warning(disable:4996)
#include <stdio.h>
int main() {
	int n, i, j, k, cnt = 0;
	scanf("%d", &n);

	for (i = 1; i <= 10; i++) {
		for (j = i + 1; j <= 10; j++) {
			for (k = j + 1; k <= 10; k++) {
				if (i + j + k == n) {
					printf("%d %d %d\n", i, j, k);
					cnt++;
				}
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}