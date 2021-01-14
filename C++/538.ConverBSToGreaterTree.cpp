/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\538.ConverBSToGreaterTree.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-01-14 16:36:44
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-01-14 16:54:35
 * @Version             : 1.0
 * @Description         : 转换BST 为累加树。 —— 【注意这道题目与1038相同。】
 * 538. 把二叉搜索树转换为累加树
给出二叉 搜索 树的根节点，该树的节点值各不相同，请你将其转换为累加树（Greater Sum Tree），使每个节点 node 的新值等于原树中大于或等于 node.val 的值之和。

提醒一下，二叉搜索树满足下列约束条件：

节点的左子树仅包含键 小于 节点键的节点。
节点的右子树仅包含键 大于 节点键的节点。
左右子树也必须是二叉搜索树。
注意：本题和 1038: https://leetcode-cn.com/problems/binary-search-tree-to-greater-sum-tree/ 相同

 

示例 1：



输入：[4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
输出：[30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
示例 2：

输入：root = [0,null,1]
输出：[1,null,1]
示例 3：

输入：root = [1,0,2]
输出：[3,3,2]
示例 4：

输入：root = [3,2,4,1]
输出：[7,9,4,10]
 

提示：

树中的节点数介于 0 和 104 之间。
每个节点的值介于 -104 和 104 之间。
树中的所有值 互不相同 。
给定的树为二叉搜索树。
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
     * @Description: 基本思路——因为BST中序遍历为升序；这里只需要右中左--这样的中序即可 完成大到小的累加
     * @param {*}
     * @return {*}
     * @notes: 
     */
    TreeNode* convertBST(TreeNode* root) {
        if(root == nullptr) return nullptr;

        int accumuSum = 0;
        sumGreaterBST(root, accumuSum);
        return root;
    }
    // 辅助函数 —— 累加当前节点。中序遍历。
    void sumGreaterBST(TreeNode* root, int& sum){
        if(root == nullptr) return ;
        sumGreaterBST(root->right, sum);
        // 中序  visit
        sum+=root->val;
        root->val = sum;
        sumGreaterBST(root->left, sum);
    }
};



int main(){

    system("pause");
    return 0;
}