/*
 * @FilePath            : \project\AlgorithmSlay\C++\DynamicProgram\1312.MinInsertToPalindrome.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-03-04 20:52:03
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-03-04 21:58:22
 * @Version             : 1.0
 * @Description         : 成为回文字符串的最少插入次数
 * 1312. 让字符串成为回文串的最少插入次数
给你一个字符串 s ，每一次操作你都可以在字符串的任意位置插入任意字符。

请你返回让 s 成为回文串的 最少操作次数 。

「回文串」是正读和反读都相同的字符串。

 

示例 1：

输入：s = "zzazz"
输出：0
解释：字符串 "zzazz" 已经是回文串了，所以不需要做任何插入操作。
示例 2：

输入：s = "mbadm"
输出：2
解释：字符串可变为 "mbdadbm" 或者 "mdbabdm" 。
示例 3：

输入：s = "leetcode"
输出：5
解释：插入 5 个字符后字符串变为 "leetcodocteel" 。
示例 4：

输入：s = "g"
输出：0
示例 5：

输入：s = "no"
输出：1
 

提示：

1 <= s.length <= 500
s 中所有字符都是小写字母。
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
     * @Description: 构造回文串的最少插入次数
     * @param {string} s
     * @return {*}
     * @notes: 类似于 516最长回文子串的求法
     */
    int minInsertions(string s) {
        int n = s.size();
        if( n==0 || n==1) return 0;
        // base case + init
        vector<vector<int>> dp(n, vector<int>(n,0));
            // dui jiao
        // for(int i=0;i<n;i++)  dp[i][i] = 0;

        // start
        for(int i = n-2;i>=0;i--){
            for(int j = i+1;j<n;j++){
                //状态转移方程
                if(s[i] == s[j])  dp[i][j] = dp[i+1][j-1];
                else{
                    dp[i][j] = min(dp[i+1][j], dp[i][j-1])+1;
                }
            }
        }
        return dp[0][n-1];    
    }
    int minInsertions2(string s) {
        int n = s.size();
        if( n==0 || n==1) return 0;
        // base case + init
        vector<int> dp(n, 0);

        // start
        for(int i = n-2;i>=0;i--){
            int pre = 0;
            for(int j = i+1;j<n;j++){
                int temp = dp[j];
                //状态转移方程
                if(s[i] == s[j])  dp[j] = pre;
                else{
                    dp[j] = min(dp[j], dp[j-1])+1;
                }
                pre = temp;
            }
        }
        return dp[n-1];
    }
};

