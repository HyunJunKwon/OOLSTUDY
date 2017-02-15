/*
Pure Virtual Function�� Abstract Class


class Employee
{
private:
	char name[100];
public:
	Employee(char * name)
	{
		strcpy(this->name, name);
	}
	void ShowYourName() const
	{
		cout<<"name: "<<name<<endl;
	}
	virtual int GetPay() const
	{
		return 0;
	}
	virtual void ShowSalaryInfo() const
	{  }
};
�� Ŭ������ ���� Ŭ�����μ��� �ǹ̸� ���� ��, ��ü�� ������ ��������
���ǵ� Ŭ������ �ƴϴ�. �̷��� Ŭ���� �߿����� ��ü������
�������� ���ǵ��� �ʴ� Ŭ������ ����...
���� �����Լ��� ���������Լ��� �����ϸ� �Ǽ� ���� �� �ִ�.
	virtual int GetPay() const = 0;
	virtual void ShowSalaryInfo() const = 0;

�ϳ� �̻��� ����Լ��� ���� �����Լ��� ������ Ŭ������ ������
�߻� Ŭ������ �Ѵ�.

���� ���� �Ҹ��ڵ� ����,,
�� �Ʒ� ������ ����Ŭ���� �Ҹ��ڰ� ȣ��Ǹ鼭 ���� Ŭ������
�Ҹ��ڰ� ���������� ȣ��ȴ�.
*/
 
#include <iostream>
using namespace std;

class First
{
private:
	char * strOne;
public:
	First(char * str)
	{
		strOne=new char[strlen(str)+1];
	}
	virtual ~First()
	{
		cout<<"~First()"<<endl;
		delete []strOne;
	}
};
   
class Second: public First
{
private:
	char * strTwo;
public:
	Second(char * str1, char * str2) : First(str1)
	{
		strTwo=new char[strlen(str2)+1];
	}
	virtual ~Second()
	{
		cout<<"~Second()"<<endl;
		delete []strTwo;
	}
};

int main(void)
{
	First * ptr=new Second("simple", "complex");
	delete ptr;
	return 0;
}
