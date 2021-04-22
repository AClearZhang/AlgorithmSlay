/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\154.FindMiniRotatedSortArrII.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-04-22 17:16:43
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-04-22 21:04:24
 * @Version             : 1.0
 * @Description         : 寻找旋转数组 最小值II
 * 154. 寻找旋转排序数组中的最小值 II
已知一个长度为 n 的数组，预先按照升序排列，经由 1 到 n 次 旋转 后，得到输入数组。例如，原数组 nums = [0,1,4,4,5,6,7] 在变化后可能得到：
若旋转 4 次，则可以得到 [4,5,6,7,0,1,4]
若旋转 7 次，则可以得到 [0,1,4,4,5,6,7]
注意，数组 [a[0], a[1], a[2], ..., a[n-1]] 旋转一次 的结果为数组 [a[n-1], a[0], a[1], a[2], ..., a[n-2]] 。

给你一个可能存在 重复 元素值的数组 nums ，它原来是一个升序排列的数组，并按上述情形进行了多次旋转。请你找出并返回数组中的 最小元素 。

 

示例 1：

输入：nums = [1,3,5]
输出：1
示例 2：

输入：nums = [2,2,2,0,1]
输出：0
 

提示：

n == nums.length
1 <= n <= 5000
-5000 <= nums[i] <= 5000
nums 原来是一个升序排序的数组，并进行了 1 至 n 次旋转
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
     * @Description: 使用二分搜索 左侧边界——有重复但是 可以发现最小值
     * @param {*}
     * @return {*}
     * @notes: 注意  选择左侧边界，且不区分 target而只是寻找
     */
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left=0, right=n-1;
        while( left < right ){ // 左闭右闭
            int mid = (right-left)/2 + left;
            if(nums[mid] < nums[right]){
                right = mid;
            }else if(nums[mid] == nums[right]){
                // 循环到不重复 看有无数值
                int tmp = mid;
                while(nums[mid] == nums[right] && mid<right){
                    mid++;
                }
                if(nums[mid] < nums[right]){
                    left = mid;
                }else if(nums[mid] > nums[right]){ // ==
                    return nums[right];
                }else{
                    // ==
                    right = tmp;
                }
            }else{
                left = mid+1;
            }
        }
        return nums[left];
    }
};




class Solution {
public:
    /**
     * @Description: 使用二分搜索  相比于没有重复，添加 == 时：right--;
     * @param {*}
     * @return {*}
     * @notes: 注意  选择左侧边界，且不区分 target而只是寻找
     */
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left=0, right=n-1;
        while( left < right ){ // 左闭右闭
            int mid = (right-left)/2 + left;
            if(nums[mid] < nums[right]){
                right = mid;
            }else if(nums[mid] > nums[right]){
                // 循环到不重复 看有无数值
                left = mid + 1;
            }else{ // ==
                right -= 1;
            }
        }
        return nums[left];
    }
};
