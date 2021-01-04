/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\652.FindDupSubTrees.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-01-04 15:46:02
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-01-04 20:19:13
 * @Version             : 1.0
 * @Description         : 寻找重复字数
 * 652. 寻找重复的子树
给定一棵二叉树，返回所有重复的子树。对于同一类的重复子树，你只需要返回其中任意一棵的根结点即可。

两棵树重复是指它们具有相同的结构以及相同的结点值。

示例 1：

        1
       / \
      2   3
     /   / \
    4   2   4
       /
      4
下面是两个重复的子树：

      2
     /
    4
和

    4
因此，你需要以列表的形式返回上述重复子树的根结点。
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
#include <sstream>


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
     * @Description: 首先：想到看到自身全貌——使用后序遍历递归返回string子树序列化一次性发现自身subTree；然后，全局重复使用 HashMap进行计数，重复则加入ans。
     * @param {*}
     * @return {*}
     * @notes: 【注意：外加一个记录节点的数据结构； 注意 解题时的递归不一定是本身——而是要考虑效率和实用性基础上 ；创造性的开创 helper() 序列化——相信递归定义、知晓根节点做什么；】最后，利用数据结构重复性在根节点处 解题。
     */
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> subTree;
        vector<TreeNode *> ans;    // 如果重复则记录当前子树的根节点。
        if(root == nullptr) return ans;
        
        helper(root, subTree, ans);
        return ans;
    }
    // 辅助函数 —— 后序遍历序列化所有子树；并判断是否重复 加入节点。
    // 【注意：】这里有一个知识点 —— 序列化和反序列化二叉树
    string helper(TreeNode* root, unordered_map<string, int>& subTree, vector<TreeNode *>& ans){
        if(root == nullptr)  return "#";

        string left = helper(root->left, subTree, ans);
        string right = helper(root->right, subTree, ans);

        // 序列化根节点
        stringstream ssr;
        string a;
        ssr << root->val;
        ssr >> a;
            // 序列化
        string curTree = left + ',' + right + ',' + a;
        int count = subTree[curTree]++;                         // 【关键之处】 注意map这里是后++；所以首先count=0; //但是 subTree[curTree] =1 会首先为1。
        cout << "now subTree["<< curTree<<"] is:" << subTree[curTree] << endl;
            // 防止重复出现
        if(count == 1){
            // 第二次出现 即重复了  // 题解
            ans.push_back(root);
        }

        return curTree;

    }

};

int mian(){
    
    system("pause");
    return 0;
}