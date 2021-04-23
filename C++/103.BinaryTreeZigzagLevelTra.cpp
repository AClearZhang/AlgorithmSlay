/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\103.BinaryTreeZigzagLevelTra.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-04-23 10:52:30
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-04-23 11:18:12
 * @Version             : 1.0
 * @Description         : 二叉树的锯齿形层序遍历。
 * 103. 二叉树的锯齿形层序遍历
给定一个二叉树，返回其节点值的锯齿形层序遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回锯齿形层序遍历如下：

[
  [3],
  [20,9],
  [15,7]
]
通过次数133,159提交次数233,143
 */

/**
 * Definition for a binary tree node.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

#define For(x,y,z) for(int x=y, x<z, x++)


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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if(root)
            q.push(root);
        bool lr = true;

        while(!q.empty())
        {
            int sz = q.size();
            vector<int> level(sz,0);

            for(int i = 0;i < sz;i++)
            {
                // solve
                root = q.front();
                q.pop();
                level[lr ? i : sz - i - 1] = root->val;

                // neighbor
                if(root->left)
                {
                    q.push(root->left);
                }
                if(root->right)
                {
                    q.push(root->right);
                }
            }

            res.push_back(level);
            lr = !lr;
        }
        return res;
    }
};