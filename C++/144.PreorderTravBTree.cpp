/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\144.PreorderTravBTree.cpp
 * @Author              : AClearZhang
 * @Date                : 2020-12-30 21:18:18
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2020-12-30 21:58:17
 * @Version             : 1.0
 * @Description         : 二叉树的前序遍历
 * 
 * 给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
 * 
 * 提示：

树中节点数目在范围 [0, 100] 内
-100 <= Node.val <= 100
 

进阶：递归算法很简单，你可以通过迭代算法完成吗？
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
#include <stack>

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
     * @Description: 方法一：使用递归，返回前序遍历的输出
     * @param {*}
     * @return {*}
     * @notes: 
     */
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr) return ans;

        preDfs(root, ans);
        return ans;
    }
    // 辅助前序递归遍历
    void preDfs(TreeNode* root, vector<int> &ans){
        if(root == nullptr) return;

        ans.push_back(root->val);
        preDfs(root->left, ans);
        preDfs(root->right, ans);
    }

    /**
     * @Description: 使用非递归前序 —— stack方法。
     * @param {*}
     * @return {*}
     * @notes: 
     */
    vector<int> preorderTraversal1(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr) return ans;
        stack<TreeNode*> stack_node;
        stack_node.push(root);
        // ans.push_back(root->val);

        while(!stack_node.empty()){
            TreeNode* cur_node = stack_node.top();
            stack_node.pop();
            // 必须这里访问
            ans.push_back(cur_node->val);

            // 加入stack
            if(cur_node->right){
                stack_node.push(cur_node->right);
                // ans.push_back(cur_node->right->val);
            }
            if(cur_node->left) {  // 仍然层次 不对！
                stack_node.push(cur_node->left);
                // ans.push_back(cur_node->left->val);
            }
        }

        return ans;
    }
};





int main(){

    system("pause");
    return 0;
    
}
