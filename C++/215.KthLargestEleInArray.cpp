/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\215.kthLargestEleInArray.cpp
 * @Author              : AClearZhang
 * @Date                : 2020-12-14 22:04:43
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2020-12-15 20:53:52
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
#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <windows.h>

using namespace std;

class Solution
{
public:
    bool static comp(int a, int b)
    {
        return a > b;
    }
    /**
     * @Description: 方法二——注意在类内 由于需要一个全局的静态成员函数， 所以加了static；进行从大到小的比较。
     * @Param: 
     * @Return: 
     * @Notes: 24ms  the BEST！
     */
    int findKthLargest1(vector<int> &nums, int k)
    {
        //从大到小排序 —— 找到 k-1 个未知的数。
        int n = nums.size();
        sort(nums.begin(), nums.begin() + n, comp);
        return nums[k - 1];
    }

    /**
     * @Description: 下面通过自定义快排序实现 从大到小排序。
     * @Param: 
     * @Return: 
     * @Notes: 180ms
     */
    int findKthLargest(vector<int> &nums, int k)
    {
        //从大到小排序 —— 找到 k-1 个未知的数。
        QuickSort(nums, 0, nums.size() - 1);
        return nums[k - 1];
    }
    void QuickSort(vector<int> &nums, int left, int right)
    {
        if (left < right)
        { //左闭右闭   从大到小排序
            //相当于先序遍历， 先排好一个位置，然后继续搜索左右分别开工排序。一个个位置
            int pivot = Partition(nums, left, right);
            QuickSort(nums, left, pivot - 1);
            QuickSort(nums, pivot + 1, right);
        }
    }
    int Partition(vector<int> &nums, int left, int right)
    {
        int pivot = nums[left];
        while (left < right)
        {
            while (left < right && nums[right] <= pivot)
                right--;
            nums[left] = nums[right];
            while (left < right && nums[left] >= pivot)
                left++;
            nums[right] = nums[left];
        }
        nums[left] = pivot;
        return left;
    }
    /**
     * @Description: 同时改变快速排序的想法；  实现快速选择。 —— 新增
     * @Param: 
     * @Return: 
     * @Notes: 注意不同于快速排序的地方——快速选择只需要找到第k大的枢轴值(pivot)即可，然后  再在大于或小于的方向缩小范围寻找 “位置”。
     */
    int findKthLargest2(vector<int> &nums, int k)
    {
        // 仍然从小到大快速选择；找到导数第k个， 即正数第nums.size()-k+1个；但是需要数组从零开始所以是数组 nums.size()-k
        int l = 0, r = nums.size() - 1, target = nums.size() - k;
        while (l < r)
        {
            int pivot = quickSelection(nums, l, r);
            if (pivot == target)
                return nums[pivot];
            else if (pivot > target)
                r = pivot - 1;
            else
            {
                l = pivot + 1;
            }
        }
        // 如果说没找到l==r了；返回 此时位置即可。
        return nums[l];
    }
    // 辅助函数 —— 快速选择位置 
    // 52ms
    int quickSelection(vector<int> &nums, int l, int r)
    {
        int pivot = nums[l];
        while (l < r)
        {
            while (l < r && nums[r] >= pivot)
                r--;
            nums[l] = nums[r];
            while (l < r && nums[l] <= pivot)
                l++;
            nums[r] = nums[l];
        }
        // 当前l为枢轴值，定了
        nums[l] = pivot;
        return l;
    }
    // 辅助函数 —— 快速选择c++ 大佬做题
    //不好136ms
    int quickSelection101(vector<int> &nums, int l, int r)
    {
        int i = l + 1, j = r;
        while (true)
        {
            while (i < r && nums[i] <= nums[l])
            {
                ++i;
            }
            while (l < j && nums[j] >= nums[l])
            {
                --j;
            }
            if (i >= j)
            {
                break;
            }
            swap(nums[i], nums[j]);
        }
        swap(nums[l], nums[j]);
        return j;
    }
};

int main()
{
    // vector<int> arr = {3,2,1,5,6,4};
    vector<int> arr = {3, 1, 2, 4};
    // int k = 2;
    int k = 2;
    Solution so;
    // int rel = so.findKthLargest1(arr, k);
    int rel = so.findKthLargest2(arr, k);
    cout << "result is :" << rel << endl;
    for (auto a : arr)
    {
        cout << a << endl;
    }

    system("pause");
    return 0;
}
