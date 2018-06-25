/*
static 개념.
전역변수에 선언된 static의 의미
-> 선언된 파일 내에서만 참조를 허용하겠다는 의미
함수 내에 선언된 static의 의미
-> 한번만 초기화되고, 지역변수와 달리 함수를 빠져나가도 소멸되지 않는다.
*/
#include <iostream>
using namespace std;

class SoSimple
{
private:
	static int simObjCnt;
public:
	SoSimple()
	{
		simObjCnt++;
		cout << simObjCnt << "th SoSimple object" << endl;
	}
};
int SoSimple::simObjCnt = 0; // 메모리 공간에 할당하기 때문에 별도로 선언!!!!  

class SoComplex
{
private:
	static int cmxObjCnt;
public:
	SoComplex()
	{
		// simObjCnt = 0;  <- 틀린문장!!!! 이미 할당이루어졌기 때문,. 
		cmxObjCnt++;
		cout << cmxObjCnt << "th SoComplex object" << endl;
	}
	SoComplex(SoComplex &copy)
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "th SoComplex object" << endl;
	}
};
int SoComplex::cmxObjCnt = 0;

int main(void)
{
	SoSimple sim1; // 초기화가 되면서 cout 출력
	SoSimple sim2;

	SoComplex cmx1;
	SoComplex cmx2 = cmx1;
	SoComplex();
	return 0;
}
