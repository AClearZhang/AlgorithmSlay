/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\DynamicProgram\213.HouseRobberII.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-03-08 17:28:03
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-03-08 17:36:43
 * @Version             : 1.0
 * @Description         : 房屋偷盗II
 * 
 */

#include <iostream>
#include <cmath>
#include <windows.h>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    int RobRange(vector<int>& nums, int start, int end){
        int n = nums.size();

        //base n+2 最后是0
        int dp_2 = 0, dp_1 = 0;  
        int dp = 0;

        // dp start
        for(int i=end; i>=start ;i--){
            dp = max(dp_1,           // 不取
                        nums[i]+dp_2); // 取
            dp_2 = dp_1;
            dp_1 = dp;
        }
        return dp;
    }
    int rob(vector<int>& nums) {
        // 分析单调栈模板的——通过 分析选择情况二三。
        int n = nums.size();
        if(n == 1) return nums[0];
        return max(RobRange(nums, 0, n-2), 
                    RobRange(nums, 1, n-1));
    }
    
};
