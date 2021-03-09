/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\DynamicProgram\213.HouseRobberII.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-03-08 17:28:03
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-03-09 16:01:44
 * @Version             : 1.0
 * @Description         : 213. 打家劫舍 II
你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。

给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，能够偷窃到的最高金额。

 

示例 1：

输入：nums = [2,3,2]
输出：3
解释：你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
示例 2：

输入：nums = [1,2,3,1]
输出：4
解释：你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
     偷窃到的最高金额 = 1 + 3 = 4 。
示例 3：

输入：nums = [0]
输出：0
 

提示：

1 <= nums.length <= 100
0 <= nums[i] <= 1000
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
