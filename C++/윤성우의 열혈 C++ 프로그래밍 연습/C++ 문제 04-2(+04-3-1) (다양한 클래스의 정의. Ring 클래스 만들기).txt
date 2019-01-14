오후 7:45 2017-09-20
#include <iostream>
using namespace std;

class Point		// 점 구조체
{
private:
	int xpos, ypos;
public:
	void Init(int x, int y)
	{
		xpos = x;
		ypos = y;
	}	

	void ShowPointInfo() const
	{
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
};


class Circle			// 원 구조체
{
private:
	int radius;			// 반지름
	Point center;		// 중심 좌표
public:
	void Circle_Init(Point p, int num);		// 원 구조체 초기화. 원점과 반지름을 입력받는다.
	int ShowRadius();						// 반지름을 출력하는 함수이다.
};

void Circle::Circle_Init(Point p, int num)		// 원 초기화
{
	center = p;
	radius = num;
}

int Circle::ShowRadius()						// 반지름 출력
{
	return radius;
}

class Ring				// 링 구조체
{
private:
	Point FirstRingCenter, SecondRingCenter;		// 1번째와 2번째 중심 좌표
	Circle c1, c2;									// 1번째와 2번째 원
public:
	void Init(int first_x, int first_y, int first_rad, int sec_x, int sec_y, int sec_rad);		// 링 초기화. 총 6개의 인수를 입력받는다.
	void ShowRingInfo();			// 링의 정보 출력
	
};

void Ring::Init(int first_x, int first_y, int first_rad, int sec_x, int sec_y, int sec_rad)
{
	FirstRingCenter.Init(first_x, first_y);			// 1번째 원의 중심좌표에 first_x, first_y 넣기
	SecondRingCenter.Init(sec_x, sec_y);			// 2번째 원의 중심좌표에 sec_x, sec_y 넣기
	c1.Circle_Init(FirstRingCenter, first_rad);		// 원 c1에 입력받았던 점과 반지름 넣기
	c2.Circle_Init(SecondRingCenter, sec_rad);		// 원 c2에 입력받았던 점과 반지름 넣기
	
}

void Ring::ShowRingInfo()		// 링의 정보 출력
{
	cout << "Inner Circle Info..." << endl;
	cout << "radius: " << c1.ShowRadius() << endl;
	FirstRingCenter.ShowPointInfo();

	cout << "Outer Circle Info..." << endl;
	cout << "radius: " << c2.ShowRadius() << endl;
	SecondRingCenter.ShowPointInfo();

}

int main()
{
	Ring ring;
	ring.Init(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	return 0;
}