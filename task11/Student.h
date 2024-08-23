#ifndef _STUDENT
#define _STUDENT

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void clearScreen(); //声明一个全局清屏函数
void disableCursor();   //声明禁止显示光标函数
void enableCursor();    //声明启用光标显示函数

//定义一个学生基类
class Student
{
    protected:
    string Name;
    int ID;
    vector<string> grades;
    
    
    public:
    Student();  //声明构造函数
    void setStudentInfo();  //声明添加学生信息函数
};

#endif  //STUDENT