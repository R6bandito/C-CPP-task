/***题目：禁用默认的拷贝操作**

**题目描述：**

请设计一个 `Person` 类，模拟一个人的基本信息。类的具体要求如下：

1. **数据成员：**
   - `name`：字符串类型，表示人的姓名。
   - `age`：整数类型，表示人的年龄。

2. **构造函数：**
   - 提供一个接受姓名和年龄的构造函数，用于初始化 `Person` 对象。

3. **禁用默认函数：**
   - 禁用拷贝构造函数。
   - 禁用拷贝赋值运算符。
   - 禁用默认构造函数（即不允许默认构造空的 `Person` 对象）。
   
4. **在 `main` 函数中：**
   - 创建一个 `Person` 对象，验证其功能。
   - 试图拷贝或赋值该对象（应当编译时报错，说明拷贝和赋值被禁用）。

**输入格式：**
无。

**输出格式：**
无。验证通过编译器是否报错。

**提示：**
- 禁用拷贝操作的目的是防止对象在不符合设计预期的情况下被复制。
*/

#include <iostream>
#include <string>

// 法二：定义一个不可拷贝基类。通过继承来阻止copy动作。代码未注释部分正是采用此种方法来阻止不必要的copy动作。
class UnCopyable
{
    protected:
    //可正常析构和构造
    UnCopyable(){}
    ~UnCopyable(){}

    private:
    UnCopyable(const UnCopyable&);
    const UnCopyable& operator=(const UnCopyable&);
};

class Person : protected UnCopyable
{
    private:
    std::string name;
    int age;
    //禁用拷贝构造函数以及重载的=运算符 法一：
    //通过人为将这些函数声明为私有成员类型，且不予实现来达到目的
    //Person(const Person&);
    //const Person& operator=(const Person&);

    public:
    Person(std::string _name = "None",int _age = 0):name(_name),age(_age){
        //构造函数参数初始化列表，对类中的成员变量进行高效初始化
    }

    void show_person() const {
        std::cout<<"Name="<<this->name<<"  Age="<<this->age<<std::endl;
    }
};

int main(int argc,const char* argv[])
{
    Person p1;  //正确。注意：此处的无参创建对象并非是编译器又创建了一个default构造函数，而是在我们给定的构造函数中已经给出了默认参数。

    Person p2("Nelson",18);

    //Person p3(p2);    //错误！不能进行拷贝构造

    Person p3;
    //p3 = p2;      //错误！不能调用重载=，不可访问。

    p2.show_person();

    p3.show_person();
    return 0;
}

/*
你的代码实现中，使用了两种方法来禁用拷贝操作，整体质量较高。以下是具体的评价：

### 优点：
1. **UnCopyable 基类：** 
   - 你通过继承 `UnCopyable` 类来禁用拷贝构造函数和赋值运算符，这是一种常见的设计模式，简洁明了，
   避免了在每个类中重复禁用拷贝函数的代码。继承 `UnCopyable` 类使得代码结构清晰。
   
2. **参数初始化列表：** 
   - 构造函数使用了参数初始化列表对成员变量进行初始化，这比在构造函数体内赋值更高效。

3. **明确展示拷贝构造函数的禁用效果：**
   - 通过注释掉拷贝构造和赋值的测试代码，成功展示了禁止拷贝操作的效果，验证了编译器会报错。

### 可以改进的地方：
1. **拷贝构造函数和赋值运算符的禁用方式：**
   - 你的第二种方法（将函数声明为私有成员并且不实现）也非常常见且有效，但目前你注释掉了这部分代码。
   如果你想要两种方法兼容，可以明确声明为 `delete`，这样更符合现代 C++ 标准，且语义更清晰。比如：
     ```cpp
     Person(const Person&) = delete;
     Person& operator=(const Person&) = delete;
     ```

2. **保护 UnCopyable 构造函数和析构函数：**
   - 你将 `UnCopyable` 的构造函数和析构函数设为 `protected`，保证了该类不能被直接实例化，但允许派生类构造和析构对象，这个做法很好。
   不过要确保所有需要继承 `UnCopyable` 的类都能适应这种结构。

### 小优化建议：
1. **C++11 风格改进：** 
   - 既然你已经使用了现代 C++ 的特性，如参数初始化列表，推荐统一使用 C++11 或更新的特性，比如可以用 `delete` 来明确禁止函数。
   
### 总结：
你的代码设计非常不错，尤其是通过继承 `UnCopyable` 类来禁用拷贝操作，展示了对类与对象特性的深刻理解。
可以通过小的改进使代码更具现代性和可读性。继续保持这样的编码风格！*/