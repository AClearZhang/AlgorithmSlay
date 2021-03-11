/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\DynamicProgram\188.BuySellStockBestTimeIV.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-03-11 12:11:42
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-03-11 12:33:44
 * @Version             : 1.0
 * @Description         : 买卖股票的最佳时期IV  k不限定
 * 188. 买卖股票的最佳时机 IV
给定一个整数数组 prices ，它的第 i 个元素 prices[i] 是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

 

示例 1：

输入：k = 2, prices = [2,4,1]
输出：2
解释：在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4-2 = 2 。
示例 2：

输入：k = 2, prices = [3,2,6,5,0,3]
输出：7
解释：在第 2 天 (股票价格 = 2) 的时候买入，在第 3 天 (股票价格 = 6) 的时候卖出, 这笔交易所能获得利润 = 6-2 = 4 。
     随后，在第 5 天 (股票价格 = 0) 的时候买入，在第 6 天 (股票价格 = 3) 的时候卖出, 这笔交易所能获得利润 = 3-0 = 3 。
 

提示：

0 <= k <= 100
0 <= prices.length <= 1000
0 <= prices[i] <= 1000 
 */

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

class Solution
{
public:
    /**
     * @Description: 状态机方法： 注意区别于前面k=2;这次k不限定。  结合 `k=2&k=+inf` 做本题。
     * @param {int} k
     * @param {vector<int>} &prices
     * @return {*}
     * @notes: 【关键】有个大问题：max_k太大容易 溢出！
     *              优化思考：买入和卖出交易次数最大为 `n/2`;所以
     */
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        if(n==0) return 0;
        
        int max_k = k;
        // 超出空间限制  k=inf+; 因为 k>=n/2 相当于无限次交易了！使用另一个 无限次交易的函数。
        if(k >= n/2){
            return maxProfitInf(prices);
        }
        // dp 数组
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(max_k + 1, vector<int>(2, 0)));

        // base
        // dp start
        for (int i = 0; i < n; i++)
        {

            for (int k1 = max_k; k1 >= 1; k1--) // 正反都可以，因为 主要是下面状态压缩怕正反 修改数值。
            {                                // cuo wu
                if (i - 1 == -1)
                {
                    dp[i][k1][0] = 0;
                    dp[i][k1][1] = -prices[i];
                    continue; // cuo
                }
                dp[i][k1][0] = max(dp[i - 1][k1][0], dp[i - 1][k1][1] + prices[i]);
                dp[i][k1][1] = max(dp[i - 1][k1][1], dp[i - 1][k1 - 1][0] - prices[i]);
            }
        }

        // return
        return dp[n - 1][max_k][0];
    }
    // helper——使用无限次交易的 状态机来帮助完成本题。
    int maxProfitInf(vector<int> &prices)
    {
        // int maxPro = 0;
        int dp_i_0 = 0, dp_i_1 = -prices[0];
        for (int i = 0; i < prices.size(); i++)
        {
            int temp = dp_i_0;
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]); // 上个状态更新了，下面有用了！
            dp_i_1 = max(dp_i_1, temp - prices[i]);
        }
        return dp_i_0;
    }
};
