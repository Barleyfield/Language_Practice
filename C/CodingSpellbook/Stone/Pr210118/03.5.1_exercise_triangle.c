/*
* �ڵ������� 03.5 ��������
* �ﰢ�� ����� ����ϴ� ���α׷� �ۼ�
* �ణ ���� : ���� ������ �� ���ڸ�ŭ ����ϱ�
*/

#pragma warning(disable:4996)
#include <stdio.h>
int main() {
	int n = 0, i = 0, j = 0;
	printf("n �Է� : ");
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= i; j++) {
			printf("#");
		}
		printf("\n");
	}

	return 0;
}