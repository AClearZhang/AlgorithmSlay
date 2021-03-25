/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\DS\503.NextGreaterElementII.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-03-25 10:51:42
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-03-25 11:13:53
 * @Version             : 1.0
 * @Description         : 下一个更大的的元素II
 * 503. 下一个更大元素 II
给定一个循环数组（最后一个元素的下一个元素是数组的第一个元素），输出每个元素的下一个更大元素。数字 x 的下一个更大的元素是按数组遍历顺序，这个数字之后的第一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。如果不存在，则输出 -1。

示例 1:

输入: [1,2,1]
输出: [2,-1,2]
解释: 第一个 1 的下一个更大的数是 2；
数字 2 找不到下一个更大的数； 
第二个 1 的下一个最大的数需要循环搜索，结果也是 2。
注意: 输入数组的长度不会超过 10000。
 */
#include <algorithm>
#include <cmath>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <set>
#include <stack>

using namespace std;

class Solution {
public:
    /**
     * @Description: 循环 基于496题目，进行 2倍数组扩展的% 取余模拟计算。下一个更大值。
     * @param {*}
     * @return {*}
     * @notes:  使用单调栈。
     */
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);    // 注意 vector是固定长度的，需要预先分配好地址！
        stack<int> s;
        for(int i = 2*n-1; i>=0 ;i--){
            while(!s.empty() && s.top()<=nums[i%n]){  // 将比当前值小或等于的统统 删掉。
                s.pop();
            }
            ans[i%n] = s.empty() ? -1 : s.top();
            s.push(nums[i%n]);
        }
        return ans;
    }
};