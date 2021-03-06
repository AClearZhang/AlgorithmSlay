/*
 * @FilePath            : \project\AlgorithmSlay\C++\DynamicProgram\10.RegularExpreMatching.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-03-05 18:12:00
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-03-06 13:13:16
 * @Version             : 1.0
 * @Description         : 正则表达式匹配 —— DP方法
 * 10. 正则表达式匹配
给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素
所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。

 
示例 1：

输入：s = "aa" p = "a"
输出：false
解释："a" 无法匹配 "aa" 整个字符串。
示例 2:

输入：s = "aa" p = "a*"
输出：true
解释：因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
示例 3：

输入：s = "ab" p = ".*"
输出：true
解释：".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
示例 4：

输入：s = "aab" p = "c*a*b"
输出：true
解释：因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。
示例 5：

输入：s = "mississippi" p = "mis*is*p*."
输出：false
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
     * @Description: 
     * @param {string} s
     * @param {string} p
     * @return {*}
     * @notes:> 关键点：这里只设置 `True`.
> 1. 因为DP自底向上，所以要从后向前  分情况讨论 `*`. 且 False初始化了，不用想不等于。
> 2. 匹配如何匹配 `*`的多个前面字符？满足 三种情况即可。【多个，单个，无。】

     */
    bool isMatch(string s, string p) {
		int m=s.size(), n=p.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));

		// base
		dp[0][0] = true;
            // important dp[0][...]
			// 重点新增 dp[0]的初始化！！！ 注意！！！
        for(int i = 1;i<=n;i++){
            if(p[i-1]=='*' && i>=2){
                dp[0][i] = dp[0][i-2];
            }
        }
		// start dp
		for(int i = 1;i<=m;i++){
			for(int j = 1; j<=n ;j++){
				if(s[i-1] == p[j-1] || p[j-1]=='.'){
					dp[i][j] = dp[i-1][j-1];
				}else if(p[j-1]=='*'){
					if(p[j-2] != s[i-1] && p[j-2]!='.')  dp[i][j] = dp[i][j-2];
					else{// if(p[j-2]==s[i-1]||p[j-2]=='.')
						dp[i][j] = (dp[i][j-1]||dp[i-1][j]||dp[i][j-2]);
					}
				}
			}
		}
		return dp[m][n];
    }


    
};


// /**
//  * @Description: 其它老哥在 leetcode上的代码
//  * @param {*}
//  * @return {*}
//  * @notes: 
//  */
// class Solution {
//     public boolean isMatch(String s, String p) {
//         int sLen = s.length(), pLen = p.length();
// 		boolean[][] memory = new boolean[sLen+1][pLen+1];
// 		memory[0][0] = true;
// 		for(int i = 0; i <= sLen; i++) {
// 			for(int j = 1; j <= pLen; j++) {
// 				if(p.charAt(j-1) == '*') {
// 					memory[i][j] = memory[i][j-2] || (i > 0 && (s.charAt(i-1) == p.charAt(j-2) || 
// 							p.charAt(j-2) == '.') && memory[i-1][j]);
// 				}else {
// 					memory[i][j] = i > 0 && (s.charAt(i-1) == p.charAt(j-1) || p.charAt(j-1) == '.')
// 									&& memory[i-1][j-1];
// 				}
// 			}
// 		}
// 		return memory[sLen][pLen];
//     }
// }
// // 在上面方法的基础上，由于每次都只使用了memory表中相邻的两行，因此可以进一步降低代码的空间复杂度如下:

// class Solution {
//     public boolean isMatch(String s, String p) {
//         int sLen = s.length(), pLen = p.length();
// 		boolean[][] memory = new boolean[2][pLen+1];
// 		memory[0][0] = true;
// 		int cur = 0, pre = 0;
// 		for(int i = 0; i <= sLen; i++) {
// 			cur = i % 2;
// 			pre = (i + 1) % 2;
// 			if(i > 1) {
// 				for(int j = 0; j <= pLen; j++) {
// 					memory[cur][j] = false;
// 				}
// 			}
// 			for(int j = 1; j <= pLen; j++) {
// 				if(p.charAt(j-1) == '*') {
					
// 					memory[cur][j] = memory[cur][j-2] || (i > 0 && (s.charAt(i-1) == p.charAt(j-2) || 
// 							p.charAt(j-2) == '.') && memory[pre][j]);
// 				}else {
// 					memory[cur][j] = i > 0 && (s.charAt(i-1) == p.charAt(j-1) || p.charAt(j-1) == '.')
// 									&& memory[pre][j-1];
// 				}
// 			}
// 		}
// 		return memory[cur][pLen];
//     }
// }