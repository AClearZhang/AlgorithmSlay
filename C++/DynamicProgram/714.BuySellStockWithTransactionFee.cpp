/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\DynamicProgram\714.BuySellStockWithTransactionFee.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-03-11 13:02:32
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-03-11 13:18:44
 * @Version             : 1.0
 * @Description         : 买卖购票最佳收益。带有 手续费，无限次交易。
 * 714. 买卖股票的最佳时机含手续费
给定一个整数数组 prices，其中第 i 个元素代表了第 i 天的股票价格 ；非负整数 fee 代表了交易股票的手续费用。

你可以无限次地完成交易，但是你每笔交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。

返回获得利润的最大值。

注意：这里的一笔交易指买入持有并卖出股票的整个过程，每笔交易你只需要为支付一次手续费。

示例 1:

输入: prices = [1, 3, 2, 8, 4, 9], fee = 2
输出: 8
解释: 能够达到的最大利润:  
在此处买入 prices[0] = 1
在此处卖出 prices[3] = 8
在此处买入 prices[4] = 4
在此处卖出 prices[5] = 9
总利润: ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
注意:

0 < prices.length <= 50000.
0 < prices[i] < 50000.
0 <= fee < 50000.
 */

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;


class Solution {
public:
    /**
     * @Description: 状态机：带有手续费的 股票交易的 无限次交易。
     * @param {int} fee
     * @return {*}
     * @notes: 关键：在买入或卖出的时候 支付手续费。这里在 买入的时候k-1 时同时减去 手续费用。
     *                      相应的 basecase 也要减去 fee!!!
     */
    int maxProfit(vector<int>& prices, int fee) {
        if(prices.size() == 0) return 0;

        int dp_i_0=0, dp_i_1 = -prices[0]-fee;
        // int dp_i2_0 = 0;
        for(int i = 0; i<prices.size(); i++){
            // 记录上上个状态
            int temp1 = dp_i_0;
            dp_i_0 = max(dp_i_0, dp_i_1+prices[i]);  // 上个状态更新了，下面有用了！
            dp_i_1 = max(dp_i_1, temp1-prices[i]-fee);  // dp[i-2][0]
            // dp_i2_0 = temp1;
        }
        return dp_i_0;
    }
    /**
     * @Description: 状态机：带有手续费的 股票交易的 无限次交易。
     * @param {int} fee
     * @return {*}
     * @notes: 关键：在买入或卖出的时候 支付手续费。买入的时候k-1 时同时减去 手续费用。
     *                      相应的 basecase 也要减去 fee!!!
     *          
     *          这里在卖出的时候 减去手续费，所以买入的 basecase  不用减去fee！！！
     */
    int maxProfit(vector<int>& prices, int fee) {
        if(prices.size() == 0) return 0;

        int dp_i_0=0, dp_i_1 = -prices[0];  //【不同
        // int dp_i2_0 = 0;
        for(int i = 0; i<prices.size(); i++){
            // 记录上上个状态
            int temp1 = dp_i_0;
            dp_i_0 = max(dp_i_0, dp_i_1+prices[i]-fee); //【不同 // 上个状态更新了，下面有用了！
            dp_i_1 = max(dp_i_1, temp1-prices[i]);  //【不同   // dp[i-2][0]
            // dp_i2_0 = temp1;
        }
        return dp_i_0;
    }
};
