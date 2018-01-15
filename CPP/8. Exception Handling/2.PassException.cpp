#include <iostream>
using namespace std;

void Divide(int num1, int num2)
{
	if (num2 == 0)
		throw num2;

	cout << "³ª´°¼ÀÀÇ ¸ò: " << num1 / num2 << endl;
	cout << "³ª´°¼ÀÀÇ ³ª¸ÓÁö: " << num1%num2 << endl;
}

int main(void)
{
	int num1, num2;
	cout << "µÎ °³ÀÇ ¼ýÀÚ ÀÔ·Â: ";
	cin >> num1 >> num2;

	try
	{
		Divide(num1, num2);
		cout << "³ª´°¼ÀÀ» ¸¶ÃÆ½À´Ï´Ù." << endl;
	}
	catch (int expn)
	{
		cout << "Á¦¼ö´Â " << expn << "ÀÌ µÉ ¼ö ¾ø½À´Ï´Ù." << endl;
		cout << "ÇÁ·Î±×·¥À» ´Ù½Ã ½ÇÇàÇÏ¼¼¿ä." << endl;
	}

	return 0;
	/*
	µÎ °³ÀÇ ¼ýÀÚ ÀÔ·Â: ³ª´°¼ÀÀÇ ¸ò: 1
	³ª´°¼ÀÀÇ ³ª¸ÓÁö: 1
	³ª´°¼ÀÀ» ¸¶ÃÆ½À´Ï´Ù.
	*/
}
