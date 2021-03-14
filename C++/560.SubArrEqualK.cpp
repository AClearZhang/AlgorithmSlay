/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\560.SubArrEqualK.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-03-14 23:47:07
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-03-15 00:30:33
 * @Version             : 1.0
 * @Description         : 子数组的和为k
 * 560. 和为K的子数组
给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。

示例 1 :

输入:nums = [1,1,1], k = 2
输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。
说明 :

数组的长度为 [1, 20,000]。
数组中元素的范围是 [-1000, 1000] ，且整数 k 的范围是 [-1e7, 1e7]。
 */

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    /**
     * @Description: 前缀和 求子数组和。
     * @param {int} k
     * @return {*}
     * @notes: 暴力穷举  O(N^2)
     */
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        // 构造前缀和
        vector<int> sum(n+1, 0);
        
        for (int i = 0; i < n; i++)
            sum[i+1] = sum[i]+nums[i];

        int ans = 0;
        // 穷举所有子数组
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < i; j++)
                // sum of nums[j..i-1]
                if (sum[i] - sum[j] == k)
                    ans++;

        return ans;
    }
    /**
     * @Description: 方法二： 计算等式 sum[i] - k == sum[j]. //
     * @param {vector<int>} &nums
     * @param {int} k
     * @return {*}
     * @notes: 关键 使用hashmap 每次的后面j加和过程中，直接count 有几个[前缀和-k] 出现的次数。
     */
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        // 记录前缀和， 以及前缀和出现的次数。
        unordered_map<int, int> preSum;
        preSum[0] = 1;

        int ans = 0, sum0_i = 0;
        for(int i = 0; i<n ;i++){
            sum0_i += nums[i];

            int sum0_j = sum0_i - k;
            if(preSum.count(sum0_j)){
                ans+=preSum[sum0_j];
                // preSum[sum0_j] ++;
            }
            // else{ // 不存在 则加入
            //     preSum.emplace(sum0_i, 1);
            // }
            // 在不在都需要加1
            preSum[sum0_i]++;
        }
        return ans;
    }
};