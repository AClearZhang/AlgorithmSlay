/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\BST\99.RecoverBST.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-01-16 17:18:38
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-01-16 21:43:33
 * @Version             : 1.0
 * @Description         : 恢复二叉搜索树
 * 
 * 99. 恢复二叉搜索树
给你二叉搜索树的根节点 root ，该树中的两个节点被错误地交换。请在不改变其结构的情况下，恢复这棵树。

进阶：使用 O(n) 空间复杂度的解法很容易实现。你能想出一个只使用常数空间的解决方案吗？

 

示例 1：


输入：root = [1,3,null,null,2]
输出：[3,1,null,null,2]
解释：3 不能是 1 左孩子，因为 3 > 1 。交换 1 和 3 使二叉搜索树有效。
示例 2：


输入：root = [3,1,4,null,null,2]
输出：[2,1,4,null,null,3]
解释：2 不能在 3 的右子树中，因为 2 < 3 。交换 2 和 3 使二叉搜索树有效。
 

提示：

树上节点的数目在范围 [2, 1000] 内
-231 <= Node.val <= 231 - 1
 */

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

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
     * @Description: 找到并 交换恢复BST;且 只有一处错误
     * @param {*}
     * @return {*}
     * @notes: 
     */
    void recoverTree(TreeNode *root)
    {
        TreeNode *max= nullptr;
        TreeNode *min= nullptr;
        TreeNode *pre= nullptr;
        bool found = false;
        findRecover(root, pre, max, min, found);
        cout << max->val << endl;
        cout << min->val << endl;
        swap(max->val, min->val);
    }
    /**
     * @Description: 
     * @param {bool} isFound
     * @return {*}
     * @notes: 
     */
    void findRecover(TreeNode *root, TreeNode* &pre, TreeNode* &max, TreeNode* &min, bool &isFound)
    {
        if (root == nullptr)
            return;

        findRecover(root->left, pre, max, min, isFound);

        // 中序遍历
        if (pre!=nullptr && !isFound && root->val <= pre->val)
        {
            isFound = true; // 发现过一次错乱。
            max = pre;
            min = root;
            // pre = root;
            // return ;
        }
        else if (pre!=nullptr && isFound && root->val <= pre->val)
        { // 第二次发现错乱
            min = root;
        }
        pre = root;

        findRecover(root->right, pre, max, min, isFound);
    }
    // /**
    //  * @Description: 【注意】不一定只有上下交换，还有可能在其他分支平行交换。
    //  * @param {bool} isFound
    //  * @return {*}
    //  * @notes:
    //  */
    // void findRecover(TreeNode* root, TreeNode* min, TreeNode* max, bool isFound){
    //     if( isFound || root == nullptr) return;

    //     if(min!=nullptr && root->val <= min->val) {
    //         // found
    //         isFound = true;
    //         swap(root->val, min->val);
    //     }
    //     if(max!=nullptr && root->val >= max->val) {
    //         // found
    //         isFound = true;
    //         swap(root->val, max->val);
    //     }

    //     findRecover(root->left, min, root, isFound);
    //     findRecover(root->right, root, max, isFound);
    // }
};