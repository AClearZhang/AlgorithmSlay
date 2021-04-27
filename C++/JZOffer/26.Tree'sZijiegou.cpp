/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\JZOffer\26.Tree'sZijiegou.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-04-27 17:17:16
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-04-27 18:56:07
 * @Version             : 1.0
 * @Description         : 树的子结构
 * 
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

class Solution {
public:
    /**
     * @Description: 其中  root为nullptr没想到！鲁棒性一定要检查！
     * @param {*}
     * @return {*}
     * @notes: 关键：一个深搜查询有没有一致的。 另一个辅助函数查找当前是否为子结构
     */
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        //dfs
        bool res = false;
        // base
        if(A==nullptr || B==nullptr){
            return false;
        }
        // dfs
        if(A->val == B->val){
            res = hasSubStructure(A, B);
        }
        res = res || isSubStructure(A->left,B) || isSubStructure(A->right, B);
        return res;
    }
    bool hasSubStructure(TreeNode*& A, TreeNode*& B) {
        // BASE
        if(B==nullptr){
            return true;
        }
        if(A==nullptr){
            return false;
        }

        // TRA
        if(A->val != B->val){
            return false;
        }
        return hasSubStructure(A->left,B->left) && hasSubStructure(A->right, B->right);
    }
    // bool isSubStructure(TreeNode* A, TreeNode* B) {
    //     // base
    //     if(A == nullptr){
    //         if(B==nullptr){
    //             return true;
    //         }else{
    //             return false;
    //         }
    //     }

    //     // traverse
    //     if(A->val == B->val){
    //         if(isSubStructure(A->left, B->left) && isSubStructure(A->right, B->right)){
    //             return true;
    //         }
    //     }
    //     // continue
    //     return isSubStructure(A->left, B) || isSubStructure(A->right, B);
    // }
};