/*
������ �����ε�: �����ڰ� �ϴ� ���� �Լ��� ������ �ʿ信 �°� ������ ��.

�����ڸ� �����ε� �ϴ� ������� ���� �� ������ �ִ�. (pos1 + pos2)
-����Լ��� ���� ������ �����ε� pos1.operator+(pos2);
-�����Լ��� ���� ������ �����ε� operator+(pos1, pos2);

����Լ� ������� �����ε� �� �Լ��� �����Լ� ������� �����ε� ��
�Լ����� �켱�õǾ� ȣ��ȴ�.

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
	Point operator+(const Point &ref)    //operator+��� �̸��� �Լ� ����Լ� ����  
	{
		Point pos(xpos + ref.xpos, ypos + ref.ypos);
		return pos;
	}
	friend Point operator+(const Point &pos1, const Point &pos2); // 18��: �Լ��� ���� private������ ������ ����ϱ� ����..  
};

Point operator+(const Point &pos1, const Point &pos2) // �����Լ� ����   
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
