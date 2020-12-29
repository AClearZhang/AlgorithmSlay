/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\101.SymmetricTree.cpp
 * @Author              : AClearZhang
 * @Date                : 2020-12-29 21:40:57
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2020-12-29 21:42:04
 * @Version             : 1.0
 * @Description         : 对称二叉树
 * 
 * 101. 对称二叉树
给定一个二叉树，检查它是否是镜像对称的。

 

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
 

但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3
 

进阶：

你可以运用递归和迭代两种方法解决这个问题吗？
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
     * @param {*}
     * @return {*}
     * @notes: 
     */
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        // if(!root->left || !root->right) return false;

        return helper(root->left, root->right);
    }
    // 辅助函数——对应对称搜索 左右两棵子树。
    bool helper(TreeNode* root1, TreeNode* root2){
        // 边界 / 结束条件
        if(root1 == nullptr && root2 == nullptr) return true;
        if(!root1 || !root2 ) return false;

        // 开始后序遍历
        return helper(root1->left, root2->right) && helper(root1->right, root2->left) 
                && root1->val == root2->val;

    }
};


int main(){

    system("pause");
    return 0;
    
}
