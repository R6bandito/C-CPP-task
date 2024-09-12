/*题目：实现一个简单的字符串类
要求：
实现一个名为 SimpleString 的 RAII 类，用于管理动态分配的字符串。该类需要在构造时分配内存，在析构时释放内存，并提供基本的字符串操作功能。

功能：
构造函数：接受一个 const char* 类型的字符串作为参数，分配足够的内存来存储该字符串，并将其复制到内部存储。
析构函数：释放动态分配的内存。
拷贝构造函数：实现深拷贝，确保在复制 SimpleString 对象时，复制其内部字符串的内容。
赋值运算符：实现深拷贝赋值运算符，确保赋值时正确管理内存，避免内存泄漏。
获取字符串：提供一个 c_str 方法，返回内部字符串的 const char* 指针。
获取字符串长度：提供一个 length 方法，返回字符串的长度。
*/

#include <iostream>
#include <cstring>

class SimpleString
{
private:
    char *PInv;

    void copy_cope(const SimpleString &other)
    {
        delete[] this->PInv; // 释放当前PInv
        this->PInv = new char[strlen(other.PInv) + 1];
        strcpy(this->PInv, other.PInv);
    }

public:
    // 构造函数。开辟一段新存储空间存储传入的字符串
    SimpleString(const char *ptr) : PInv(NULL)
    {
        if (ptr)
        {
            this->PInv = new char[strlen(ptr) + 1];
            strcpy(this->PInv,ptr);
        }
        else
        {
            this->PInv = new char[1];
            *(this->PInv) = '\0';
        }
    }
    // 拷贝构造，实现深拷贝
    SimpleString(const SimpleString &other) : PInv(NULL)
    {
        copy_cope(other);
    }
    // 深拷贝赋值函数
    SimpleString &operator=(const SimpleString &other)
    {
        // 自我赋值检查
        if (this != &other)
        {
            copy_cope(other);
        }
        return *this;
    }

    // 对象生命周期结束,释放资源
    ~SimpleString()
    {
        delete[] this->PInv;
    }

    // 获取原始指针
    const char* getSource() const
    {
        return this->PInv;
    }

    // 返回字符串长度
    const size_t length() const
    {
        return strlen(this->PInv);
    }
};

void print(const SimpleString& s) 
{
    std::cout << "Length: " << s.length() << std::endl;
    std::cout << s.getSource()<< std::endl;
}

int main(int argc, const char *argv[])
{
    SimpleString s1("Hello");
    // 拷贝构造测试
    SimpleString s2(s1);

    SimpleString s3("Hello,C++");

    SimpleString s4 = s3;

    print(s1);
    print(s2);
    print(s4);

    return 0;
}

/*你的 SimpleString 类实现得相当不错，整体结构清晰，功能完整。下面是一些具体的评价和建议：

优点：
RAII 原则：你正确地使用了 RAII 原则，确保在构造时分配内存，在析构时释放内存，避免内存泄漏。
深拷贝：拷贝构造函数和赋值运算符都实现了深拷贝，避免了潜在的悬挂指针和双重释放的问题。
自我赋值检查：在赋值运算符中进行了自我赋值检查，这是良好的编程习惯。
字符串操作：提供了获取原始字符串指针和计算字符串长度的方法，符合基本的字符串类需求。
建议：
copy_cope 函数命名：函数名 copy_cope 可能是一个拼写错误，建议改为 copy 或 copyFrom，以提高可读性。

构造函数中的内存分配：在构造函数中，你可以考虑使用 std::strlen 和 std::strcpy，以避免潜在的命名冲突。

异常安全：在内存分配失败时，new 会抛出异常，这在你的代码中没有处理。虽然 C++ 默认会处理这个情况，但可以考虑在 copy_cope 中捕获异常并进行适当处理。
getSource 方法：虽然你使用 getSource 方法获取字符串，但建议将其改为 c_str，以更符合 C++ 标准库中的命名习惯。

总结：
整体来说，你的代码结构良好，功能实现完整，遵循了 RAII 和深拷贝的原则。只需对一些细节进行微调即可。
继续保持这样的编程风格和思考方式，相信你会在 C++ 的学习上取得更大的进步！
*/