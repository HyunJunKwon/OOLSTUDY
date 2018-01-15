/*
연산자 오버로딩: 연산자가 하는 일을 함수로 개인의 필요에 맞게 구현한 것.

연산자를 오버로딩 하는 방법에는 다음 두 가지가 있다. (pos1 + pos2)
-멤버함수에 의한 연산자 오버로딩 pos1.operator+(pos2);
-전역함수에 의한 연산자 오버로딩 operator+(pos1, pos2);

멤버함수 기반으로 오버로딩 된 함수가 전역함수 기반으로 오버로딩 된
함수보다 우선시되어 호출된다.

*/
#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{  }
	void ShowPosition() const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
	Point operator+(const Point &ref)    //operator+라는 이름의 함수 멤버함수 형식  
	{
		Point pos(xpos + ref.xpos, ypos + ref.ypos);
		return pos;
	}
	friend Point operator+(const Point &pos1, const Point &pos2); // 18행: 함수에 대해 private영역의 접근을 허용하기 위해..  
};

Point operator+(const Point &pos1, const Point &pos2) // 전역함수 형태   
{
	Point pos(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
	return pos;
}

int main(void)
{
	Point pos1(3, 4);
	Point pos2(10, 20);
	Point pos3 = pos1 + pos2;

	pos1.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();
	return 0;
}
