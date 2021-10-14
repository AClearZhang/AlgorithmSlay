/*
 * @FilePath            : \project\AlgorithmSlay\C++\JZOffer\39.ShuZuChuXianChaoYiBanShuZi.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-10-14 22:08:30
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-10-14 23:33:13
 * @Version             : 1.0
 * @Description         : 剑指 Offer 39. 数组中出现次数超过一半的数字
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。

 

你可以假设数组是非空的，并且给定的数组总是存在多数元素。

 

示例 1:

输入: [1, 2, 3, 2, 2, 2, 5, 4, 2]
输出: 2
 

限制：

1 <= 数组长度 <= 50000
 */
#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

#define For(x, y, z) for (ll x = y; x < z; ++x)
typedef long long ll;

class Solution
{
public:
    /**
     * @Description: 方法一  直接排序，找n/2 位置
     * @param {*}
     * @return {*}
     * @notes: 
     */
    /**
     * @Description: 方法二 使用partition区分
     * @param {*}
     * @return {*}
     * @notes: 
     */
    int Partition(vector<int> &nums, int n, int left, int right)
    {
        int pivot = nums[left];
        while (left < right)
        {
            while (left < right && nums[right] >= pivot)
                right--;
            nums[left] = nums[right];
            while (left < right && nums[left] <= pivot)
                left++;
            nums[right] = nums[left];
        }
        nums[left] = pivot;
        return left;
    }

    bool inputInvalid = false;

    // bool checkInvalidArray()  检查是否为nullptr 或者0 边界返回false
    bool checkMoreThanHalf(vector<int> nums, int num)
    {
        int n = nums.size();
        int times = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == num)
            {
                times++;
            }
        }
        if (times < n / 2)
        {
            inputInvalid = true;
        }
        return false;
    } // 是否超过一半的个数
    int majorityElement(vector<int> &nums)
    {
        // 如果 位置大于k-1 找左边；小于k-1 找右边。
        int n = nums.size();
        int mid = nums.size() / 2;
        int left = 0, right = n - 1;
        int index = Partition(nums, n, left, right);
        while (index != mid)
        {
            if (index > mid)
            {
                right = index - 1;
                index = Partition(nums, n, left, right);
            }
            else
            {
                left = index + 1;
                index = Partition(nums, n, left, right);
            }
        }

        int result = nums[mid];
        if (!checkMoreThanHalf(nums, result))
        {
            return 0;
        }
        return result;
    }
    /**
 * @Description: 哈希表2
 * @param {*}
 * @return {*}
 * @notes: 
 */
    int majorityElement2(vector<int> &nums)
    {
        unordered_map<int, int> hash;
        int res = 0, len = nums.size();
        for (int i = 0; i < len; i++)
        {
            hash[nums[i]]++;
            //不必等到哈希表完全建立再进行此判断
            if (hash[nums[i]] > len / 2)
                res = nums[i];
        }
        return res;
    }
};
