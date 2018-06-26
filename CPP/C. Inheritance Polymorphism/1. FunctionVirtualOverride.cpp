/*
C++에서, BBB형 포인터 변수는 class BBB : public AAA 일때,
BBB 객체 또는 BBB를 직접 혹은 간접적으로 상속하는 (AAA)
모든 객체를 가리킬 수 있다.(객체의 주소 값을 저장할 수 있다)
int main(void)
{
	Base * bptr = new Derived(); // 컴파일 ok
	bptr->DerivedFunc(); // 컴파일 err
}
	-> 
	C++ 컴파일러는 포인터 연산의 가능성 여부를 판단 할 때,
	포인터의 자료형을 기준으로 판단하지, 실제 가리키는 객체의
	자료형을 기준으로 판단하지 않는다.
int main(void)
{
	Derived * dptr = new Derived(); // 컴파일 ok
	Base  * bptr = dptr ; // 컴파일 ok
}
dptr은 Derived 클래스의 포인터 변수니까, 이 포인터가 가리키는 객체는
분명 Base 클래스를 직접 혹은 간접적으로 상속하는 객체이다.
그러니 Base형 포인터 변수로도 참조가 가능!!
base *
↓
derived * ▲할당가능
!!! 결론적으로는 포인터형에 해당하는 클래스에 정의된 멤버에만 접근 가능!!!
가상함수가 선언되면 이 함수를 오버라이딩 하는 함수도 가상함수가 된다.
*/

#include <iostream>
using namespace std;
class First
{
public:
	virtual void MyFunc()
	{
		cout << "FirstFunc" << endl;
	}
};
class Second : public First
{
public:
	virtual void MyFunc()
	{
		cout << "SecondFunc" << endl;
	}
};
class Third : public Second
{
public:
	virtual void MyFunc()
	{
		cout << "ThirdFunc" << endl;
	}
};
int main(void)
{
	// First >= Second >= Third
	Third * tptr = new Third(); // 생성
	Second * sptr = tptr;
	First * fptr = sptr;
	// ThirdFunc를 가진 tptr을 sptr에 할당, (tptr은 sptr을 상속함으로 가능)
	// 또한 이를 fptr에 할당,
	// 밑의 코드를 실행하면, 제일 마지막으로 tptr의 가상함수 MyFunc()가 실행
	fptr->MyFunc();
	sptr->MyFunc();
	tptr->MyFunc();
	/* 
	output:
		ThirdFunc
		ThirdFunc
		ThirdFunc
	*/
	delete tptr;
	return 0;
}
