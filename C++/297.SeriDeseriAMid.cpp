/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\297.SeriDeseriAMid.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-01-10 16:32:22
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-01-10 18:03:45
 * @Version             : 1.0
 * @Description         : 序列化和反序列化的  后序和中序遍历【只能后序，中序的反序列化行不通。】
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
    string serialize(TreeNode *root)
    {
        stringstream ssr;

        serialize(root, ssr);
        string ans;
        ssr >> ans;
        return ans;
    }
    // void serialize_helper(TreeNode* root, StringBuild )

    // Decodes your encoded data to tree.
    /**
     * @Description: ①首先 切分为string传入queue；②后序递归构建  二叉树
     * @param {*}
     * @return {*}
     * @notes:  //【此处为关键！！！】 queue 和 split 和 getline(ssr, str, ',');
     */
    TreeNode *deserialize(string data)
    {
        stringstream ssr(data);
        // queue<string> q;
        stack<string> sta;
        string s;
        while(getline(ssr, s, ',') ){
            sta.push(s);
        }
        TreeNode* root = deserialize(sta);
        return root;
    }
    // TreeNode *deserialize(string data)
    // {
    //     // 分隔符化为 数组
    //     stringstream ssr(data);
    //     string str;
    //     vector<string> preTree;
    //     queue<string> q;
    //     while(getline(ssr, str, ',')){
    //         // preTree.push_back(str);
    //         q.push(str);                //【此处为关键！！！】
    //     }
    //     static int cur = 0;  // 行不通！
    //     // TreeNode *root = deserialize(preTree, cur);
    //     TreeNode *root = deserialize(q);
    //     return root;
    // }

private:
    // 辅助函数 序列化
    // 后序
    void serialize(TreeNode *root, stringstream &ssr)
    {
        // 前序遍历序列化
        if (root == nullptr){
            ssr << "null"
                << ",";
            return ;
        }
        
        
        serialize(root->left, ssr);
        serialize(root->right, ssr);
        ssr << to_string(root->val) << ",";

         //注意最后输出 带括号所以需要辅助函数。
    } 
    // 辅助函数 反序列化
    // 因为string是后序； 所以stack—— 先右左 来做。
    TreeNode* deserialize(stack<string> &sta)
    {
        if(sta.empty()) return nullptr;
        
        string cur = sta.top();
        sta.pop();
        if(cur == "null")  return nullptr;

        TreeNode* root = new TreeNode(stoi(cur));
        root->right = deserialize(sta);
        root->left = deserialize(sta);

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
