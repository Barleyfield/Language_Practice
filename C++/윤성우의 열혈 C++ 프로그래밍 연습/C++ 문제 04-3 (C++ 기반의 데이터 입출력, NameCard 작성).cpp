// 오후 10:02 2017-09-20
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

typedef enum COMP_POS { CLERK, SENIOR, ASSIST, MANAGER };		// COMP_POS enum(열거체) 선언

class NameCard
{
private:
	string name;				// string 변수형을 이용하면 자동으로 동적 할당이 이루어진다.
	string company;
	string phoneNum;
	int rank;

public:
	NameCard(string inputName, string inputCompany, string inputPhoneNum, int inputRank);
	void ShowNameCardInfo();
	void ShowRank();

};

NameCard::NameCard(string inputName, string inputCompany, string inputPhoneNum, int inputRank)
{
	name = inputName;
	company = inputCompany;				// 이름 복사도 대입처럼 그냥 등호 쓰면 된다.
	phoneNum = inputPhoneNum;
	rank = inputRank;
}


void NameCard::ShowNameCardInfo()
{
	cout << "이름: " << name << endl;
	cout << "회사: " << company << endl;
	cout << "전화번호: " << phoneNum << endl;
	cout << "직급: ";  ShowRank(); 
}

void NameCard::ShowRank()		// 열거체에 따른 직급 문자열 출력
{
	switch (rank)
	{
	case CLERK:
		cout << "사원" << endl;
		break;
	case SENIOR:
		cout << "주임" << endl;
		break;
	case ASSIST:
		cout << "대리" << endl;
		break;
	case MANAGER:
		cout << "과장" << endl;
		break;
	default:
		cout << "직급 오류!" << endl;
		break;
	}
	printf("\n");
	
}


int main()
{
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard manSenior("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);
	manClerk.ShowNameCardInfo();
	manSenior.ShowNameCardInfo();
	manAssist.ShowNameCardInfo();
	return 0;
}
		

	