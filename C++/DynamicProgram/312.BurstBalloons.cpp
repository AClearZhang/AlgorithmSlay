/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\DynamicProgram\312.BurstBalloons.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-03-06 18:13:46
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-03-07 00:44:04
 * @Version             : 1.0
 * @Description         : 戳气球
 * 312. 戳气球
有 n 个气球，编号为0 到 n - 1，每个气球上都标有一个数字，这些数字存在数组 nums 中。

现在要求你戳破所有的气球。戳破第 i 个气球，你可以获得 nums[i - 1] * nums[i] * nums[i + 1] 枚硬币。 这里的 i - 1 和 i + 1 代表和 i 相邻的两个气球的序号。如果 i - 1或 i + 1 超出了数组的边界，那么就当它是一个数字为 1 的气球。

求所能获得硬币的最大数量。

 

示例 1：
输入：nums = [3,1,5,8]
输出：167
解释：
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
示例 2：

输入：nums = [1,5]
输出：10
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
     * @Description: 经典动态规划问题。
     * @param {*}
     * @return {*} dp[i][j]含义: 开区间(i,j) 之间戳破气球所得到的最大金币总和。
     * @notes: 关键———去除子问题相互影响； 反向思考——重定义dp的含义为开区间，并
     *                                      并找最后一个戳破的气球(k) 从而可以建立i k j的状态转移方程的链接。
     */
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        // nums => points
        vector<int> points(n+2, 1);
        for(int i = 1; i<=n ;i++){
            points[i] = nums[i-1];
        }
        // base
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
            // 下三角全部设置为0
        
        // dp start
            // 下到上左到右
        for(int i = n;i>=0;i--){
            for(int j = i+1;j<=n+1;j++){
                // 最后一个戳破的气球为k
                for(int k = i+1; k < j ;k++){
                    // 对应最大的一个
                    int temp = dp[i][k]+dp[k][j]+points[i]*points[k]*points[j];
                    dp[i][j] = max(dp[i][j], temp);
                }

            }
        }
        return dp[0][n+1];
    }
};
