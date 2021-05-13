/* 도전 프로그래밍 1 - 6 */
#include <stdio.h>

int main(void)
{
	int num = 0;
	int h = 0, m = 0;		// 시, 분 변수 선언

	printf("초 입력: ");
	scanf_s("%d", &num);

	if (num < 60)		// 조건 : 60초 이내, 60초 이상~1시간 이내, 1시간 이상
		printf("h:0 m:0 s:%d \n", num);
	else if (num >= 60 && num < 3600)
	{
		m = 1;		// 이거 안해주면 1시간 이내 시간은 1분씩 늘어남 왜 그런지는 나중에 물어보자. 아마 1분 이상이라 1로 초기화해야되서 그런가봄.
		for (; m < 60; m++)
		{
			num = num - 60;
			if (num < 60)
				break;
		}
		printf("h:0 m:%d s:%d \n", m, num);
	}
	else
	{
		for (; ; h++)		
		{
			while(m<60)
			{
				if (num >= 60)
					num = num - 60;		// num 즉 초가 60 아래로 될 때까지 감소
				else if (num < 60)		// 60 이하면 멈추기
					break;
				m++;
			}
			if (m >= 60)		// 이어서 분도 60 이상이면 계속 감소, 이하면 멈추기
			{
				m = m - 60;
				m = 0;
			}
			else if (m < 60)
				break;
		}
		
		printf("h:%d m:%d s:%d \n", h, m, num);
	}

	
	return 0;
}