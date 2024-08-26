#include <iostream>
#include "Error_func.h"
#include <windows.h>

void Delay_ms(unsigned int cont)
{
    Sleep(cont);
}

void Cin_Error_Print()
{
    std::cout << "输入错误，请重试";
    // 延迟1秒
    Delay_ms(1000);
    // 清空该行的内容
    std::cout << "\033[2K";
    // 光标复原
    std::cout << "\033[u";
    // 清空从光标处到行尾的内容
    std::cout << "\033[K";
}

void Cin_Restore()
{
    std::cin.clear();
    std::cin.ignore(1024, '\n');
}

