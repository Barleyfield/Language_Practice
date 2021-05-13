#include <stdio.h>


int money(int n)
{
	int ten = 0, fifty = 0, hund = 0; 		
	

	while (n % 10 != 0)
	{
		printf("10원 단위로 입력하시오: ");
		scanf_s("%d", &n);
		
	}



		for( ; n>=100; hund++)			// 100원씩 깎으며 100원동전 개수 늘리기.
		{
			n = n - 100;
			if( 50<=n && n<100)			// 계속 깎아서 n이 50~100사이의 값 될 때 다음 for문 실행
			{
				for( ; n>=50; fifty++)		// n이 50 이상일 경우 50씩 깎으며 50원동전 개수 늘리기.
				{
					n = n - 50;
					if ( n<50)				// 50씩 계속 깎아서 n이 50 미만이 되면 다음 for문 실행
					{
						for( ; n>0; ten++)		// 마지막으로 10원씩 깎으며 10원동전 개수 늘리기. 0 밑으로 안 넘어가게 설정.
						{
							n = n - 10;
						
						}
					}
				}
			}
			else if (0<=n && n<50)		//만약 100원씩 깎았는데 남은 값이 50미만(예: 1040원)일 경우 바로 10원 계산
			{
				for( ; n>0; ten++)
				{
					n = n - 10;
				}
			}
		}

		
	printf("100원: %d, 50원: %d, 10원: %d", hund, fifty, ten);
	return 0;

}


int main(void)
{
	int n = 0;
	printf("돈 분배하기: \n");
	scanf_s("%d", &n);
	money(n);


	return 0;
}

