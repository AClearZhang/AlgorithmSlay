/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\STL\BSTBasics.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-01-11 23:24:59
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-01-12 00:35:35
 * @Version             : 1.0
 * @Description         : BST基础 code
 * 主要涉及 书籍P236——P242
 * 关于合法性检查 、 改查（搜索）、增（插入）、删（节点）
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


/**
 * @Description: 检测BST的构造是否合法
 * @param {TreeNode} *root
 * @return {*}
 * @notes: 
 */
boolean isValidBST(TreeNode* root){
    return isValidBST(root, nullptr, nullptr);
}
boolean isValidBST(TreeNode* root,TreeNode* min, TreeNode* max){
    // 辅助函数 —— 检测是否构成合法的BST
    if(root == nullptr) return true;
        // 注意当前节点要和所有的左右节点比较！
    if(min != nullptr && root->val <= min->val) return false;
    if(max != nullptr && root->val >= max->val) return false;

    // 其它交给递归
    return isValidBST(root->left, min, root) &&
            isValidBST(root->right, root, max);  // 相当于在后面给所有节点添加了一个 min 和 max的边界约束。
                                                 // 约束了root 的左子树节点值不超过root的值、右子树节点值不小于root的值。
}

/**
 * @Description: 搜索、改查
 * @param {*}
 * @return {*}
 * @notes: 
 */
boolean isInBST(TreeNode* root, int target){
    // 当前节点该做的事
    if(root == nullptr) return false;
    if(root->val == target) return true;

    // 递归框架.
    if(target > root->val) return isInBST(root->right, target);
    if(target < root->val) return isInBST(root->left, target);
}

/**
 * @Description: 增（插入）
 * @param {*}
 * @return {*}
 * @notes: 
 */
TreeNode* insertIntoBST(TreeNode* root, int val){
    // 新增节点，所以要返回构建的节点
    if(root == nullptr) return new TreeNode(val);
    
    if(val == root->val) return root; // 重复了不添加新的
    else if(val > root->val){
        root->right = insertIntoBST(root->right, val);
    }else if(val < root->val){
        root->left = insertIntoBST(root->left, val);
    }
    return  root;
}


/**
 * @Description: 最复杂和难的  
 * @param {*} 注意关键：按照有几个子节点进行分类和 构建伪代码框架——分为三类; 且注意：两个节点要找到最小的进行互换之后、删除最小的节点即可。
 * @return {*}
 * @notes: 
 */
TreeNode* deleteNode(TreeNode* root, int key){
    // 首先搜索，找到了分情况删除； 未找到递归查找。
    if(root == nullptr ) return nullptr;
    if(root->val == key){
        // 分情况进行删除结点；三种情况。
            // 一
        if(root->left == nullptr && root->right == nullptr) return nullptr;
            // 二 （可以和上一种合起来
        if(root->left == nullptr) return root->right;
        if(root->right == nullptr) return root->left;
            // 第三种情况：
            // 先找到最小的节点赋值， 然后递归删除最后的节点即可。
        TreeNode* cur_min = getMin(root->right); // 这里决定了选择右边最小的节点进行交换
                // 声明这样做不正规，但是正确；（本应该是在指针级别 进行操作的；因为不同结构体内的成员不同
        root->val = cur_min->val;
        // return deleteNode(root->right, cur_min->val);  // 错了
        root->right = deleteNode(root->right, cur_min->val); //【这样才对，否则 就覆盖了root了！】

    }else if(root->val > key){
        root->left = deleteNode(root->left, key);
    }else if(root->val < key){
        root->right = deleteNode(root->right, key);
    }
    return root;
}

TreeNode* getMin(TreeNode* root){
    // 辅助函数——辅助第三种情况交换节点 并删除
    // 要么右边最小节点； 要么左边最大节点
    // 这里选择右边最小节点 [只能上一层 主函数进行选择]
    while(root->left != nullptr) root = root->left;
    return root;
}




int main(){

    system("pause");
    return 0;
}







