/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\637.AveOfLevelnBTree.cpp
 * @Author              : AClearZhang
 * @Date                : 2020-12-30 11:00:20
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2020-12-30 14:41:24
 * @Version             : 1.0
 * @Description         : 二叉树的层平均值
 * 637. 二叉树的层平均值
给定一个非空二叉树, 返回一个由每层节点平均值组成的数组。

 

示例 1：

输入：
    3
   / \
  9  20
    /  \
   15   7
输出：[3, 14.5, 11]
解释：
第 0 层的平均值是 3 ,  第1层是 14.5 , 第2层是 11 。因此返回 [3, 14.5, 11] 。
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
     * @Description: 简单的层次遍历
     * @param {*}
     * @return {*}
     * @notes: 
     */
    vector<double> averageOfLevels(TreeNode* root) {
        if(root == nullptr) return {};
        // visited 不需要
        queue<TreeNode*> q;
        vector<double> ans;

        // visit
        ans.push_back(root->val);
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            long sum = 0;  // 【注意需要32位有符号整型 变量。】
            while(sz--){
                TreeNode* cur = q.front();
                q.pop();
                // 剪枝

                // visit 加入
                if(cur->left)  {
                    sum+=cur->left->val;
                    q.push(cur->left);
                }
                if(cur->right)  {
                    sum+=cur->right->val;
                    q.push(cur->right);
                }
            }
            if(q.size()){

                ans.push_back((double)sum/q.size());
            }
        }
        return ans;
    }
};




int main(){

    system("pause");
    return 0;
    
}
