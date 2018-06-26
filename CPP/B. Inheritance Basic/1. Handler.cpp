/*
컨트롤 클래스의 특징
	-프로그램 전체의 기능을 담당한다. 따라서 기능적 성격이 강한 클래스이다.
	-컨트롤 클래스만 봐도 프로그램의 전체 기능과 흐름을 파악할 수 있다.

Entity 클래스의 특징
	-데이터적 성격이 강하다. 따라서 파일 및 데이터 베이스에 저장되는 데이터를 소유하고 있다.
	-프로그램의 기능을 파악하는데 도움을 주지는 못한다.
	-그러나 프로그램상에서 관리되는 데이터의 종류를 파악하는 데는 도움이 된다.
		--> 기능적 성격이 강한 컨트롤 클래스를 등장시키면, 우리가 구현하고 있는 단계별 프로젝트에서 전역함수들을 없앨 수 있다. 이들을 하나의 컨트롤 클래스로 묶을 수 있기 때문.
*/

#include <iostream>
#include <cstring>
using namespace std;
const int NAME_LEN = 20;

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

/*
* 클래스 이름: Account
* 클래스 유형: Entity 클래스
*/
class Account
{
private:
	int accID;
	int balance;
	char * cusName;
public:
	Account(int ID, int money, char * name);
	Account(const Account & ref);

	int GetAccID() const;
	void Deposit(int money);
	int Withdraw(int money);
	void ShowAccInfo() const;
	~Account();
};
Account::Account(int ID, int money, char * name) : accID(ID), balance(money)
{
	cusName = new char[strlen(name) + 1];
	strcpy(cusName, name);
}
Account::Account(const Account & ref) : accID(ref.accID), balance(ref.balance)
{
	cusName = new char[strlen(ref.cusName) + 1];
	strcpy(cusName, ref.cusName);
}
int Account::GetAccID() const 
{ 
	return accID; 
}
void Account::Deposit(int money)
{
	balance += money;
}
int Account::Withdraw(int money)
{
	if (balance < money)
		return 0;
	balance -= money;
	return money;
}
void Account::ShowAccInfo() const
{
	cout << "Account ID: " << accID << endl;
	cout << "Name      : " << cusName << endl;
	cout << "Balance   : " << balance << endl;
}
Account::~Account()
{
	delete[]cusName;
}

/*
* 클래스 이름: AccountHandler
* 클래스 유형: 컨트롤(Control) 클래스
*/
class AccountHandler
{
private:
	Account * accArr[100];
	int accNum;
public:
	AccountHandler();
	void ShowMenu(void) const;
	void MakeAccount(void);
	void DepositMoney(void);
	void WithdrawMoney(void);
	void ShowAllAccInfo(void) const;
	~AccountHandler();
};
void AccountHandler::ShowMenu(void) const
{
	cout << "-----Menu------" << endl;
	cout << "1. Create Account" << endl;
	cout << "2. Deposit" << endl;
	cout << "3. Withdraw" << endl;
	cout << "4. Print Out All Account Information" << endl;
	cout << "5. Exit Program" << endl;
}
void AccountHandler::MakeAccount(void)
{
	int id;
	char name[NAME_LEN];
	int balance;

	cout << "[Create Account]" << endl;
	cout << "Account ID: ";	cin >> id;
	cout << "Name: ";	cin >> name;
	cout << "Initial Deposit Amout: "; cin >> balance;
	cout << endl;

	accArr[accNum++] = new Account(id, balance, name);
}
void AccountHandler::DepositMoney(void)
{
	int money;
	int id;
	cout << "[Deposit]" << endl;
	cout << "Account ID: ";	cin >> id;
	cout << "Deposit Amount: ";	cin >> money;

	for (int i = 0; i<accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			accArr[i]->Deposit(money);
			cout << "Deposit Completed" << endl << endl;
			return;
		}
	}
	cout << "Invalid ID." << endl << endl;
}
void AccountHandler::WithdrawMoney(void)
{
	int money;
	int id;
	cout << "[Withdraw]" << endl;
	cout << "Account ID: ";	cin >> id;
	cout << "Withdraw Amount: "; cin >> money;

	for (int i = 0; i<accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			if (accArr[i]->Withdraw(money) == 0)
			{
				cout << "Not Enough Balance" << endl << endl;
				return;
			}

			cout << "Deposit Completed" << endl << endl;
			return;
		}
	}
	cout << "Invalid ID" << endl << endl;
}
AccountHandler::AccountHandler() : accNum(0)
{  }
void AccountHandler::ShowAllAccInfo(void) const
{
	for (int i = 0; i<accNum; i++)
	{
		accArr[i]->ShowAccInfo();
		cout << endl;
	}
}
AccountHandler::~AccountHandler()
{
	for (int i = 0; i<accNum; i++)
		delete accArr[i];
}

/*
* 컨트롤 클래스 AccountHandler 중심으로 변경된 main 함수
*/

int main(void)
{
	AccountHandler manager;
	int choice;

	while (1)
	{
		manager.ShowMenu();
		cout << "choice: ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case MAKE:
			manager.MakeAccount();
			break;
		case DEPOSIT:
			manager.DepositMoney();
			break;
		case WITHDRAW:
			manager.WithdrawMoney();
			break;
		case INQUIRE:
			manager.ShowAllAccInfo();
			break;
		case EXIT:
			return 0;
		default:
			cout << "Illegal selection.." << endl;
		}
	}
	return 0;
}
