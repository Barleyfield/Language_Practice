// 탑스팟 2020년 컴퓨터일반 기출문제집 C언어 1049번

#include <stdio.h>
#include <stdlib.h>
#define N 3
int main() {
	int(*in)[N], * out, sum = 0;

	in = (int(*)[N])malloc(N * N * sizeof(int));
	out = (int*)in;

	for (int i = 0; i < N * N; i++) {
		out[i] = i;
	}

	for (int i = 0; i < N; i++) {
		sum += in[i][i];
	}

	printf("%d", sum);
	return 0;
}