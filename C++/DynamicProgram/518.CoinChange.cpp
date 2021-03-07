/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\DynamicProgram\518.CoinChange.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-03-07 17:41:00
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-03-07 18:33:12
 * @Version             : 1.0
 * @Description         : 零钱兑换2
 * 518. 零钱兑换 II
给定不同面额的硬币和一个总金额。写出函数来计算可以凑成总金额的硬币组合数。假设每一种面额的硬币有无限个。 

 

示例 1:

输入: amount = 5, coins = [1, 2, 5]
输出: 4
解释: 有四种方式可以凑成总金额:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
示例 2:

输入: amount = 3, coins = [2]
输出: 0
解释: 只用面额2的硬币不能凑成总金额3。
示例 3:

输入: amount = 10, coins = [10] 
输出: 1
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
     * @Description: 完全背包问题 —— 可以无限次运用 一个有价值的物品/或者硬币。
     * @param {int} amount
     * @return {*}
     * @notes: 
     */
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // base
        vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));
            // amount=0  dp=1
        for(int i = 0;i<n+1;i++){
            dp[i][0] = 1;
        }

        // dp start
        for(int i = 1;i<n+1;i++){
            for(int j = 1;j<amount+1;j++){
                if( j-coins[i-1]>=0 ){  // 错误1  >0
                    // 可装可不装
                    dp[i][j] = dp[i-1][j] 
                                + dp[i][j-coins[i-1]];  // 不装； 装
                                //// 错误2 [i-1][]
                }else{
                    // 装不进去 不装
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][amount];
    }
};
