#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <deque>

// 一个vector的资源管理类(RAII机制)
template <class Type>
class ManageVector
{
private:
    // 维护一个指向vector类型的指针
    typename std::vector<Type> *VecPtr;

    // 不允许拷贝和赋值
    ManageVector(const ManageVector &) = delete;
    ManageVector &operator=(const ManageVector &) = delete;

public:
    ManageVector(size_t RevCapacity) : VecPtr(nullptr)
    {
        this->VecPtr = new std::vector<Type>;
        this->VecPtr->reserve(RevCapacity); // 空间预留
    }

    ManageVector() : VecPtr(nullptr)
    {
        this->VecPtr = new std::vector<Type>;
    }

    // 拿到原始指针(指针的指向与指向的地址都不可改变!)
    const std::vector<Type> *const getSource()
    {
        return this->VecPtr;
    }

    void loadArr(Type array[],size_t size)
    {
        for (int i = 0; i < size; i++)
            this->VecPtr->push_back(array[i]);
        std::cout<<"Load Successfully"<<std::endl;
    }

    void loadArr(std::string array[])
    {
        for(int i=0;i<array->size();i++)
            this->VecPtr->push_back(array[i]);
        std::cout<<"Load Successfully"<<std::endl;
    }

    void loadArr(std::queue<Type> &que)
    {
        while(!que.empty()){
            this->VecPtr->push_back(que.front());
            que.pop();
        }
        std::cout<<"Load Successfully"<<std::endl;
    }

    void loadArr(std::deque<Type> &deq)
    {
        while(!deq.empty()){
            this->VecPtr->push_back(deq.front());
            deq.pop_front();
        }
        std::cout<<"Load Successfully"<<std::endl;
    }

    void loadArr(std::stack<Type> &stk)
    {
        while(!stk.empty()){
            this->VecPtr->push_back(stk.top());
            stk.pop();
        }
        std::cout<<"Load Successfully"<<std::endl;
    }

    ~ManageVector()
    {
        delete this->VecPtr;
    }
};

template <typename T>
void printVector(const std::vector<T> *vec)
{
    typename std::vector<T>::const_iterator it = vec->begin();
    for (it; it != vec->end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void FillStack(std::stack<int> &stk)
{
    for(int i=0;i<10;i++)
        stk.push(i*2);
}

int main(int argc, const char *argv[])
{
    std::string str[5] = {"Hello","Bojure","Salute","SayHello","Love"};
    float fta[6] = {1.24,6.22,4.58,4.56,2.66,2.87};
    std::stack<int> stk1;
    FillStack(stk1);

    ManageVector<std::string> vc(5);
    ManageVector<float> fc;
    ManageVector<int>_stack;

    vc.loadArr(str);
    fc.loadArr(fta,6);
    _stack.loadArr(stk1);

    printVector(fc.getSource());
    printVector(vc.getSource());
    printVector(_stack.getSource());

    return 0;
}