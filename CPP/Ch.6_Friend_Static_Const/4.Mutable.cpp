/*
const 함수 내에서의 값의 변경을 예외적으로 허용한다.
mutable의 과도한 사용은 C++에 있어서 
그 중요성을 인정받은 키워드인 const의 선언을 의미 없게 만들어버린다.
*/
#include <iostream>
using namespace std;

class SoSimple
{
private:
	int num1;
	mutable int num2; // const 함수에 대해 예외를 둔다!!!  
public:
	SoSimple(int n1, int n2)
		: num1(n1), num2(n2)
	{  }
	void ShowSimpleData() const
	{
		cout<<num1<<", "<<num2<<endl;
	}
	void CopyToNum2() const
	{
		num2=num1; // 예외 문장!!!  
	}
};

int main(void)
{
	SoSimple sm(1, 2);
	sm.ShowSimpleData();
	sm.CopyToNum2();
	sm.ShowSimpleData();
	return 0;
}
