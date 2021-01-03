/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\654.MaxBTree.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-01-03 20:23:02
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-01-03 21:46:48
 * @Version             : 1.0
 * @Description         : 最大二叉树
 * 
 * 654. 最大二叉树
给定一个不含重复元素的整数数组。一个以此数组构建的最大二叉树定义如下：

二叉树的根是数组中的最大元素。
左子树是通过数组中最大值左边部分构造出的最大二叉树。
右子树是通过数组中最大值右边部分构造出的最大二叉树。
通过给定的数组构建最大二叉树，并且输出这个树的根节点。

 

示例 ：

输入：[3,2,1,6,0,5]
输出：返回下面这棵树的根节点：

      6
    /   \
   3     5
    \    / 
     2  0   
       \
        1
 

提示：

给定的数组的大小在 [1, 1000] 之间。
 */

#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <windows.h>

using namespace std;

//  Definition for a Node.
struct TreeNode
{
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
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        if (nums.empty())
            return nullptr;
        // 寻找最大节点
        // unordered_set<int> list(nums.begin(), nums.end());

        int point = max_element(nums.begin(), nums.end()) - nums.begin(); // 对应的下标，因为返回的是it 迭代器
        cout << "Now point is : " << point;
        cout << ";Now pointnum is : " << nums[point] << endl;
        TreeNode* root = new TreeNode(nums[point]);   // 默认为 null了
        // 边界
        if (point > 0)
        {
            vector<int> nums1(nums.begin(), nums.begin() + point);
            root->left = constructMaximumBinaryTree(nums1); // 左边部分的递归
        }
       
        if (point < nums.size() - 1)
        {
            vector<int> nums2(nums.begin() + point + 1, nums.end());
            root->right = constructMaximumBinaryTree(nums2); // 左边部分的递归
        }
        

        return root;
    }
};

int main()
{

    return 0;
}
