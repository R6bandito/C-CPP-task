/*题目描述：
设计一个简单的银行账户管理系统。系统中有一个基类 BankAccount，包含纯虚函数 deposit() 和 withdraw()。
要求你从 BankAccount 类派生出两个具体的账户类 SavingsAccount 和 CheckingAccount，分别实现不同的存取款方式。
SavingsAccount 类可能会有存款利息计算功能，而 CheckingAccount 类可能会有支票手续费的计算功能。*/

#include <iostream>
#include <windows.h>
using namespace std;

//基类
class BankAccount  
{
    public:
    BankAccount():balance(0){}
    virtual void Withdraw() = 0;     //纯虚取款函数,实现多态性
    virtual void Deposit() = 0;   //纯虚存款函数
    virtual ~BankAccount(){}    //虚析构函数

    void dispalyAccount(){
        cout<<"账户余额:"<<balance<<endl;
    }
    protected:
    float balance;  //账户余额
};

//派生类 savingAccount
class savingAccount : public BankAccount    
{
    public:
    savingAccount(float h=0.0,float a=0.0,float b=0.0):interestRate(h),depositamount(a),withdrawamount(b) {} //构造函数参数初始化表
    void Withdraw() override{   //重写取款函数
        if(balance >= withdrawamount){
            balance -= withdrawamount;
        }
        else{
            cout<<"取款失败，余额不足"<<endl;
        }
    }
    void Deposit() override{    //重写存款函数
        balance += depositamount;
        balance += balance*interestRate;    //利息计算
        cout<<"存款成功"<<endl;
    }
    private:
    float interestRate;     //利息
    float depositamount;   //存款数目
    float withdrawamount;   //取款数目
};

//派生类 checkingAccount
class checkingAccount :public BankAccount
{
    public:
    checkingAccount(float fee=2.0,float h=0.0,float b=0.0):transactionFee(fee),depositamount(h),withdrawamount(b){}
    void Withdraw() override{   //取款
        if(balance >= (withdrawamount+transactionFee)){
            balance -= (withdrawamount+transactionFee);
        }
        else{
            cout<<"取款失败，余额不足"<<endl;
        }
    }
    void Deposit() override{    //存款
        balance += (depositamount-transactionFee);
        cout<<"存款成功"<<endl;
    }
    private:
    float depositamount;
    float withdrawamount;
    float transactionFee;   //手续费
};

void Function(BankAccount* ptr)     //父类指针指向派生类对象
{
    ptr->dispalyAccount();
    ptr->Deposit();
    ptr->Withdraw();
    ptr->dispalyAccount();
}

int main(int argc,const char* argv[])
{
    SetConsoleOutputCP(CP_UTF8);

//测试代码
    savingAccount s1(0.53,500,300);     //利息0.53，存款500，取款300
    checkingAccount c1(4,750,400);  //手续费4，存款750，取款400
    Function(&s1);
    cout<<endl<<endl;
    Function(&c1);
    system("pause");
    return 0;
}