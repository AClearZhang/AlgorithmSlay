/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\209.MiniSizeSubarraySum.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-04-23 17:10:16
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-04-23 17:19:16
 * @Version             : 1.0
 * @Description         : 最小长度子数组和
 * 209. 长度最小的子数组
给定一个含有 n 个正整数的数组和一个正整数 target 。

找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。

 

示例 1：

输入：target = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的子数组。
示例 2：

输入：target = 4, nums = [1,4,4]
输出：1
示例 3：

输入：target = 11, nums = [1,1,1,1,1,1,1,1]
输出：0
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
#include <map>
#include <vector>

using namespace std;



#define For(x,y,z) for(ll x = y; x < z;++x)
typedef long long ll;

class Solution {
public:
    /**
     * @Description: 大于目标值 最小子数组和
     * @param {int} target
     * @return {*}
     * @notes: 
     */
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left=0, right=0;
        int minArr = INT_MAX;
        int sum=0;
        while(right<n){
            sum+=nums[right];
            right++;

            while( target >= sum ){
                // 查看是否最小
                int len = right-left + 1;
                minArr = minArr>len?len:minArr;

                // shrink windows
                sum -= nums[left];
                left++;
            }
        }
        return minArr;
    }
};
