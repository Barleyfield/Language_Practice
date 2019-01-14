/* 오후 7:35 2017-08-31 */
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
	int index = 0;
	cout << "난수 5개 생성" << endl;
	srand(time(NULL));

	for (index = 0; index < 5; index++)
	{
		cout << rand() % 100 << endl;
	}

	return 0;
}