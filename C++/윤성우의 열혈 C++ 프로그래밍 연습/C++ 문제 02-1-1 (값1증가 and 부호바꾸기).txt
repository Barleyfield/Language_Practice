오후 4:55 2017-08-28
#include <iostream>
using namespace std;

void Increase(int &num)
{
	cout << (num) + 1 << endl;
}

void ChangeSign(int &num)
{
	if ((&num) <= 0)
	{
		num = num + (2 * num);
	}
	else
	{
		num = num - (2 * num);
	}
	cout << num << endl;
}



int main()
{
	int val = 0;
	cout << "수 입력: ";
	cin >> val;
	Increase(val);
	ChangeSign(val);

	return 0;
}