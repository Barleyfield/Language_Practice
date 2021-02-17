/*
* 코딩마법서 19.2 연습문제
* 어떤 1개의 양의 정수에 대해서 그 수 자신을 제외한 모든 약수의 합이 그 수 자신과 같은 수를 완전수라고 하고,
* 그 수 자신을 제외한 모든 약수의 합이 그 수 자신보다 작은 수를 부족수라고 한다.
* 그리고 그 수 자신을 제외한 모든 약수의 합이 그 수 자신보다 큰 수를 과잉수라고 한다.
* 1개의 양의 정수 N이 주어지면 그 수가 완전수인지, 부족수인지, 과잉수인지를 판별하는 프로그램을 작성하라.
* Input Form : 첫째 줄에 1 이상 10,000 이하의 양의 정수 N이 주어진다.
* Output Form : 주어진 정수 N이 완전수이면 "PERFECT", 부족수이면 "DEFICIENT", 과잉수이면 "ABUNDANT"를
*               첫째 줄에 출력하여라.
*/

#pragma warning(disable:4996)
#include <cstdio>
int main() {
	int n = 0, i=0, sum=0;
	scanf("%d", &n);
	for (i = 1; i <= n - 1; i++) {
		if (n % i == 0) {
			sum += i;
		}
	}

	if (sum == n) {
		printf("PERFECT\n");
	}
	else if (sum > n) {
		printf("ABUNDANT\n");
	}
	else {
		printf("DEFICIENT\n");
	}
	
}