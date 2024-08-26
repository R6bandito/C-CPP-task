#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <algorithm>
#include "Person.h"
#include "Error_func.h"
#include "Random_Number.h"

//打印学生信息
void Print(Person &per)
{
    std::cout<<"姓名:"<<per.Name<<std::endl;
    std::cout<<"编号:"<<per.ID<<std::endl;
    std::cout<<"10次得分:";

    for(std::deque<int>::iterator it = per.Marks.begin();it!=per.Marks.end();it++)
    {
        std::cout<<*it<<" ";
    }
    std::cout<<std::endl;
    std::cout<<"最终得分:"<<per.Goal<<std::endl;
    std::cout<<std::endl;
}

// Person类构造函数
Person::Person()
{
    this->Name = "None";
    this->ID = 1;
    this->Goal = 0;

    // 初始化deque容器
    for(int i=0;i<10;i++)
    {
        this->Marks.push_back(0);
    }
}

// 析构函数
Person::~Person() {}

// 添加选手信息
void Person::addPerson()
{
    using namespace std;

    // 将光标置于左上角
    cout << "\033[2J\033[H";
    cout << "请输入选手的姓名:";
    cin >> this->Name;

    cout << "请输入选手编号(1-2位数字):";
    // 记录光标位置
    cout << "\033[s";
    //检测用户输入是否为数值型以及是否是1-2位数字
    while (!(cin >> this->ID) || this->ID < 1 || this->ID > 99)
    {
        Cin_Restore();
        Cin_Error_Print();
    }
    cout<<"添加成功";
    Delay_ms(1000);
    //清除该行
    cout<<"\033[2K";
    cout<<endl;
}

//为选手打分
void Person::Get_The_Mark()
{
    using namespace std;

    cout<<"电脑评委正在打分......";
    //延迟两秒
    Delay_ms(2000);
    cout<<"\033[2K";
    cout<<endl;
    //遍历deque容器打分
    for(deque<int>::iterator it = this->Marks.begin();it!=this->Marks.end();it++)
    {
        *it = randomNum_Create();
    }
    cout<<endl<<"打分完毕!";
    Delay_ms(1000);
    cout<<"\033[2K";
    cout<<endl;
}

//计算选手最终得分
void Person::caculate_Average()
{
    //定义一个deque的拷贝容器,防止后续操作改变原先的数据
    std::deque<int> cpy(this->Marks);
    //为10个分数进行排序
    std::sort(cpy.begin(),cpy.end());
    //去掉最高分与最低分
    cpy.pop_front();
    cpy.pop_back();
    //计算其均分
    int sum = 0;
    for(int i=0;i<8;i++)
    {
        sum += cpy[i];
    }
    this->Goal = sum / 8;
}

//显示选手信息
void show_Info (std::vector<Person> &v)
{
    std::for_each(v.begin(),v.end(),Print);
}