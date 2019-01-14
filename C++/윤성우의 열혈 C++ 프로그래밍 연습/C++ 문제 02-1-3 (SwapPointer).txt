#include <iostream>

using namespace std;

void SwapPointer(int &point1, int &point2)
{
	int temp = 0;
	temp = point1;
	point1 = point2;
	point2 = temp;
}


int main()
{
	int num1 = 5;
	int *ptr1 = &num1;
	int num2 = 10;
	int *ptr2 = &num2;
	SwapPointer(*ptr1, *ptr2);
	cout << *ptr1 << endl;
	cout << *ptr2 << endl;
	return 0;
}