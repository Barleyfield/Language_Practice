// 오전 10:10 2017-08-26
#include <iostream>

int main(void)
{
	int num[5];
	int result = 0;

	for (int i = 0; i < 5; i++)
	{
		std::cout << i+1 << "번째 정수 입력: ";
		std::cin >> num[i];
		result += num[i];
	}
	std::cout << "합계: " << result << std::endl;
	printf("\n");
	return 0;
}
