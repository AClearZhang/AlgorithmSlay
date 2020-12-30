/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\105.ConstructBTree.cpp
 * @Author              : AClearZhang
 * @Date                : 2020-12-30 14:44:26
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2020-12-30 21:18:44
 * @Version             : 1.0
 * @Description         : 前序和中序遍历 序列来构建二叉树
 * 105. 从前序与中序遍历序列构造二叉树
根据一棵树的前序遍历与中序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7
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
     * @Description: 题目已知前序和中序，如何求 当前的树结构？
     * @param {*}
     * @return {*}
     * @notes: 
     */
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderMap;
        for(int i = 0; i<inorder.size() ;i++){
            inorderMap[inorder[i]] = i;
        }
        return helper(preorder, inorderMap, 0, preorder.size()-1, 0, inorder.size()-1);
    }
    // 辅助函数 —— 递归构建
    // 每次都构建根节点，然后 找中间点。  递归构建左右子树。  再回溯后序返回，——最终能返回到root
    TreeNode* helper(vector<int>& preorder,  unordered_map<int, int> &inorderMap, int preLeft, int preRight, int inLeft, int inRight){
        if( preLeft > preRight )  return nullptr;

        TreeNode* root = new TreeNode(preorder[preLeft]);
        int pivot = inorderMap[preorder[preLeft]];
        int num_left = pivot - inLeft, num_right = inRight - pivot;
        root->left = helper(preorder, inorderMap, preLeft+1, preLeft+num_left, inLeft, pivot-1);
        root->right = helper(preorder, inorderMap,  preLeft+num_left+1, preRight, pivot+1, inRight);
        return root;
    }
};



int main(){

    system("pause");
    return 0;
    
}
