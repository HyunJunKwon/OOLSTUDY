/*
A 클래스가 B 클래스를 대상으로 friend선언을 하면, 
B 클래스는 A 클래스의 private 멤버에 직접 접근이 가능하다.
단, A 클래스도 B 클래스의 private 멤버에 직접 접근이 가능하려면, 
B클래스가 A클래스를 대상으로 friend 선언을 해주어야한다.


!! "friend 선언은 지나치면 아주위험하다 정보은닉을 무너뜨리는 문법이다"
*/
#include <iostream>
#include <cstring>
using namespace std;

class Girl; // Girl 이라는 이름이 클래스의 이름임을 알림. 

class Boy
{
private:
	int height;
	friend class Girl; // Girl 클래스에 대한 friend 선언  
public:
	Boy(int len) : height(len)
	{ }
	void ShowYourFriendInfo(Girl &frn);
};

class Girl
{
private:
	char phNum[20];
public:
	Girl(char * num)
	{
		strcpy(phNum, num);
	}
	void ShowYourFriendInfo(Boy &frn);
	friend class Boy; // friend선언
};

void Boy::ShowYourFriendInfo(Girl &frn)
{
	cout << "Her phone number: " << frn.phNum << endl;
}

void Girl::ShowYourFriendInfo(Boy &frn)
{
	cout << "His height: " << frn.height << endl;
}

int main(void)
{
	Boy boy(170);
	Girl girl("010-1234-5678");

	boy.ShowYourFriendInfo(girl);
	girl.ShowYourFriendInfo(boy);
	return 0;
}
