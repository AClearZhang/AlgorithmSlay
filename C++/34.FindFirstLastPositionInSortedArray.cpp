/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\34.FindFirstLastPositionInSortedArray.cpp
 * @Author              : AClearZhang
 * @Date                : 2020-12-03 10:45:47
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2020-12-09 15:42:35
 * @Version             : 1.0
 * @Description         : 在排序数组中查找元素的第一个和最后一个位置
 * 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 target，返回 [-1, -1]。

进阶：
你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？
 

示例 1：
输入：nums = [5,7,7,8,8,10], target = 8
输出：[3,4]

示例 2：
输入：nums = [5,7,7,8,8,10], target = 6
输出：[-1,-1]

示例 3：
输入：nums = [], target = 0
输出：[-1,-1]
 

提示：

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums 是一个非递减数组
-109 <= target <= 109

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */


#include <cmath>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <windows.h>

using namespace std;

class Solution {
public:
    /**
     * @description:  寻找有序数组的下确界和上确界。
     * @param {*}
     * @return {*}
     * @notes: 
     */
    vector<int> searchRange(vector<int>& nums, int target) {
        //二分查找 首先找左边界
        int n = nums.size();
        int left = 0, right = n;
        int mid;
        vector<int> ans;
        while( left < right ){
            mid = left + (right-left)/2;
            if( nums[mid] >= target ){
                right = mid;
            }else if( nums[mid] < target ){
                left = mid + 1;
            }
        }
        if( left >= n || nums[left] != target) ans.push_back(-1);
        else
            ans.push_back(left);
        
        //其次 找右边界
        left=0, right=n;
        while(left<right){
            mid = left + (right-left)/2;
            if( nums[mid] <= target ){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        if( left == 0 || nums[left-1] != target )  ans.push_back(-1);
        else{
            ans.push_back(left-1);
        }
        return ans;
    }
};


int main(){

    vector<int> arr = {5,7,7,8,8,10};
    int target = 8;
    Solution so;
    auto answer = so.searchRange(arr, target);
    cout<<"answer is : ";
    for(auto a : answer){
        cout << a << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}

