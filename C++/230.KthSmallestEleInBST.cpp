/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\230.KthSmallestEleInBST.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-01-11 22:34:16
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-01-13 17:01:34
 * @Version             : 1.0
 * @Description         : 二叉搜索树中 第k小的元素。
 * 230. 二叉搜索树中第K小的元素
给定一个二叉搜索树，编写一个函数 kthSmallest 来查找其中第 k 个最小的元素。

说明：
你可以假设 k 总是有效的，1 ≤ k ≤ 二叉搜索树元素个数。

示例 1:

输入: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
输出: 1
示例 2:

输入: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
输出: 3
进阶：
如果二叉搜索树经常被修改（插入/删除操作）并且你需要频繁地查找第 k 小的值，你将如何优化 kthSmallest 函数？
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
     * @Description: 寻找BST中第k小的数。简单——因为中序遍历即为升序。
     * @param {int} k
     * @return {*}
     * @notes: 
     */
    int kthSmallest(TreeNode* root, int k) {
        int ans=0, cur=0;
        findKthSmallest(root, k, cur, ans);
        return ans;
    }
    // 辅助函数 —— 返回找到的第k小的数。
    void findKthSmallest(TreeNode* root, int k, int& cur, int& ans){
        if(root == nullptr || cur == k) return ; 
        findKthSmallest(root->left, k, cur, ans);
        // 中序找到返回
        if(cur == k) {
            return ;
        }
        if(++cur == k){
            ans = root->val;
            return ;
        }
        findKthSmallest(root->right, k, cur, ans);

    }
};


int main(){

    system("pause");
    return 0;
}