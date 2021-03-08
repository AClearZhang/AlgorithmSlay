/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\DynamicProgram\198.HouseRobber.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-03-08 16:47:08
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-03-08 17:31:22
 * @Version             : 1.0
 * @Description         : 房屋偷盗
 * 198. 打家劫舍
你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。

 

示例 1：

输入：[1,2,3,1]
输出：4
解释：偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
     偷窃到的最高金额 = 1 + 3 = 4 。
示例 2：

输入：[2,7,9,3,1]
输出：12
解释：偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
     偷窃到的最高金额 = 2 + 9 + 1 = 12 。
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
    /**
     * @Description: dp[i] 表示从i开始 最大能偷盗多少钱
     * @param {*}
     * @return {*}
     * @notes: 
     */
    int rob(vector<int>& nums) {
        int n = nums.size();
        //base n+2 最后是0
        vector<int> dp(n+2, 0);

        // dp start
        for(int i=n-1; i>=0 ;i--){
            dp[i] = max(dp[i+1],           // 不取
                        nums[i]+dp[i+2]); // 取
        }
        return dp[0];
    }
    /**
     * @Description: 状态压缩
     * @param {*}
     * @return {*}
     * @notes: 
     */
    int rob(vector<int>& nums) {
        int n = nums.size();

        //base n+2 最后是0
        int dp_2 = 0, dp_1 = 0;  
        int dp = 0;

        // dp start
        for(int i=n-1; i>=0 ;i--){
            dp = max(dp_1,           // 不取
                        nums[i]+dp_2); // 取
            dp_2 = dp_1;
            dp_1 = dp;
        }
        return dp;
    }

};