/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\Others\CompleteBinaryTree.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-01-18 17:08:58
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-01-18 17:20:15
 * @Version             : 1.0
 * @Description         : 完全二叉树  最小时间复杂度的——全部节点的计算方法
 * 如果是一个普通二叉树，显然只要向下面这样遍历一边即可，时间复杂度 O(N)：

public int countNodes(TreeNode root) {
    if (root == null) return 0;
    return 1 + countNodes(root.left) + countNodes(root.right);
}
那如果是一棵满二叉树，节点总数就和树的高度呈指数关系，时间复杂度 O(logN)：

public int countNodes(TreeNode root) {
    int h = 0;
    // 计算树的高度
    while (root != null) {
        root = root.left;
        h++;
    }
    // 节点总数就是 2^h - 1
    return (int)Math.pow(2, h) - 1;
}
完全二叉树比普通二叉树特殊，但又没有满二叉树那么特殊，计算它的节点总数，可以说是普通二叉树和完全二叉树的结合版，先看代码：

public int countNodes(TreeNode root) {
    TreeNode l = root, r = root;
    // 记录左、右子树的高度
    int hl = 0, hr = 0;
    while (l != null) {
        l = l.left;
        hl++;
    }
    while (r != null) {
        r = r.right;
        hr++;
    }
    // 如果左右子树的高度相同，则是一棵满二叉树
    if (hl == hr) {
        return (int)Math.pow(2, hl) - 1;
    }
    // 如果左右高度不同，则按照普通二叉树的逻辑计算
    return 1 + countNodes(root.left) + countNodes(root.right);
}
结合刚才针对满二叉树和普通二叉树的算法，上面这段代码应该不难理解，就是一个结合版，但是其中降低时间复杂度的技巧是非常微妙的
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
    /**
     * @Description: 注意计算完全二叉树的方法—— 结合 普通二叉树深搜+满二叉树logN 的搜索方法。
     * @param {*}
     * @return {*}
     * @notes: 【虽然是两者的结合】但是由于 完全二叉树中 **每次**递归 都只有一边递归，另一边直接就是满二叉树；
     *              满二叉树一直高度h，节点个数为： 2^h - 1;
     */
    int countBTNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        int hl = 0, hr = 0;
        TreeNode  *left = root, *right = root;
        // 计算左右子树的高度
        while(left->left != nullptr){
            left = left->left;
            hl++;
        }
        hl++;
        while(right->left != nullptr){
            right = right->left;
            hr++;
        }
        hr++;
        
        // 判断并返回
        if( hl == hr){
            // 则是 满二叉树
            return pow(2, hl) - 1;
        }

        // 其它不是满二叉树 继续搜索并此处加加
        return 1 + countBTNodes(root->left) + countBTNodes(root->right);
    }
};


