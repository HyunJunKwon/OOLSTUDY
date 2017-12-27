/*
C++����, AAA�� ������ ������ 
AAA ��ü �Ǵ� AAA�� ���� Ȥ�� ���������� ����ϴ� 
��� ��ü�� ����ų �� �ִ�.(��ü�� �ּ� ���� ������ �� �ִ�)

int main(void)
{
	Base * bptr = new Derived(); // ������ ok
	bptr->DerivedFunc(); // ������ err
}
-> C++ �����Ϸ��� ������ ������ ���ɼ� ���θ� �Ǵ� �� ��, 
�������� �ڷ����� �������� �Ǵ�����, ���� ����Ű�� ��ü�� 
�ڷ����� �������� �Ǵ����� �ʴ´�.
int main(void)
{
	Derived * dptr = new Derived(); // ������ ok
	Base  * bptr = dptr ; // ������ ok
}
dptr�� Derived Ŭ������ ������ �����ϱ�, �� �����Ͱ� ����Ű�� ��ü��
�и� Base Ŭ������ ���� Ȥ�� ���������� ����ϴ� ��ü�̴�.
�׷��� Base�� ������ �����ε� ������ ����!!
base *
��
derived * ���Ҵ簡��

!!! ��������δ� ���������� �ش��ϴ� Ŭ������ ���ǵ� ������� ���� ����!!! 

�����Լ��� ����Ǹ� �� �Լ��� �������̵� �ϴ� �Լ��� �����Լ��� �ȴ�.
*/

#include <iostream>
using namespace std;

class First
{
public:
	virtual void MyFunc()
	{
		cout<<"FirstFunc"<<endl;
	}
};

class Second: public First
{
public:
	virtual void MyFunc()
	{
		cout<<"SecondFunc"<<endl;
	}
};

class Third: public Second
{
public:
	virtual void MyFunc()
	{
		cout<<"ThirdFunc"<<endl;
	}
};

int main(void)
{
	Third * tptr=new Third();
	Second * sptr=tptr;
	First * fptr=sptr;

	fptr->MyFunc();
	sptr->MyFunc();
	tptr->MyFunc();
	// third, third, third
	delete tptr;
	return 0;
}
