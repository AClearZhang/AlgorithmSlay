/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\TwiceTimes\102.BinaryTreeOrderTraverse.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-04-01 10:44:15
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-04-01 11:01:17
 * @Version             : 1.0
 * @Description         : 二叉树层次遍历
 * 
 */
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include<unordered_set>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    /**
     * @Description: 注意 树中的层次遍历 不需要防止重复访问——因为不会回到父节点；
     *                  但是要去除 nullptr的节点。
     * @param {TreeNode} *root
     * @return {*}
     * @notes: 
     */
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        queue<TreeNode*> q;
        // unordered_set<TreeNode*> visited;
        vector<vector<int>> ans;
        
        if(root==nullptr) return ans;
        q.push(root);
        // visited.insert(root);
        int step = 0;

        while(!q.empty()){
            int sz = q.size();
            vector<int> tmp;
            for(int i=0;i<sz;i++){
                TreeNode* now = q.front();
                q.pop();
                tmp.push_back(now->val);
                // 结束条件

                // 下一层添加
                // if(!visited.count(now)){
                if(now->left){
                    q.push(now->left);
                }
                if(now->right){
                    q.push(now->right);
                }
                // visited.insert(now);
                // }

            }
            ans.push_back(tmp);
            step++;
        }
        return ans;
    }
};