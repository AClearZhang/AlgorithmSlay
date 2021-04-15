/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\TwiceTimes\72.EditDistrance.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-04-15 14:45:39
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-04-15 15:29:53
 * @Version             : 1.0
 * @Description         : 编辑距离 二刷
 * 
 */
#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;


#define For(x,y,z) for(int x = y; x < z;++x)


class Solution {
public:
    /**
     * @Description: 当前i,j的最短编辑距离【明确相信 都是相等的】，base 0--i
     * @param {string} word1
     * @param {string} word2
     * @return {*}【状态之间的 联系】
     * @notes: 状态转移方程：当字符相同时 跳过； 当字符不同时：三种操作  删除s1(i-1)/j 相匹配；插入s1使得i+1与j匹配 (i与j-1匹配)；替换使得 i-1和j-1 匹配.
     */
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, m));
        // base case
        For(i,0,n+1){
            dp[i][0] = i;
        }
        For(j,0,m+1){
            dp[0][j] = j;
        }
        
        // 状态转移
        For(i, 1, n+1){
            For(j, 1, m+1){
                if(word1[i-1] == word2[j-1]){
                    // skip
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = min(
                        dp[i-1][j-1]+1,
                        min(dp[i-1][j]+1, dp[i][j-1]+1)
                    );
                }
            }
        }

        return dp[n][m];
    }
};