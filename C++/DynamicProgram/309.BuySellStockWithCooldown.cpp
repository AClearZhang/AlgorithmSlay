/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\DynamicProgram\309.BuySellStockWithCooldown.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-03-11 12:34:44
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-03-11 12:57:32
 * @Version             : 1.0
 * @Description         : 带有冷静期的 无限次交易的最大收益。
 * 309. 最佳买卖股票时机含冷冻期
给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。​

设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:

你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
示例:

输入: [1,2,3,0,2]
输出: 3 
解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]
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
     * @Description: 状态机+压缩空间： 带有冷静期 1天。
     * @param {*}
     * @return {*}
     * @notes: 关键：卖出后 冷静期1天才能买。
     */
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;

        int dp_i_0=0, dp_i_1 = -prices[0];
        int dp_i2_0 = 0;
        for(int i = 0; i<prices.size(); i++){
            // 记录上上个状态
            int temp1 = dp_i_0;
            dp_i_0 = max(dp_i_0, dp_i_1+prices[i]);  // 上个状态更新了，下面有用了！
            dp_i_1 = max(dp_i_1, dp_i2_0-prices[i]);  // dp[i-2][0]
            dp_i2_0 = temp1;
        }
        return dp_i_0;
    }
};
