/*c++案例  评委打分
有5名选手，10个评委分别对其进行随机打分，去除最高分和最低分后，取均值作为最终成绩*/


#include <iostream>
#include <vector>
#include <windows.h>
#include "Person.h"


int main(int argc,const char* argv[])
{
    SetConsoleOutputCP(CP_UTF8);
    //定义一个person类的容器
    std::vector<Person> v;
    for(int i=0 ;i<5;i++)
    {
        Person* pr = new Person;
        pr->addPerson();
        pr->Get_The_Mark();
        pr->caculate_Average();
        v.push_back(*pr);
        delete pr;
        pr = NULL;
    }

    show_Info(v);
    system("pause");
    return 0;
}