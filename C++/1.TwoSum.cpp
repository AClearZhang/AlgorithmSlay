/*
 * @FilePath            : \AlgorithmSlay\C++\1,TwoSum.cpp
 * @Author              : AClearZhang
 * @Date                : 2020-11-22 22:57:29
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2020-11-22 23:15:14
 * @Version             : 1.0
 * @Description         : 两数之和  C++
 * 
 * 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

 

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include <vector>
#include <iostream>
#include <windows.h>

using namespace std;

//方法一 暴力法：
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i,j;
        for(i=0;i<nums.size()-1;i++)
        {
            for(j=i+1;j<nums.size();j++)
            {
                if(nums[i]+nums[j]==target)
                {
                   return {i,j};
                }
            }
        }
        return {i,j};
    };
};

int main(){

    Solution s;
    vector<int> c = {2, 7, 11, 15};
    vector<int> a = s.twoSum( c, 9);
    for(int i = 0; i<a.size() ;i++){
        cout << a[i] << " ";
    }
    system("pause");
    return 0;
}


