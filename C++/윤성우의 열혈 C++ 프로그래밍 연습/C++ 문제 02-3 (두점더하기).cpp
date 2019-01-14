오후 8:34 2017-08-30
/* 참고로 실행은 되는데 Heap Corruption이 뜬다. */

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef struct __Point {
	int xpos;
	int ypos;
} Point;

Point& PntAdder(const Point &p1, const Point &p2);

int main()
{
	int i = 0;
	cout << "점 2개를 입력하세요" << endl;
	Point *Pnt = new Point;

	for (i = 0; i < 2; i++)
	{
		cout << i + 1 << " 번째 x,y: ";
		cin >> Pnt[i].xpos >> Pnt[i].ypos;
	}

	Point &addresult = PntAdder(Pnt[0], Pnt[1]);
	cout << "결과 [x,y] : " << addresult.xpos << ' ' << addresult.ypos << endl;

	
	delete[] Pnt;
	delete[] &addresult;

	return 0;
}

Point& PntAdder(const Point &p1, const Point &p2)
{
	Point *result = new Point;
	result->xpos = p1.xpos + p2.xpos;
	result->ypos = p1.ypos + p2.ypos;
	return *result;
	
}

	
	