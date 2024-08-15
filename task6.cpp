/*设计一个C++类模板 Pair，用于存储两个不同类型的值。该类模板应支持基本的操作，如设置和获取这两个值。*/

#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

template<class T1 = int,class T2 = int> //有默认参数的模板参数列表
class Pair
{
    private:
    T1 obj1;
    T2 obj2;

    public:
    Pair(T1 tmp1=0,T2 tmp2=0):obj1(tmp1),obj2(tmp2){    //通过参数传递来设置两成员变量的值
        cout<<"Pair类构造函数调用"<<endl;
    }
    void getvalue() //获取两成员的值
    {
        cout<<"obj1 = "<<this->obj1<<"  obj2 = "<<this->obj2<<endl;
    }
};

template <class K1,class K2> //模板类对象的参数传递
void Func(Pair<K1,K2> &pm)
{
    pm.getvalue();
}

int main(int argc,const char* argv[])
{
    SetConsoleOutputCP(CP_UTF8);
    Pair<string,string> p("Hello","World!");
    Func(p);
    cout<<endl<<endl;
    Pair<double,int> p1(0.584,5);
    Func(p1);
    cout<<endl<<endl;
    //使用默认参数
    Pair<> p2;
    Func(p2);
    return 0;
}