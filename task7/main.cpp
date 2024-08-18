/*一个通用的自定义数组类练习*/

#include <iostream>
#include "MyArray.hpp"
#include <windows.h>
using namespace std;

int main(int argc,const char* argv[])
{
    SetConsoleOutputCP(CP_UTF8);

    MyArray<> p1(10);
    MyArray<> p2(p1);
    //向p1中插入10个数据用于测试
    for(int i=0;i<10;i++)  
    {
        p1.push_Rear(i);
    }
    Display(p1);
    system("pause");
    //继续向p1插入数据，检查代码中的溢出处理部分是否正常工作
    p1.push_Rear(10);
    system("pause");
    p2 = p1;
    //删掉后三个数据
    for(int i=0;i<3;i++)    
    {
        p2.delete_Rear();
    }
    Display(p2);
    system("pause");

    int result = p2.get_Capacity();
    cout<<"p2的容量为:"<<result<<endl;
    result = p1.get_Amount();
    cout<<"p1的大小为:"<<result<<endl;
    result = p2.get_Amount();
    cout<<"p2的大小为:"<<result<<endl;
    system("pause");

    //检查代码中防止删除溢出的代码是否有效
    for(int i=0;i<8;i++)
    {
        p2.delete_Rear();
    }
    system("pause");
    return 0;
}



