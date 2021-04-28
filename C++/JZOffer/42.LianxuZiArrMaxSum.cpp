/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\JZOffer\42.LianxuZiArrMaxSum.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-04-28 23:09:25
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-04-29 00:09:18
 * @Version             : 1.0
 * @Description         : 
 */
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        // dp存储, 0
        int maxRes = nums[0];  
        int dp_0 = nums[0], dp_1 = 0;
        

        // 状态转移方程
        for( int i = 1; i < n ;i++ ){
            // 两种情况: 本身 或 前者+自身
            dp_1 = max( nums[i], dp_0+nums[i] );
            dp_0 = dp_1;
            maxRes = max(maxRes, dp_0);
        }
        return maxRes;
    }
};