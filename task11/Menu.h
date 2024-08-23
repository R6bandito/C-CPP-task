#ifndef MENU
#define MENU

#include <iostream>

//定义一个菜单类
class Menu
{
    protected:
    int length;
    int width;
    int count;  //count用于记录行数

    public:
    Menu(); //声明构造函数
    void lace_of_Menu() ;    //声明边框函数(绘制边框)
    int content_of_Menu(); //声明菜单内容函数
};

#endif //MENU