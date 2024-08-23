#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include "Student.h"
#include "Menu.h"
#include <conio.h>
using namespace std;

// 构造函数
Menu::Menu()
{
    this->length = 40;
    this->width = 20;
    this->count = 0;
}

// 绘制边框
void Menu::lace_of_Menu()
{
    while (1)
    {
        for (int i = 0; i < length; i++)
        {
            cout << "*";
        }
        cout << endl;
        count++;
        if (count == 2)
        {
            for (int k = 0; k < 6; k++) // 6行
            {
                cout << "**";
                for (int j = 2; j < length - 2; j++)
                {
                    cout << " ";
                }
                cout << "**";
                cout << endl;
                count++;
            }
            while (count != 10)
            {
                for (int i = 0; i < length; i++)
                {
                    cout << "*";
                }
                count++;
                cout << endl;
            }
            //重置count
            this->count = 0;
            return;
        }
    }
}

// 菜单内容
int Menu::content_of_Menu()
{
    // 保存当前光标位置，用于之后的复原操作
    cout << "\033[s";

    char input[2];
    char ch;
    int count = 0;

    // 光标移动到3行8列
    cout << "\033[3;8H";
    cout << "1.添加学生";

    // 将光标移动到4行8列的位置
    cout << "\033[4;8H";
    cout << "2.添加学生成绩";

    // 光标移动到5行8列的位置
    cout << "\033[5;8H";
    cout << "3.计算所有学生平均成绩";

    // 光标移动到6行8列位置
    cout << "\033[6;8H";
    cout << "4.计算所有学生平均成绩";

    // 光标移动到7行30列的位置
    cout << "\033[7;30H";
    cout << "[   ]";
    cout << "\033[3D";

label1:
    // 在指定位置进行输入
    while (1)
    {
        ch = _getch(); // 使用_getch()读取字符输入
        if (ch >= '0' && ch <= '9' && count < 1)
        {
            cout << ch;
            input[count++] = ch;
        }
        // 处理输入的退格键
        else if (ch == '\b' && count > 0)
        {
            cout << "\b \b";
            input[--count] = 0;
        }
        // 只允许输入一个字符，而后禁止光标显示
        if (count == 1)
        {
            disableCursor();
        }
        // 处理输入的回车符(即按下回车)
        if (ch == '\r')
        {
            break;
        }
    }
    // 启动光标
    enableCursor();
    // 复原光标位置
    cout << "\033[u";

    if (input[0] < '1' || input[0] > '4')
    {
        cout << "输入错误，请重试" ;
        Sleep(1000);
        //清除光标所在行
        cout<<"\033[2K";
        //移动光标到7行32列
        cout<<"\033[7;33H";
        //输出一个退格符
        cout<<"\b \b";
        //重置count
        count = 0;
        goto label1;
    }
    //返回光标输入的数据
    count = 0;
    return input[0];
}
