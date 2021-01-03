/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\114.FlattenBTreeToList.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-01-02 21:53:58
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-01-03 20:23:15
 * @Version             : 1.0
 * @Description         : 二叉树展开为链表
 * 
 * 114. 二叉树展开为链表
给定一个二叉树，原地将它展开为一个单链表。

 
例如，给定二叉树

    1
   / \
  2   5
 / \   \
3   4   6
将其展开为：

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
 */

#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <windows.h>

using namespace std;

//  Definition for a Node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    /**
     * @Description: 递归 且 重想不干扰原先结构。
     * @param {TreeNode} *root
     * @return {*}
     * @notes: 【可以后序遍历】
     */
    void flatten(TreeNode *root)
    {
        if(root == nullptr) return ;
        
        flatten(root->left);
        flatten(root->right);

        // 开始展开成一侧 并 重置为nullptr
        if(root->left == nullptr)  return;
        // 两侧都有值，开始 flatten
        TreeNode* tmp = root->right;
        root->right = root->left;
            // 寻找最后一个 尾节点链接到tmp
        TreeNode* cur=root->right;
        while(cur->right != nullptr) cur = cur->right;
        cur->right = tmp;
        root->left = nullptr;
    }

    
    /**
     * @Description: 注意是要求本地展开为一个链表！ 先序遍历思想 —— 不太对 重新想递归。
     * @param {TreeNode} *root
     * @return {*}
     * @notes: 
     */
    void flatten1(TreeNode *root)
    {
        if(root == nullptr) return ;
        dfsAndPoint(root->left, root, root->right);
    }
    void dfsAndPoint(TreeNode* root, TreeNode* cur, TreeNode* tmp){
        // 深搜并替换
        // 边界
        if(root==nullptr) return;
            // 特殊 结果处理
        if(cur->right == root) {
            // 重置并返回；因为已经链接上了
            cur = tmp;
            tmp = cur->right;
            return ;
        }

        // 先序遍历
        // visit
        cur->right = root;
        // root->

        dfsAndPoint(root->left, cur, tmp);  // 【想法有地方没有覆盖 —— 并不算递归 重复调用，因为会打乱之前的 树的链接！】



    }
};

int main()
{

    system("pause");
    return 0;
}