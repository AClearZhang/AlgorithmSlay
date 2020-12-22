/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\111.MinDepOfBiTree.cpp
 * @Author              : AClearZhang
 * @Date                : 2020-12-22 17:09:14
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2020-12-22 21:08:03
 * @Version             : 1.0
 * @Description         : 求解二叉树的最小深度/高度
 * 
 * 111. 二叉树的最小深度
给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

说明：叶子节点是指没有子节点的节点。

 

示例 1：


输入：root = [3,9,20,null,null,15,7]
输出：2
示例 2：

输入：root = [2,null,3,null,4,null,5,null,6]
输出：5
 

提示：

树中节点数的范围在 [0, 105] 内
-1000 <= Node.val <= 1000
 */


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

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <queue>
#include <set>

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
     * @Description: 使用多个TreeNode 指针数组进行，层次遍历/层次建立搜索树的方法——寻找最小的深度
     * @Param: 
     * @Return: 
     * @Notes: 【注意：注释的代码  为框架的完整  方式，自行体悟与使用。】
     */
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;

        queue<TreeNode*> q;
        // set<TreeNode*> visited;


        // visited
        q.push(root);
        // visited.insert(root);

        int depth = 1;
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i<sz ;++i){
                //出队列
                TreeNode* cur = q.front();
                q.pop();

                //找其邻居
                if(cur->left){
                    //存在
                    //visited
                    q.push(cur->left);
                }
                if(cur->right){
                    //visited
                    q.push(cur->right);
                }
                //当前问题 最小高度
                if(!cur->left && !cur-> right){
                    // 都不存在，当前节点为叶子结点
                    return depth;
                }
                //设置为已访问 【但是二叉树不需要使用 visited —— 因为二叉树不会回退到父节点——只有二维数组会】
                // visited
                
            }// 遍历完一层次
            depth++;
        }
        return depth;
    }
};


int main(){

    // TreeNode *root = {3,9,20,nullptr, nullptr, 15, 7};

    system("pause");
    return 0;
}
