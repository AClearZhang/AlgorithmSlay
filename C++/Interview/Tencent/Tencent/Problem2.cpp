/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\Tencent\Problem2.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-04-30 15:18:27
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-04-30 15:25:07
 * @Version             : 1.0
 * @Description         : 
 */
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

#define For(x, y, z) for (int x = y; x < z; ++x)
typedef long long ll;

int maxLenOfSubArr(vector<int> &nums)
{
    if (nums.size() == 0)
        return 0;
    vector<int> dp(nums.size(), 1);

    int res = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if(nums[i] > nums[j])
                dp[i] = max(dp[i], dp[j]+1);
        }
        res = dp[i]>res?dp[i]:res;
    }
    return res;
}

int main()
{
    vector<int> nums{5,4,0,3,1,2};
    cout << maxLenOfSubArr(nums) << endl;
    system("pause");
    return 0;
}
