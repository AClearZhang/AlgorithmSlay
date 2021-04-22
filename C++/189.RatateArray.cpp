/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\189.RatateArray.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-04-22 17:02:17
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-04-22 17:12:42
 * @Version             : 1.0
 * @Description         : 旋转数组
 * 189. 旋转数组
给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。

 

进阶：

尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
你可以使用空间复杂度为 O(1) 的 原地 算法解决这个问题吗？
 

示例 1:

输入: nums = [1,2,3,4,5,6,7], k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右旋转 1 步: [7,1,2,3,4,5,6]
向右旋转 2 步: [6,7,1,2,3,4,5]
向右旋转 3 步: [5,6,7,1,2,3,4]
示例 2:

输入：nums = [-1,-100,3,99], k = 2
输出：[3,99,-1,-100]
解释: 
向右旋转 1 步: [99,-1,-100,3]
向右旋转 2 步: [3,99,-1,-100]
 

提示：

1 <= nums.length <= 2 * 104
-231 <= nums[i] <= 231 - 1
0 <= k <= 105
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
     * @Description: 旋转数组  一个个循环旋转。
     * @param {int} k
     * @return {*}
     * @notes: 方法：这里使用倒转 前n-k个 以及后k个。
     */
    void rotate(vector<int>& nums, int k) {
        if(nums.size() == 1 || k==0){
            return ;
        }
        int n = nums.size();
        k %= n;
        reverseVec(nums, 0, n-k);
        reverseVec(nums, n-k, n);
        reverseVec(nums, 0, n);
    }
    // helper reverse 
    void reverseVec(vector<int>& nums, int start, int end){  // 左闭右开
        int left = start, right = end-1;
        while(left<right){
            int tmp = nums[left];
            nums[left++] = nums[right];
            nums[right--] = tmp;
        }
    }
};


int main(){


    return 0;
}
