// 오후 12:45 2017-08-26
#include <iostream>

int main(void)
{
	int basic = 50;
	int sell = 0;
	int result = 0;

	while (1)
	{
		
		std::cout << "판매 금액을 만원 단위로 입력 (-1 to end): ";
		std::cin >> sell;
		if (sell == -1)		//여기에 넣어야 급여 계산 안 하고 바로 프로그램 종료 가능
		{
			std::cout << "프로그램을 종료합니다" << std::endl;
			break;
		}
		result = basic + (sell * 0.12);
		std::cout << "이번 달 급여: " << result << "만원" << std::endl;
		

	}

	
	
	return 0;
}

