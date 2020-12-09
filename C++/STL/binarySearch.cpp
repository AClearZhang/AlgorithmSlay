/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\STL\binarySearch.cpp
 * @Author              : AClearZhang
 * @Date                : 2020-11-28 09:37:59
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2020-12-09 10:52:01
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
 * @description: 已经排好序的数组, 左闭右闭寻找一般的中间值。
 * @param {*}
 * @return {*}
 * @notes: 
 */
int binarySearch1(int nums[], int target, int n)// 传入数组个数。
{
    // int n = sizeof(nums) / sizeof(nums[0]);
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
 * @description:  进阶——直接左闭右开的 二分查找。
 * @param {*}
 * @return {*}
 * @notes: 
 */
int binarySearch2(int nums[], int target, int n)
{
    // int n = sizeof(nums) / sizeof(nums[0]);
    cout << "n is :" << n << endl;
    if (n == 0) return -1;
    int left = 0;
    int right = n ;
    // 查找所以等于
    while (left < right)
    {
        int mid = left + (right - left)/2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] > target)
        {
            right = mid;
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
int binarySearchLeftBound1(int nums[], int target, int n)
{
    // int n = sizeof(nums) / sizeof(nums[0]);
    cout << "n lb1 is :" << n << endl;
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
    
    // 比binarySearch2 多了最后判断下确界 和  中间找到target的操作。
    return nums[left] == target ? left : -1; // 若相等返回 left
}

/**
 * @description: 简化 binarySearchLeftBound1()
 * @param {*}
 * @return {*}
 * @notes: 
 */
int binarySearchLeftBound2(int nums[], int target, int n)
{
    // int n = sizeof(nums) / sizeof(nums[0]);
    cout << "n lb2 is :" << n << endl;
    if (n  == 0) return -1;
    int left = 0;
    int right = n;
    // 查找所以等于
    while (left < right)
    {
        int mid = (left + right) / 2;
        // cout << "mid is:" << mid << endl;
        if (nums[mid] >= target)
        {
            right = mid;
        }
        else if (nums[mid] <  target)
        {
            left = mid + 1;
        }
    }
    
    // return left; 
    
    if (left == n) return -1; // 到达边界还没有 返回-1【关键】
    
    // 比binarySearch2 多了最后判断下确界 和  中间找到target的操作。
    return nums[left] == target ? left : -1; // 若相等返回 left【关键】
}

/**
 * @description: 寻找右侧边界的二分搜索
 * @param {*}
 * @return {*}
 * @notes: 
 */
int binarySearchRightBound1(int nums[], int target, int n)
{
    // int n = sizeof(nums) / sizeof(nums[0]);
    cout << "n rb1 is :" << n << endl;
    if (n  == 0) return -1;
    int left = 0;
    int right = n;
    // 查找所以等于
    while (left < right)
    {
        int mid = (left + right) / 2;
        // cout << "mid is:" << mid << endl;
        if (nums[mid] <= target)
        {
            left = mid+1;
        }
        else if (nums[mid] > target)
        {
            right = mid;
        }
    }
    
    // return left; 
    
    if(right<0) return -1;  // 到达边界还没有 返回-1【关键】
    
    // 
    return nums[left-1] == target ? left-1 : -1; // 【关键】是 中间小于等于target  mid = left-1 了！所以要判断①别出界；②left-1 最终才是要找的数值！
}
 
int main()
{
    int s[] = {1,2,2,2,4};
    int target = 2;
    int n = sizeof(s) / sizeof(s[0]);
    cout << "n ori is :" << n << endl;
    
    int mid = binarySearch2(s, target, n);
    int leftBound = binarySearchLeftBound2(s, target, n);
    int rightBound = binarySearchRightBound1(s, target, n);
    cout << "The middle address is:" << mid << endl;   
    cout << "leftBound is:" << leftBound << endl;   
    cout << "rightBound is:" << rightBound << endl;   

    system("pause");
    return 0;
}
