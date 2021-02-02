/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\300.LongestIncreSubsequence.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-02-01 23:40:05
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-02-02 17:33:24
 * @Version             : 1.0
 * @Description         : LIS 最长递增子序列（区别 不是子串，不用非得连续）
 * 300. 最长递增子序列
给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。

子序列是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。

 
示例 1：

输入：nums = [10,9,2,5,3,7,101,18]
输出：4
解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
示例 2：

输入：nums = [0,1,0,3,2,3]
输出：4
示例 3：

输入：nums = [7,7,7,7,7,7,7]
输出：1
 

提示：

1 <= nums.length <= 2500
-104 <= nums[i] <= 104
 

进阶：

你可以设计时间复杂度为 O(n2) 的解决方案吗？
你能将算法的时间复杂度降低到 O(n log(n)) 吗?
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
     * @Description: 最长递增子序列
     * @param {*}
     * @return {*}
     * @notes: 
     */
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        for(int i = 0; i<nums.size() ; i++){
            for(int j = 0; j<i ;j++){
                if(nums[i] > nums[j]){
                    // 表明当前状态 可由j+1 进行设置数值
                    dp[i] = max(dp[i], 1+dp[j]);
                }
            }
        }

        // 遍历找出最大的dp来
        int maxSeq = 1;
        for(int a:dp){
            maxSeq = a>maxSeq ? a : maxSeq ;
        }
        return maxSeq;
    }
};



