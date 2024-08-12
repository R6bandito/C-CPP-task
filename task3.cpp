/*封装一个程序，先生成一个文件并向其中写入数据后保存。而后读取该文件中的内容。*/

#include <iostream>
#include <windows.h>
#include <string>
#include <fstream> //文件操作头文件包含
using namespace std;

class File // 定义文件基类
{
public:
    virtual void openFile() = 0;
    virtual void writeFile() = 0; // 写入文件
    virtual void readFile() = 0;  // 读取文件
    virtual ~File() {}            // 虚析构函数

protected:
    ofstream ofs; // 定义文件输出流对象
    ifstream ifs; // 定义文件输入流对象
};

// 公有派生类 Filewriting
class FileWriting : public File
{
public:
    void ManipulateFile()   //公用接口
    {
        openFile();
        writeFile();
    }

private:
    void openFile() override;
    void readFile() override{}
    void writeFile() override; // 声明函数
    void inputdata()
    {
        cout << "请输入要写入文件的数据" << endl;
        getline(cin, Content);
    }
    string Content;
};

// 公有派生类 Filereading
class FileReading : public File
{
public:
    void manipulateFile()
    { // 公用接口
        openFile();
        readFile();
        ifs.close();
    }

private:
    string Content;
    void openFile() override;
    void readFile() override;
    void writeFile() override{}
};

int main(int argc, const char *argv[])
{
    SetConsoleOutputCP(CP_UTF8);

    File *fp = new FileWriting;     //基类指针指向对象
    fp->openFile();
    fp->writeFile();
    File *np = new FileReading;
    np->openFile();
    np->readFile();
    delete fp;
    delete np;
    return 0;
}

void FileWriting::writeFile()
{
    inputdata();                                         // 调用函数输入数据
    ofs << Content; // 写入文件
    ofs.close();                                         // 关闭文件
}

void FileReading::openFile()
{
    ifs.open("Data.txt", ios::in); // 打开文件进行读取操作
    if (!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }
}

void FileWriting::openFile()
{
    ofs.open("Data.txt", ios::out); // 打开文件进行写入操作
    if (!ofs.is_open())
    { // 检验文件是否正常打开
        cout << "文件打开失败" << endl;
        return; // 结束函数
    }
}

void FileReading::readFile()
{
    Content.clear();    //清空Content内容，防止干扰
    while (getline(ifs,Content)) // 读取文件并打印
    {
        cout << Content << endl;
    }
}