/*
Pure Virtual Function과 Abstract Class


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
이 클래스는 기초 클래스로서만 의미를 가질 뿐, 객체의 생성을 목적으로
정의된 클래스는 아니다. 이렇듯 클래스 중에서는 객체생성을
목적으로 정의되지 않는 클래스도 존재...
위의 가상함수를 순수가상함수로 정의하면 실수 막을 수 있다.
	virtual int GetPay() const = 0;
	virtual void ShowSalaryInfo() const = 0;

하나 이상의 멤버함수를 순수 가상함수로 선언한 클래스를 가리켜
추상 클래스라 한다.

또한 가상 소멸자도 존재,,
맨 아래 계층의 유도클래스 소멸자가 호출되면서 기초 클래스의
소멸자가 순차적으로 호출된다.
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
