/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\STL\reverseArray.cpp
 * @Author              : AClearZhang
 * @Date                : 2020-11-28 09:50:46
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2020-11-30 22:13:21
 * @Version             : 1.0
 * @Description         : 翻转数组小例子
 * 
 */


/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\STL\binarySearch.cpp
 * @Author              : AClearZhang
 * @Date                : 2020-11-28 09:37:59
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2020-11-28 09:50:17
 * @Version             : 1.0
 * @Description         : 最简单的二分查找
 */


#include <iostream>
#include <windows.h>
#include <algorithm>
#include <vector>
// #include <stdio.h>

using namespace std;


int reverse(int nums[]){
    int n = sizeof(nums) / sizeof(nums[0]);
    int left = 0;
    int right = n-1;
    while(left<right){
        int temp = nums[left];
        nums[left]=nums[right];
        nums[right]=temp;
        left++, right--;
    }

}



