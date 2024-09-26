#ifndef ATM_MY
#define ATM_MY

#include <iostream>
#include <string>

using namespace std;

class atm_basic {	// base class
protected:
	double balance;
	string name;
	string password;

public:
	atm_basic() : balance(0), name("Default_Customer"), password("000000") { }
	virtual ~atm_basic() { }	// virtual destructor
};

class atm : public atm_basic {	// derived class
public:
	atm() : atm_basic() { }

	bool Unlock(const string&) const;

	void ChangePassword();

	void Deposit();

	void Withdraw();

	void Display() const;

	~atm() { }
};

void atm::Display() const {	//��ʾ���
	cout << endl << "Name:" << this->name << endl;
	cout << "Account Balance:" << this->balance << endl;
}

void atm::Withdraw() {	//ȡǮ
	double withdraw_money;
	cout << "Please Input The Money You Want to Withdraw:" << endl;
	while (true) {
		if (!(cin >> withdraw_money)) {
			cout << "Wrong Input!Please Try Again!" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		break;
	}
	this->balance -= withdraw_money;
	cout << "Successfully Withdrawn!" << endl;
}

void atm::Deposit() {	//��Ǯ
	float desposit_money;
	cout << "Please Input The Money You Want to Depoist:" << endl;
	while (true) {
		if (!(cin >> desposit_money)) {
			cout << "Wrong Inout!Please Try Again!" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		break;
	}
	this->balance += desposit_money;
	cout << "Successfully Deposited!" << endl;
}



void atm::ChangePassword() {	//�޸�����
	string NewPassword;
	cout<<"Please Input The New Password:"<<endl;
	cin >> NewPassword;

	if (this->password != NewPassword) {
		this->password = NewPassword;
		cout << "Successfully Changed!" << endl;
	}
	else {
		cout << "The Password Cant Be The Same!" << endl;
		return;
	}
}

bool atm::Unlock(const string& _password) const {	//��֤�����Ƿ���ȷ
	static int count = 3;
	if (this->password == _password) {
		cout << "Successfully Unlocked!" << endl;
		if (count != 3) count = 3;	//����count�Ĵ���
		return true;
	}
	else {
		if (count == 0) {
			cout << "You have entered the wrong password too many times.The Account has been locked." << endl;
			exit(EXIT_FAILURE);
		}
		cout << "Wrong Password,Please try again! Within" << count-- << " times" << endl;
		return false;
	}
}

#endif // !ATM_MY
