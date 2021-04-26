/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\BiteOperation\MathOperation.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-04-26 21:15:30
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-04-26 21:30:53
 * @Version             : 1.0
 * @Description         : 巧用数学技巧
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
