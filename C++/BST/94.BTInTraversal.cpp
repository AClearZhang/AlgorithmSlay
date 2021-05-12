/*
 * @FilePath            : \AlgorithmInterview\AlgorithmSlay\C++\BST\94.BTInTraversal.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-05-12 18:04:17
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-05-12 18:04:52
 * @Version             : 1.0
 * @Description         : 二叉树中序遍历 使用迭代方法
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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
class Solution
{
public:
    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> tmp;
    //     if(root == nullptr) return tmp;

    //     tmp = inorderTraversal(root->left);
    //     tmp.push_back(root->val);
    //     for(auto i :inorderTraversal(root->right)){
    //         tmp.push_back(i);
    //     }
    //     return tmp;
    // }
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> res;
        stack<TreeNode *> st;
        auto p = root;

        // 左链入栈循环
        // 这个循环你会发现和后面的的循环代码有一部分重复，你可以进行合并。
        // 但是这样你就需要在后面循环条件多加一个判断 while (p || !st.empty())，代码也会变得稍微没那么直观。你可以参考一下版本二。
        // 为了方便学习还是分开考虑为宜。优化的事情在你学习完后再考虑。
        while (p)
        {
            st.push(p);
            p = p->left;
        }

        while (!st.empty())
        {
            auto node = st.top();
            st.pop();
            res.emplace_back(node->val);
            p = node->right;
            // 一旦弹出一个节点，继续做“左链入栈”操作
            while (p)
            {
                st.push(p);
                p = p->left;
            }
        }
        return res;
    }
};
