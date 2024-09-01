/*修改过后的代码*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

//递归调用最大深度
const int MAX_DEPTH = 20;

// 该函数用于用户输入有误时的错误处理
void error_Cope()
{
    char ch;
    // 清空输入缓冲区中的错误输入
    while ((ch=getchar()) != '\n' && ch != EOF){}
    printf("输入错误，请重试\n");
}

// 输入函数
void Input_Integer(int *KeyIn)
{
    while (true)
    {
        printf("请输入: ");
        if (scanf("%d", KeyIn) != 1)
        {
            error_Cope();
            continue;
        }
        break;
    }
}
// 用于用户输入的生成随机数数量，并调用生成函数
void range_Check(int*,int*,int*,int);    //函数声明
void inputData(int *minptr, int *maxptr, int *random_Num_ptr,int depth)
{
    if(depth >= MAX_DEPTH){
        printf("Exceeded maximum recursion depth\n");
        return;
    }
    printf("要生成的随机数数量,");
    Input_Integer(random_Num_ptr);
    //对随机数数量进行正负校验
    if(*random_Num_ptr <= 0){
        printf("输入错误，请重试\n");
        //递归调用，为了防止重复输入，使用goto语句直接跳转到函数尾部
        inputData(minptr,maxptr,random_Num_ptr,depth++);
        goto label;
    }

    printf("请输入要生成随机数的区间\n");
    printf("上限 ");
    Input_Integer(maxptr);

    printf("下限 ");
    Input_Integer(minptr);
    //输入范围校验
    range_Check(maxptr,minptr,random_Num_ptr,depth);
label:
    return;
}

//对用户的输入进行检查
void range_Check(int *maxptr,int *minptr,int *random_Num_ptr,int depth)
{
    if(*maxptr <= *minptr){
        printf("输入错误，请重试\n");
        inputData(minptr,maxptr,random_Num_ptr,depth++);
    }
}

// 生成随机数，将其存储到一个数组中，并返回该数组的地址
int *generate_RandomNum(const int num, const int max, const int min, int arr[])
{
    // 初始化随机数生成器
    srand(time(NULL));
    printf("------------------------------------------------------------");
    printf("\n生成的随机数为:");
    // 生成随机数
    for (int i = 0; i < num; i++)
    {
        arr[i] = rand() % (max - min + 1) + min;
        printf("%d ", arr[i]);
    }
    // 返回数组地址
    return arr;
}

// 统计函数
void Count(const int *array, const int num)
{
    // 奇数计数器
    int odd_count = 0;

    for (int i = 0; i < num; i++)
    {
        if ((*array++) % 2 != 0)
            odd_count++;
    }

    printf("\n奇数个数:%d\n", odd_count);
    printf("偶数个数:%d\n", num - odd_count);
}

// 找出最大最小值
void found_Max_Min(const int arr[], const int num,const char mode[])
{
    if(strcmp(mode,"max")==0 || strcmp(mode,"min")==0){}
    else    return;
    for(int i=0;i<num;i++)
    {
       
        if(strcmp(mode,"max")){
            static int max_index = 0; 
            if(arr[max_index] < arr[i])
                max_index = i;
            if(i==num-1)
                printf("最大值为:%d\n",arr[max_index]);
        }
        else if(strcmp(mode,"min")){
            static int min_index = 0;
            if(arr[min_index] > arr[i])
                min_index = i;
            if(i==num-1)
                printf("最小值为:%d\n",arr[min_index]);
        }
    }
}

// 统计数字出现频率
void Frequency(const int arr[], const int num, const int max, const int min)
{
    // 定义一个辅助动态数组
    int frequency_arr[max - min + 1];
    // 将该数组内元素初始化为0
    for (int i = 0; i < (max - min + 1); i++)
    {
        frequency_arr[i] = 0;
    }

    for (int i = 0; i < num; i++)
    {
        frequency_arr[arr[i] - min]++;
    }
    printf("------------------------------------------------------------");
    printf("\n数字出现的频率\n");
    for (int i = 0; i < (max - min + 1); i++)
    {
        if (frequency_arr[i] > 0)
        {
            printf("%d 出现了 %d 次\n", i + min, frequency_arr[i]);
        }
    }
}

int main(int argc, const char *argv[])
{
    int max;
    int min;
    int num;

    // 用户输入所需数据
    inputData(&min, &max, &num,0);
    int arr[num];
    // 生成随机数
    int *ptr = generate_RandomNum(num, max, min, arr);
    // 统计
    Count(ptr, num);
    // 找出最大值
    found_Max_Min(ptr, num,"max");
    //找出最小值
    found_Max_Min(ptr,num,"min");
    // 统计数字出现频率
    Frequency(ptr, num, max, min);
    return 0;
}