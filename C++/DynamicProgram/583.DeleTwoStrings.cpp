/*
 * @FilePath            : \project\AlgorithmSlay\C++\DynamicProgram\583.DeleTwoStrings.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-03-05 12:22:40
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-03-05 12:47:04
 * @Version             : 1.0
 * @Description         : 两个字符串删除使相同的 最小步数
 * 583. 两个字符串的删除操作
给定两个单词 word1 和 word2，找到使得 word1 和 word2 相同所需的最小步数，每步可以删除任意一个字符串中的一个字符。

 

示例：

输入: "sea", "eat"
输出: 2
解释: 第一步将"sea"变为"ea"，第二步将"eat"变为"ea"
 

提示：

给定单词的长度不超过500。
给定单词中的字符只含有小写字母。
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
     * @Description: 删除到相等——即 公共子序列(lcs).且最大LCS  为需要删除的个数。
     * @param {string} word1
     * @param {string} word2
     * @return {*}
     * @notes: 
     */
    int minDistance(string word1, string word2) {
        int m=word1.size(), n=word2.size();
        int len = longestCommonSubsequence(word1, word2);
        return m-len+n-len;
    }

    // 借助1143 LCS的函数来做。
    /**
     * @Description: 最大公共子序列——子序列问题。
     * @param {string} text1
     * @param {string} text2
     * @return {返回 最大公共子序列的个数}
     * @notes: 
     */
    int longestCommonSubsequence(string text1, string text2) {
        // base 
        int m = text1.size(), n = text2.size();
        if(m == 0 || n == 0){
            return 0;
        }
            // base case 0 0 置为0
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        // 开始扫描，状态转移方程
        // dp[i][j]  表示 text1[0- i-1]   text2[0- j-1] 为止有多少公共子序列
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(text1[i-1] == text2[j-1])  dp[i][j] = 1+dp[i-1][j-1];
                else{  // 不相等，说明至少有一个不在lcs中， 取最大数
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        // 最后返回 最大的
        return dp[m][n];
    }
};

