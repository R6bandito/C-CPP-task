/*
#include <iostream>
#include <thread>
#include "atm.hpp"
#include <functional>

static void unlock_menu(const atm& Atm) {
	std::string password;
	std::cout<<"Please Input Your Password:"<<std::endl;
	while (true) {
		getline(std::cin, password);
		if (Atm.Unlock(password)) break;
		else continue;
	}
}

static void Menu_Atm(atm& Atm) {
	using namespace std;
#if defined(_WIN32) || defined(_WIN64)
	system("cls");
#else
	system("clear");
#endif

	cout << R"delimiter(					Welcome to Simple Bank System

			1.Deposit	2.Withdraw	3.Display	4.Change Password
									 
											version 1.0
)delimiter";

}

void Input_Handle(atm& atm_) {
	int num = 0;
	std::cout << "\n\nPlease Input the Function Number:";
	if (!(cin >> num)) {
		std::cout << "Wrong Input!Try Again" << std::endl;
		cin.clear();
		cin.ignore(1024, '\n');
	}

	switch (num) {
	case 1:atm_.Deposit(); break;
	case 2:atm_.Withdraw(); break;
	case 3:atm_.Display(); break;
	case 4:atm_.ChangePassword(); break;
	default:std::cout << "Wrong Input!Try Again" << std::endl;
	}
}
int main(int argc, const char* argv[]) {
	size_t switch_num = 0;
	atm atm_;

	std::thread t1(unlock_menu, std::ref(atm_));
	if (t1.joinable()) t1.join();

	std::thread t2(Menu_Atm, std::ref(atm_));
	if(t2.joinable()) t2.join();

	Input_Handle(atm_);

	//getchar();
	return 0;
}
*/