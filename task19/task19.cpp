#include <iostream>
#include <string>
#include <vector>

//函数声明
void userInput(std::string &);

int main(int argc,const char* argv[])
{
    std::string processer;
    userInput(processer);
}

void userInput(std::string &pr)
{
    using namespace std;
    cout<<"请输入一个字符串: ";

    if(getline(cin,pr)){
        cout<<"成功读取该字符串!"<<endl;
        return;
    }
    else{
        cout<<"输入出错啦！未读取到该字符串"<<endl;
        exit(EXIT_FAILURE);
    }
}