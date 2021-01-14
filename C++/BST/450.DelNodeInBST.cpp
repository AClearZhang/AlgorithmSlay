/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\BST\450.DelNodeInBST.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-01-14 17:16:46
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-01-14 17:16:47
 * @Version             : 1.0
 * @Description         : 
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


