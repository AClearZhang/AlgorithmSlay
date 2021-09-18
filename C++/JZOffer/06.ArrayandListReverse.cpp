/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\JZOffer\6.ArrayandListReverse.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-04-27 16:21:14
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-04-27 16:59:58
 * @Version             : 1.0
 * @Description         : 递归 从尾到头返回
 */

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

#define For(x, y, z) for (int x = y; x < z; ++x)
typedef long long ll;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        if(head == nullptr){
            return vector<int>{};
        }
        // 递归当前的 valpushback到后面
        vector<int> ans = reversePrint(head->next);
        ans.push_back(head->val);
        return ans;
    }
};