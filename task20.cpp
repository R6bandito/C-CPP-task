#include <iostream>
#include <string>
#include <memory>

class Date
{
private:
    int year;
    int month;
    int day;

public:
    Date() {};
    Date(int y, int m, int d) : year(y), month(m), day(d) {}
};

class Customer
{
private:
    std::string Name;
    Date visitTime;

public:
    Customer() {};
    Customer(std::string _name, Date d) : Name(_name), visitTime(d) {}
    Customer(const Customer &rhs) : Name(rhs.Name), visitTime(rhs.visitTime) {}
    Customer &operator=(const Customer &rhs)
    {
        // 先进行自我赋值检查，防止相同对象赋值出现问题
        if (this != &rhs)
        {
            this->Name = rhs.Name;
            this->visitTime = rhs.visitTime;
        }
        return *this;
    }
};

class VIPCustomer : public Customer
{
private:
    size_t vipGrade;

public:
    // 默认构造
    VIPCustomer() {};
    // 构造函数
    VIPCustomer(const Customer cus, size_t grade = 0) : Customer::Customer(cus), vipGrade(grade) {}
    // 拷贝构造
    VIPCustomer(const VIPCustomer &rhs) : Customer(rhs), vipGrade(rhs.vipGrade) {}
    // copy assignment 函数
    VIPCustomer &operator=(const VIPCustomer &rhs)
    {
        if (this != &rhs)
        {
            // 对父类对象中的成员进行拷贝
            Customer::operator=(rhs);
            // 将此类对象中的local变量进行拷贝
            this->vipGrade = rhs.vipGrade;
        }
        return *this;
    }
};

// 供应VIPCustomer对象
std::unique_ptr<Customer> createVIPCustomer()
{
    return std::make_unique<VIPCustomer>();
}

void test()
{
    try
    {
        // 运用RAII对象管理资源
        std::unique_ptr<Customer> pInv1(createVIPCustomer());
        auto pInv2 = std::move(pInv1);
    }
    catch (std::bad_alloc &e)
    {
        std::cout << "Caught bad_alloc: " << e.what() << std::endl;
    }
    catch(...)
    {
        std::cout<<"Something Unknown Wrong Happened."<<std::endl;
    }
}

int main(int argc, const char *argv[])
{
    try
    {
        VIPCustomer v1(Customer("Wang", Date(2021, 4, 13)), 1);
        VIPCustomer v2(Customer("Liu", Date(2022, 9, 24)), 2);
        VIPCustomer v3(Customer("Feng", Date(2022, 6, 25)), 2);
        VIPCustomer v4(v3);
    }
    catch (std::runtime_error &e)
    {
        std::cout << "Caught runtime_error:" << e.what() << std::endl;
    }

    return 0;
}