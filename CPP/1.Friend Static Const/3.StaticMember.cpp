/*
static ����.
���������� ����� static�� �ǹ�
-> ����� ���� �������� ������ ����ϰڴٴ� �ǹ�
�Լ� ���� ����� static�� �ǹ�
-> �ѹ��� �ʱ�ȭ�ǰ�, ���������� �޸� �Լ��� ���������� �Ҹ���� �ʴ´�.
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
		cout<<simObjCnt<<"��° SoSimple ��ü"<<endl;
	}
};
int SoSimple::simObjCnt=0; // �޸� ������ �Ҵ��ϱ� ������ ������ ����!!!!  

class SoComplex
{
private:
	static int cmxObjCnt;
public:
	SoComplex()
	{
		// simObjCnt = 0;  <- Ʋ������!!!! �̹� �Ҵ��̷������ ����,. 
		cmxObjCnt++;
		cout<<cmxObjCnt<<"��° SoComplex ��ü"<<endl;
	}
	SoComplex(SoComplex &copy)
	{
		cmxObjCnt++;
		cout<<cmxObjCnt<<"��° SoComplex ��ü"<<endl;
	}
};
int SoComplex::cmxObjCnt=0;

int main(void)
{
	SoSimple sim1;
	SoSimple sim2;

	SoComplex cmx1;
	SoComplex cmx2=cmx1;
	SoComplex();
	return 0;
}
