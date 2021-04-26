/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\415.SubMissions.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-04-26 21:16:17
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-04-26 21:30:33
 * @Version             : 1.0
 * @Description         : 字符相加，返回字符 415
 * 415. 字符串相加
给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。

 

提示：

num1 和num2 的长度都小于 5100
num1 和num2 都只包含数字 0-9
num1 和num2 都不包含任何前导零
你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式
通过次数111,673提交次数213,233
 */

#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <map>
#include <vector>

using namespace std;


#define For(x,y,z) for(ll x = y; x < z;++x)
typedef long long ll;


class Solution {
public:
    /**
     * @Description: 415
     * @param {string} num1
     * @param {string} num2
     * @return {*}
     * @notes:  关键：从后往前加； 但是 res要 ： res= XX + res;
     */
    string addStrings(string num1, string num2) { 
       int cur = 0;
       int p1=num1.size()-1, p2=num2.size()-1;
       string res;
       while(p1>=0 || p2>=0) {
           if(p1>=0) cur += num1[p1--]-'0';
           if(p2>=0) cur += num2[p2--]-'0';
           res = to_string(cur%10) + res;
           cur /= 10;
       }
       if( cur != 0){  // "1"  "9"
           res = to_string(cur) + res;
       }
       return res;
    }
};
