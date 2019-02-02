// 오후 8:02 2017-10-19
#include <iostream>
#include <cstring>
using namespace std;

class Rectangle
{
private:
	int side1;
	int side2;
public:
	Rectangle(int s) : side1(s), side2(s) { }
	Rectangle(int s1, int s2) : side1(s1), side2(s2) { }
	void ShowAreaInfo()
	{
		cout << "면적: " << side1 * side2 << endl;
	}

};

class Square : public Rectangle
{
private:
	int side;
public:
	Square(int s) : Rectangle(s) { }
};

int main()
{
	Rectangle rec(4, 3);
	rec.ShowAreaInfo();

	Square sqr(7);
	sqr.ShowAreaInfo();
	return 0;
}



