/*
 * @FilePath            : \project\AlgorithmSlay\C++\DynamicProgram\494.TargetSum.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-03-11 16:31:26
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-03-12 12:06:41
 * @Version             : 1.0
 * @Description         : 目标和  区别回溯 以及 冬天规划
 * 494. 目标和
给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。现在你有两个符号 + 和 -。对于数组中的任意一个整数，你都可以从 + 或 -中选择一个符号添加在前面。

返回可以使最终数组和为目标数 S 的所有添加符号的方法数。

 

示例：

输入：nums: [1, 1, 1, 1, 1], S: 3
输出：5
解释：

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

一共有5种方法让最终目标和为3。
 

提示：

数组非空，且长度不会超过 20 。
初始的数组的和不会超过 1000 。
保证返回的最终结果能被 32 位整数存下。
 */

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    /**
     * @Description: 方法一：回溯算法
     * @param {int} S
     * @return {*}
     * @notes: 
     */
    int findTargetSumWays(vector<int> &nums, int S)
    {
        if (nums.size() == 0)
            return 0;
        int count = 0;
        unordered_map<string, int> memo;
        return backtrack(nums, S, 0, memo);
    }
    // helper —— 辅助函数
    // 返回选择加和 到 target的可能个数
    int backtrack(vector<int> &nums, long target, int start, unordered_map<string, int>& memo)
    { // -nums 会出界！

        // 转换为 string 作为键值
        string key =  to_string(start)+","+ to_string(target);
        if(memo.count(key) > 0){
            return memo[key];
        }

        // 边界 or 最后一个判断是否相等
        if (start == (nums.size() - 1))
        {
            int count = 0;
            if (nums[start] == target)
                count++;
            if (-nums[start] == target)
                count++;
            return count;
        }
        if (start > (nums.size() - 1))
            return 0;

        // 回溯、 选择
        int count = 0;
        for (int i = 0; i < 2; i++)
        { // 正负两种选择
            int nowNum = pow((-1), i) * nums[start];
            count += backtrack(nums, target - nowNum, start + 1, memo);
        }
        memo[key] = count;
        return count;
    }
    /**
     * @Description: 方法二: 动态规划——转为为——子集划分的01背包问题。
     * @param {int} S
     * @return {*}
     * @notes: 
     */
    int findTargetSumWays(vector<int> &nums, int S)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        
        int sum = 0;
        for(int num:nums){
            sum+=num;
        }
        // 不合法的子集划分 排除掉。
        if(sum < S || (sum+S) %2 == 1){
            return 0;                     // 不合法
        }

        // 进入0-1 背包问题中
        return subSets(nums, (S+sum)/2);

    }
    // helper —— 辅助函数
    // 真正的 子集划分01背包问题。
        // dp[i][j]  i从1开始。 前i个物品，载重为j 最多能有几种方法将背包恰好填满。
    int subSets(vector<int>& nums, int target){
        int n = nums.size();

        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        // base
        for(int i=0;i<n+1;i++){
            dp[i][0] = 1;
        }

        // 遍历
        for(int i = 1;i<n+1;i++){
            for(int j = 0;j<target+1;j++){  // j=0 开始，因为 还有i=0的 重量/数字呢！
                if(j >= nums[i-1]){// 放得下
                    dp[i][j] = dp[i-1][j]+dp[i-1][j-nums[i-1]];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][target];

    }
    /**
     * @Description: 辅助函数 状态压缩。内存压缩。
     * @param {int} target
     * @return {*}
     * @notes: 
     */
    int subSets(vector<int>& nums, int target){
        int n = nums.size();

        // 压缩到1维
        vector<int> dp(target+1, 0);
        // base
        dp[0] = 1;

        // 遍历
        for(int i = 1;i<n+1;i++){
            for(int j = target; j>=0;j--){  // 从后到前，防止覆盖上个状态。// j=0 开始，因为 还有i=0的 重量/数字呢！
                if(j >= nums[i-1]){// 放得下
                    dp[j] = dp[j]+dp[j-nums[i-1]];
                }else{
                    dp[j] = dp[j];
                }
            }
        }
        return dp[target];

    }
};
