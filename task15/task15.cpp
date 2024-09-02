/***题目：自定义排序的学生成绩单**

**题目描述：**

有一个学生成绩单，包含了多个学生的名字及其对应的分数。现在需要你编写一个C++程序来对这些学生成绩单进行排序，要求按以下规则进行排序：

1. 首先按分数从高到低排序。
2. 如果两个学生的分数相同，则按名字的字典序从小到大排序。

你需要使用C++的STL标准库模板来实现这个功能，具体要求如下：

- 使用 `vector` 容器来存储学生信息。
- 使用 `sort` 函数来进行排序，并结合 `pair` 或自定义结构体来存储每个学生的名字和分数。
- 不允许使用 `map` 容器。

**输入格式：**
- 第一行输入一个整数 `n`，表示学生的数量。
- 接下来的 `n` 行，每行包含一个字符串（学生的名字）和一个整数（学生的分数），中间用空格隔开。

**输出格式：**
- 按照要求排序后的学生名字列表，每行一个名字。

**样例输入：**
```
5
Alice 90
Bob 85
Charlie 90
David 85
Eve 95
```

**样例输出：**
```
Eve
Alice
Charlie
Bob
David
```

**提示：**
- 你需要定义比较规则以满足题目中关于排序的要求。
- 注意处理输入和输出的格式。

**附加挑战：**
- 尝试在不使用额外空间的情况下完成排序。
- 试着通过命令行参数读取输入文件并输出结果到文件中。*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// 函数声明
// 输入学生信息
void input_Student(std::vector<std::pair<std::string, int>> &v);
// 排序学生数据
void Sort_Student(std::vector<std::pair<std::string, int>> &v);
// 自定义排序类型
bool MyCompare(std::pair<std::string, int> &p1, std::pair<std::string, int> &p2);
// 打印信息
void output_Student_Info(std::vector<std::pair<std::string, int>> &v);

int main(int argc, const char *argv[])
{
    // 定义一个动态数组存储学生信息
    std::vector<std::pair<std::string, int>> v;
    // 预留50的空间
    v.reserve(50);
    // 输入信息
    input_Student(v);
    // 排序
    Sort_Student(v);
    // 打印输出
    output_Student_Info(v);
    return 0;
}

void input_Student(std::vector<std::pair<std::string, int>> &v)
{
    int StuNum;
    std::cout << "请输入学生个数:";
    std::cin >> StuNum;
    // 忽略掉换行符
    std::cin.ignore();
    std::cout << std::endl<< "请输入学生姓名和年龄(共" << StuNum << ")个" << std::endl;
    for (int i = 0; i < StuNum; i++)
    {
        // 在堆区开辟一个对组对象
        std::pair<std::string, int> *p = new std::pair<std::string, int>;
        // 输入对象信息
        std::cin>>p->first>>p->second;
        std::cin.ignore();
        // 将对象放入容器中
        v.push_back(*p);
        // 释放空间
        delete p;
        // 指针置空
        p = NULL;
    }
}

void Sort_Student(std::vector<std::pair<std::string, int>> &v)
{
    // 对成绩进行排序
    std::sort(v.begin(), v.end(), MyCompare); // sort函数默认从小到大
}

bool MyCompare(std::pair<std::string, int> &p1, std::pair<std::string, int> &p2)
{
    // 成绩由高到低排序
    if (p1.second != p2.second)
        return p1.second > p2.second;
    else
        return p1.first < p2.first;
}

void output_Student_Info(std::vector<std::pair<std::string, int>> &v)
{
    // 清屏，方便输出
    std::cout << "\033[2J\033[H";
    // 定义一个迭代器
    std::vector<std::pair<std::string, int>>::iterator it = v.begin();
    for (it; it != v.end(); it++)
    {
        std::cout << (*it).first << std::endl;
    }
}

/*这段代码总体上是合格的，能完成题目要求的功能，逻辑清晰，使用了标准模板库(STL)的功能来完成排序任务。
但还有一些地方可以优化。以下是我对这段代码的详细评价和评分：

### 优点：
1. **逻辑清晰**：代码结构清晰，主函数 `main()` 先输入数据、再排序、最后输出，符合常规流程。
2. **STL使用得当**：使用了 `vector` 和 `sort`，并且通过自定义比较函数 `MyCompare` 实现了按照题目要求的排序规则。
3. **内存管理**：在 `input_Student` 函数中，你有使用 `new` 和 `delete` 来管理内存，这表明你在考虑内存管理问题。

### 缺点及改进建议：
1. **内存管理不必要复杂化**：
   - 在 `input_Student` 函数中使用了 `new` 来创建 `pair` 对象，但这是不必要的。可以直接在栈上创建 `pair` 对象，然后直接 `push_back` 到 `vector` 中。
   这不仅可以简化代码，还能避免内存泄漏的风险。
   - 建议如下改进：
     ```cpp
     for (int i = 0; i < StuNum; i++)
     {
         std::pair<std::string, int> p;
         std::cin >> p.first >> p.second;
         v.push_back(p);
     }
     ```

2. **参数传递的优化**：
   - `MyCompare` 函数中，参数的传递使用了引用，但是由于比较函数通常是只读的，建议使用 `const` 引用来防止意外修改。
   - 改进后的代码如下：
     ```cpp
     bool MyCompare(const std::pair<std::string, int> &p1, const std::pair<std::string, int> &p2)
     ```

3. **命名规范**：
   - `input_Student` 函数名称中的下划线命名风格与其他函数命名（如 `Sort_Student`）不一致，建议统一命名风格。
   常见的命名风格包括驼峰式（如 `inputStudent`）或下划线分隔（如 `input_student`）。
   
4. **不必要的清屏操作**：
   - 在 `output_Student_Info` 函数中使用了清屏代码 `\033[2J\033[H`，这在一般应用程序中不是必须的，甚至可能在某些终端中不能正确工作。
   如果清屏是必需的，应该明确说明，并且可能需要考虑其他平台的兼容性。

5. **用户交互体验**：
   - 在 `input_Student` 函数中，`std::cin.ignore()` 在这个上下文中并不总是必要的。在读取整数和字符串时，需要小心处理换行符问题。
   你这里的处理方法没有问题，但要确保每次输入之间没有多余的换行。

### 总评分：**80/100**

- **代码结构**：25/30
- **STL使用**：20/20
- **内存管理**：10/20
- **可读性**：15/20
- **用户体验**：10/10

总体而言，这段代码已经实现了题目要求的功能，但在内存管理、命名规范和代码简化方面还有一些可以改进的地方。如果这些建议被采纳，代码质量可以进一步提高。*/