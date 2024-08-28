/*自定义数据类型排序
将年龄从大到小排序，如果年龄相同，则按身高从高到低排序*/
#include <iostream>
#include <string>
#include <list>

class Person
{
public:
    int Age;          // 年龄
    std::string Name; // 姓名
    float Height;     // 身高

    Person() : Age(0), Name("None"), Height(0.00) {}
    void inputPersonInfo(); // 输入人物信息
};

// 输入人物信息
void Person::inputPersonInfo()
{
    using namespace std;
    cout << "请输入姓名: ";
    getline(cin, this->Name);

    cout << endl
         << "请输入年龄: ";
    cin >> this->Age;

    cout << endl
         << "请输入身高: ";
    cin >> this->Height;

    cout << "信息输入成功" << endl;
    cin.ignore(1024, '\n');
    _sleep(1000);
    // 清屏
    cout << "\033[2J\033[H";
}

// 排序函数
bool Compare(const Person &p1, const Person &p2)
{
    if (p1.Age != p2.Age)
    {
        return p2.Age > p1.Age;
    }
    else
    {
        return p2.Height > p1.Height;
    }
}

// 打印LIST
void printList(const std::list<Person> &L)
{
    std::list<Person>::const_iterator it = L.begin();
    for (it; it != L.end(); it++)
    {
        std::cout << "名字:" << it->Name << "  ";
        std::cout << "年龄:" << it->Age << "  ";
        std::cout << "身高:" << it->Height << std::endl;
    }
    std::cout << std::endl;
}

int main(int argc, const char *argv[])
{
    const int PER_AMOUNT = 4;
    std::list<Person> L1;

    while (L1.size() != PER_AMOUNT)
    {
        Person p;
        p.inputPersonInfo();
        L1.push_back(p);
    }
    std::cout << "排序前" << std::endl;
    printList(L1);

    L1.sort(Compare);
    std::cout << std::endl
              << "排序后" << std::endl;
    printList(L1);

    return 0;
}