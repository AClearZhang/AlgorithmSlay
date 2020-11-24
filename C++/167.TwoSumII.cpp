/*
 * @FilePath            : \AlgorithmSlay\C++\2.TwoSumII.cpp
 * @Author              : AClearZhang
 * @Date                : 2020-11-22 21:57:43
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2020-11-23 22:14:46
 * @Version             : 1.0
 * @Description         : 101 LeetCode双指针题目中的问题
 */

// 给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。

// 函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。

// 说明:

// 返回的下标值（index1 和 index2）不是从零开始的。
// 你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
// 示例:

// 输入: numbers = [2, 7, 11, 15], target = 9
// 输出: [1,2]
// 解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。

// class Solution {
// public:
//     vector<int> twoSum(vector<int> &numbers, int target) {
//         vector<int> result;
//         int low=0, high = numbers.size()-1;
//         while (low < high){
//             if (numbers[low] + numbers[high] == target){
//                 result.push_back(low+1);
//                 result.push_back(high+1);
//                 return result;
//             }else{
//                 numbers[low] + numbers[high] > target ? high-- : low++;
//             }
//         }
//         return result;
//     }
// };

// 区别于上一个 —— 因为已经排好序了。所以可以直接 双指针按顺序做.
// 且一定能 双指针遍历一遍就   一定得到解答
#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        // 双指针 有序  双向遍历
        int head = 0, tail = numbers.size() - 1;
        int sum = numbers[head] + numbers[tail];
        while (head < tail)
        {
            if (sum == target)
            {
                return {head + 1, tail + 1};
            }
            else if (sum > target)
            {
                tail--;
            }
            else if (sum < target)
            {
                head++;
            }
            sum = numbers[head] + numbers[tail];
        }
        return {-1, -1};
    }
};

int main()
{
    Solution s;
    vector<int> c = {2, 7, 11, 15};
    vector<int> a = s.twoSum(c, 9);
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    system("pause");
    return 0;
}
