/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\215.kthLargestEleInArray.cpp
 * @Author              : AClearZhang
 * @Date                : 2020-12-14 22:04:43
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2020-12-15 11:06:45
 * @Version             : 1.0
 * @Description         : 215. 数组中的第K个最大元素
在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

示例 1:

输入: [3,2,1,5,6,4] 和 k = 2
输出: 5
示例 2:

输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4
 */
#include <iostream>
#include <map>
#include <vector>
#include <windows.h>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool comp(int a, int b){
        return a>b; 
    }
    int findKthLargest1(vector<int>& nums, int k) {
        //从大到小排序 —— 找到 k-1 个未知的数。
        int n = nums.size();
        sort(nums.begin(), nums.begin()+n, comp);
        return nums[k-1];
    }
    
    
    int findKthLargest(vector<int>& nums, int k) {
        //从大到小排序 —— 找到 k-1 个未知的数。
        QuickSort(nums, 0, nums.size()-1);
        return nums[k-1];

    }
    void QuickSort(vector<int> &nums, int left, int right){
        if(left < right){//左闭右闭   从大到小排序
            //相当于先序遍历， 先排好一个位置，然后继续搜索左右分别开工排序。一个个位置
            int pivot = Partition(nums, left, right);
            QuickSort(nums,left, pivot-1);
            QuickSort(nums,pivot+1, right);
        }

    }
    int Partition(vector<int> &nums,int left, int right){
        int pivot = nums[left];
        while(left < right){
            while( left<right && nums[right]<=pivot ) right--;
            nums[left] = nums[right];
            while( left<right && nums[left]>=pivot ) left++;
            nums[right] = nums[left];
        }
        nums[left] = pivot;
        return left;
    }
};

int main(){
    // vector<int> arr = {3,2,1,5,6,4};
    vector<int> arr = {3,1,2,4};
    // int k = 2;
    int k = 2;
    Solution so;
    int rel = so.findKthLargest1(arr, k);
    cout<<"result is :" << rel << endl;
    for(auto a:arr){
        cout << a << endl;
    }

    system("pause");
    return 0;
}



