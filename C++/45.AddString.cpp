/*
 * @FilePath            : \project\AlgorithmSlay\C++\45.AddString.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-04-24 23:40:19
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-04-24 23:47:51
 * @Version             : 1.0
 * @Description         : 字符串相加
 415. 字符串相加
给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。

 

提示：

num1 和num2 的长度都小于 5100
num1 和num2 都只包含数字 0-9
num1 和num2 都不包含任何前导零
你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式
 */
#include <algorithm>
#include <cmath>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

#define For(x, y, z) for (int x = y; y < z; x++)

class Solution
{
public:
    /**
     * @Description: 直接每个数 减去char '0'去做。string相加。且 carry进位。
     * @param {string} num1
     * @param {string} num2
     * @return {*}
     * @notes: 
     */
    string addStrings(string num1, string num2)
    {
        string str;
        int cur = 0, i = num1.size() - 1, j = num2.size() - 1;
        while (i >= 0 || j >= 0 || cur != 0)
        {
            if (i >= 0)
                cur += num1[i--] - '0';
            if (j >= 0)
                cur += num2[j--] - '0';
            // str += to_string(cur % 10);
            str = to_string(cur % 10)+str;
            cur /= 10;
        }
        // reverse(str.begin(), str.end());
        return str;
    }
};