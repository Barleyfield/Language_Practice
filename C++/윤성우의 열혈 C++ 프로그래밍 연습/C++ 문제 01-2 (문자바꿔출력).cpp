#include <iostream>

void swap(int *num1, int *num2)
{
	std::cout << *num2 << ' ' << *num1 << std::endl;
}

// 오전 9:07 2017-08-27
void swap(char *ch1, char *ch2)
{
	std::cout << *ch2 << ' ' << *ch1 << std::endl;

}

void swap(double *dbl1, double *dbl2)
{
	std::cout << *dbl2 << ' ' << *dbl1 << std::endl;
}

int main(void)
{
	int num1 = 20, num2 = 30;
	swap(&num1, &num2);

	char ch1 = 'A', ch2 = 'Z';
	swap(&ch1, &ch2);

	double dbl1 = 1.111, dbl2 = 5.555;
	swap(&dbl1, &dbl2);

	return 0;
}
