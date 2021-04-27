/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\JZOffer\52.ListFirstCommonNode.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-04-27 16:21:14
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-04-27 16:47:46
 * @Version             : 1.0
 * @Description         : 两个链表第一个公共节点
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
    /**
     * @Description: a+c+b = b+c+a  两边走相同长度的路程，可以得到 相交的第一个节点。
     * @param {ListNode} *headA
     * @param {ListNode} *headB
     * @return {*}
     * @notes: 
     */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *l1 = headA, *l2 = headB;
        while(l1!=l2){
            l1 = l1==nullptr?headB:l1->next;
            l2 = l2==nullptr?headA:l2->next;
        }
        return l1;
    }
};