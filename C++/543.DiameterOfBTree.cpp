/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\543.DiameterOfBTree.cpp
 * @Author              : AClearZhang
 * @Date                : 2020-12-28 22:15:38
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2020-12-29 20:28:28
 * @Version             : 1.0
 * @Description         : 二叉树的直径
 * 543. 二叉树的直径
给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点。

 

示例 :
给定二叉树

          1
         / \
        2   3
       / \     
      4   5    
返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。

 

注意：两结点之间的路径长度是以它们之间边的数目表示。
 * 
 * 
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


/**
 * @Description: 我看出了递归树的用法【每次都需要维持一个左右最大深度，但是 最终合并为一个路径】，但是没有看出框架方便的实质 ——  ①我想从上往下走，但是每次都要O(n^2)复杂度。 ②但是递归是深搜——最好 从下往上走，【visit是每次比较下，使用max()即可】。
 * @Param: D.S. 维持一个深度递归返回深度， 维持当前路径为形参。
 * @Return: 
 * @Notes: 本题最简单的方法：①使用 递归<本质的回传至是树的一侧。>；②在形参处添加 直径进行solution。 ③注意后序遍历中，因为后序判断完了才 使得当前深度+1；所以到最后 由于左右都是那个高度，没有+1，所以最终结果直接返回即可。
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        // 树的最大路径，变得最长边的距离
        int diameter = 0;
        findMaxDiaFromDownToFront(root, diameter);
        return diameter;

    }
    // 辅助函数—— 仍然是递归树进行递归和使用。
    /**
     * @Description: 
     * @param {int} &diameter
     * @return {从下到上返回当前二叉树最大高度}
     * @notes: 
     */
    int findMaxDiaFromDownToFront(TreeNode* root, int &diameter){
        // 结束位置
        if(root == nullptr){ return 0; }

        // 递归和  visit
        int l = findMaxDiaFromDownToFront(root->left, diameter), r = findMaxDiaFromDownToFront(root->right, diameter);
        
            // visit 进入递归的最下方——进行处理
            // 相当于后续
        diameter = max(l+r, diameter);  //【注意这里没有 +1 +1 ;所以直接 等于图的直径。当前状态没有加1，返回的时候当前状态的高度才进行加1！】。

        return 1 + max(l,r); // 相当于 寻找最大的高度


    }


};


int main()
{
       
    system("pause");
    return 0;
}