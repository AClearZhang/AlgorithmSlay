/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\297.SeriAndDeseriBTree.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-01-04 20:48:04
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-01-09 23:59:54
 * @Version             : 1.0
 * @Description         : serialize  序列化和反序列化二叉树
 * 297. 二叉树的序列化与反序列化
序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。

请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。

示例: 

你可以将以下二叉树：

    1
   / \
  2   3
     / \
    4   5

序列化为 "[1,2,3,null,null,4,5]"
提示: 这与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。

说明: 不要使用类的成员 / 全局 / 静态变量来存储状态，你的序列化和反序列化算法应该是无状态的。
 */

#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
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
     * @Description: 
     * @param {*}
     * @return {*}
     * @notes:  //【此处为关键！！！】 queue 和 split 和 getline(ssr, str, ',');
     */
    TreeNode *deserialize(string data)
    {
        // 分隔符化为 数组
        stringstream ssr(data);
        string str;
        vector<string> preTree;
        queue<string> q;
        while(getline(ssr, str, ',')){
            // preTree.push_back(str);
            q.push(str);                //【此处为关键！！！】
        }
        static int cur = 0;  // 行不通！
        // TreeNode *root = deserialize(preTree, cur);
        TreeNode *root = deserialize(q);
        return root;
    }

private:
    // 辅助函数 序列化
    void serialize(TreeNode *root, stringstream &ssr)
    {
        // 前序遍历序列化
        if (root == nullptr){
            ssr << "null"
                << ",";
            return ;
        }
        
        ssr << to_string(root->val) << ",";
        
        serialize(root->left, ssr);
        serialize(root->right, ssr);

         //注意最后输出 带括号所以需要辅助函数。
    } 
    // 辅助函数 反序列化
    TreeNode* deserialize(vector<string> &preTree,int cur)
    {
        cout << "now cur is:" << cur << endl;
        if(preTree[cur] == "null") return nullptr;

        TreeNode* root = new TreeNode(stoi(preTree[cur]));

        root->left = deserialize(preTree, ++cur);
        root->right = deserialize(preTree, ++cur);
        return root;
        
    }
    TreeNode* deserialize(queue<string> &q)
    {
        if(q.empty()) return nullptr;

        string cur = q.front();
        q.pop();
        if(cur == "null") return nullptr;

        TreeNode* root = new TreeNode(stoi(cur));

        root->left = deserialize(q);
        root->right = deserialize(q);
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
