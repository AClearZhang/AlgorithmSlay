/*
 * @FilePath            : \project\AlgorithmSlay\C++\DynamicProgram\516.LongestPalindromeSSeq.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-03-04 17:06:49
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-03-04 17:24:10
 * @Version             : 1.0
 * @Description         : 最长回文子序列
 * 516. 最长回文子序列
给定一个字符串 s ，找到其中最长的回文子序列，并返回该序列的长度。可以假设 s 的最大长度为 1000 。

 

示例 1:
输入:

"bbbab"
输出:

4
一个可能的最长回文子序列为 "bbbb"。

示例 2:
输入:

"cbbd"
输出:

2
一个可能的最长回文子序列为 "bb"。

 

提示：

1 <= s.length <= 1000
s 只包含小写英文字母
 */

// 此题比较特殊——用两个数组 做一个数组的子序列回文串问题

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
     * @Description: 
     * @param {string} s
     * @return {*}返回 dp[0][n-1]
     * @notes: 首先basecase 下三角0/1; 然后 目标为右上角；最后 状态转移方程为 == +2; else: 找 max(i,j-1  i+1,j )
     * dp[n][n] 表示由dp[i+1][j-1] 退出dp[i][j] 回文长度。
     */
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        if( n==0 || n==1) return n==0?0:1;
        // base case + init
        vector<vector<int>> dp(n, vector<int>(n,0));
            // dui jiao
        for(int i=0;i<n;i++)  dp[i][i] = 1;

        // start
        for(int i = n-2;i>=0;i--){
            for(int j = i+1;j<n;j++){
                //状态转移方程
                if(s[i] == s[j])  dp[i][j] = dp[i+1][j-1]+2;
                else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];
    }
};

