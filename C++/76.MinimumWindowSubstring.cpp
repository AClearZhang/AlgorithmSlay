/*
 * @FilePath            : \project\AlgorithmSlay\C++\76.MinimumWindowSubstring.cpp
 * @Author              : AClearZhang
 * @Date                : 2020-11-28 00:06:16
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2020-11-28 00:19:47
 * @Version             : 1.0
 * @Description         : 最小覆盖子串 —— 滑动窗口方法
 * 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
注意：如果 s 中存在这样的子串，我们保证它是唯一的答案。

 

示例 1：

输入：s = "ADOBECODEBANC", t = "ABC"
输出："BANC"
示例 2：

输入：s = "a", t = "a"
输出："a"
 

提示：

1 <= s.length, t.length <= 105
s 和 t 由英文字母组成
 

进阶：你能设计一个在 o(n) 时间内解决此问题的算法吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-window-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <iostream>
#include <windows.h>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        char*  cur, *pre;
        while( *pre!= s[s.size()-1]){
            
        }
    }
};


int mian(){

    

    system("pause");
    return 0;
}

