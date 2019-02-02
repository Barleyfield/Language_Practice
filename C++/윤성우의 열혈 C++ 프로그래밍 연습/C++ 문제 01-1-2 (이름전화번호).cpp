// 오전 10:16 2017-08-26
#include <iostream>

int main(void)
{
	char name[10];
	char phonenum[20];

	std::cout << "이름을 입력하세요: ";
	std::cin >> name;
	std::cout << "전화번호를 입력하세요: ";
	std::cin >> phonenum;

	std::cout << "이름: " << name << std::endl;
	std::cout << "전화번호: " << phonenum << std::endl;
	return 0;

}