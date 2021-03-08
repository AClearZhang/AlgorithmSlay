/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\DynamicProgram\337.HouseRobberIII.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-03-08 17:39:00
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-03-08 22:45:58
 * @Version             : 1.0
 * @Description         : 房屋抢劫III
 * 337. 打家劫舍 III
在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为“根”。 除了“根”之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。

计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。

示例 1:

输入: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \ 
     3   1

输出: 7 
解释: 小偷一晚能够盗取的最高金额 = 3 + 3 + 1 = 7.
示例 2:

输入: [3,4,5,1,3,null,1]

     3
    / \
   4   5
  / \   \ 
 1   3   1

输出: 9
解释: 小偷一晚能够盗取的最高金额 = 4 + 5 = 9.
 */


#include <iostream>
#include <cmath>
#include <windows.h>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    /**
     * @Description: 继续使用实际定义——找状态 + 选择 == 偷or不偷
     * @param {*}
     * @return {*}
     * @notes: rob 返回当前node下  偷取的最大数值
     */
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> memo;
        return RobRecall(root, memo);
    }
    int RobRecall(TreeNode* root, unordered_map<TreeNode* , int> &memo){
        if(!root) return 0;
        if(memo.find(root) != memo.end()) return memo[root];

        // dp start
        int res = 0;
        int get = 0, not_get = 0;
            // 取
        get = root->val + 
                (root->left==nullptr?0:RobRecall(root->left->left, memo)+RobRecall(root->left->right, memo)) +
                (root->right==nullptr?0:RobRecall(root->right->left, memo)+RobRecall(root->right->right, memo));
                
            // 不取
        not_get = RobRecall(root->left, memo) + RobRecall(root->right, memo);
        res = max(get, not_get);
        memo[root] = res;
        return res;
    }
};