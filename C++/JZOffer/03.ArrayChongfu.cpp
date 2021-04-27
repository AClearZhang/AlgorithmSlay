/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\JZOffer\03.ArrayChongfu.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-04-27 14:27:14
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-04-27 15:02:13
 * @Version             : 1.0
 * @Description         : 数组中 重复的数字
 * 
 */

#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

#define For(x, y, z) for (ll x = y; x < z; ++x)
typedef long long ll;

class Solution {
public:
    /**
     * @Description: 方法1考虑时间1
     * @param {*}
     * @return {*}
     * @notes: 
     */
    int findRepeatNumber(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> map_nums;
        For(i, 0, n){
            if(map_nums.count(nums[i]) > 0){
                return nums[i];
            }else{
                map_nums[nums[i]]++;
            }
        }
        return -1;
    }
};



class Solution {
public:
    /**
     * @Description: 方法2  考虑空间。——置换 
     * @param {*}
     * @return {*}
     * @notes: : 鸽巢原理，因为出现的元素值 < nums.size(); 所以我们可以将见到的元素 放到索引的位置，如果交换时，发现索引处已存在该元素，则重复 O(N) 空间O(1)
     */
    int findRepeatNumber(vector<int>& nums) {
        int n = nums.size();
        
        For(i, 0, n){
            while(nums[i] != i){
                if(nums[i] == nums[nums[i]]){
                    return nums[i];
                }else{
                    // swap 两者
                    swap(nums[i], nums[nums[i]]);
                }
            }
        }
        return -1;
    }
};

class Solution {
public:

    /**
     * @Description: 
     * @param {*}
     * @return {*}
     * @notes: //方法3：对0到n-1进行二分查找，时间O(nlogn)，空间O(1)，不修改原数据，用时间换空间
                //该方法需要数字一定有重复的才行，因此如果题目修改在长度为n，数字在1到n-1的情况下，此时数组中至少有一个数字是重复的，该方法可以通过。
     */
    int findRepeatNumber(vector<int>& nums) {
        //统计nums中元素位于0到m的数量，如果数量大于这个值，那么重复的元素肯定是位于0到m的
        int left = 0 ;
        int right = nums.size()-1;
        while(left<right){
            int mid = (right+left)>>1;
            int count = countRange(nums,left,mid);
            if(count > mid-left+1) {
                right = mid;
            }else{
                left = mid+1;
            }
        }
        //最后left=right
        return left;
    }

    //统计范围内元素数量,时间O(n)
    int countRange(vector<int>& nums,int left,int right){
        int count = 0 ;
        for(int num:nums){
            if(num>=left && num<=right){
                count++;
            }
        }
        return count;
    }

};