// 오후 4:04 2017-10-10
#include <iostream>
#include <cstdio>
#include <string>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

namespace COMP_POS
{
	enum { CLERK, SENIOR, ASSIST, MANAGER };		// enum(열거체) 선언

	void ShowPositionInfo(int pos)
	{
		switch(pos)
		{
		case CLERK:
			cout<<"사원"<<endl;
			break;
		case SENIOR:
			cout<<"주임"<<endl;
			break;
		case ASSIST:
			cout<<"대리"<<endl;
			break;
		case MANAGER:
			cout<<"과장"<<endl;
			break;
		}
	}
}

class NameCard
{
private:
	char *name;
	char *company;
	char *phone;
	int position;

public:
	NameCard(char *_name, char *_company, char *_phone, int pos);
	void ShowNameCardInfo();
	NameCard(const NameCard &copy);
	~NameCard();

};

NameCard::NameCard(char *_name, char *_company, char *_phone, int pos)
{
	this->name = new char[strlen(_name)+1];
	this->company = new char[strlen(_company)+1];
	this->phone = new char[strlen(_phone)+1];
	strcpy(this->name, _name);
	strcpy(this->company, _company);
	strcpy(this->phone, _phone);
	this->position = pos;
}


void NameCard::ShowNameCardInfo()
{
	cout << "이름: " << name << endl;
	cout << "회사: " << company << endl;
	cout << "전화번호: " << phone << endl;
	cout << "직급: ";  COMP_POS::ShowPositionInfo(position);
}

NameCard::NameCard(const NameCard &copy)
{
	name = new char[strlen(copy.name) + 1];
	company = new char[strlen(copy.company) + 1];
	phone = new char[strlen(copy.phone) + 1];
	strcpy(name, copy.name);
	strcpy(company, copy.company);
	strcpy(phone, copy.phone);
	position = copy.position;
}


NameCard::~NameCard()
{
	delete[] name;
	delete[] company;
	delete[] phone;
}


int main()
{
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard copy1 = manClerk;
	NameCard manSenior("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard copy2 = manSenior;
	copy1.ShowNameCardInfo();
	copy2.ShowNameCardInfo();

	return 0;
}
		
