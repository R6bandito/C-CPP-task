#ifndef MANAGE_
#define MANAGE_

#include "Student.h"



class ManageStudent : public Student
{
    public:
    ManageStudent();    //声明构造函数
    void addGrades();   //声明添加学生成绩函数
};

void addStudent(vector<ManageStudent> &v);  //声明添加学生函数
#endif