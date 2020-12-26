/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\104.MaxDepthOfbinaryTree.cpp
 * @Author              : AClearZhang
 * @Date                : 2020-12-26 10:57:42
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2020-12-26 11:22:15
 * @Version             : 1.0
 * @Description         : 求二叉树的最大深度
 * 104. 二叉树的最大深度
给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。

示例：
给定二叉树 [3,9,20,null,null,15,7]，

    3
   / \
  9  20
    /  \
   15   7
返回它的最大深度 3 。
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
    int maxDepth(TreeNode* root) {
        //深搜/遍历 找高度
        if(root == nullptr) return 0;

        int cur = 1, height = 1;
        dfs(root->left, cur+1, height);
        dfs(root->right, cur+1, height);
        return height;
    }
    void dfs(TreeNode* root, int cur, int& height){
        // 边界
        if(root == nullptr) {return ;}

        // do比较设置
        height = cur>height? cur : height;
        // 继续深搜
        dfs(root->left, cur+1, height);
        dfs(root->right, cur+1, height);

    }

    /**
     * @Description: BFS广搜/层次 找高度
     * @Param: 
     * @Return: 
     * @Notes: 
     */
    int maxDepth1(TreeNode* root) {
        
    }
};
int main()
{
    
    system("pause");
    return 0;
}

