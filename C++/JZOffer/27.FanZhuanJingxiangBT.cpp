/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\JZOffer\27.FanZhuanJingxiangBT.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-05-08 21:05:41
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-05-08 21:12:08
 * @Version             : 1.0
 * @Description         : 翻转二叉树——二叉树的镜像
 * 
 */

#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

#define For(x, y, z) for (ll x = y; x < z; ++x)
typedef long long ll;


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * @Description: 翻转二叉树。
 * @param {*}
 * @return {*}
 * @notes: 当前节点：左右互换；后序遍历； null 则回退。
 */
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(root == nullptr || (root->left==nullptr && root->right==nullptr)){
            return root;
        }
        root->left = mirrorTree(root->left);
        root->right = mirrorTree(root->right);
        TreeNode *tmp = root->right;
        root->right = root->left;
        root->left = tmp;
        return root;
    }
};
