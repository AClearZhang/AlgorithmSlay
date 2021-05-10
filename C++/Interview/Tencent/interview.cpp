/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\Interview\Tencent\interview.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-05-10 11:55:23
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-05-10 17:39:16
 * @Version             : 1.0
 * @Description         : 腾讯 面试题目
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





TreeNode * find(TreeNode* root, int A, int B, unordered_map<int, int>& map){

    if(root == nullptr) return nullptr;

    TreeNode *left = find(root->left, A, B);
    TreeNode *right = find(root->right, A, B);
    
    // 如果 A B有一个不存在，必须放在后序
    // 如果保证都存在，则可放在前面 —— 因为前面快！
    if(root->value == A ) {
        map[A]++;
        return root;
    }else if(root->value == B){
        map[B]++;
        return root;
    }
    if(left != nullptr && right != nullptr) return root;
    else if(left == nullptr && right == nullptr) return nullptr;
    else{
        return left == nullptr ? right : left ;
    }
    
}
TreeNode * find(TreeNode* root, int A, int B){
    unordered_map<int, int> map;
    TreeNode *res = find(root, A, B, map);
    if(map.count(A) > 0 && map.count(B)>0){
        return res;
    }else{
        return nullptr;
    }
}

int main(){
   

}
