/*
 * @FilePath            : \project\AlgorithmSlay\C++\JZOffer\20.ShuZhiString.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-09-18 17:24:46
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-09-18 17:47:51
 * @Version             : 1.0
 * @Description         : 表示数值的字符串。。。状态机、、用例模拟编程。
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

/**
 * @Description: 一看AC通过了20就知道这事儿不简单，说一下我的解法！

写两个子函数，一个是判断是否为整数，一个判断是否为浮点数

对原字符串预处理，去掉首尾的空格

一次扫描看一下是否含有'e'或'E

如果有的话，直接返回(左半段是整数||左半段是小数)&&右半段是整数

如果没有的话，直接返回(s是小数||s是整数)
 * @param {*}
 * @return {*}
 * @notes: 
 */

class Solution
{
public:
    void trim(string &s)
    {
        if (s.size() == 0)
            return;

        while (!s.empty() && s[0] == ' ')
            s.erase(0, 1);
        while (!s.empty() && s[s.size() - 1] == ' ')
            s.erase(s.size() - 1, 1);
        return; // 注意直接在string上做， 有可能全部去除了。
    }
    bool isNumber(string s)
    {
        //s进行预处理,去掉空格,观察有无'e'或者'E'
        this->trim(s);
        if(s == "") return false;
        
        int n = s.size(), divide = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'e' || s[i] == 'E')
            {
                divide = i;
                if (i == 0)
                    return false; //保证不在第一位
                break;
            }
        }

        // 最终判断：
//         如果有的话，直接返回(左半段是整数||左半段是小数)&&右半段是整数

// 如果没有的话，直接返回(s是小数||s是整数)

        if (divide != 0)
        {
            return ((isFloat(s.substr(0, divide)) || isInteg(s.substr(0, divide))) && isInteg(s.substr(divide + 1, n - divide)));
        }
        else
            return (isFloat(s) || isInteg(s));
        return true;
    }
    bool isFloat(string s)
    {
        if (s.empty())
            return false;
        if (s.size() == 1 && !(s[0] <= '9' && s[0] >= '0'))
            return false;
        int point = 0, i = 0, num = 0; // 记录小数点个数、 i记录当前第几个字符、 num记录几个数字。
        for (auto c : s)
        {
            if (c == '.') // "."不能超过一个
            {
                if (point < 1)
                    point++;
                else
                    return false;
            }
            else if (c == '+' || c == '-') // + - 必须在第一位
            {
                if (i != 0)
                    return false;
            }
            else if (!(c <= '9' && c >= '0')) //有奇怪字符
            {
                return false;
            }
            else if ((c <= '9' && c >= '0'))
                num++;
            i++;
        }
        return num > 0;
    }
    bool isInteg(string s)
    {
        if (s.empty())
            return false;
        int n = s.size();
        if (n == 1 && !(s[0] <= '9' && s[0] >= '0'))
            return false;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '+' || s[i] == '-') //+-必须在前边
            {
                if (i != 0)
                    return false;
            }
            else if (!(s[i] <= '9' && s[i] >= '0')) //除此之外必须是数字
                return false;
        }
        return true;
    }
};
