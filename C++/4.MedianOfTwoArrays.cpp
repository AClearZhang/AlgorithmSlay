/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\4.MedianOfTwoArrays.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-04-15 18:07:47
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-04-15 21:42:42
 * @Version             : 1.0
 * @Description         : 两个正序排序数组的中位数。
 * 4. 寻找两个正序数组的中位数
给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。

 

示例 1：

输入：nums1 = [1,3], nums2 = [2]
输出：2.00000
解释：合并数组 = [1,2,3] ，中位数 2
示例 2：

输入：nums1 = [1,2], nums2 = [3,4]
输出：2.50000
解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
示例 3：

输入：nums1 = [0,0], nums2 = [0,0]
输出：0.00000
示例 4：

输入：nums1 = [], nums2 = [1]
输出：1.00000
示例 5：

输入：nums1 = [2], nums2 = []
输出：2.00000
 

提示：

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
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
#include <vector>

using namespace std;


#define For(x,y,z) for(int x = y; x < z;++x)


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(), n = nums2.size();
        double left = (m+n+1)/2;
        double right = (m+n+2)/2;
        return double(findKth(nums1, 0, nums2, 0, left) + findKth(nums1, 0, nums2, 0, right))/2;

    }
    /**
     * @Description: 
     * @param {int} l1
     * @param {int} l2
     * @param {int} k
     * @return {*} 返回中间值 —— 最终值.
     * @notes: 注意：返回是 int 向下取值。
     */
    int findKth(vector<int>& nums1, int l1,vector<int>& nums2, int l2, int k){
        // base case
        if( l1 >= nums1.size()) return nums2[l2+k-1];
        if( l2 >= nums2.size()) return nums1[l1+k-1];
        if(  k == 1){
            return min(nums1[l1], nums2[l2]);
        }
        // general
        int minVal1 = (l1 + k/2 -1)<nums1.size() ?nums1[l1+k/2-1]:INT_MAX; // INTMAX_MAX 错误返回小的值了！
        int minVal2 = (l2 + k/2 -1)<nums2.size()?nums2[l2+k/2-1]:INT_MAX;
        if(minVal1<minVal2){
            return findKth(nums1, l1+k/2, nums2, l2, k-k/2); 
        }else{
            return findKth(nums1, l1, nums2, l2+k/2, k-k/2);
        }


    }
};
