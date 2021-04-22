/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\33.SearchRotatedSortArray.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-04-22 21:13:47
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-04-22 22:11:13
 * @Version             : 1.0
 * @Description         : 搜索旋转排序树组
 *33. 搜索旋转排序数组
整数数组 nums 按升序排列，数组中的值 互不相同 。

在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转，使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。例如， [0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2] 。

给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。

 

示例 1：

输入：nums = [4,5,6,7,0,1,2], target = 0
输出：4
示例 2：

输入：nums = [4,5,6,7,0,1,2], target = 3
输出：-1
示例 3：

输入：nums = [1], target = 0
输出：-1
 

提示：

1 <= nums.length <= 5000
-10^4 <= nums[i] <= 10^4
nums 中的每个值都 独一无二
题目数据保证 nums 在预先未知的某个下标上进行了旋转
-10^4 <= target <= 10^4 
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
     * @Description: 不是寻找最小而是对应  target了！还好不重复 —— 这样也可以像是有序似的进行做题。
     * @param {int} target
     * @return {*}
     * @notes: 关键：因为旋转数组只在一侧有序。查找 target看在有序的那一侧——缩小距离
     *              【怎样判断有序一侧 —— 因为旋转数组 只在一个位置开始前后断层，所以二分就好了。必定有一侧有序。】
     *              太细节了！！！注意千万 别死循环了！！！ 等号加不加注意看！！！
     */
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r=n-1;
        while(l<=r){  // 
            int m = (r-l)/2 + l;
            if(nums[m] == target){
                return m;
            }
            if(nums[m] >= nums[l]){   //等号
                // 左边有序
                if(target >= nums[l] && target < nums[m]) {
                    r=m-1;   // 注意上面必须 无等号，才能使这里 -1;才能不无限循环。
                }else{
                    l=m+1;
                }

            }else{ // 右边有序
                if(target > nums[m] && target <= nums[r]) {
                    l=m+1;   // 注意上面必须 无等号，才能使这里 -1;才能不无限循环。
                }else{
                    r=m-1;
                }
            }
        }
        return -1;
    }   
};
