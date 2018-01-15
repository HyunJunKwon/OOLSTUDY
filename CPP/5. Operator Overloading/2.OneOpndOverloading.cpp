/*
단항 연산자의 오버로딩 ++pos;
-멤버함수에 의한 연산자 오버로딩 pos.operator++();
-전역함수에 의한 연산자 오버로딩 operator++(pos);

*/
#include <iostream>
using namespace std;

class Point 
{
private:
	int xpos, ypos;
public:
	Point(int x=0, int y=0) : xpos(x), ypos(y)
	{  }
	void ShowPosition() const
	{
		cout<<'['<<xpos<<", "<<ypos<<']'<<endl; 
	}
	Point& operator++()
	{
		xpos+=1;
		ypos+=1;
		return *this;
	}
	friend Point& operator--(Point &ref);
};

Point& operator--(Point &ref)
{
	ref.xpos-=1;
	ref.ypos-=1;
	return ref;
}

int main(void)
{
	Point pos(1, 2);
	++pos;
	pos.ShowPosition();
	--pos;
	pos.ShowPosition(); 

	++(++pos);
	pos.ShowPosition();
	--(--pos);
	pos.ShowPosition();
	return 0;
}
