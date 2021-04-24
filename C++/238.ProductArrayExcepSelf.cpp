/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\238.ProductArrayExcepSelf.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-04-24 17:28:40
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-04-24 17:37:41
 * @Version             : 1.0
 * @Description         : 除去自身以外的 数组相乘
 * 238. 除自身以外数组的乘积
难度
中等

802

收藏

分享
切换为英文
接收动态
反馈
给你一个长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。

 

示例:

输入: [1,2,3,4]
输出: [24,12,8,6]
 

提示：题目数据保证数组之中任意元素的全部前缀元素和后缀（甚至是整个数组）的乘积都在 32 位整数范围内。

说明: 请不要使用除法，且在 O(n) 时间复杂度内完成此题。

进阶：
你可以在常数空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组不被视为额外空间。）
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
     * @Description: 关键是 不能用除法+还要原地或者用res 进行O(1)的算法题解。
     * @param {*}
     * @return {*}
     * @notes: 使用res 计算元素左侧的乘积； 再进行一次从右到左 计算元素右边的乘积，对应乘res 即可得到结果。
     */
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1); // 首先代表 i左侧的元素乘积
        For(i, 1, n){
            res[i] = res[i-1]*nums[i-1];
        }
        // 右边有个tmp
        int tmp = 1;  //动态右边的累乘 除去自身
        for(int j = n-2; j >= 0;j--){
            tmp *= nums[j+1];
            res[j] *= tmp;
        }
        return res;
    }  
};