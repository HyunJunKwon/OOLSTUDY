#include <iostream>
using namespace std;

class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) : num(n)
	{ }
	//SoSimple& AddNum(int n)
	//{
	//	num += n;
	//	return *this;
	//}
	void SimpleFunc()
	{
		cout << "SimpleFunc: " << num << endl;
	}
	void SimpleFunc() const // 26 라인 실행될 때, 20 라인 실행된다... 
	{
		cout << "const SimpleFunc: " << num << endl;
	}
};

void YourFunc(const SoSimple &obj)
{
	obj.SimpleFunc();
}

int main(void)
{
	SoSimple obj1(2);
	const SoSimple obj2(7);
	obj1.SimpleFunc();
	obj2.SimpleFunc();
	/* 위 두 문장이 실행될 때에는 class안에 const로 정의되있는지에 따라
	실행되지만, 밑의 두 문장은 YourFunc(const class)이므로 무조건 const로
	정의된 함수가 실행.
	*/
	YourFunc(obj1);
	YourFunc(obj2);
	return 0;
}