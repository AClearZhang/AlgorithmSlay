/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\106.ConsBTreeFromMPost.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-01-03 21:50:33
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-01-04 11:03:17
 * @Version             : 1.0
 * @Description         : 106 通过中序和后序来构造二叉树
 * 106. 从中序与后序遍历序列构造二叉树
根据一棵树的中序遍历与后序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

中序遍历 inorder = [9,3,15,20,7]
后序遍历 postorder = [9,15,7,20,3]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7
 */
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
     * @Description: 使用后序和中序 遍历构建一棵二叉树 —— 类似于前序和中序的反过程
     * @param {*}
     * @return {*}
     * @notes: 
     */
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> inorderMap;
        for(int i = 0; i<inorder.size() ;i++){
            inorderMap.insert({inorder[i], i});
        }

        return helper(postorder, inorderMap, 0, postorder.size()-1, 0, inorder.size()-1);
    }
    // 辅助函数构建二叉树  
    // 左闭右闭
    TreeNode* helper(vector<int> &postorder, unordered_map<int,int> &inorderMap, int postLeft, int postRight, int inLeft, int inRight){
        if(postLeft > postRight) return nullptr;


        // 相信并想象如何递归构建
        TreeNode* root = new TreeNode(postorder[postRight]);
        
        
        int pivot =  inorderMap[postorder[postRight]]; // 寻找 中序的分治点。
        root->left = helper( postorder, inorderMap, 0, postLeft+(pivot-inLeft)-1, 0, pivot-1);
        root->right = helper( postorder, inorderMap, postLeft+(pivot - inLeft), postLeft+inRight-inLeft, pivot+1, inRight);
        return root;
    }
};



int main(){

    system("pause");
    return 0;
    
}

