/*
상속관계에서의 안전한 형 변환
상속관계에 놓여 있는 두 클래스 사이에서 유도 클래스의 포인터 및
참조형 데이터를 기초 클래스의 포인터 및 참조형 데이터로 형 변환하는
경우
*/

#include <iostream>
using namespace std;

class Car
{
private:
	int fuelGauge;
public:
	Car(int fuel) : fuelGauge(fuel)
	{  }
	void ShowCarState()
	{
		cout << "잔여 연료량: " << fuelGauge << endl;
	}
};

class Truck : public Car
{
private:
	int freightWeight;

public:
	Truck(int fuel, int weight)
		: Car(fuel), freightWeight(weight)
	{  }
	void ShowTruckState()
	{
		ShowCarState();
		cout << "화물의 무게: " << freightWeight << endl;
	}
};

int main(void)
{
	Car * pcar1 = new Truck(80, 200);
	Truck * ptruck1 = dynamic_cast<Truck*>(pcar1);     // 컴파일 에러

	Car * pcar2 = new Car(120);
	Truck * ptruck2 = dynamic_cast<Truck*>(pcar2);     // 컴파일 에러

	Truck * ptruck3 = new Truck(70, 150);
	Car * pcar3 = dynamic_cast<Car*>(ptruck3);     // 컴파일 OK!

	return 0;
	/*
	앞선 포인터 관계보면 편할듯
	*/
}
