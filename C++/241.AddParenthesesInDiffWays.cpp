/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\241.AddParenthesesInDiffWays.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-03-17 22:28:20
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-03-18 15:07:29
 * @Version             : 1.0
 * @Description         : 用不同方式设置优先级
 * 241. 为运算表达式设计优先级
给定一个含有数字和运算符的字符串，为表达式添加括号，改变其运算优先级以求出不同的结果。你需要给出所有可能的组合的结果。有效的运算符号包含 +, - 以及 * 。

示例 1:

输入: "2-1-1"
输出: [0, 2]
解释: 
((2-1)-1) = 0 
(2-(1-1)) = 2
示例 2:

输入: "2*3-4*5"
输出: [-34, -14, -10, -10, 10]
解释: 
(2*(3-(4*5))) = -34 
((2*3)-(4*5)) = -14 
((2*(3-4))*5) = -10 
(2*((3-4)*5)) = -10 
(((2*3)-4)*5) = 10
 */


#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;


class Solution {
public:
    /**
     * @Description: 递归、回溯、动规、   分治类似—— 先分 后治（merge）
     * @param {string} expression
     * @return {*}
     * @notes: 
     */
    vector<int> diffWaysToCompute(string expression) {
        // 先分开， 到底计算出有几个数据 返回得到的数组； 然后合并起来 
        vector<int> res;
        // 分而治之 —— 分开
        for(int i = 0; i< expression.size() ;i++){
            if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*'){
                // 遇到运算符号之时开始分开运算
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i+1, expression.size()-i-1));

                //之后 进行merge
                for(int le : left){
                    for(int ri : right){
                        if(expression[i] == '+'){
                            res.push_back(le+ri);
                        }else if(expression[i] == '-'){
                            res.push_back(le - ri);
                        }else if(expression[i] == '*'){
                            res.push_back(le*ri);
                        }
                    }
                }
            }
            // 结束此间递归的分治
        }
        // 返回得到的res
            // 注意当当前存在 数字进行返回时要 —— 返回对应的数字
        if(res.empty()){
            stringstream sstream;
            int temp;
            sstream << expression;
            sstream >> temp;
            res.push_back(temp);
        }
        return res;
    }
};

