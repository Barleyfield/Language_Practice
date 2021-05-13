// 탑스팟 2020년 컴퓨터일반 기출문제집 C언어 1046번
#include <stdio.h>

double h(double* f, int d, double x) {
	int i;
	double res = 0.0;
	for (i = d - 1; i >= 0; i--) {
		res = res * x + f[i];
	}
	return res;
}

int main() {
	double f[] = { 1,2,3,4 };
	printf("%3.1f\n", h(f, 4, 2));
	return 0;
}