/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\DynamicProgram\123.BuySellStockBestTimeIII.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-03-10 18:02:33
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-03-11 12:29:31
 * @Version             : 1.0
 * @Description         : 买卖股票最佳时间 最大利润。III。 添加限制 只能交易两次。
 * 123. 买卖股票的最佳时机 III
给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

 

示例 1:

输入：prices = [3,3,5,0,0,3,1,4]
输出：6
解释：在第 4 天（股票价格 = 0）的时候买入，在第 6 天（股票价格 = 3）的时候卖出，这笔交易所能获得利润 = 3-0 = 3 。
     随后，在第 7 天（股票价格 = 1）的时候买入，在第 8 天 （股票价格 = 4）的时候卖出，这笔交易所能获得利润 = 4-1 = 3 。
示例 2：

输入：prices = [1,2,3,4,5]
输出：4
解释：在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。   
     注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。   
     因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
示例 3：

输入：prices = [7,6,4,3,1] 
输出：0 
解释：在这个情况下, 没有交易完成, 所以最大利润为 0。
示例 4：

输入：prices = [1]
输出：0
 

提示：

1 <= prices.length <= 105
0 <= prices[i] <= 105
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
     * @Description: k=2  状态机—— 优化成模板！
     * @param {*}
     * @return {*} 注意理解： 返回的一定是k=2状态，因为 每个状态机都代表——
     *              当前状态下递推(递归似的)的既得收益！
     * @notes: 关键：状态机穷举所有状态 + 使用所有选择 更新。
     */
     int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int max_k = 2;
        // dp 数组
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(max_k + 1, vector<int>(2, 0)));

        // base
        // dp start
        for (int i = 0; i < n; i++)
        {

            for (int k = max_k; k >= 1; k--) // 正反都可以，因为 主要是下面状态压缩怕正反 修改数值。
            {                                // cuo wu
                if (i - 1 == -1)
                {
                    dp[i][k][0] = 0;
                    dp[i][k][1] = -prices[i];
                    continue; // cuo
                }
                dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i]);
                dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i]);
            }
        }

        // return
        return dp[n - 1][max_k][0];
    }
     /**
     * @Description: 方法二：状态机 压缩空间 —— 高效！！！
     * @param {*}
     * @return {*} 注意理解： 返回的一定是k=2状态，因为 每个状态机都代表——
     *              当前状态下递推(递归似的)的既得收益！
     * @notes: 关键：状态机穷举所有状态 + 使用所有选择 更新。
     */
     int maxProfit(vector<int> &prices)
     {
          int n = prices.size();
          int max_k = 2;

          // base
          // dp start
          int dp_1_0 = 0, dp_1_1 = -prices[0], dp_2_0 = 0, dp_2_1 = -prices[0];
          for (int i = 0; i < n; i++)
          {
               int temp1 = dp_1_0;
               dp_1_0 = max(dp_1_0, dp_1_1+prices[i]);
               dp_1_1 = max(dp_1_1, -prices[i]);
               dp_2_0 = max(dp_2_0, dp_2_1+prices[i]);
               dp_2_1 = max(dp_2_1, temp1-prices[i]);   // 主要是这里 k后到前 就不用temp1 新建了！
               // if (i - 1 == -1)
               // {
               //      dp[i][1][0] = 0;
               //      dp[i][1][1] = -prices[i];
               //      dp[i][2][0] = 0;
               //      dp[i][2][1] = -prices[i];
               //      continue; // cuo
               // }
               // for (int k = max_k; k >= 1; k--)
               // { // cuo wu

               //      dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i]);
               //      dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i]);
               // }
          }

          // return
          return dp_2_0;
     }
     // int maxProfit(vector<int>& prices){
     //     int n = prices.size();
     //     // dp 数组
     //     vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(2,0)));

     //     // base
     //     // dp start
     //     for(int i = 0; i<n ;i++){
     //        if(i-1 == -1) {
     //             dp[0][0][0] = 0;
     //             dp[0][0][1] = INT_MIN;
     //             dp[0][1][0] = 0;
     //             dp[0][1][1] = INT_MIN;
     //             // cuo
     //        }
     //        for(int k=0;k<2;k++){  // cuo wu
     //         dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1]+prices[i]);
     //         dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0]-prices[i]);
     //        }
     //     }

     //     // return
     //     return dp[n-1][2][0];
     // }
};
