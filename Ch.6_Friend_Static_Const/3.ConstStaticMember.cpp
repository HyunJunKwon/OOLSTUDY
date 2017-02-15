/*
클래스 내에 선언된 const 멤버변수(상수)의 초기화는 이니셜라이저를 통해야만한다.
그러나 const static으로 선언되는 멤버변수(상수)는 다음과 같이 선언과 동시에 초기화가 가능하다.
const static 멤버변수는, 클래스가 정의될 때 지정된 값이 유지되는 상수이기 때문에, 초기화가 가능!!!!  
*/ 
#include <iostream>
using namespace std;

class CountryArea
{
public:
	const static int RUSSIA			=1707540;
	const static int CANADA			=998467;
	const static int CHINA			=957290;
	const static int SOUTH_KOREA	=9922; 
};

int main(void)
{
	cout<<"러시아 면적: "<<CountryArea::RUSSIA<<"㎢"<<endl;
	cout<<"캐나다 면적: "<<CountryArea::CANADA<<"㎢"<<endl;
	cout<<"중국 면적: "<<CountryArea::CHINA<<"㎢"<<endl;
	cout<<"한국 면적: "<<CountryArea::SOUTH_KOREA<<"㎢"<<endl; // 정의된 상수에 접근하기 위해서 굳이 객체를 생성할 필요는 없다..  
	return 0;
}
