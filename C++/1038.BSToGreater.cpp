/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\1038.BSToGreater.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-01-14 16:49:37
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-01-14 16:50:46
 * @Version             : 1.0
 * @Description         : BST树 转换为累加树 【注意这道题目与538相同。】
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
     * @Description: 基本思路——因为BST中序遍历为升序；这里只需要右中左--这样的中序即可 完成大到小的累加
     * @param {*}
     * @return {*}
     * @notes: 
     */
    TreeNode* bstToGst(TreeNode* root) {
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

