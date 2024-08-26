#ifndef _PERSON
#define _PERSON

#include <iostream>
#include <string>
#include <deque>

//定义一个人物类
class Person
{
    friend void Print(Person &per);    //声明打印函数
    private:
    std::string Name;   //选手姓名
    int ID; //选手号码
    std::deque<int> Marks;  //选手10次得分 
    int Goal;   //选手最终得分

    public:
    Person();   //声明构造函数
    ~Person();    //声明析构函数

    void addPerson();   //声明添加选手信息函数
    void Get_The_Mark();    //声明打分函数
    void caculate_Average();    //声明计算平均分函数
};
void show_Info(std::vector<Person> &v);   //声明显示选手信息函数

#endif