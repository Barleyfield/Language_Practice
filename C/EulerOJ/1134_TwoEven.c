// EulerOJ에서 채점 불가

#pragma warning(disable:4996)
#include <stdio.h>
// #include <math.h> -> EulerOJ에서 작동 불가

int squareroot(int num) {
	int result = 0, i = 0;
	for (i = 1; (i * i) <= num; i++) {
		// 제곱근 구하기
		if (((i * i) <= num) && (((i + 1) * (i + 1)) > num)) {
			result = i;
			break;
		}
	}
	return result;
}

int main() {
	int n = 0, i = 0, j=0, result=0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		// 처음 : 2개의 짝수로 표현될 수 있다 = a*b라면 a,b 모두 최소 2의 배수가 되어야 한다 -> n은 4의 배수면 된다.
		// 그런데 문제를 보니 정말로 정확히 2개의 짝수의 곱으로 표현되는 수만 골라야 한다.
		// 그래서 짝수의 곱으로 나타낼 수 있는 두 짝수 쌍 개수를 세는 변수를 추가한다.
		int even_counter = 0;

		// 두 짝수의 곱으로 표현하려면 4의 배수가 되어야 한다.
		if (i % 4 == 0) {
			// i의 제곱근 이하의 약수를 구하면 그의 짝도 다 알 수 있다.
			// 예 : 28의 제곱근 : 5 이상 6 이하, 1,2,4,7,14,28이므로 1,2,4까지만 알면 그 짝을 다 알 수 있다.
			// for (j = 1; j <= sqrt(i); j++) {
			for (j = 1; j <= squareroot(i); j++) {
				// j도 i를 j로 나눈 수도 모두 짝수라면 -> 예 : 2와 (28/2)=14 둘 다 짝수면 even_couter++
				if ((j%2==0) && ((i/j)%2==0)) {
					even_counter++;
				}
			}
		}
		// 정확히 2개의 짝수의 곱이여야 하므로 16처럼 2*8, 4*4가 나온 경우는 빼야 한다.
		// 그래서 짝수 카운터=1인 것만 골라낸다.
		if (even_counter == 1) {
			result++;
		}
	}
	printf("%d\n", result);
	return 0;
}