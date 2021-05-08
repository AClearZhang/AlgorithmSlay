/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\JZOffer\38.ZiFuChuanPailie.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-05-08 21:17:34
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-05-08 22:20:31
 * @Version             : 1.0
 * @Description         : 字符串的排列
 * 剑指 Offer 38. 字符串的排列
输入一个字符串，打印出该字符串中字符的所有排列。

 

你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。

 

示例:

输入：s = "abc"
输出：["abc","acb","bac","bca","cab","cba"]
 

限制：

1 <= s 的长度 <= 8
 */

#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

#define For(x, y, z) for (ll x = y; x < z; ++x)
typedef long long ll;


class Solution {
public:
    /**
     * @Description: 
     * @param {string} s
     * @return {*}
     * @notes: 
     */
    vector<string> permutation(string s) {
        vector<string> ans;
        string tmp;
        sort(s.begin(), s.end());
        // cout << s << endl;
        backverse(ans, tmp, s);
        return ans;
    }
    // helper 回溯
    void backverse(vector<string>& ans, string tmp, string s){
        if(s.empty()){
            ans.push_back(tmp);
            // if(find(ans.begin(),ans.end(), tmp) == ans.end()){
            // }
        }

        // 邻域 路径搜索
        for(int i = 0;i<s.size();i++){
            while(i+1<s.size() && s[i] == s[i+1]) {         // 先排序去除重复！ 在回溯！
                i++;
            }
            tmp.push_back(s[i]);
            string tmpString = s;
            backverse(ans, tmp, tmpString.erase(i, 1));
            tmp.pop_back();
        }

    }


    /**
     * @Description: 
     * @param {string} s
     * @return {*}
     * @notes: 
     */
    vector<string> permutation(string s) {
        vector<string> ans;
        string tmp;
        backverse(ans, tmp, s);
        return ans;
    }
    // helper 回溯
    void backverse(vector<string>& ans, string tmp, string s){
        if(s.empty()){
            if(find(ans.begin(),ans.end(), tmp) == ans.end()){  // 此处会超时！！！
                ans.push_back(tmp);
            }
        }

        // 邻域 路径搜索
        for(int i = 0;i<s.size();i++){
            tmp.push_back(s[i]);
            string tmpString = s;
            backverse(ans, tmp, tmpString.erase(i, 1));
            tmp.pop_back();
        }

    }
};
