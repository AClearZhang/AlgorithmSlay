/*
 * @FilePath            : \project\AlgorithmSlay\C++\DynamicProgram\121.BuySellStockBestTime.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-03-10 16:55:40
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-03-10 17:19:46
 * @Version             : 1.0
 * @Description         : 买卖股票的最佳时期
 * 121. 买卖股票的最佳时机
给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。

你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。

返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。

 

示例 1：

输入：[7,1,5,3,6,4]
输出：5
解释：在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。
示例 2：

输入：prices = [7,6,4,3,1]
输出：0
解释：在这种情况下, 没有交易完成, 所以最大利润为 0。
 

提示：

1 <= prices.length <= 105
0 <= prices[i] <= 104
通过次数384,869提交次数684,619
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
     * @Description: 方法一 暴力解决。
     * @param {*}
     * @return {*}
     * @notes: 
     */
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxPro = 0;
        for(int i = 0; i<n-1 ;i++){
            for(int j = i+1;j<n;j++){
                //i买入 j卖出
                maxPro = max(maxPro, prices[j]-prices[i]);
            }
        }
        return maxPro;
    }
    /**
     * @Description: 方法二 固定卖出，找最小的买入价格。
     * @param {*}
     * @return {*}
     * @notes: Key：因为 关键不在于最大值还是最小值，而是数字的添加和减少。
     * 添加新数时，可以根据已有最值，推导出新的最值；而减少数字时，不一定能直接推出新的最值，不得不重新遍历。
     * 
     * 所以 为了递推 且 减少冗余的循环使用了 固定卖出天数，找最小值去递推。
     */
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minSell = prices[0], maxPro = 0;
        for(int i = 1; i<n ;i++){   // 固定卖出，递归买入时间。
            if(prices[i]<minSell){ minSell = prices[i]; }
            
            maxPro = max(maxPro, prices[i]-minSell);
        }
        return maxPro;
    }
};