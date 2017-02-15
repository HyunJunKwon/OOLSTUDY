/*
객체가 생성되면 멤버변수는 객체 내에 존재하지만, 멤버함수는 
메모리의 한 공간에 별도로 위치하고선, 이 함수가 정의된 클래스의
모든 객체가 이를 공유하는 형태를 취한다.
->가상함수의 원리, 가상함수 테이블.

아래의 예에선 
AAA와 BBB의 테이블이 각각 있다
AAA에는 AAA::Func1(), Func2()
BBB에는 BBB::F1, AAA::F2, BBB::F3
*/
 
#include <iostream>
using namespace std;

class AAA
{
private:
	int num1;
public:
	virtual void Func1() { cout<<"Func1"<<endl; }
	virtual void Func2() { cout<<"Func2"<<endl; }	
};

class BBB: public AAA
{
private:
	int num2;
public:
	virtual void Func1() { cout<<"BBB::Func1"<<endl; }
	void Func3() { cout<<"Func3"<<endl; }
};

int main(void)
{
	AAA * aptr=new AAA();
	aptr->Func1();

	BBB * bptr=new BBB();
	bptr->Func1();
	/*
	Func1
	BBB::Func1
	*/
	return 0;
}
