/*题目：实现一个简单的字符串处理工具
要求：
使用 C++ 标准模板库（STL）中的容器和算法来实现。
实现一个类 StringProcessor，该类能够处理字符串，并提供以下功能：
统计字符串中每个字符出现的次数。
统计字符串中每个单词出现的次数。
将字符串中的所有单词按字母顺序排序。
将字符串中的所有单词按出现频率排序。
输入：
一个字符串，可能包含字母、数字、标点符号和空格。
*/

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

    // 从字符串中根据空格/逗号/句号及/号等截取单词
    while (this->processor.find_first_of(" \"\'.,/?![]{}",location_Head) != std::string::npos)
    {
        // 从location_Head下一处开始查找空格
        location_Tail = this->processor.find_first_of(" ,./?!\'\"[]{}", location_Head);
        // 如果头和尾非26英文字符(包含大小写)则不读取
        if (((this->processor[location_Tail]) < 65 || (this->processor[location_Tail] > 90)) 
        && ((this->processor[location_Tail]) < 97 || (this->processor[location_Tail] > 122)) 
        && ((this->processor[location_Head]) < 65 || (this->processor[location_Head] > 90)) 
        && ((this->processor[location_Head]) < 97 || (this->processor[location_Head] > 122))) 
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

/*你的 StringProcessor 类实现了基本的字符串处理功能，包括用户输入、单词拆分、字符频率统计和单词频率统计，整体结构清晰且功能完整。
以下是对你代码的具体评价，包括优点与改进建议：

优点：
清晰的结构：代码逻辑清晰，类的设计合理，功能划分明确，使得每个方法只负责一项任务，符合单一职责原则。

使用 STL 容器：有效地使用了 std::vector 和 std::map 处理数据，利用 STL 的特性简化了代码。

用户交互：通过 userInput 方法与用户进行交互，采用 getline 函数读取字符串，能够处理包含空格的输入。

频率统计：实现了字符和单词的频率统计，输出格式友好，易于理解。

改进建议：
输入验证：在 userInput 方法中，可以增加输入的长度限制，避免用户输入过长字符串导致的潜在问题。

字符统计逻辑：在 countChar 方法中，使用 while(this->processor[i++] != '\0') 的方式遍历字符串并不优雅，建议使用 for 循环或范围 for 循环来遍历字符串。

字符频率统计的简化：在 countChar 方法中，使用 std::map 的插入操作判断字符是否已存在，建议使用 std::map::operator[] 直接访问并自增计数器，简化代码逻辑
。
单词拆分逻辑：在 splitWords 方法中，使用 find_first_of 和 substr 进行单词拆分的逻辑较为复杂，可以考虑使用正则表达式或更简单的字符串处理方法。

异常处理：在输入阶段可以考虑添加异常处理机制，提升代码的健壮性。
*/