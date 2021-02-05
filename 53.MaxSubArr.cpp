/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\53.MaxSubArr.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-02-05 18:06:53
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-02-05 18:33:28
 * @Version             : 1.0
 * @Description         : 53. 最大子序和
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

 

示例 1：

输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
输出：6
解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
示例 2：

输入：nums = [1]
输出：1
示例 3：

输入：nums = [0]
输出：0
示例 4：

输入：nums = [-1]
输出：-1
示例 5：

输入：nums = [-100000]
输出：-100000
 */


#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <cmath>
#include <algorithm>

using namespace std;


class Solution {
public:
    /**
     * @Description: 最大子序数组--动态规划: 状态dp[i]- 当前index为结尾所得的最大和； 选择几个值返回最大。
     * @param {*}
     * @return {*}
     * @notes: 【重点】 最后要搜索一下最大值
     */
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        // dp存储, 0
        vector<int> dp(n, 0);
        // base case 第一个
        dp[0]  = nums[0];
        // 状态转移方程
        for( int i = 1; i < n ;i++ ){
            // 两种情况: 本身 或 前者+自身
            dp[i] = max( nums[i], dp[i-1]+nums[i] );
        }

        // 搜索Max
        // int max = nums[0];
        int max = INT_MIN;          // 【错误1】
        for(auto a:dp){
            max = a>max ? a : max ;
        }
        return max;
    }
};

