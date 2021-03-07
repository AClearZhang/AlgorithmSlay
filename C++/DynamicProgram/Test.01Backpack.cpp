/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\DynamicProgram\Test.01Backpack.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-03-07 14:08:00
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-03-07 15:00:32
 * @Version             : 1.0
 * @Description         : 0-1 背包问题：01 是指不能将物品按照价值和重量分开，只能一股脑放进去；找到最大的装载 价值。
 * 
 */

#include <iostream>
#include <cmath>
#include <windows.h>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;


class Solution{
public:
    /**
     * @Description: dong's Solution：DP定义:dp[i][w]:前i个背包 承重w，所能获得的最大价值。
     * @param {int} W
     * @param {int} N
     * @param {vector<int>} &wt
     * @return {*}
     * @notes: 
     */
    int knapsack(int W, int N, vector<int>& wt, vector<int>& val){
        // base
        vector<vector<int>> dp(N+1, vector<int>(W+1, 0));

        for(int i = 1; i <= N ;i++){
            for(int w = 1; w <= W ;w++){
                // 放入与不放入两个类别；但是 要防止装不进去
                if(w - wt[i-1] < 0){
                    // 放不进去
                    dp[i][w] = dp[i-1][w];
                }else{
                    // 可以放进去，但是看放不放找最大 价值
                    dp[i][w] = max(dp[i-1][w],
                                dp[i-1][w-wt[i-1]]+val[i-1]);
                }


            }
        }
        return dp[N][W];
    }
    /**
     * @Description: 我的解法DP对应不同的定义：dp[i][j]: 在限定条件下  i--j所能承载的最大价值。
     * @param {int} W
     * @param {int} N
     * @return {*}
     * @notes:  关键要限定好重量 别超载；（ 其次数量N已经限定了, 且题目说是N个物品 都可以遍历到。）
     */
    int knapsack(int W, int N, vector<int>& wt, vector<int>& val){
        // init
            // first 重量，second 价值
        vector<vector<pair<int, int>>> dp(N, vector<pair<int, int>>(N, pair<int,int>(0,0)));
            // base: i == j时 价值为不超重的本身
            // 且 遍历只遍历上三角
        for(int i = 0; i < N ;i++){
            if(wt[i] <= W){
                // 未超载
                dp[i][i].first = wt[i];
                dp[i][i].second = val[i];
            }
        }

        // dp start: 下到上 左到右
        for(int i = N-2; i >= 0 ;i--){
            for(int j = i+1; j < N ;j++){
               // 控制 wt不超载
                // i+1,j-1 归纳i,j
               if(wt[i]+wt[j]+dp[i+1][j-1].first <= W){
                   dp[i][j].first = dp[i+1][j-1].first + wt[i] + wt[j];
                   dp[i][j].second = dp[i+1][j-1].second + val[i] + val[j];
               }else
               {    // 超载，取两者最大价值的一个。
                    dp[i][j] = dp[i][j-1].second> dp[i+1][j].second ?dp[i][j-1]:dp[i+1][j];
               }
            }
        }
        return dp[N][W].second;
    }
};




