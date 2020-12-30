/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\1110.DelNodeToForest.cpp
 * @Author              : AClearZhang
 * @Date                : 2020-12-29 22:18:44
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2020-12-30 10:29:28
 * @Version             : 1.0
 * @Description         : 删点成林
 * 1110. 删点成林
给出二叉树的根节点 root，树上每个节点都有一个不同的值。

如果节点值在 to_delete 中出现，我们就把该节点从树上删去，最后得到一个森林（一些不相交的树构成的集合）。

返回森林中的每棵树。你可以按任意顺序组织答案。

 

示例：



输入：root = [1,2,3,4,5,6,7], to_delete = [3,5]
输出：[[1,2,null,4],[6],[7]]
 

提示：

树中的节点数最大为 1000。
每个节点都有一个介于 1 到 1000 之间的值，且各不相同。
to_delete.length <= 1000
to_delete 包含一些从 1 到 1000、各不相同的值。
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
     * @Description: 算法思维：树的框架进行递归 —— 后序遍历方便一次性 加入到ans中。
     * @param {*} 设置成unordered_set 方便进行搜索。 vector<TreeNode* > ans
     * @return {*} 
     * @notes: 注意：【是要根据实际实用的 要求在递归的1、形参2、返回值中使用】 在这里进行删除的关键点是如何给父节点分发nullptr？！所以 返回root指针方便操作。
     */
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        //删点成林
        vector<TreeNode*> ans;
        unordered_set<int> delete_list(to_delete.begin(), to_delete.end());
        root = helper(root, delete_list, ans);
        if(!root){
            ans.push_back(root);
        }
        return ans;
    }
    // helper辅助函数——寻找删除点 并 返回构建树的结果？删除<其中要 注意是中间节点即要加入进去>or原始不变？
    TreeNode* helper(TreeNode* root, unordered_set<int> delete_list,  vector<TreeNode*> ans){
        // 边界，返回root
        if(!root) return root;

        // 后序遍历 开始
        root->left = helper(root->left, delete_list, ans);
        root->right = helper(root->right, delete_list, ans);
            // visit
        if(delete_list.count(root->val)>0) { //存在
            // 中间节点  
            if(root->left){ ans.push_back(root->left); }
            if(root->right){ ans.push_back(root->right); }
            
            return nullptr;
        }

        // 遍历结束
        return root;
    }
};



int main(){

    system("pause");
    return 0;
    
}
