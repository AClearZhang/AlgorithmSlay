/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\DynamicProgram\55.JumpGameI.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-03-08 23:32:20
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-03-09 12:22:11
 * @Version             : 1.0
 * @Description         : 贪婪+DP——跳跃游戏I
 * 55. 跳跃游戏
给定一个非负整数数组 nums ，你最初位于数组的 第一个下标 。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个下标。

 

示例 1：

输入：nums = [2,3,1,1,4]
输出：true
解释：可以先跳 1 步，从下标 0 到达下标 1, 然后再从下标 1 跳 3 步到达最后一个下标。
示例 2：

输入：nums = [3,2,1,0,4]
输出：false
解释：无论怎样，总会到达下标为 3 的位置。但该下标的最大跳跃长度是 0 ， 所以永远不可能到达最后一个下标。
 */
#include <iostream>
#include <cmath>
#include <windows.h>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    /**
     * @Description: 关键可以是 找 最大跳跃到的长度。 O(N) 即可完成。
     * @param {*}
     * @return {*}
     * @notes: 
     */
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return true;
        int farest = 0;
        for(int i = 0; i < n; i++){
            farest = max(farest, i+nums[i]);  // 找当前局部最大 与 全局最大对比。
            // 如果当前为0 返回false
            if(farest == i && i!=(n-1)) return false;
        }
        return true;
    }
};
