/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\BST\701.InsertInBST.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-01-14 17:17:01
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-01-16 11:32:10
 * @Version             : 1.0
 * @Description         : 二叉树中插入操作
 * 
 */


#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <cmath>
#include <algorithm>

using namespace std;

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
     * @Description: 简单点 插入在叶子节点
     * @param {*}
     * @return {*}
     * @notes: 
     */
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr)  return new TreeNode(val);
        
        // 如果存在 则返回避免重复插入
        if(val == root->val) return root;
        else if(val < root->val) root->left = insertIntoBST(root->left, val);
        else if(val > root->val) root->right = insertIntoBST(root->right, val);
        return root;
    }
};


int main(){
    
    system("pause");
    return 0;
}