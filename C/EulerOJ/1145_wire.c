#pragma warning(disable:4996)
#include <stdio.h>
int main() {
	int n = 0;
	scanf("%d", &n);
	// 예 : 6번 꺾이면 먼저 2+3+4+5+6+7+8이므로 2부터 n+2까지 더한 값 * (n+1)개 / 2를 해야 한다.
	// 그러면 35가 나오는데, 여기서 꺾인점 개수 6을 빼줘야 한다.(더할 때 겹쳤기 때문)
	printf("%d\n", ((2 + (n + 2)) * (n + 1) / 2) - n);
	return 0;
}