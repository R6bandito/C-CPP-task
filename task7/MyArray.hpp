#ifndef MY_ARRAY
#define MY_ARRAY

#include <iostream>
#include <string>
using namespace std;

//MyArray模板类
template<class T = int> //默认类型 int
class MyArray
{
    template<class U>
    friend void Display(const MyArray<U>&arr);
    private:
    T* pAddress;    //该指针指向堆区开辟的数组
    size_t arr_Capacity;    //开辟在堆区的数组的容量
    size_t arr_Amount;  //数组中的元素个数（即数组的大小）

    public:
    MyArray(size_t num=0):arr_Capacity(num),arr_Amount(0){    //构造函数参数初始化表
        this->pAddress = new T[arr_Capacity];   //堆区开辟数组空间
        cout<<"MyArray构造调用"<<endl;
    }  
    //尾插法插入数据
    void push_Rear(const T& value)
    {
        if(this->arr_Capacity == this->arr_Amount){ //插入数据之前先判断容量是否已满
            cout<<"数组容量已满"<<endl;
            return; //结束函数
        }
        this->pAddress[this->arr_Amount] = value;   //新增一个数据
        this->arr_Amount++;     //插入一个数据后，数组总大小要更新
    }
    //尾删法删除数据
    void delete_Rear()
    {
        if(this->arr_Amount <= 0)   //删除数据前，判断数组是否已空
        {
            cout<<"数组已空"<<endl;
            return;
        }
        this->pAddress[this->arr_Amount-1] = 0; //将最后一个数据置0
        this->arr_Amount--; //动态更新数组大小
    }
    //函数重载。重载[]运算符，使可以直接通过下标来访问
    T& operator[](int index) const
    {
        return this->pAddress[index]; //通过下标访问
    }
    //析构函数
    ~MyArray(){
        delete[] this->pAddress;    //从堆区释放掉整个数组
        this->pAddress = NULL;  //释放过后将指针置空，防止出现野指针
        cout<<"The Array has been released"<<endl;
    }
    //拷贝构造,解决浅拷贝问题
    MyArray(const MyArray& p){
        cout<<"拷贝构造调用"<<endl;
        this->arr_Amount = p.arr_Amount;
        this->arr_Capacity = p.arr_Capacity;
        this->pAddress = new T[p.arr_Capacity]();
    }
    //获取数组容量
    int get_Capacity()
    {
        return this->arr_Capacity;
    }
    //获取数组大小
    int get_Amount()
    {
        return this->arr_Amount;
    }
    //=运算符重载,对堆区的数据进行拷贝
    MyArray& operator=(const MyArray& pt)
    {
        cout<<"运算符重载调用"<<endl;
        int i;
        for(i=0;i<pt.arr_Amount;i++)
        {
            this->pAddress[i] = pt.pAddress[i];
        }
        this->arr_Amount = pt.arr_Amount;
        return *this;
    }
};

template<class U>
void Display(const MyArray<U>&arr)
{
    for(int i=0;i<arr.arr_Amount;i++)
    {
        cout<<"the "<<i<<" value is "<<arr[i]<<endl;
    }
}

#endif //MY_ARRAY