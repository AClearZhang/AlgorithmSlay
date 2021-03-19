/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\5.LongestPalindromeSubStr.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-03-18 22:48:50
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-03-19 20:40:44
 * @Version             : 1.0
 * @Description         : 最长回文子串
 * 5. 最长回文子串
给你一个字符串 s，找到 s 中最长的回文子串。

 

示例 1：

输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案。
示例 2：

输入：s = "cbbd"
输出："bb"
示例 3：

输入：s = "a"
输出："a"
示例 4：

输入：s = "ac"
输出："a"
 

提示：

1 <= s.length <= 1000
s 仅由数字和英文字母（大写和/或小写）组成
 */

#include <algorithm>
#include <cmath>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    /**
     * @Description:  关键是——回文寻找核心思想：从中间 向两边寻找回文字符串。   使用双指针。
     * @param {string} s
     * @return {*}
     * @notes: 
     */
    string longestPalindrome(string s)
    {
        if (s.size() == 1)
            return s;
        string res = "";
        for (int i = 0; i < s.size(); i++)
        {
            string jString = findPalindrome(s, i, i);
            string oString = findPalindrome(s, i, i + 1);
            jString = jString.size() > oString.size() ? jString : oString;
            if (jString.size() > res.size())
            {
                res = jString;
            }
        }
        return res;
    }
    // 辅助函数 返回当前从中到两边的，所得到的最长回文子串。
    // l和r也不一定相等！注意！
    string findPalindrome(string s, int l, int r)
    {
        while (l >= 0 && r <= s.size() - 1 && s[l] == s[r])
        {
            l--;
            r++;
        }
        return s.substr(l + 1, r - l - 1);
    }
};