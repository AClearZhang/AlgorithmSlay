/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\226.InvertBTree.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-01-02 21:04:35
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-01-02 21:14:15
 * @Version             : 1.0
 * @Description         : 翻转二叉树
 * 
 * 226. 翻转二叉树
翻转一棵二叉树。

示例：

输入：

     4
   /   \
  2     7
 / \   / \
1   3 6   9
输出：

     4
   /   \
  7     2
 / \   / \
9   6 3   1
备注:
这个问题是受到 Max Howell 的 原问题 启发的 ：

谷歌：我们90％的工程师使用您编写的软件(Homebrew)，但是您却无法在面试时在白板上写出翻转二叉树这道题，这太糟糕了。
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
     * @Description: 前序遍历， 调换左右子树
     * @param {*}
     * @return {*}
     * @notes: 
     */
    TreeNode* invertTree(TreeNode* root) {
        // 翻转二叉树 —— 镜像； 直接调换左右子树。
        // 是叶子结点 则返回
        if(root == nullptr ) {
            return nullptr;
        }

        // 调换左右子树
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        // 前序递归遍历
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};



int main(){


    system("pause");
    return 0;
}
