/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\BST\98.ValidInBST.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-01-14 17:17:41
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-01-15 11:36:49
 * @Version             : 1.0
 * @Description         : 验证BST 构建的合法性。
 * 98. 验证二叉搜索树
给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：

节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
示例 1:

输入:
    2
   / \
  1   3
输出: true
示例 2:

输入:
    5
   / \
  1   4
     / \
    3   6
输出: false
解释: 输入为: [5,1,4,null,null,3,6]。
     根节点的值为 5 ，但是其右子节点值为 4 。
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
     * @Description: 总的思路：使得中间的值大于所有左边 小于左右右边。
     * @param {*} 新函数--有最小节点和最大节点 ； 
     * @return {*}
     * @notes: 
     */
    bool isValidBST(TreeNode* root) {
        // if(root == nullptr) return true;
        return isValidBST(root, nullptr, nullptr);
    }
    // 辅助函数判断是否 大于和小于
    /**
     * @Description: 变相后序：使得左子树限定在不大于root，  右子树限定在不小于root
     * @param {*}  即：左子树 小于root<max>， 右子树 大于root<min>；
     * @return {*}
     * @notes: 
     */
    bool isValidBST(TreeNode* root, TreeNode* min, TreeNode* max){
        if(root == nullptr ) return true;
        // 三种--- 使得当前节点-不超过右子树min[就是root节点啊！]  大于左子树max[就是root节点啊]
        if(min!=nullptr && root->val <= min->val) return false;
        if(max!=nullptr && root->val >= max->val) return false;

        return isValidBST(root->left, min, root) 
                && isValidBST(root->right, root, max);

    }
    /**
     * @Description: 站在了 中间节点角度，上边是站在了 左右子树角度。
     * @param {*}
     * @return {*}
     * @notes: 
     */
    bool isValidBST(TreeNode* root, TreeNode* min, TreeNode* max){
        if(root == nullptr) return true;
        // 左搜---右边最小的
        bool left = isValidBST(root->left, min, root);
        bool right = isValidBST(root->right, root, max);

        if(max!=nullptr && root->val >= max->val) return false;
        if(min!=nullptr && root->val <= min->val) return false;
        return left && right;

        // if(root->val < min->val) {
        //     bool left = isValidBST(root->left, root, max);
        // }else{
        //     bool left = isValidBST(root->left, min, max);
        // }
        // if(root->val > max->val) {
        //     bool right = isValidBST(root->right, min, root);
        // }else{
        //     bool right = isValidBST(root->right, min, max);
        // }

        
            // visit 后序 【不对】。因为是看上面的 max和min是否有值！ 而不是看root->lefr 是否有值！
        // 叶子节点
        // if(root->left == nullptr && root->right==nullptr) return true;
        // // 单节点
        // else if(root->left == nullptr && root->val < min->val && left && right){
        //     return true;
        // }
        // else if(root->right == nullptr && root->val > max->val && left && right){
        //     return true;
        // }
        // // 双节点
        // else if(root->val > max->val && root->val < min->val && left && right){
        //     return true;
        // }
        // return false;
    }
};