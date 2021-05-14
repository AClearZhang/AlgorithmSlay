/*
 * @FilePath            : \AlgorithmInterview\AlgorithmSlay\C++\JZOffer\51.NixuduiLcof.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-05-14 19:17:01
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-05-14 20:17:40
 * @Version             : 1.0
 * @Description         : 寻找逆序对的个数
 * 剑指 Offer 51. 数组中的逆序对
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。

 

示例 1:

输入: [7,5,6,4]
输出: 5
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

class Solution {
public:
    /**
     * @Description: 
     * @param {*}
     * @return {*}
     * @notes: 关键使用  归并排序（分治法）；
     *          顺便在排序的时候 ： 
     *                  否则（即 tmp[i]>tmp[j]）时： 
     *                  添加右子数组当前元素 tmp[j] ，并执行 j=j+1；此时构成 m−i+1个「逆序对」，统计添加至 resresres ；
     */
    int count = 0;
    void merge_sort(vector<int>& nums, int l, int r, vector<int>& tmp){// 左闭右闭
        if(l>=r){
            return ;
        }
        int m = (r-l)/2 + l;
        merge_sort(nums, l, m, tmp);
        merge_sort(nums, m+1, r, tmp);
        
        int p=l, q=m+1, i=l;
        while( p<=m || q<=r ){
            // p++; 低位放在前面
            if( q>r || (p<=m && nums[p]<=nums[q]) ){
                tmp[i++] = nums[p++];
            }else if(p<=m && nums[p] > nums[q]){
                // 前面排好序了  直接 m-i+1个加上
                count += m-p+1;
                // cout << "now count is:" << count << endl;
                tmp[i++] = nums[q++];
            }else{
                tmp[i++] = nums[q++];
            }
        }

        for(int i = l; i<=r ;i++){
            nums[i] = tmp[i];
        }
        
    }
    int reversePairs(vector<int>& nums) {
        vector<int> tmp(nums.begin(), nums.end());
        merge_sort(nums, 0, nums.size()-1, tmp);
        return count;
    }
};