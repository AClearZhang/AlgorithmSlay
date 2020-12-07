/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\69.sqrtx.cpp
 * @Author              : AClearZhang
 * @Date                : 2020-12-03 10:44:43
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2020-12-07 09:25:03
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

#include <cmath>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <windows.h>

using namespace std;

class Solution
{
public:
    // 最简单可以完成
    int mySqrt1(int x)
    {
        return sqrt(x);
        //二分查找 中间值
    }

    // 通过二分查找，找到方大于x 直至刚好小于x的下确界
    int mySqrt2(int x)
    {
        // if (x == 0)
        //     return x;
        // int l = 1, r = x, mid, sqrt;
        // while (l <= r)
        // {
        //     mid = l + (r - l) / 2;
        //     sqrt = x / mid;
        //     if (sqrt == mid)
        //     {
        //         return mid;
        //     }
        //     else if (mid > sqrt)
        //     {
        //         r = mid - 1;
        //     }
        //     else
        //     {
        //         l = mid + 1;
        //     }
        // }
        // return r;
        if (x == 0) return 0;
        int left = 1;   //gai
        int right = x; // 左闭右闭
        // 查找所以等于
        while (left <= right)
        {
            // int mid = (left + right) / 2; // 会溢出！所以最好用下面一行的！
            int mid = left + (right - left) / 2;
            int sqr2 = x/mid;  // 重点
            if ( sqr2 == mid)
            {
                return mid;
            }
            else if (sqr2 < mid)
            {
                right = mid - 1;
            }
            else if (sqr2 > mid)
            {
                left = mid + 1;
            }
        }
        return right; // 返回一个 刚好的下确界  【重点！】
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
    int x = 2147483647;

    cout << "x" << x << "的向下根号为：" << so.mySqrt2(x) << endl;
    system("pause");
    return 0;
}
