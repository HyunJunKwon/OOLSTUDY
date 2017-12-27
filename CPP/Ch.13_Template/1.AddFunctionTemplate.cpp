/*
아래 예제에서의 정의를 가리켜 함수 템플릿이라한다
반면 위의 템플릿을 기반으로 컴파일러가 만들어 내는 다음 예제의
함수들을 가리켜 템플릿 함수라고 한다.
*/
#include <iostream>
using namespace std;

template <typename T>
T Add(T num1, T num2) 
{
	return num1+num2;
}



/*
int main(void)
{
	cout<< Add<int>(15, 20)			<<endl;
	cout<< Add<double>(2.9, 3.7)	<<endl;
	cout<< Add<int>(3.2, 3.2)		<<endl;
	cout<< Add<double>(3.14, 2.75)	<<endl;
	return 0;
}
*/

int main(void)
{
	cout<< Add(15, 20)		<<endl;
	cout<< Add(2.9, 3.7)	<<endl;
	cout<< Add(3.2, 3.2)	<<endl;
	cout<< Add(3.14, 2.75)	<<endl;
	return 0;
}
