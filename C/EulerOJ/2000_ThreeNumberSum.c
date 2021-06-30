/*
코딩마법서 정답지에도 오류가 있는데, n=15일 때 실제로 코드 돌리면 10개만 나온다.
하지만 2개가 더 있다!
15
1 2 12
1 3 11
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
12
*/ 

#pragma warning(disable:4996)
#include <stdio.h>
int main() {
	// 세 수의 합 N(6≤N≤30) -> n
	// 세 정수는 모두 1 이상, 세 수는 모두 달라야 한다.
	int n = 0, result = 0;
	int i = 0, j = 0, k = 0;
	scanf("%d", &n);
	/*
	* k_max 변수
	* 예 : i가 1이고(최소일 때) j가 i=1인 상태에서 (n-i)/2 범위 내 최대일 때 (10인 경우 i=1, j=4)
	* 그 때 k 값이 다음 i,j 단계에서의 k의 최댓값이다.
	* 실제로 1,4,5일 때 k_max=5. i=2일때도 2,3,5인 것처럼 k는 절대 k_max를 넘지 않는다.
	* 초기화 : 우선은 n-3부터. 그 후 반복문 안에서 1씩 줄여나간다.
	*/

	for (i = 1; i <= (n - 3) / 2; i++) {
		// j는 i부터 시작해야 중복 제거가 저절로 된다.
		// 예 : 10이면 1,2,7이 있는데 2,1,7이 또 나와서 중복이 될 수 있는데, j=i부터 시작하면
		// 2,2,6은 중복이니까 skip 2,3,5부터 시작한다.
		for (j = i; j <= (n - i) / 2; j++) {
			for (k = 1; k <= (n - 3); k++) {
				if (((i + j + k) == n) && (i != j) && (j != k) && (i != k)) {
					printf("%d %d %d\n", i, j, k);
					result++;
				}
			}
		}
	}
	printf("%d", result);
	return 0;
}
	