/*
 * @FilePath            : \project\AlgorithmSlay\C++\107.BinaryTreeLevelTraII.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-04-25 00:08:24
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-04-25 00:20:15
 * @Version             : 1.0
 * @Description         : 二叉树层次遍历II
 * 
 */


#include <vector>
#include <iostream>
#include <queue>

using namespace std;

#define For(x,y,z) for(int x=y; x<z; x++)




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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if(root)
            q.push(root);

        while(!q.empty())
        {
            int sz = q.size();
            vector<int> tmp;

            for(int i = 0;i < sz;i++)
            {
                // solve
                root = q.front();
                q.pop();
              
                tmp.push_back(root->val);

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

            res.push_back(tmp);
        }
        // reverse  jike
        int nRes = res.size();
        For(i,0,nRes/2){
            swap(res[i],res[nRes-1-i]);
        }
        return res;
    }
};