오전 9:30 2017-08-28

NameSp2.h

#include <iostream>

namespace BestComImpl
{
	void SimpleFunc();
}

namespace ProgComImpl
{
	void SimpleFunc();
}

---------------------------------------------
NameSp2.cpp
#include <iostream>
#include "NameSp2.h"

void BestComImpl::SimpleFunc()
{
	std::cout << "BestCom이 정의한 함수" << std::endl;
}

void ProgComImpl::SimpleFunc()
{
	std::cout << "ProgCom이 정의한 함수" << std::endl;
}

--------------------------------------------
NameSp2-2.cpp
#include <iostream>
#include "NameSp2.h"

int main()
{
	BestComImpl::SimpleFunc();
	ProgComImpl::SimpleFunc();
	return 0;
}