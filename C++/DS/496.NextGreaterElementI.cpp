/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\DS\496.NextGreaterElementI.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-03-25 10:50:52
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-03-25 11:05:49
 * @Version             : 1.0
 * @Description         : 下一个更大的元素I
 * 496. 下一个更大元素 I
给你两个 没有重复元素 的数组 nums1 和 nums2 ，其中nums1 是 nums2 的子集。

请你找出 nums1 中每个元素在 nums2 中的下一个比其大的值。

nums1 中数字 x 的下一个更大元素是指 x 在 nums2 中对应位置的右边的第一个比 x 大的元素。如果不存在，对应位置输出 -1 。

 

示例 1:

输入: nums1 = [4,1,2], nums2 = [1,3,4,2].
输出: [-1,3,-1]
解释:
    对于 num1 中的数字 4 ，你无法在第二个数组中找到下一个更大的数字，因此输出 -1 。
    对于 num1 中的数字 1 ，第二个数组中数字1右边的下一个较大数字是 3 。
    对于 num1 中的数字 2 ，第二个数组中没有下一个更大的数字，因此输出 -1 。
示例 2:

输入: nums1 = [2,4], nums2 = [1,2,3,4].
输出: [3,-1]
解释:
    对于 num1 中的数字 2 ，第二个数组中的下一个较大数字是 3 。
    对于 num1 中的数字 4 ，第二个数组中没有下一个更大的数字，因此输出 -1 。
 */
#include <algorithm>
#include <cmath>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <set>
#include <stack>

using namespace std;

class Solution {
public:
    /**
     * @Description: 把握好单调栈 核心——每次都push但是 每次都将比自己小的pop 出去。
     * @param {*}
     * @return {*}
     * @notes: 【用于解决 下一个更大的元素问题】
     */
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int, int> ans; // 一个放置 nums[i], 另一个防止ans  下一个更大的数
        stack<int> s; // 存储单调栈 一个比一个大。// 从后往前 一个个大
        int n2 = nums2.size(), n1 = nums1.size();
        for(int i = n2-1; i>=0 ;i--){
            while(!s.empty() && s.top()<=nums2[i]){  // 将比当前值小或等于的统统 删掉。
                s.pop();
            }
            ans[nums2[i]] = s.empty() ? -1 : s.top() ;
            s.push(nums2[i]);
        }

        // nums1 中寻找并返回
        vector<int> ans1(n1, -1);
        for(int i = 0;i<n1;i++){
            ans1[i] = ans[nums1[i]];
        }
        return ans1;
    }
};
