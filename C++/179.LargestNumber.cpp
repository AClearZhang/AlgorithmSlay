/*
 * @FilePath            : \AlgorithmInterview\AlgorithmSlay\C++\179.LargestNumber.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-05-14 18:40:55
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-05-14 19:15:59
 * @Version             : 1.0
 * @Description         : 最大数
 * 179. 最大数
给定一组非负整数 nums，重新排列每个数的顺序（每个数不可拆分）使之组成一个最大的整数。

注意：输出结果可能非常大，所以你需要返回一个字符串而不是整数。

 

示例 1：

输入：nums = [10,2]
输出："210"
示例 2：

输入：nums = [3,30,34,5,9]
输出："9534330"
示例 3：

输入：nums = [1]
输出："1"
示例 4：

输入：nums = [10]
输出："10"
 

提示：

1 <= nums.length <= 100
0 <= nums[i] <= 109
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
#include <vector>

using namespace std;

class Solution
{
public:
    /**
     * @Description: C++ 精髓：str_a+str_b > str_b+str_a
     * @param {const string} a
     * @param {const string} b
     * @return {*}
     * @notes: 
     */
    static bool cmp(const string a, const string b)
    {
        return (a+b) > (b+a);
    }
    string largestNumber(vector<int> &nums)
    {
        vector<string> s;
        for (auto n1 : nums)
        {
            s.push_back(to_string(n1));
        }


        sort(s.begin(), s.end(), cmp);
        string ans;
        for(auto s1: s){
            ans+=s1;
        }

        // 特殊情况 若干个零
        if( ans[0] == '0' )  return "0";

        return ans;
    }
};

int main()
{

    // Solution so;
    vector<int> a{3, 30, 34, 5, 9};
    // so.largestNumber(a);
    vector<string> s;
    for (auto a1 : a)
    {
        s.push_back(to_string(a1));
    }
    // string s(nums.begin(), nums.end());
    for (auto s1 : s)
    {
        cout << s1 << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}