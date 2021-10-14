/*
 * @FilePath            : \project\AlgorithmSlay\C++\JZOffer\40.ZuiXiaoDeKGeShu.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-10-14 22:08:56
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-10-14 23:40:58
 * @Version             : 1.0
 * @Description         : 剑指 Offer 40. 最小的k个数
输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。

 

示例 1：

输入：arr = [3,2,1], k = 2
输出：[1,2] 或者 [2,1]
示例 2：

输入：arr = [0,1,2,1], k = 1
输出：[0]
 

限制：

0 <= k <= arr.length <= 10000
0 <= arr[i] <= 10000
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
class Solution
{
public:
    int Partition(vector<int> &nums, int n, int left, int right)
    {
        int pivot = nums[left];
        while (left < right)
        {
            while (left < right && nums[right] >= pivot)
                right--;
            nums[left] = nums[right];
            while (left < right && nums[left] <= pivot)
                left++;
            nums[right] = nums[left];
        }
        nums[left] = pivot;
        return left;
    }
    vector<int> getLeastNumbers(vector<int> &arr, int k)
    {
        vector<int> res;
        int n = arr.size();
        if( k <= 0 || n <=0) return res;
        int left = 0, right = n - 1;
        int index = Partition(arr, n, left, right);
        // 当 index在k-1时候，左边都是 k个小的！
        while(index != (k - 1)){
            if( index > (k-1) ){
                right = index - 1;
                index = Partition(arr, n, left, right);
            }else{
                left = index + 1;
                index = Partition(arr, n, left, right);
            }
        }

        // k个赋值
        for( int i = 0; i<k ;i++ ){
            res.push_back(arr[i]);
        }
        return res;

    }
};
