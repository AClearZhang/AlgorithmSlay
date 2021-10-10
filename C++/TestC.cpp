/*
 * @FilePath            : \AlgorithmInterview\AlgorithmSlay\C++\TestC.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-09-27 22:01:01
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-09-27 22:20:39
 * @Version             : 1.0
 * @Description         : 
 */
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(int argc, char const *argv[])
{
    int a[5] = {1,2,3,4,5};
    int* p1 = (int*)(&a + 1);
    int* p2 = (int*)(a+1);

    printf("%d, %d\n", p1[-1], p2[1]);

    int a1[5] = {1,2,3,4,5};
    printf("%d\n", &a1[3]-&a1[0]);

    system("pause");
    return 0;
}


