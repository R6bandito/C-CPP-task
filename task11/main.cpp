#include <iostream>
#include <vector>
#include <windows.h>
#include "ManageStudent.h"
#include "Student.h"
#include "Menu.h"

int main(int argc,const char* argv[])
{
    SetConsoleOutputCP(CP_UTF8);

    //定义一个动态容器存储学生人数
    vector<ManageStudent> v;
    int i;

    Menu mu;
    //显示菜单
    mu.lace_of_Menu();
    i = mu.content_of_Menu();

    return 0;
}
