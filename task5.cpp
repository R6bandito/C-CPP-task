/*设计一个简单的C++程序，模拟一个基本的图形库。定义一个基类 Shape，并从中派生出两个子类 Circle 和 Rectangle。
每个类都应有一个虚函数 draw，用于输出图形的描述。*/

#include <iostream>
#include <windows.h>
using namespace std;

//定义基类
class Shape
{
    public:
    Shape(){
        cout<<"基类构造函数调用"<<endl;
    }
    virtual void draw() const = 0;    //纯虚函数，实现多态性
    virtual ~Shape(){
        cout<<"基类析构函数调用"<<endl;
    }
};

//公有派生类 Circle
class Circle : public Shape
{
    public:
    Circle(){
        cout<<"Circle类构造函数调用"<<endl;
    }
    void draw() const override{
        cout<<"Drawing a circle."<<endl;
    }
    ~Circle(){
        cout<<"Circle类析构函数调用"<<endl;
    }
};

//公有派生类 Rectangle
class REctangle : public Shape
{
    public:
    REctangle(){
        cout<<"Rectangle类构造函数调用"<<endl;
    }
    void draw() const override{
        cout<<"Drawing a rectangle."<<endl;
    }
    ~REctangle(){
        cout<<"Rectangle类析构函数调用"<<endl;
    }
};

void Func(Shape* ptr)   //父类指针指向派生类对象
{
    ptr->draw();
}

int main(int argc,const char* argv[])
{
    SetConsoleOutputCP(CP_UTF8);
    Circle c;
    Func(&c);
    REctangle r;
    Func(&r);
    return 0;
}