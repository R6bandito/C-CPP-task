#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include "Student.h"
using namespace std;

// Student类构造函数
Student::Student()
{
    this->Name = "NULL";
    this->ID = 0;
}

// 添加学生信息
void Student::setStudentInfo()
{
    cout << "请输入学生姓名:";
    getline(cin, this->Name);
    cout << endl
         << "请输入学生ID:";
    //记录目前光标的位置
    cout<<"\033[s";
    while (!(cin >> this->ID))
    {
        // 再次使能cin
        cin.clear();
        // 清空输入缓冲区
        cin.ignore(1024,'\n');
        cout << "非数值型输入，请重试";
        Sleep(1000);
        //清除当前行
        cout << "\033[2K";
        //读取保存的光标位置
        cout<<"\033[u";
        //清除从光标位置到行末的内容
        cout<<"\033[K";
    }
    cin.ignore(); // 清除输入缓冲区
}

// 清屏
void clearScreen()
{
    system("cls");
}

// 使用ANSI禁止显示光标
void disableCursor()
{
    cout << "\033[?25l";
}

// 启用光标
void enableCursor()
{
    cout << "\033[?25h";
}
