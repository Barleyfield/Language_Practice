/* 도전! 프로그래밍 1 - 8 */

#include <stdio.h>

int twopower(int n);


int main(void)
{
	int n = 0;
	printf("2의 몇 승?: ");
	scanf_s("%d", &n);
	printf("2의 %d승은 %d \n", n, twopower(n));


	return 0;
}

int twopower(int n)
{
	if (n < 1 && n >= 0)		//2의 0승은 1이기 때문에 1 반환
		return 1;
	else if (n >= 1)
	{
		return twopower(n - 1) * 2;		// 재귀함수 이용. twopower 함수의 이전 값에 2를 곱함으로써 2의 거듭제곱을 계산할 수 있는 코드 완성.
	}

}	