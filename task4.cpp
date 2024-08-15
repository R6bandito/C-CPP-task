/*设计一个C++程序，包含一个函数模板 print，用于输出不同类型的数据。
同时，重载这个函数模板，使其能够处理字符串类型的数据，并在输出时添加引号。*/

#include <iostream>
#include <string>
using namespace std;

//函数模板：实现不同数据类型的参数输入
template<typename T>
void print(T* ptr)
{
    cout<<*ptr<<endl;
}
//重载的print函数，专门处理string类型
void print(string* ptr)
{
    cout<<"\""<<*ptr<<"\""<<endl;
}

int main(int argc,const char* argv[])
{
    int a =10;
    double b = 2.56847;
    string str = "Hello World!";
    print(&a);
    print(&b);
    print(&str);
    system("pause");
    return 0;
}   