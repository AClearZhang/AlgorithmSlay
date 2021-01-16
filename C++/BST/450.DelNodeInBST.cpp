/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\BST\450.DelNodeInBST.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-01-14 17:16:46
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-01-16 16:31:11
 * @Version             : 1.0
 * @Description         : 删除bst 一个节点
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
     * @Description: 删除节点三种情况：①叶子节点直接删除 ②单独节点删除并返回有的 一个节点 ③中间节点找到最小值 替换并递归删除
     * @param {*}
     * @return {*}
     * @notes: 
     */
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return nullptr;

        // 如果是当前值 —— 再分三种情况。
        if(root->val == key) {
            // 1
            if(root->left==nullptr && root->right == nullptr) return nullptr;
            // 2
            if(root->left == nullptr) return root->right;
            if(root->right == nullptr) return root->left;
            // 3 ; 找到右边最小的节点替换，并递归删除叶子结点
            int tmp = root->val;
            root->val = getMin(root->right, tmp);

            root->right = deleteNode(root->right, tmp);
        }
        if(key < root->val) root->left = deleteNode(root->left, key);
        else if(key > root->val) root->right = deleteNode(root->right, key);

        return root;
    }
    // 辅助函数寻找当前bst的最小值，最左边！
    int getMin(TreeNode* root, int val){
        while(root->left != nullptr) root = root->left;
        int tmp = root->val;
        root->val = val;
        return tmp;
    }
};
