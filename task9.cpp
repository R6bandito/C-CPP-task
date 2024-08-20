/*编写一个函数，接收一个 std::string 类型的字符串和两个字符 oldChar 和 newChar，
将字符串中所有的 oldChar 替换为 newChar，并返回修改后的字符串。*/

/*要求：
定义一个函数 std::string replaceChar(std::string str, char oldChar, char newChar)。
函数应遍历字符串并执行替换操作。
在主函数中调用该函数，输入一个字符串及要替换的字符，输出替换后的结果。*/

#include <iostream>
#include <string>
using namespace std;

//字符串中字符的查找与替换
void replaceChar(string &str,const char oldChar,const char newChar)
{

    int pos;
    if((pos = str.find(oldChar)) == -1)
    {
        cout<<"未找到该字符"<<endl;
        return;
    }
    str[pos] = newChar;
    cout<<"替换成功"<<endl;
    cout<<"新字符串为:"<<str<<endl;
    int i;
}

//字符输入函数
void inputCharData(char* oldChar,char* newChar)
{
    cout<<"请输入要查找的字符"<<endl;
    cin>>(*oldChar);
    cout<<"请输入要将其替换为:";
    cin>>(*newChar);
}

//字符串输入函数
void inputStrData(string &str)
{
    cout<<"请输入字符串:";
    getline(cin,str);
    cout<<"你输入的字符串为:"<<str<<endl;
}   

int main(int argc,const char* argv[])
{
    string str;
    char oldChar;
    char newChar;

    inputStrData(str);
    inputCharData(&oldChar,&newChar);
    replaceChar(str,oldChar,newChar);
}