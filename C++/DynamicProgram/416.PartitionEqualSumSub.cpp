/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\DynamicProgram\416.PartitionEqualSumSub.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-03-07 16:44:03
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-03-07 17:12:01
 * @Version             : 1.0
 * @Description         : 分割等和子集。
 * 416. 分割等和子集
给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

注意:

每个数组中的元素不会超过 100
数组的大小不会超过 200
示例 1:

输入: [1, 5, 11, 5]

输出: true

解释: 数组可以分割成 [1, 5, 5] 和 [11].
 

示例 2:

输入: [1, 2, 3, 5]

输出: false

解释: 数组不能分割成两个元素和相等的子集.
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
     * @Description: dp[i][j]=ture/false: nums[i-1]的重量以及当前载重为j时 是否能恰好装满。
     * @param {*}
     * @return {*}
     * @notes: 不用考虑其它，只需要 想定义、选择(装入不装入)、base、
     *      状态转移(取决于前面的 归纳，所以也是可以一步步 自底向上求出来的) 以及方向。
     */
    bool canPartition(vector<int>& nums) {
        // 加和
        int sum=0, n=nums.size();
        for(int i = 0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum % 2 != 0){
            return false;
        }
        int w = sum/2;
        // base
        vector<vector<int>> dp(n+1, vector<int>(w+1, false));
            // dp[0][...] =  false; dp[..][0] = true;
        for(int i = 0;i<n+1;i++){
            dp[i][0] = true;
        }
        // for(int j = 0;j<w+1;j++){
        //     dp[0][j] = false;
        // }

        // dp start
        for(int i = 1; i <= n ;i++){
            for(int j = 1; j <= w ;j++){
                // 放入与不放入两个类别；但是 要防止装不进去
                if(j - nums[i-1] < 0){
                    // 放不进去
                    dp[i][j] = dp[i-1][j];
                }else{
                    // 可以放进去;取决于状态 dp[i-1][j-nums[i-1]] 或者也可以不放进去 or
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                }
            }
        }
        return dp[n][w];
    }
};

