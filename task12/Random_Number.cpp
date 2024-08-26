#include <iostream>
#include <random>
#include "Random_Number.h"

int randomNum_Create()
{
    int rand_num;
    //创建随机数生成器，并使用设备随机数作为种子
    std::random_device rd;
    std::mt19937 gen(rd());

    //生成1-9之间的整型随机数
    std::uniform_int_distribution<> distrib(1,9);

    //生成随机数
    rand_num = distrib(gen);
    return rand_num;
}