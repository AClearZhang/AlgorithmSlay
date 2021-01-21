/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\LinkedList\24.SwapNodesInPairs.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-01-21 11:02:48
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-01-21 11:47:18
 * @Version             : 1.0
 * @Description         : 交换两个 成对节点。在链表中。
 * 24. 两两交换链表中的节点
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

 

示例 1：


输入：head = [1,2,3,4]
输出：[2,1,4,3]
示例 2：

输入：head = []
输出：[]
示例 3：

输入：head = [1]
输出：[1]
 

提示：

链表中节点的数目在范围 [0, 100] 内
0 <= Node.val <= 100
 */

#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <cmath>
#include <algorithm>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    /**
     * @Description: 若要使用递归交换两个节点，则需要辅助函数的prev【并不需要！因为直接返回 prev了！】
     * @param {*}
     * @return {*}
     * @notes: 
     */
    ListNode *swapPairs(ListNode *head)
    {
        if(head == nullptr) return nullptr;

        if(head->next == nullptr){
            return head;
        }

        // 当前节点
        ListNode* tmp = head->next;
        ListNode* tmp1 = tmp->next;
            // 交换head & tmp
        // prev->next = tmp;
        tmp->next = head;
        head->next = swapPairs(tmp1);
        return tmp;
    }

    // 非递归方法
    ListNode *swapPairs(ListNode *head){
        ListNode* p = head, *s;
        if(p && p->next) {
            s = p->next;
            // 交换
            p->next = s->next;
            s->next = p;
            head = s;
            while(p->next && p->next->next) {
                //都存在 又可以交换
                s = p->next->next;
                p->next->next = s->next;
                s->next = p->next;
                p->next = s;
                p = s->next;
            }
        }
        return head;
    }

};
