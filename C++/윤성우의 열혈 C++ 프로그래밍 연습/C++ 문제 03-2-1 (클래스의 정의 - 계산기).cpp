#include <iostream>
using namespace std;

class Calculator
{
private:
	double num;
	int AddCount = 0;
	int MinCount = 0;
	int MulCount = 0;
	int DivCount = 0;
public:
	void Init()
	{
		num = 0;
	}

	double Add(double num, double x)
	{
		num += x;
		AddCount++;
		return num;
	}

	double Min(double num, double x)
	{
		num -= x;
		MinCount++;
		return num;
	}

	double Mul(double num, double x)
	{
		num *= x;
		MulCount++;
		return num;
	}

	double Div(double num, double x)
	{
		num /= x;
		DivCount++;
		return num;
	}

	void ShowOpCount()
	{
		cout << "덧셈: " << AddCount << "뺄셈: " << MinCount << "곱셈: " << MulCount << "나눗셈: " << DivCount << endl;
	}
};

int main()
{
	Calculator cal;
	cal.Init();
	cout << "3.2+2.4 = " << cal.Add(3.2, 2.4) << endl;
	cout << "3.5/1.7 = " << cal.Div(3.5, 1.7) << endl;
	cout << "2.2-1.5 = " << cal.Min(2.2, 1.5) << endl;
	cout << "4.9/1.2 = " << cal.Div(4.9, 1.2) << endl;
	cal.ShowOpCount();
	return 0;

}
			