/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\STL\binarySearch.cpp
 * @Author              : AClearZhang
 * @Date                : 2020-11-28 09:37:59
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2020-12-05 22:03:40
 * @Version             : 1.0
 * @Description         : 最简单的二分查找
 */

#include <algorithm>
#include <iostream>
#include <vector>
#include <windows.h>
// #include <stdio.h>

using namespace std;

/**
 * @description: 
 * @param {*}
 * @return {*}
 * @notes: 已经排好序的数组, 左闭右闭寻找一般的中间值。
 */
int binarySearch1(int nums[], int target)
{
    int n = sizeof(nums) / sizeof(nums[0]);
    if (n == 0) return -1;
    int left = 0;
    int right = n - 1;
    // 查找所以等于
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] > target)
        {
            right = mid - 1;
        }
        else if (nums[mid] < target)
        {
            left = mid + 1;
        }
    }
    return -1; // 表示未查找到。
}

/**
 * @description: 左侧边界的二分查找，注意要有多个target才行；使用左闭右开
 * @param {*}
 * @return {*}
 * @notes: 
 */
int binarySearch2(int nums[], int target)
{
    int n = sizeof(nums) / sizeof(nums[0]);
    if (n  == 0) return -1;
    int left = 0;
    int right = n;
    // 查找所以等于
    while (left < right)
    {
        int mid = (left + right) / 2;
        // cout << "mid is:" << mid << endl;
        if (nums[mid] == target)
        {
            right = mid;
        }
        else if (nums[mid] > target)
        {
            right = mid;
        }
        else if (nums[mid] <  target)
        {
            left = mid + 1;
        }
    }
    
    // return left; 
    
    if (left == n) return -1; // 到达边界还没有 返回-1
    
    return nums[left] == target ? left : -1; // 若相等返回 left
}

/**
 * @description: 寻找右侧边界的二分搜索
 * @param {*}
 * @return {*}
 * @notes: 
 */


int main()
{
    int s[] = {1,2,2,2,4};
    int target = 2;
    int leftBound = binarySearch2(s, target);
    cout << "leftBound is:" << leftBound << endl;   

    system("pause");
    return 0;
}
