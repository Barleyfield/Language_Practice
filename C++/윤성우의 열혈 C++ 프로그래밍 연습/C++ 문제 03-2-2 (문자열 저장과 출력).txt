#include <iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

class Printer
{
private:
	char SavedStr[100];		//여기를 포인터로 설정하면 상수화되어 복사가 되지 않는다! 컴파일러가 자체적으로 막는 듯 하다.
public:						//부가설명 : http://itguru.tistory.com/33
	char SetString(char *str);
	void ShowString();

};

char Printer::SetString(char *str)
{
	strcpy(SavedStr, str);
	return *SavedStr;		//return을 포인터로 하든지, 아니면 반환형을 포인터로 설정하면 성공한다.

}

void Printer::ShowString()
{
	cout << SavedStr << endl;		//여긴 굳이 *SavedStr 안 붙여도 될 듯.
}


int main()
{
	Printer pnt;
	pnt.SetString("Hello World!");
	pnt.ShowString();

	pnt.SetString("I love C++");
	pnt.ShowString();
	return 0;
}



	