/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\46.Permutations.cpp
 * @Author              : AClearZhang
 * @Date                : 2020-12-19 11:43:32
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2020-12-20 21:53:29
 * @Version             : 1.0
 * @Description         : 全排列
 * 给定一个 没有重复 数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @Description: 全排列 —— 使用回溯 “决策树”
     * @Param: 
     * @Return: 
     * @Notes: 
     */
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> track;
        recallTree(nums, track, ans);
        return ans;
    }
    void recallTree(vector<int> &nums, vector<int> &track, vector<vector<int>> &ans){
        if(track.size() == nums.size()){
            ans.push_back(track);
            return ;
        }

        // 选择列表的选择。
        for(int i=0; i < nums.size(); ++i ){
            if( find(track.begin(), track.end(), nums[i]) != track.end() ){
                // 找到了
                continue;
            }
            // 未找到进行添加，路径 添加
            track.push_back(nums[i]);
            recallTree(nums, track, ans);
            // 还原track
            track.pop_back();
        }


    }
};


int main(){

    vector<int> arr = {1,2,3};
    Solution so;
    auto rel = so.permute(arr);
    printf("输出结果为：/n");
    for(auto r: rel){
        cout << "[ " ;
        for(auto r2:r){
            cout << r2 << ", " ;
        }
        cout << " ]" << endl;
    }


    system("pause");
    return 0;
}
