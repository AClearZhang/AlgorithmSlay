/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\104.MaxDepthOfbinaryTree.cpp
 * @Author              : AClearZhang
 * @Date                : 2020-12-26 10:57:42
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2020-12-29 20:20:29
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
   15   7 返回它的最大深度 3 。
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
 * @Description: 深度搜索 找最大深度
 * @Param: 
 * @Return: 
 * @Notes: 
 */
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
     * @Param: queue，
     * @Return: 
     * @Notes: 【注意：】在这一题中，广搜和深搜的时间和空间复杂度是一样的。
     */
    int maxDepth1(TreeNode* root) {
        //visited 不用了
        if(root == nullptr) {return 0;}
        queue<TreeNode*> q;
        int height = 0;

        q.push(root);
        while(!q.empty()){
            // 开始bfs
            int sz = q.size();
            while(sz--){
                TreeNode* a = q.front();
                q.pop();

                // height

                // xunzhao1
                // visit
                if(a->left != nullptr){
                    q.push(a->left);

                }
                if(a->right!=nullptr){
                    q.push(a->right);

                }
                

            }
            height++;
        }

        return height;
    }
    /**
     * @Description: 大佬递归方法。
     * @Param: 
     * @Return: 
     * @Notes: 
     */
    int maxDepth2(TreeNode* root) {
        // 最大深度
        return root? 1 + max(maxDepth(root->left), maxDepth(root->right)): 0 ;
    }
};
int main()
{
    
    system("pause");
    return 0;
}

