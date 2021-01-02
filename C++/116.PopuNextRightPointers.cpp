/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\116.PopuNextRightPointers.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-01-02 21:21:46
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-01-02 21:47:33
 * @Version             : 1.0
 * @Description         : 
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
#include <stack>

using namespace std;



//  Definition for a Node.
/**
 * @Description: 给出完美二叉树定义：每个椰子鸡诶单在同一层， 每个父节点都有两个子节点。
 * @param {*}
 * @return {*}
 * @notes: 
 */
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    /**
     * @Description: 从上到下，  一点点的连接 并  遍历。
     * @param {*}
     * @return {*}
     * @notes: 
     */
    Node* connect(Node* root) {
        // 边界
        if(root == nullptr || !root->left || !root->right)
            return nullptr;
        // if(root->next == nullptr)  root->next = nullptr;

        root->left->next = root->right;

        // 前序遍历递归寻找右侧节点
        connect(root->left);
        connect(root->right);
        return root;
    }
};



int main(){



}