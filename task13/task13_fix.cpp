// task13修改后代码

#include <iostream>
#include <string>
#include <list>

// 定义人物类
class Person
{
public:
    int Age;          // 年龄
    std::string Name; // 姓名
    float Height;     // 身高

    Person() : Age(0), Name("None"), Height(0.00) {}
    void inputPersonInfo(); // 输入人物信息
};

// 定义排序策略基类
class sortStrategy
{
public:
    virtual ~sortStrategy() {}
    virtual bool compare(const Person &p1, const Person &p2) const = 0;
};

// 定义按年龄与身高综合排序策略类
class sort_Age_Height_Strategy : public sortStrategy
{
public:
    ~sort_Age_Height_Strategy() {}
    bool compare(const Person &p1, const Person &p2) const override
    {
        if (p2.Age != p1.Age)
            return p2.Age < p1.Age;
        return p2.Height < p1.Height;
    }
};

//定义排序函数
void sortPerson(std::list<Person> &persons,const sortStrategy &strategy)
{
    persons.sort([&](const Person &p1,const Person &p2){
        return strategy.compare(p1,p2);
    });
}

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
    // 运用constexpr定义编译期常量
    constexpr int PER_AMOUNT = 4;
    // 将L1变量更换为更具描述性的personList1
    std::list<Person> personList1;

    // 接收要排序的人数，并调用输入信息函数键入相关信息
    while (personList1.size() != PER_AMOUNT)
    {
        Person p;
        p.inputPersonInfo();
        personList1.push_back(p);
    }

    std::cout << "排序前:" << std::endl;
    printList(personList1);

    std::cout << std::endl;

    //选择排序类型
    sort_Age_Height_Strategy age_height_strategy;
    sortPerson(personList1,age_height_strategy);
    std::cout << "排序后:" << std::endl;
    printList(personList1);

    return 0;
}

/*
代码质量评价
这段代码展示了一个使用策略模式来对 Person 对象进行排序的实现。代码中的设计思路清晰，通过面向对象编程的方式使用策略模式定义不同的排序规则。
以下是对该代码质量的详细评价：

1. 代码设计和架构
策略模式的使用：代码使用策略模式来实现灵活的排序机制，通过定义一个基类 sortStrategy 和派生类 sort_Age_Height_Strategy 来实现按年龄和身高的综合排序。
这种设计模式有效地解耦了排序逻辑与排序算法，使得添加新的排序策略（例如按姓名排序）变得简单，只需实现新的策略类即可。

类和函数的封装：代码中将 Person 的属性和行为（如信息输入）封装在类内，符合面向对象编程的封装原则。sortPerson 函数独立于 Person 类，
使得排序功能更加模块化和独立。

使用了现代 C++ 的特性：如 constexpr 用于定义编译期常量 PER_AMOUNT，lambda 表达式用于简化排序逻辑，这些都使代码更加现代化和简洁。

2. 代码可读性和命名
命名规范：变量和类名命名较为清晰，如 Person、sortStrategy、sort_Age_Height_Strategy 和 sortPerson 等，能够反映出其用途。
局部变量 personList1 也比原来的 L1 更具描述性，这提升了代码的可读性。

注释：代码注释合理，解释了类的用途和关键函数的功能，如对 sortStrategy 的描述。然而，某些地方的注释略显简单，
特别是在复杂逻辑部分可以增加一些注释来帮助理解。

3. 代码健壮性和错误处理
输入处理：在 Person::inputPersonInfo 函数中，使用了 getline 和 cin 来获取输入，但没有处理输入的错误情况。
例如，如果用户输入了非整数的年龄或者非浮点数的身高，程序可能会异常终止。
可以增加输入检查，使用 cin.fail() 检测输入错误，并清理输入流。

清屏功能：使用了 \033[2J\033[H 清屏，这种方式可能只在某些控制台上有效，跨平台兼容性有限。
如果目标是跨平台开发，建议使用更通用的方法，如通过库函数来处理清屏。

睡眠函数：使用 _sleep(1000); 实现延时，通常建议使用标准库中的 std::this_thread::sleep_for(std::chrono::milliseconds(1000));，
这可以提高代码的可移植性和可读性。

4. 性能和效率
使用 std::list：在代码中使用了 std::list 来存储 Person 对象，这是合适的选择，因为 std::list 在插入和删除操作方面有较好的性能表现。
但如果需要频繁随机访问元素，可以考虑使用 std::vector。

排序性能：使用 std::list::sort 是高效的，因为它在链表中是原地排序，不需要额外的内存来复制数据。
比较函数使用 lambda 表达式传递，使得代码紧凑和高效。

5. 扩展性
易于扩展：由于采用了策略模式，新增排序策略非常容易，只需继承 sortStrategy 并实现新的 compare 方法。
这种设计使得代码具有良好的扩展性，可以根据需求增加不同的排序逻辑。
6. 跨平台性
依赖系统特定功能：代码中使用了 _sleep 和 ANSI 转义码（\033[2J\033[H）来延时和清屏，这些功能在不同的操作系统之间可能表现不同。
例如，Windows 和 Linux 在处理控制台输出时有差异，建议使用跨平台库（如 ncurses 或 Qt）来处理这些功能。
总体评分与建议
总体评分：8/10

这段代码总体质量较高，设计模式合理，代码结构清晰，具备良好的扩展性和可读性。但在错误处理和跨平台兼容性方面可以进一步完善。*/