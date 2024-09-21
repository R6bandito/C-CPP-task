/*题目：简单的多线程计数器
背景：
你需要实现一个简单的多线程计数器，程序将启动多个线程，每个线程将增加一个共享计数器的值。

要求：
编写一个名为 Counter 的类，该类包含一个整数计数器和相关的方法。
在 Counter 类中，提供一个公共方法 increment(int times)，该方法接受一个整数参数 times，表示要增加计数器的次数。
使用多个线程来调用 increment 方法，每个线程都将增加计数器的值。
确保计数器的访问是线程安全的，避免数据竞争。
在所有线程完成后，输出计数器的最终值。
*/
#include <iostream>
#include <mingw.mutex.h>
#include <mingw.thread.h>

std::mutex mtx; //互斥锁

class Counter
{
    private:
    int count;

    public:
    Counter():count(0){}

    void increment(int times){
        //std::unique_lock<std::mutex> lock(mtx);     //自动管理锁
        std::lock_guard<std::mutex> lock(mtx);  //自动管理锁
        for(int i=0;i<times;i++)
            this->count++;
    }

    void display(){
        std::cout<<"The count is "<<this->count<<std::endl;
    }
};

int main(int argc,const char* argv[])
{
    Counter cont;

    std::thread th1(&Counter::increment,&cont,34600);
    std::thread th2(&Counter::increment,&cont,5000);
    std::thread th3(&Counter::increment,&cont,12000);

    if(th1.joinable())  th1.join(); 
    cont.display();
    if(th2.joinable())  th2.join(); 
    cont.display();
    if(th3.joinable())  th3.join(); 
    cont.display();

    return 0;
}