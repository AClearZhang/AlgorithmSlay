/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\236.LowestCommonAncestor.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-01-18 18:24:51
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-01-20 15:58:59
 * @Version             : 1.0
 * @Description         : 寻找二叉树中的 最近公共祖先
 * 
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
     * @Description: 我的解法：因为定义、参数 、返回值运用
     * @param {*} 定义寻找【公共】祖先 ，所以公共，且最近。由于还有返回值 所以可以充分运用 ——
     *                  递归 + 当前节点思想—— 【首先 null 则返回null；其它返回有用的祖先 -- 因为自身可以为祖先so】
     *                         ① 当前是公共节点 且不为自身(左右已经获得了node*) 
     *                          ②  本身是其中一个(p,q)，返回这个 root
     *                           ③  左右存在值 则返回左右任意一个，其它返回null；
     * @return {*}
     * @notes: 【注意】每次递归——就是在把 “以root 为根”转移成“以root的子节点为根”，不断缩小问题规模 重复迭代/递归的过程。
     *          思考的定义/当前节点应该做：分为 param中的 三种情况。
     */
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return nullptr;
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // 找到公共
        if((left == p && right == q) || (left == q && right == p))  return root;
        else if(root == p || root == q) return root;
        else if(left != nullptr) return left;
        else if(right != nullptr) return right;
        return nullptr;
    }
    // dong的解法
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return nullptr;
        if(root == p || root == q) return root;

        // 用后序遍历 —— 方便找到最近的公共祖先
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // 当前节点，分为三种情况
        if(left != nullptr && right != nullptr) return root;
        else if(left == nullptr && right == nullptr) return nullptr;
        else{
            return left == nullptr ? right : left ;
        }

    }
};

int main() {

    system("pause");
    return 0;
}
