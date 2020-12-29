/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\437.PathSumIII.cpp
 * @Author              : AClearZhang
 * @Date                : 2020-12-29 20:22:11
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2020-12-29 22:19:11
 * @Version             : 1.0
 * @Description         : 路径总和
 * 437. 路径总和 III
给定一个二叉树，它的每个结点都存放着一个整数值。

找出路径和等于给定数值的路径总数。

路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。

二叉树不超过1000个节点，且节点数值范围是 [-1000000,1000000] 的整数。

示例：

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

返回 3。和等于 8 的路径有:

1.  5 -> 3
2.  5 -> 2 -> 1
3.  -3 -> 11
 */



#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <windows.h>

using namespace std;

//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    /**
     * @Description: 
     * @param {int} sum
     * @return {*}
     * @notes: 【注意】这里的路径说的是，从上往下的路径， 不包括回去绕个 节点的路径！
     */
    int pathSum(TreeNode* root, int sum) {
        // 前序遍历/深搜 + 自动回溯。
        // 全部从上到下 遍历一遍。
        if( root == nullptr) return 0;

        // visit
        int count = dfsAndTrack(root, sum);
            // dfs
        count += pathSum(root->left, sum);
        count += pathSum(root->right, sum);
        return count;

    }
    // 上述辅助函数，对应深搜和track
    int dfsAndTrack(TreeNode* root, int sum){
        if(root == nullptr)  return 0;

        // visit
        bool flag = false;
        if(root->val == sum ) flag = true;
        
        return flag ? 1+dfsAndTrack(root->left, sum-root->val)+dfsAndTrack(root->right, sum-root->val) 
                    : dfsAndTrack(root->left, sum-root->val)+dfsAndTrack(root->right, sum-root->val) ; // 这里注意两边是分别独立的。

    }
};

int main()
{
       
    system("pause");
    return 0;
}

