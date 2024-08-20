/*编写一个函数，接收一个 std::string 类型的参数，并返回该字符串的反转版本。例如，输入 "hello"，函数应返回 "olleh"。*/
/*要求：
定义一个函数 std::string reverseString(const std::string &str)。
函数应使用 std::string 容器的基本操作，如 size() 和 operator[]。
不得使用 std::reverse 等标准库算法函数。
在主函数中调用该函数，输入一个字符串，并输出反转后的结果。*/

#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

//字符串反转函数
void reverseString(string &str)
{
    string str1 = str;
    int k = 0;
    for(int i=str.size()-1;i>=0;i--)
    {
        str[k] = str1[i];
        k++;
    }
}

//字符串显示函数
void Display(string &str)
{
    cout<<"输入字符串的逆序输出为:"<<str<<endl;
}

int main(int argc,const char* argv[])
{
    SetConsoleOutputCP(CP_UTF8);
    string str;
    cout<<"请输入字符串"<<endl;
    getline(cin,str);

    cout<<"用户输入字符串为:"<<str<<"   大小为:"<<str.size()<<endl;
    reverseString(str);
    Display(str);
    return 0;
}