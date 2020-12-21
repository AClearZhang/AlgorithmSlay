/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\77.combinations.cpp
 * @Author              : AClearZhang
 * @Date                : 2020-12-20 22:11:50
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2020-12-20 22:11:51
 * @Version             : 1.0
 * @Description         : 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

示例:

输入: n = 4, k = 2
输出:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combinations
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
     * @Description: 46是为排列，本题为组合
     * @Param: 
     * @Return: 
     * @Notes: 
     */
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> comb(k,0); // 记录
        int count = 0;
        backtracking(ans, comb, count, 1, n, k);
        // recallTree(n,k,0, track, ans);
        return ans;
    
    }
    /**
     * @Description: 大佬的做法
     * @Param: 
     * @Return: 
     * @Notes: 
     */
    void backtracking(vector<vector<int>> &ans, vector<int> &comb, int &count, int pos, int n, int k){
        if(count == k){
            ans.push_back(comb);
            return ;
        }
        // pos是下一个位置到末尾，所以不会 重复。yes 我也想到了
        // 只不过我的有剪枝
        for( int i =  pos; i <= n ; ++i){
            comb[count++] = i; //修改当前节点状态
            backtracking(ans, comb, count, i+1, n, k);
            --count;
        }
    }

    /**
     * @Description: 我的做法—— l1——n； 到  n-k+1+(l1-1)
     * @Param: 
     * @Return: 
     * @Notes: 
     */    
    void recallTreeMe(int n, int k, int level, vector<int> &track, vector<vector<int>> &ans)
    {
        if (track.size() == nums.size())
        {
            ans.push_back(track);
            return;
        }

        // 选择列表的选择。
        for (int i = 0; i < nums.size(); ++i)
        {
            if (find(track.begin(), track.end(), nums[i]) != track.end())
            {
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

int main()
{

    vector<int> arr = {1, 2, 3};
    Solution so;
    auto rel = so.permute(arr);
    printf("输出结果为：/n");
    for (auto r : rel)
    {
        cout << "[ ";
        for (auto r2 : r)
        {
            cout << r2 << ", ";
        }
        cout << " ]" << endl;
    }

    system("pause");
    return 0;
}
