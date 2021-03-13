/*
 * @FilePath            : \project\AlgorithmSlay\C++\22.GenerateParenthesis.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-03-13 11:48:54
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-03-13 12:11:20
 * @Version             : 1.0
 * @Description         : 回溯 —— 生成括号
 * 22. 括号生成
数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

 

示例 1：

输入：n = 3
输出：["((()))","(()())","(())()","()(())","()()()"]
示例 2：

输入：n = 1
输出：["()"]
 

提示：

1 <= n <= 8
 */


#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>

using namespace std;



class Solution {
public:
    /**
     * @Description: 用回溯 暴力生成——关键是 遍历过程中 去除不合法的括号即可。
     * @param {int} n
     * @return {*}
     * @notes: 
     */
    vector<string> generateParenthesis(int n) {
        if(n == 0) return {};
        vector<string> res;
        string track;
        backtrack(n, n, track,res);
        return res;
    }
    // helper--- 回溯法;
        //Key: 合法性作为结束条件； 路径为track；选择 左右括号。
        // left right 表示左右括号分别 还有多少个可用。
    void backtrack(int left, int right, string track, vector<string>& res){
        // 合法性判断与结束条件
        if(left > right)  return;   // 还剩几个！所以 要用大于号。
        if(left<0 || right < 0) return;
        if(left == 0 && right == 0) {
            // done
            res.push_back(track);
            return;
        }

        // backtrack start
        track.push_back('(');
        backtrack(left-1, right, track, res);
        track.pop_back();

            // right
        track.push_back(')');
        backtrack(left, right-1, track, res);
        track.pop_back();
    }
     /**
     * @Description: 方法二：同上面的 方法一；只不过 left和right 修正的更符合实际运用啦~ 
     * @param {int} n
     * @return {*}
     * @notes: 
     */
    vector<string> generateParenthesis(int n) {
        if(n == 0) return {};
        vector<string> res;
        backtrack(0, 0, "",res, n);
        return res;
    }
    // helper--- 回溯法;
        //Key: 合法性作为结束条件； 路径为track；选择 左右括号。
        // left right 表示左右括号用了多少括号。
    void backtrack(int left, int right, string track, vector<string>& res,int n){
        // 合法性判断与结束条件
        if(left < right|| left>n || right>n)  return; 
        if(left == n && right == n) {
            // done
            res.push_back(track);
            return;
        }

        // backtrack start
        backtrack(left+1, right, track+'(', res, n);
        backtrack(left, right+1, track+')', res, n);
        return;

        //     // right
        // track.push_back(')');
        // backtrack(left, right-1, track, res);
        // track.pop_back();
    }




};