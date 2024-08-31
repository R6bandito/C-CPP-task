/*
### 题目：随机数生成与统计分析

**描述**：  
编写一个C语言程序，用于生成指定数量的随机整数，并对生成的随机数进行统计分析。

**要求**：
1. 使用标准库函数 `rand()` 生成随机数。
2. 用户输入需要生成的随机数的数量 `n` 和随机数的范围 `[min, max]`。
3. 生成的随机数存储在一个数组中。
4. 程序需要完成以下功能：
   - 统计并输出生成的随机数中，奇数和偶数的个数。
   - 计算并输出生成的随机数的平均值。
   - 找出并输出生成的随机数中的最大值和最小值。
   - 统计并输出每个数在数组中出现的次数（假设范围 `[min, max]` 不超过 1000）。

**提示**：
- 使用 `%` 操作符判断奇偶性。
- 使用循环和条件判断实现最大值和最小值的查找。
- 考虑如何在范围 `[min, max]` 内统计每个数的出现次数。

**样例输出**：
```plaintext
请输入要生成的随机数的数量：10
请输入随机数的范围（min max）：1 100
生成的随机数为：12 47 23 85 96 74 12 49 85 39
奇数个数：6
偶数个数：4
随机数平均值：52.2
最大值：96
最小值：12
数字出现频率：
12 出现了 2 次
23 出现了 1 次
39 出现了 1 次
47 出现了 1 次
49 出现了 1 次
74 出现了 1 次
85 出现了 2 次
96 出现了 1 次
```

这道题目主要考察了C语言中随机数的生成、数组的操作和基本的统计分析方法。学习者需要运用 `rand()` 函数、数组和循环结构来完成题目要求。
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// 该函数用于用户输入有误时的错误处理
void error_Input()
{
    char ch = getchar();
    // 清空输入缓冲区中的错误输入
    while (ch != '\n' && ch != EOF){}
    printf("\033[2J\033[H");
}

//输入函数
void Input(int* KeyIn)
{
    while (true)
    {
        printf("请输入: ");
        if (!scanf("%d", KeyIn))
        {
            error_Input();
            continue;
        }
        break;
    }
}
// 用于用户输入的生成随机数数量，并调用生成函数
void inputData(int* minptr,int* maxptr, int* random_Num_ptr)
{
    printf("要生成的随机数数量,");
    Input(random_Num_ptr);

    printf("请输入要生成随机数的区间\n");
    printf("上限 ");
    Input(maxptr);

    printf("下限 ");
    Input(minptr);
}

//生成随机数，将其存储到一个数组中，并返回该数组的地址
int* generate_RandomNum(const int num,const int max,const int min,int arr[])
{
    //初始化随机数生成器
    srand(time(NULL));
    printf("\n生成的随机数为:");
    //生成随机数
    for(int i=0;i<num;i++)
    {
        arr[i] = rand()%(max-min+1)+min;
        printf("%d ",arr[i]);
    }
    //返回数组地址
    return arr;
}

//统计函数
void Count(const int* array,const int num)
{
    //奇数计数器
    int count_Single = 0;

    for(int i=0;i<num;i++)
    {
        if((*array++) % 2 != 0)
            count_Single++;
    }

    printf("\n奇数个数:%d\n",count_Single);
    printf("偶数个数:%d\n",num-count_Single);
}

//找出最大最小值
void found_Max_Min(const int arr[],const int num)
{
    int k = 0;
    //找最大值
    for(int i=0;i<num;i++)
    {
        if(arr[k] < arr[i])
            k = i;
    }
    printf("最大值为:%d\n",arr[k]);
    //找最小值
    k=0;
    for(int i=0;i<num;i++)
    {
        if(arr[k] > arr[i])
            k = i;
    }
    printf("最小值为:%d\n",arr[k]);
}

//统计数字出现频率
void Frequency(const int arr[],const int num,const int max,const int min)
{
    //定义一个辅助动态数组
    int frequency_arr[max-min+1];
    //将该数组内元素初始化为0
    for(int i=0;i<(max-min+1);i++)
    {
        frequency_arr[i] = 0;
    }

    for(int i=0;i<num;i++)
    {
        frequency_arr[arr[i]-min]++;
    }
    printf("数字出现的频率\n");
    for(int i=0;i<(max-min+1);i++)
    {
        if(frequency_arr[i]>0)
        {
            printf("%d 出现了 %d 次\n",i+min,frequency_arr[i]);
        }
    }
}

int main(int argc, const char *argv[])
{
    int max;
    int min;
    int num;

    //用户输入所需数据
    inputData(&min,&max,&num);
    int arr[num];
    //生成随机数
    int* ptr = generate_RandomNum(num,max,min,arr);
    //统计
    Count(ptr,num);
    //找出最大最小值
    found_Max_Min(ptr,num);
    //统计数字出现频率
    Frequency(ptr,num,max,min);
    return 0;
}