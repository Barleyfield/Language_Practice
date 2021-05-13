// 탑스팟 2020년 컴퓨터일반 기출문제집 C언어 1047번
#include <stdio.h>
#include <stdlib.h>

void a(int n, int *num) {
	for(int i=0; i<n; i++) {
		scanf("%d", &(num[i]));
	}
}

void c(int *a, int *b) {
	int t;
	t = *a; *a = *b; *b = t;
}

void b(int n, int *lt) {
	int a,b;
	for(a=0; a<n-1; a++) {
		for(b=a+1; b<n; b++) {
			if(lt[a] > lt[b]) c(lt+a, lt+b);
		}
	}
}

int main() {
	int n;
	int *num;
	printf("How many numbers?");
	scanf("%d", &n);
	num = (int *)malloc(sizeof(int) * n);
	a(n, num);
	b(n, num);
	for(int i=0; i<n; i++) {
		printf("%d ", num[i]);
	}
}