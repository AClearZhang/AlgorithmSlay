/*
 * @FilePath            : \project\AlgorithmSlay\C++\DynamicProgram\122.BuySellStockBestTimeII.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-03-10 17:28:59
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-03-10 18:02:58
 * @Version             : 1.0
 * @Description         : k=init+ 无限次交易的最大收益
 * 122. 买卖股票的最佳时机 II
给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

 

示例 1:

输入: [7,1,5,3,6,4]
输出: 7
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
     随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6-3 = 3 。
示例 2:

输入: [1,2,3,4,5]
输出: 4
解释: 在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
     注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。
     因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
示例 3:

输入: [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
 

提示：

1 <= prices.length <= 3 * 10 ^ 4
0 <= prices[i] <= 10 ^ 4
 */
#include <iostream>
#include <cmath>
#include <windows.h>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    /**
     * @Description: 暴力递归 + memo备忘录
     * @param {*}
     * @return {*}
     * @notes: 
     */
    int maxProfit(vector<int>& prices) {
        vector<int> memo(prices.size(), -1); // 记录开始交易后 重叠记录的最大收益
        return dp(prices, 0, memo);
    }
    int dp(vector<int>& prices, int start, vector<int>& memo){  // 开始交易的时间
        // 边界
        int n = prices.size();
        if(start >= n) return 0;

        // memo
        if(memo[start] != -1) return memo[start];

        // 递归 开始
        int maxPro = 0;
        for(int i = start;i<n-1;i++){
            for(int j = i+1; j<n;j++){
                maxPro = max(maxPro, dp(prices, j+1, memo)+prices[j]-prices[i]);
            }
        }
        // 记录并返回
        memo[start] = maxPro;
        return maxPro;
    }
    /**
     * @Description: 方法二： 基于方法一 降低时间复杂度为线性。 || 方法一超出时间限制
     * @param {*}
     * @return {*}
     * @notes: 
     */
    int maxProfit(vector<int>& prices) {
        vector<int> memo(prices.size(), -1); // 记录开始交易后 重叠记录的最大收益
        return dp(prices, 0, memo);
    }
    int dp(vector<int>& prices, int start, vector<int>& memo){  // 开始交易的时间
        // 边界
        int n = prices.size();
        if(start >= n) return 0;

        // memo
        if(memo[start] != -1) return memo[start];

        // 递归 开始
        int maxPro = 0;
            // 优化：
        int curMin = prices[start];
        for(int i = start+1; i<n; i++){  // sell 到n
            curMin = min(curMin, prices[i]);
            maxPro = max(maxPro, dp(prices,i+1, memo)+prices[i]-curMin);
        }
        // for(int i = start;i<n-1;i++){
        //     for(int j = i+1; j<n;j++){
        //         maxPro = max(maxPro, dp(prices, j+1, memo)+prices[j]-prices[i]);
        //     }
        // }
        // 记录并返回
        memo[start] = maxPro;
        return maxPro;
    }
    /**
     * @Description: 通过方法 方法三：贪心算法 ——  股票无限次交易 能赚一点 是一点。
     * @param {*}
     * @return {*}
     * @notes: 
     */
    int maxProfit(vector<int>& prices) {
        int maxPro = 0;
        for(int i = 1; i<prices.size(); i++){
            if(prices[i]>prices[i-1]){
                maxPro += (prices[i]-prices[i-1]);
            }
        }
        return maxPro;
    }
    /**
     * @Description: 方法四: 动态规划 使用状态机。
     * @param {*}
     * @return {*}
     * @notes: 
     */
    int maxProfit(vector<int>& prices) {
        int maxPro = 0;
        for(int i = 1; i<prices.size(); i++){
            if(prices[i]>prices[i-1]){
                maxPro += (prices[i]-prices[i-1]);
            }
        }
        return maxPro;
    }
};
