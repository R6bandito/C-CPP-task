#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void showVector(std::string& s)
{
    std::cout<<s<<std::endl;
}

class StringProcessor
{
    private:
    //用户输入的待处理字符串
    std::string processor;
    //存储字符串中单词的容器
    std::vector<std::string> v;

    void show_words();

    public:
    void userInput();   //用户输入

    void countWords();  //统计单词

};

int main(int argc, const char *argv[])
{
    StringProcessor sp;

    sp.userInput();

    sp.countWords();

    return 0;
}

void StringProcessor::userInput() 
{
    using namespace std;
    cout << "请输入一个字符串: ";

    if (getline(cin, this->processor))
    {
        cout << "成功读取该字符串!" << endl;
        return;
    }
    else
    {
        cout << "输入出错啦！未读取到该字符串" << endl;
        exit(EXIT_FAILURE);
    }
}

void StringProcessor::countWords()
{
    size_t location_Head = 0;
    size_t location_Tail = 0;
    size_t subRange = 0;

    // 从字符串中根据空格截取单词
    while (this->processor.find(" ",location_Head) != std::string::npos)
    {
        // 从location_Head下一处开始查找空格
        location_Tail = this->processor.find(' ', location_Head);
        // 如果头和尾均为空格（即出现两个连续或以上空格）则不读取
        if (this->processor[location_Tail] == ' ' && this->processor[location_Head] == ' ')
        {
            location_Head = location_Tail + 1;
            continue;
        }
        subRange = location_Tail - location_Head;
        // 将符合条件的部分截取作为单词放入容器中
        v.push_back(this->processor.substr(location_Head, subRange));
        location_Head = location_Tail + 1;  //更新location_Head到下一个字符
    }
    //将最后一个单词放入容器。因为上面的算法仅针对非最后一个单词
    v.push_back(this->processor.substr(location_Head,std::string::npos - location_Head));

    show_words();
}

void StringProcessor::show_words()
{
    std::cout<<"该字符串中，单词如下:"<<std::endl;
    std::for_each(v.begin(),v.end(),showVector);
}