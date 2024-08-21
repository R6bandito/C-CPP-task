/*编写一个程序，使用 std::vector<int> 容器实现以下功能：

添加若干整数到容器中。
查找容器中是否存在某个指定的整数。
输出容器中所有元素的和。*/

#include <iostream>
#include <vector>
#include <windows.h>
#include <algorithm>
#include <numeric>
using namespace std;


void Print_A(int value);

// 定义向动态数组中增添元素函数
void addElement(vector<int> &v)
{
    int temp;
    cout << "请输入要添加的数据" << endl;
    cin >> temp;
    v.push_back(temp);
    cout << "成功添加" << endl;
}

//定义在数组中查询函数
void findInVector(vector<int> &v)
{
    int temp;
    cout<<"请输入要查询的数据"<<endl;
    cin>>temp;
    int count = 0;

    //定义迭代器
    vector<int>::iterator it = v.begin();
    for(it;it != v.end();it++)
    {
        if(*it == temp) //找到该信息，返回其位置，结束函数
        {
            cout<<"找到该数据"<<"   位于第"<<count<<"个位置(下标从0开始)    "<<"是第"<<++count<<"个数据"<<endl;
            return;
        }
        count++;
    }
    cout<<"在容器中未找到该数据"<<endl;
}

//定义打印数组函数
void PrintVec(const vector<int> &v)
{
    for_each(v.begin(),v.end(),Print_A);
    cout<<endl;
}

//定义数组元素加总函数
void sumVec(const vector<int> &v)
{
    // int sum = 0;
    // vector<int>::iterator it = v.begin();
    // for(it;it != v.end();it++)
    // {
    //     sum += *it;
    // }
    // cout<<"数组元素加总结果为:"<<sum<<endl;

    //第二种 标准库函数求加总方法.需包含头文件numeric
    int sum;
    sum = accumulate(v.begin(),v.end(),0);
    cout<<"数组元素加总结果为:"<<sum<<endl;
}

int main(int argc, const char *argv[])
{
    SetConsoleOutputCP(CP_UTF8);
    // 定义一个存储整型数据的容器
    vector<int> v;
    while (1)
    {
        system("cls");
        addElement(v);
        findInVector(v);

        cout<<"数组如下: ";
        PrintVec(v);
        system("pause");
        sumVec(v);
        system("pause");
    }
}


void Print_A(int value)
{
    cout<<value<<"  ";
}
