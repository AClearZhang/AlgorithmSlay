/*
 * @FilePath            : \project\AlgorithmSlay\C++\20.ValidParathesis.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-03-13 12:24:11
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-03-13 12:30:45
 * @Version             : 1.0
 * @Description         : 三种括号的 有效匹配。
 * 20. 有效的括号
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
 

示例 1：

输入：s = "()"
输出：true
示例 2：

输入：s = "()[]{}"
输出：true
示例 3：

输入：s = "(]"
输出：false
示例 4：

输入：s = "([)]"
输出：false
示例 5：

输入：s = "{[]}"
输出：true
 */

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;


class Solution {
public:
    /**
     * @Description: 关键是：用栈结合， 遇到一个右括号 就出栈和最近(即栈顶)的左括号匹配。
     * @param {string} s
     * @return {*}
     * @notes: 
     */
    bool isValid(string s) {
        stack<char> left;
        
        for(char c:s){
            if(c=='('||c=='['||c=='{'){
                // zuokuohao
                left.push(c);
            }else{
                // you
                if(!left.empty() && leftOf(c) == left.top()){
                    left.pop();
                }else{
                    return false;
                }
            }
        }

        // 注意最后 不可以留有左括号！要全出来了。
        return left.empty();
        
    }   
    // helper 判断右括号 对应左括号类型
    char leftOf(char c){
        if(c == ')') return '(';
        if(c == '}') return '{';
        else{
            return '[';
        }
    }
};