/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\110.AVLInit.cpp
 * @Author              : AClearZhang
 * @Date                : 2020-12-28 20:04:43
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2020-12-28 22:16:21
 * @Version             : 1.0
 * @Description         : 平衡二叉树 合法性判断
 * 
 * 110. 平衡二叉树
给定一个二叉树，判断它是否是高度平衡的二叉树。

本题中，一棵高度平衡二叉树定义为：

一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。

 

示例 1：


输入：root = [3,9,20,null,null,15,7]
输出：true
示例 2：


输入：root = [1,2,2,3,3,null,null,4,4]
输出：false
示例 3：

输入：root = []
输出：true
 

提示：

树中的节点数在范围 [0, 5000] 内
-104 <= Node.val <= 104
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

/**
 * @Description: 我的递归做法。
 * @Param: 
 * @Return: 
 * @Notes: 
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true; // 空的也是AVL树
        if( abs(maxDepth(root->left) - maxDepth(root->right)) <= 1 ){
            return isBalanced(root->left)&&isBalanced(root->right) ? true : false ;
        }else{
            return false;
        }

    }

    int maxDepth(TreeNode* root){
        return root? 1+ max( maxDepth(root->left), maxDepth(root->right)) : 0 ;
    }
};

/**
 * @Description: 大佬的解法，有了-1就提前结束。
 * @Param: 
 * @Return: 
 * @Notes: 
 */
class Solution1 {
public:
    bool isBalanced(TreeNode* root) {
        if( helper(root) == -1 ){
            return false;
        }else{
            return true;
        }
    }
    // 辅助函数
    int helper(TreeNode* root){
        if(!root){
            return 0;
        }
        int left = helper(root->left), right = helper(root->right);
        if( left == -1 || right == -1 || abs(left - right) > 1 ){
            return -1;
        }
        return 1 + max(left, right);
    }
};


int main()
{
    
    system("pause");
    return 0;
}

