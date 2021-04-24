/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\152.MaxProductSubarray.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-04-24 19:44:22
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-04-24 22:11:27
 * @Version             : 1.0
 * @Description         : 乘积最大子数组
 * 152. 乘积最大子数组
难度
中等

1064

收藏

分享
切换为英文
接收动态
反馈
给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。

 

示例 1:

输入: [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。
示例 2:

输入: [-2,0,-1]
输出: 0
解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
 */
#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <map>
#include <vector>

using namespace std;


#define For(x,y,z) for(ll x = y; x < z;++x)
typedef long long ll;


class Solution {
public:
    /**
     * @Description: 最大乘积 有负数，所以可以记录最大和最小值。
     * @param {*}
     * @return {*}
     * @notes: 
     */
    int maxProduct(vector<int>& nums) {
        int min_num = 1, max_num = 1;  // 代表 以 nums[i-1]为结尾的最小和最大的值
        int maxNow = INT_MIN;
        For(i, 0, nums.size()){
            if(nums[i] < 0) {
                // 最大最小互换
                int tmp = min_num;
                min_num = max_num;
                max_num = tmp;
            }
            
            min_num = min( min_num*nums[i], nums[i]);
            max_num = max( max_num*nums[i], nums[i]);  // 要么自己开始，要么和之前一样开始。

            maxNow = max_num>maxNow?max_num:maxNow;
        }
        return maxNow;
    }
};


class Solution {
public:
    /**
     * @Description: 动态规划  表示numsi 为结尾的最大子数组乘积。
     * @param {*}
     * @return {*}
     * @notes: 不对！！！！  [-2,3-4]
     */
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
    
        vector<int> dp(n, INT_MIN);
        dp[0] = nums[0];
        int maxNow = dp[0];
        For(i, 1, n){
            dp[i] = max(dp[i-1]*nums[i], nums[i]);
            maxNow = dp[i]>maxNow ?dp[i]:maxNow;
        }
        return maxNow;
    }
};
