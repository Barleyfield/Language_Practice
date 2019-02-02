// 오전 10:20 2017-08-26
#include <iostream>

int main(void)
{
	int num = 0;
	std::cout << "몇 단? : ";
	std::cin >> num;

	for (int i = 1; i < 10; i++)
	{
		std::cout << num << " X " << i << " = " << num*i << std::endl;
	}
	return 0;
}
