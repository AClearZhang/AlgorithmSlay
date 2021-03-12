/*
 * @FilePath            : \project\AlgorithmSlay\C++\78.Subsets.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-03-12 19:49:45
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-03-12 20:36:27
 * @Version             : 1.0
 * @Description         : 子集。
 * 78. 子集
给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。

 

示例 1：

输入：nums = [1,2,3]
输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
示例 2：

输入：nums = [0]
输出：[[],[0]]
 

提示：

1 <= nums.length <= 10
-10 <= nums[i] <= 10
nums 中的所有元素 互不相同
 */
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    /**
     * @Description: 方法一：数学归纳法+递归 每次从头开始复制 并添加进入当前nums[i]
     * @param {*}
     * @return {*}
     * @notes: 返回当前nums 下的子集
     */
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.size() == 0) return {{}};
        // 最后一个元素拿出来作为 插入依据
        int back = nums.back();
        nums.pop_back();

        vector<vector<int>> res = subsets(nums);
        for(int i = 0; i<res.size() ;i++){
            // 插入最后一个值到每个数组中
            res.push_back(res[i]);
            res.back().push_back(back);
        }
        return res;
    }
    /**
     * @Description: 方法二：回溯法
     * @param {*}
     * @return {*}
     * @notes: 使用回溯树， 每次在 路径(nums)中选择一个去，
     *           选择res 选择最后要回溯返回原始状态，并边界为
     */
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> track;//每次回溯需要插入最终结果的track
        vector<vector<int>> res;
        // res[0][0] = {};
        
        backtrack(nums,0, track, res);
        return res;
    }
    // helper—— 辅助函数；backtrack回溯。
    void backtrack(vector<int>& nums, int start, vector<int>& track, vector<vector<int>>& res){
        // qianzhi fuzhi
        res.push_back(track);

        // backtrack start
        for(int i = start; i<nums.size() ;i++){
            // select
            track.push_back(nums[i]);
            backtrack(nums, i+1, track, res);
            // huifu
            track.pop_back();
        }

    }

};