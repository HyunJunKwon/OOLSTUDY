#include <iostream>
#include <cstring>
using namespace std;

class Person
{
	char * name;
	int age;
public:
	Person(char * myname, int myage)
	{
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy(name, myname);
		age = myage;
	}
	/*
	Person& Person::operator=(const Person& ref) // 이렇게 깊은 복사를 해야한다!!!!
	{
		delete []name;
		int len=strlen(ref.name)+1;
		name= new char[len];
		strcpy(name, ref.name);
		age=ref.age;
		return *this;
	}
	*/

	void ShowPersonInfo() const
	{
		cout << "NAME: " << name << endl;
		cout << "AGE: " << age << endl;
	}

	~Person()
	{
		delete[]name;
		cout << "called destructor!" << endl;
	}
	// 이 문제에서는 두 개의 객채가 같은 메모리영역을 참고하고있기 때문에
	// 이미 man1에서 소멸자가 실행된 뒤 man2에서 실행해, 프로그램 오류가 난다.
	// 이를 위해 깊은 복사가 필요한 것!
};

int main(void)
{
	Person man1("Lee dong woo", 29);
	Person man2("Yoon ji yul", 22);
	man2 = man1;
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
	// 위 문장이 끝난 후 각 class는 destructor를 실행하는데, man1과 man2가 가리키는 곳이
	// 같은데 man1을 지우고 난 후, man2는 가리키는 곳이 없다 -> 오류발생
	return 0;
}
