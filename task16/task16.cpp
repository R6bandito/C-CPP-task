/***题目：通过 `const` 成员函数实现其 `non-const` 孪生兄弟**

**题目描述：**

请编写一个 C++ 程序，实现一个简单的二维点（Point）类。这个类应当包含以下功能：

1. **数据成员：**
   - 两个私有成员变量 `x` 和 `y`，分别表示点的横坐标和纵坐标。

2. **构造函数：**
   - 提供一个构造函数，用于初始化点的坐标。

3. **成员函数：**
   - 一个 `getX` 成员函数，用于返回点的横坐标。要求提供两个版本：一个 `const` 成员函数和一个 `non-const` 成员函数。
   - 一个 `getY` 成员函数，用于返回点的纵坐标。要求提供两个版本：一个 `const` 成员函数和一个 `non-const` 成员函数。
   - `non-const` 成员函数可以通过调用 `const` 成员函数来实现。

4. **其他要求：**
   - 在 `main` 函数中，创建一个 `const` 对象和一个 `non-const` 对象，分别调用这两个版本的 `getX` 和 `getY` 函数，验证它们的功能。

**输入格式：**
- 无需输入，直接在 `main` 函数中测试代码。

**输出格式：**
- 输出 `const` 和 `non-const` 对象分别调用 `getX` 和 `getY` 函数后的结果。

**样例输出：**
```
Const Object: X = 5, Y = 10
Non-Const Object: X = 20, Y = 30
```

**提示：**
- 你需要理解如何定义 `const` 成员函数，并且如何在 `non-const` 成员函数中调用 `const` 成员函数。
- 考虑 `const_cast` 的使用来实现 `non-const` 函数的功能。

**附加挑战：**
- 尝试在 `non-const` 成员函数中通过调用 `const` 成员函数实现的过程中，避免使用 `const_cast`。
- 扩展 `Point` 类，增加一个 `move` 函数，用于移动点的坐标，并验证在 `const` 对象上无法调用该函数。*/

#include <iostream>
class Point
{
    private:
    int x;  //点的横坐标
    int y;  //点的纵坐标

    public:
    Point(int x=0,int y=0){
        this->x = x;
        this->y = y;
    }

    //获取横坐标(const)
    const int& getX() const 
    {
        return this->x;
    }
    int& getX()
    {
        //实质上是对non-const对象进行两次类型转换，第一次将*this转换为const类型并通过getX() const拿到x的引用。
        //第二次将拿到的const x引用去掉const的修饰。达到通过non-const的对象调用getX() const的目的，避免代码重复
        return const_cast<int&>(static_cast<const Point&>(*this).getX());
    }

    //获取纵坐标(const)
    const int& getY() const
    {
        return this->y;
    }

    //获取纵坐标
    int& getY()
    {
        return const_cast<int&>(static_cast<const Point&>(*this).getY());
    }

    //移动点
    void move()
    {
        int R = 5;  //向右移动五位
        this->x += R;
    }
};

void constObject()
{
    const Point p1(5,10);
    int X = p1.getX();
    int Y = p1.getY();
    std::cout<<"Const Object: X="<<X<<"   Y="<<Y<<std::endl;

    //p1.move();    const对象，无法调用move函数来移动点
}

void nonconstObject()
{
    Point p1(9,12);
    int X = p1.getX();
    int Y = p1.getY();
    std::cout<<"non-Const Object: X="<<X<<"   Y="<<Y<<std::endl;

    p1.move();
    X = p1.getX();
    std::cout<<"non-Const moved Object: X="<<X<<"   Y="<<Y<<std::endl;

}
int main(int argc,const char* argv[])
{
    constObject();

    nonconstObject();

    return 0;
}

/*
这段代码总体上是相当不错的，成功实现了通过 `const` 成员函数实现 `non-const` 成员函数，
并且很好地运用了 `const_cast` 和 `static_cast` 来避免代码重复。下面是一些具体的点评：

### 优点：
1. **结构清晰**：代码结构清晰，函数的职责明确，易于理解。
2. **使用了合适的类型转换**：在 `non-const` 成员函数中通过 `const_cast` 和 `static_cast` 组合来调用 `const` 版本，避免了代码重复，这是一个不错的设计。
3. **实现了题目的要求**：成功实现了 `const` 和 `non-const` 成员函数，以及通过 `const` 成员函数实现 `non-const` 的要求。

### 改进建议：
1. **构造函数的初始化列表**：虽然代码功能正常，但在构造函数中直接使用初始化列表更为优雅，如下所示：
   ```cpp
   Point(int x=0, int y=0) : x(x), y(y) {}
   ```
   这种方式不仅更简洁，还能提高效率，避免在构造函数体内对成员变量的重复赋值。

2. **`move` 函数的灵活性**：当前 `move` 函数是将点向右移动5个单位，比较单一。可以考虑将移动距离作为参数传入，这样函数会更具灵活性，例如：
   ```cpp
   void move(int deltaX, int deltaY) {
       this->x += deltaX;
       this->y += deltaY;
   }
   ```

3. **代码注释**：虽然代码注释简要地解释了 `non-const` 函数的实现，但可以进一步详细说明类型转换的原因和必要性，以帮助读者更好地理解。

### 打分：
综合考虑代码质量、功能实现及扩展性，我会给这段代码 **8.5/10**。代码已经很好地完成了任务，但在细节上还有一些优化空间。

继续保持优秀的编程习惯，尝试在不同场景中运用这些技巧吧！*/