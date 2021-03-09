/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\DynamicProgram\45.JumpGameII.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-03-08 23:32:51
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-03-09 13:58:10
 * @Version             : 1.0
 * @Description         : 贪婪 + DP —— 跳跃游戏II
 * 45. 跳跃游戏 II
给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

你的目标是使用最少的跳跃次数到达数组的最后一个位置。

示例:

输入: [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
 */

#include <iostream>
#include <cmath>
#include <windows.h>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    /**
     * @Description: 贪心算法！  每次爬最远找 最优的可能 跳数。
     * @param {*}
     * @return {*}
     * @notes: 关键：贪婪(手动做题似的) 多试几个用例 —— 每次找最有可能、有最大潜能的部分。往下走。！O(n)完成！
     */
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 || n == 1) return 0;
        if(n == 2) return 1;
        int count = 0, end = 0;
        int farest = 0;
        for(int i = 0;i<n-1;i++){ // n-1!!! 【出错 gai 关键！！！】
            farest = max(farest, i+nums[i]);
            if(i == end){
                count++;
                end = farest;
            }
        }
        return count;
    }
    /**
     * @Description: 关键：了解了递归(每个地方都可以做，可以暴力穷举 + memo)
     * @param {*}
     * @return {*}
     * @notes: 动规+贪婪后； 可以每次找最大的去做。
     */
    int jump1(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 || n == 1) return 0;
        if(n == 2) return 1;
            // memo
        vector<int> memo(n, -1);
        return dp(nums, 0, memo);

    }
    // 辅助函数——递归穷举 由p开始到最后位置的最小 跳跃次数。
    int dp(vector<int>& nums, int p, vector<int>& memo){
        // base
        if(p >= (nums.size()-1)) return 0; // gai  边界！超出！
        if(p == (nums.size()-2)) return 1;

        // 如果 重复，则返回备忘录
        if(memo[p]!=-1) return memo[p];

        // 穷举--从前到后所有位置 跳跃次数的最小值。
        int jumpMin = nums.size();
        for(int i = p+1; i <= p+nums[p] ;i++){ // nums[p] == 0?
            jumpMin = min(jumpMin, dp(nums, i, memo)+1);
        }
        memo[p] = jumpMin;
        return jumpMin;
    }
    /**
     * @Description: 但是上述 递归穷举 + 备忘录，超出时间限制了。所以 添加贪婪，每次区取最大的步数去跳跃。
     * @param {*}  这个错了！！！看下一个 贪婪算法。
     * @return {*}
     * @notes: 
     */
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 || n == 1) return 0;
        if(n == 2) return 1;
           
        return dp(nums, 0);

    }
    // 辅助函数——递归穷举 由p开始到最后位置的最小 跳跃次数。
    int dp(vector<int>& nums, int p){
        // base
        if(p >= (nums.size()-1)) return 0; // gai  边界！超出！
        if(p == (nums.size()-2)) return 1;
        // [2,3,1,1,4] 寻找当前所能达到的 位置最大下一跳的探索步数。
        pair<int, int> jumpPoint(0,0);
        for(int i = p+1; i <= p+nums[p] ;i++){ // nums[p] == 0?
            jumpPoint = (nums[i] >= jumpPoint.second)? make_pair(i, nums[i]):jumpPoint;
            if(i == nums.size()-1) return 1; // 一跳就能到达末尾
        }
        // 贪婪tan 最大
        if(nums[p] >= jumpPoint.second) return 1+dp(nums, p+nums[p]);

        return 1+dp(nums, jumpPoint.first);
        // [4,1,1,3,1,1,1] 涵盖区间最大？
    }
    
};
