/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\297.SeriDeseriLevel.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-01-10 22:58:12
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-01-10 23:44:44
 * @Version             : 1.0
 * @Description         : 序列化与反序列化的 层次遍历完成
 * 
 */

#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <stack>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <windows.h>

using namespace std;
//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Codec
{
public:
    // Encodes a tree to a single string.
    /**
     * @Description: 层次遍历先框架，后根据实际需要进行修改。
     * @param {TreeNode} *root
     * @return {*}
     * @notes: 
     */
    string serialize(TreeNode *root)
    {
        stringstream ssr;
        queue<TreeNode*> q;
        if(root == nullptr)  return "";
        q.push(root);
        ssr << to_string(root->val) << ",";
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                TreeNode* cur = q.front();
                q.pop();
                // 结束条件
                // dong 是有的，我这没有。

                // 邻域循环， 去除已访问
                if(cur->left == nullptr) {
                    ssr << "null" << ",";
                }else{// 存在值
                    ssr << cur->left->val << ",";
                    q.push(cur->left);
                }

                if(cur->right == nullptr) {
                    ssr << "null" << ",";
                }else{// 存在值
                    ssr << cur->right->val << ",";
                    q.push(cur->right);
                }
            }

        }
        string s;
        ssr >> s;
        return s;


    }
    // void serialize_helper(TreeNode* root, StringBuild )

    // Decodes your encoded data to tree.
    /**
     * @Description: ①首先 切分为string传入queue；②层次遍历构建  二叉树
     * @param {*}
     * @return {*}
     * @notes:  //【此处为关键！！！】 queue 和 split 和 getline(ssr, str, ',');
     */
    TreeNode *deserialize(string data)
    {
        if(data == "") return nullptr;
        stringstream ssr(data);
        queue<string> q;
        queue<TreeNode *> qTree;
        string s;
        while(getline(ssr, s, ',') ){
            q.push(s);
        }
        // 准备就绪；开始层次构建 二叉树
        TreeNode* root = new TreeNode(stoi(q.front()));
        q.pop();
        qTree.push(root);
        while(!qTree.empty()){
            // 关键点：每一个非空的qTree总是会对应  q中的两个元素
            TreeNode* cur_root = qTree.front();
            qTree.pop();

            cur_root->left = q.front() == "null" ? nullptr : new TreeNode(stoi(q.front()));
            q.pop();
            cur_root->right = q.front() == "null" ? nullptr : new TreeNode(stoi(q.front()));
            q.pop();
            
            // 邻域添加入 qTree
            if(cur_root->left){
                qTree.push(cur_root->left);
            }
            if(cur_root->right){
                qTree.push(cur_root->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

int main()
{
    
    return 0;
}

