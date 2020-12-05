/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\69.sqrtx.cpp
 * @Author              : AClearZhang
 * @Date                : 2020-12-03 10:44:43
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2020-12-05 22:20:17
 * @Version             : 1.0
 * @Description         : x的平方根——使用二分查找算法
 * 实现 int sqrt(int x) 函数。

计算并返回 x 的平方根，其中 x 是非负整数。

由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

示例 1:

输入: 4
输出: 2
示例 2:

输入: 8
输出: 2
说明: 8 的平方根是 2.82842..., 
     由于返回类型是整数，小数部分将被舍去。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sqrtx
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <map>
#include <vector>
#include <windows.h>
#include <unordered_map>
#include <cmath>

using namespace std;


class Solution {
public:
    int mySqrt1(int x) {
        return sqrt(x);
        //二分查找 中间值


    }
    int mySqrt2(int x) {
        if (x == 0) return 0;
        int left = 1;   //gai
        int right = x; // 左闭右闭  
        // 查找所以等于
        while (left <= right)
        {
            int mid = (left + right) / 2;
            // int mid = left + (right - left) / 2;
            int sqr2 = x/mid;  // 重点
            if ( sqr2 == x)
            {
                return mid;
            }
            else if (sqr2 > x)
            {
                right = mid - 1;
            }
            else if (sqr2 < x)
            {
                left = mid + 1;
            }
        }
        return left; // 表示未查找到。
    }
};

int main()
{
    string s = "abcabcbb";
    // string s = "bbbb";
    // // string s = "pwwkew";
    // // string s = "";
    // // string s = " ";
    // Solution1 so;
    // int num = so.lengthOfLongestSubstring(s);
    
    Solution so;
    int x = 8;

    cout<<"x"<< x <<"的向下根号为：" << so.mySqrt1(x) << endl;
    system("pause");
    return 0;
}

