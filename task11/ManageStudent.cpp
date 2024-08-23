#include <iostream>
#include <string>
#include <vector>
#include "ManageStudent.h"
#include "Student.h"
#include <windows.h>
using namespace std;

// 定义构造函数
ManageStudent::ManageStudent() {}

// 定义添加学生成绩函数
void ManageStudent::addGrades()
{
    string mark;
    while (1)
    {
        clearScreen(); // 清屏
        cout << "请输入学生成绩(按E退出):";
        cin >> mark;

        if (mark == "E" || mark == "e")
        {
            return; // 若用户输入E，则退出函数
        }

        // 将输入的成绩加入动态数组中
        this->grades.push_back(mark);
        cout << "添加成功" << endl;
        Sleep(1000);
    }
}

// 添加学生
void addStudent(vector<ManageStudent> &v)
{
    string ch;
    while (1)
    {
        clearScreen();
        ManageStudent obj;
        // 设置学生信息
        obj.setStudentInfo();
        // 将学生信息放入容器中
        v.push_back(obj);
        cout<<"添加成功"<<endl;
        cout<<"按E退出或其余键继续"<<endl;
        getline(cin,ch);
        if(ch == "E" || ch == "e")
        {
            return;
        }
    }
}