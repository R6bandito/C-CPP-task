#include <iostream>
#include <string>
#include <vector>
#include "Student.h"
using namespace std;

//Student类构造函数
Student::Student(){
    this->Name = "NULL";
    this->ID = 0;
}

//添加学生信息
void Student::setStudentInfo()
{
    cout<<"请输入学生姓名:";
    getline(cin,this->Name);
    cout<<endl<<"请输入学生ID:";
    cin>>this->ID;
}

//清屏
void clearScreen()
{
    cout<<"\033[2J\033[H";  //通过ANSI转义码的方式来清屏
}

//使用ANSI禁止显示光标
void disableCursor()
{
    cout<<"\033[?25l";
}

//启用光标
void enableCursor()
{
    cout<<"\033[?25h";
}