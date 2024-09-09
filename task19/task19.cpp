#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <windows.h>

void showVector(const std::string& s)
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
    //存储字符串中的每个字符及其出现频率
    std::map<char,size_t> mp;

    void show_words() const;

    void splitWords();  //拆分单词并输出

    void countChar();   //计算字符出现频率

    void countWords();  //统计单词出现频率

    public:
    void userInput();   //用户输入

    void Processor();   //字符串处理公用接口

};

int main(int argc, const char *argv[])
{
    SetConsoleOutputCP(CP_UTF8);
    StringProcessor sp;

    //由用户输入字符串
    sp.userInput();
    //处理字符串
    sp.Processor();

    return 0;
}

void StringProcessor::Processor()
{
    splitWords();

    countWords();

    countChar();
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

void StringProcessor::splitWords()
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

    //将单词进行打印
    show_words();
}

void StringProcessor::show_words() const
{
    std::cout<<"该字符串中，单词如下:"<<std::endl;
    std::for_each(v.begin(),v.end(),showVector);
}

void StringProcessor::countChar()
{
    size_t i = 0;
    size_t arr_index = 0;

    //将待处理字符串中的每个字符都取出来作为键值插入map容器，并统计其频数
    while(this->processor[i++] != '\0')
    {
        //剔除空格符
        if(this->processor[arr_index] == ' ')
        {
            arr_index++;
            continue;
        }
        //将字符串中的字符挨个取出放入map容器。
        auto result = mp.insert(std::make_pair(this->processor[arr_index],1));
        //判断是否插入成功，如果插入成功则说明为容器中没有的新字符，不做任何动作。若插入失败，则说明原容器已有该字符，计数器自增。
        if(result.second){}
        else
        {
            mp[this->processor[arr_index]]++;
        }
        arr_index++;
    }

    //对频数和字符进行打印
    std::cout<<"该字符串中有如下字符:"<<std::endl;
    std::map<char,size_t> ::const_iterator it = mp.begin();
    for(it;it!=mp.end();it++)
    {
        std::cout<<it->first<<": "<<it->second<<std::endl;
    }
}

void StringProcessor::countWords()
{
    size_t i = 0;
    
    std::map<std::string,size_t> mp;
    while(i < v.size())
    {
        //同样的，插入失败则频数自增,插入成功则默认为1
        auto result = mp.insert(std::make_pair(v[i],1));
        if(result.second){}
        else
        {
            mp[v[i]]++;
        }
        i++;
    }

    std::cout<<"单词出现的频率如下:"<<std::endl;
    std::map<std::string,size_t>::const_iterator it = mp.begin();
    for(it;it!=mp.end();it++)
    {
        std::cout<<it->first<<": "<<it->second<<std::endl;
    }
}