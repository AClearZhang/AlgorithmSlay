/*
 * @FilePath            : \project\AlgorithmSlay\C++\DynamicProgram\712.MinAsciiDeleSum.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-03-05 12:25:15
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-03-05 17:14:15
 * @Version             : 1.0
 * @Description         : 最小 ASCII 删除和
 * 712. 两个字符串的最小ASCII删除和
给定两个字符串s1, s2，找到使两个字符串相等所需删除字符的ASCII值的最小和。

示例 1:

输入: s1 = "sea", s2 = "eat"
输出: 231
解释: 在 "sea" 中删除 "s" 并将 "s" 的值(115)加入总和。
在 "eat" 中删除 "t" 并将 116 加入总和。
结束时，两个字符串相等，115 + 116 = 231 就是符合条件的最小和。
示例 2:

输入: s1 = "delete", s2 = "leet"
输出: 403
解释: 在 "delete" 中删除 "dee" 字符串变成 "let"，
将 100[d]+101[e]+101[e] 加入总和。在 "leet" 中删除 "e" 将 101[e] 加入总和。
结束时，两个字符串都等于 "let"，结果即为 100+101+101+101 = 403 。
如果改为将两个字符串转换为 "lee" 或 "eet"，我们会得到 433 或 417 的结果，比答案更大。
注意:

0 < s1.length, s2.length <= 1000。
所有字符串中的字符ASCII值在[97, 122]之间。
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
     * @Description: 两种解法——①前到后的 DP ②后到前的 递归+备忘录 
     * @param {string} s1
     * @param {string} s2
     * @return {*}
     * @notes: dp[i][j] 表示s1[..--i-1] s2[..--j-1]构成ASCII码的最小值
     *          关键：稍加修改 lcs的
     */
    int minimumDeleteSum(string s1, string s2) {
        int res = 0; //ascii mini value
        int m=s1.size(),n=s2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));   
        //base 
        for(int i=1;i<=m;i++){
            res += (int)s1[i-1];
            dp[i][0] = res;
        }
        res = 0;
        for(int j=1;j<=n;j++){
            res += (int)s2[j-1];
            dp[0][j] = res;
        }

        // 开始扫描，状态转移方程
        // dp[i][j]  表示 s1[0- i-1]   s2[0- j-1] 为止有多少公共子序列
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1] == s2[j-1])  dp[i][j] = dp[i-1][j-1];
                else{  // 不相等，说明至少有一个不在lcs中， 取最小的 ASCII码
                    dp[i][j] = min(dp[i-1][j]+(int)s1[i-1], 
                    min(dp[i][j-1]+(int)s2[j-1], dp[i-1][j-1]+(int)s1[i-1]+s2[j-1]));
                }
            }
        }
        // 最后返回 最大的
        return dp[m][n];

    }
};