Fruitdeal.h



#ifndef __FRUITDEAL_H__
#define __FRUITDEAL_H__

class FruitSeller
{
private:
	int APPLE_PRICE;
	int numofApples;
	int myMoney;

public:
	bool InitMembers(int price, int num, int money);
	int SaleApples(int money);
	void ShowSalesResult() const;


};

class FruitBuyer
{
private:
	int myMoney;
	int numofApples;

public:
	bool InitMembers(int money);
	bool BuyApples(FruitSeller &seller, int money);
	void ShowBuyResult() const;


};

#endif

--------------------------------------------------------------------------

Fruitdeal.cpp



#include <iostream>
#include "Fruitdeal.h"
using namespace std;

bool FruitSeller::InitMembers(int price, int num, int money)
{
	/* if (price < 0 || num < 0 || money < 0)
	{
		cout << "0보다 작을 수 없습니다." << endl;
		return false;
	} */

	if (price<0)
	{
		cout << "판매자의 사과 가격은 0보다 작을 수 없습니다." << endl;
		return false;
	}
	else if (num<0)
	{
		cout << "판매자의 사과 개수는 0보다 작을 수 없습니다." << endl;
		return false;
	}
	else if (money<0)
	{
		cout << "판매자의 돈은 0보다 작을 수 없습니다." << endl;
		return false;
	}

	APPLE_PRICE = price;
	numofApples = num;
	myMoney = money;

}

int FruitSeller::SaleApples(int money)
{
	int num = money / APPLE_PRICE;
	numofApples -= num;
	myMoney += money;
	return num;

}

void FruitSeller::ShowSalesResult() const
{
	cout << "남은 사과: " << numofApples << endl;
	cout << "판매 수익: " << myMoney << endl;

}

bool FruitBuyer::InitMembers(int money)
{
	if (money < 0)
	{
		cout << "구매자의 돈은 0보다 작을 수 없습니다." << endl;
		return false;
	}

	myMoney = money;
	numofApples = 0;

}

bool FruitBuyer::BuyApples(FruitSeller &seller, int money)
{
	if (money < 0)
	{
		cout << "구매자는 0보다 작은 값으로 결제할 수 없습니다." << endl;
		return false;
	}
	numofApples += seller.SaleApples(money);
	myMoney -= money;

}

void FruitBuyer::ShowBuyResult() const
{
	cout << "현재 잔액: " << myMoney << endl;
	cout << "사과 개수: " << numofApples << endl;
}




--------------------------------------------------------------------------------
FruitSaleSim2.cpp


#include <iostream>
#include "Fruitdeal.h"
using namespace std;


int main()
{
	FruitSeller seller;
	seller.InitMembers(1000, 20, 0);
	FruitBuyer buyer;
	buyer.InitMembers(5000);
	buyer.BuyApples(seller, -2000);

	cout << "과일 판매자의 현황" << endl;
	seller.ShowSalesResult();
	cout << "과일 구매자의 현황" << endl;
	buyer.ShowBuyResult();
	return 0;
}
