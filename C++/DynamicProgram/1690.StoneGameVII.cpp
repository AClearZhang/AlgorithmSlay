/*
 * @FilePath            : \project\AlgorithmSlay\C++\DynamicProgram\1690.StoneGameVII.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-03-10 15:13:35
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-03-10 16:53:56
 * @Version             : 1.0
 * @Description         : 石头游戏 七 。只有这个动态规划了。
 *1690. 石子游戏 VII
石子游戏中，爱丽丝和鲍勃轮流进行自己的回合，爱丽丝先开始 。

有 n 块石子排成一排。每个玩家的回合中，可以从行中 移除 最左边的石头或最右边的石头，并获得与该行中剩余石头值之 和 相等的得分。当没有石头可移除时，得分较高者获胜。

鲍勃发现他总是输掉游戏（可怜的鲍勃，他总是输），所以他决定尽力 减小得分的差值 。爱丽丝的目标是最大限度地 扩大得分的差值 。

给你一个整数数组 stones ，其中 stones[i] 表示 从左边开始 的第 i 个石头的值，如果爱丽丝和鲍勃都 发挥出最佳水平 ，请返回他们 得分的差值 。

 

示例 1：

输入：stones = [5,3,1,4,2]
输出：6
解释：
- 爱丽丝移除 2 ，得分 5 + 3 + 1 + 4 = 13 。游戏情况：爱丽丝 = 13 ，鲍勃 = 0 ，石子 = [5,3,1,4] 。
- 鲍勃移除 5 ，得分 3 + 1 + 4 = 8 。游戏情况：爱丽丝 = 13 ，鲍勃 = 8 ，石子 = [3,1,4] 。
- 爱丽丝移除 3 ，得分 1 + 4 = 5 。游戏情况：爱丽丝 = 18 ，鲍勃 = 8 ，石子 = [1,4] 。
- 鲍勃移除 1 ，得分 4 。游戏情况：爱丽丝 = 18 ，鲍勃 = 12 ，石子 = [4] 。
- 爱丽丝移除 4 ，得分 0 。游戏情况：爱丽丝 = 18 ，鲍勃 = 12 ，石子 = [] 。
得分的差值 18 - 12 = 6 。
示例 2：

输入：stones = [7,90,5,1,100,10,10,2]
输出：122
 
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
     * @Description: 去除一个 剩下所有为获得的分值。
     * @param {*}
     * @return {*}
     * @notes: 
     */
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        if(n == 0) return 0;
        vector<vector<int>> dp(n, vector<int>(n,0));

        vector<int> sums(n+1, 0); // 之前的所有数之和 包含自身

        // 涉及到sums[-1] 所以前移动一位
        sums[0] = 0;
        for(int i = 1;i < n+1;++i)
            sums[i] = sums[i-1] + stones[i-1];
        for(int i = dp.size() - 2;i >= 0;--i){
            for(int j = i + 1;j < dp[i].size();++j){
                // 博弈 —— 每次选取当前能要的最大的。每个人！ i……j
                dp[i][j] = max(sums[j+1] - sums[i+1] - dp[i + 1][j], sums[j] - sums[i] - dp[i][j - 1]);
            }
        }
        return dp[0][n-1];
    }


    /**
     * @Description: 另一个问题解法：每次挑一个作为自己分值：石子游戏。关键在于 dp定义为两个角色  先后手堆的选择/模拟。
     * @param {*}
     * @return {*}
     * @notes: 
     */
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        if(n == 0) return 0;
            // 表示从i到j 先后手(fir, sec)选择获得的最大分值
        vector<vector<pair<int,int>>> dp(n, vector<pair<int,int>>(n, make_pair(0,0)));
        // base
        for(int i = 0;i<n;i++){
            dp[i][i].first = stones[i];
        }

        //dp start 目标：倾斜 dp[0][n-1]
        for(int num = n-2;num>=0;num--){
            for(int i = 0;i<n;i++){
                int j = n-num+i-1;
                // zhuanyi
                    // first
                int left = stones[i]+dp[i+1][j].second, right = stones[j]+dp[i][j-1].second;
                dp[i][j].first = max(left, right);
                if(left>=right){
                    dp[i][j].second = dp[i+1][j].first;
                }else{
                    dp[i][j].second = dp[i][j-1].first;
                }

            }
        }
        // 返回差值
        return dp[0][n-1].first-dp[0][n-1].second;
    }   
};