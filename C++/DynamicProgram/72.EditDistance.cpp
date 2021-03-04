/*
 * @FilePath            : \project\AlgorithmSlay\C++\DynamicProgram\72.EditDistance.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-03-04 16:03:15
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-03-04 16:21:26
 * @Version             : 1.0
 * @Description         : 编辑距离
 * 72. 编辑距离
给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。

你可以对一个单词进行如下三种操作：

插入一个字符
删除一个字符
替换一个字符
 

示例 1：

输入：word1 = "horse", word2 = "ros"
输出：3
解释：
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')
示例 2：

输入：word1 = "intention", word2 = "execution"
输出：5
解释：
intention -> inention (删除 't')
inention -> enention (将 'i' 替换为 'e')
enention -> exention (将 'n' 替换为 'x')
exention -> exection (将 'n' 替换为 'c')
exection -> execution (插入 'u')
 

提示：

0 <= word1.length, word2.length <= 500
word1 和 word2 由小写英文字母组成
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
     * @Description: 最近的编辑距离
     * @param {string} word1
     * @param {string} word2
     * @return {int}  dp[i][j]  表示，word1[0-- i-1] word2[0-- j-1]的最近编辑距离。
     * @notes: 首先basecase等初始化好， 然后状态 选择 转移到目标位置。最后 要最后位置的dp。 
     */
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        // base case
        for(int i=1;i<=m;i++)  dp[i][0] = i;
        for(int j=1;j<=n;j++)  dp[0][j] = j;
        if(m == 0 || n == 0){
            return dp[m][n];
        }

        // 状态转移 开始
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                // 顺序遍历
                if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1]; // skip
                else{
                    dp[i][j] = min(dp[i-1][j]+1,
                    min(dp[i][j-1]+1, dp[i-1][j-1]+1));// 删除 插入  替换
                }
            }

        }
        return dp[m][n];
    }
};