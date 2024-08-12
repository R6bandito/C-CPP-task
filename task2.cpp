/*设计一个管理图形的系统。系统中有一个基类 Shape，它有两个派生类 Circle 和 Rectangle。
每个形状都有一个计算面积的函数 getArea()。
使用多态机制实现不同形状的面积计算，并编写一个测试程序演示多态性。*/

#include <iostream>
#include <math.h>
using namespace std;

//基类
class shape     
{
    public:
    shape():S(0.0){
        cout<<"基类构造函数调用"<<endl;
    }
    virtual void getArea() = 0;    //纯虚函数，体现多态性
    virtual ~shape(){
        cout<<"基类析构调用"<<endl;
    }  //虚析构函数
    virtual void disPlay() const = 0;
    virtual void inputData() = 0;

    protected:
    double S;

};

//公有派生类 Circle 
class Circle : public shape     
{
    private:
    int radius;
    const double PI = 3.1415;

    public:
    Circle():radius(0){
        cout<<"Circle构造函数调用"<<endl;
    }    //构造函数参数初始化表
    ~Circle(){
        cout<<"Circle析构调用"<<endl;
    }
    void inputData() override;     //用户输入半径
    void getArea() override;    //计算面积
    void disPlay() const override {
        cout<<"圆的面积为:"<<S<<endl;
    }
};

//共有派生类 Rectangle
class Rectangle : public shape
{
    private:
    int length;
    int width;

    public:
    Rectangle():length(0),width(0){
        cout<<"Rectangle构造函数调用"<<endl;
    }
    ~Rectangle(){
        cout<<"Rectangle析构调用"<<endl;
    }
    void inputData() override;   //用户输入长与宽
    void getArea() override;    //计算面积
    void disPlay() const override{
        cout<<"矩形面积为:"<<S<<endl;
    }
};

void Function(shape* sp)
{
    sp->inputData();
    sp->getArea();
    sp->disPlay();
}

int main(int argc,const char* argv[])
{
    //在堆区开辟对象
    Rectangle* re = new Rectangle;
    Circle* ce = new Circle;
    Function(re);
    Function(ce);
    //手动释放对象
    delete re;  
    delete ce;
    return 0;
}


inline void Circle::inputData()
{
    cout<<"请输入半径（整数）"<<endl;
    cin>>radius;
}

inline void Circle::getArea()
{
    S = PI * pow(radius,2);
}

inline void Rectangle::inputData()
{
    cout<<"请输入长与宽"<<endl;
    cin>>length>>width;
}

inline void Rectangle::getArea()
{
    S = length*width;
}