/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\LinkedList\143.ReorderList.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-04-23 14:17:26
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-04-23 16:24:19
 * @Version             : 1.0
 * @Description         : 重拍链表
 * 143. 重排链表
给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

示例 1:

给定链表 1->2->3->4, 重新排列为 1->4->2->3.
示例 2:

给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.
通过次数92,131提交次数153,130
 */


#include <vector>
#include <iostream>
#include <queue>

using namespace std;

#define For(x,y,z) for(int x=y; x<z; x++)

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    /**
     * @Description: 首先快慢指针 找中点。 
     * @param {*}
     * @return {*}
     * @notes: 一前一后往后插
     */
    void reorderList(ListNode* head) {
        ListNode *slow=head, *fast=head;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *l1=head, *l2=slow->next;
        slow->next = nullptr;  // 这个指针游离了！ 就会错误！！！！
        // while(l2){
        //     ListNode *tmp1 = l1->next, *tmp2=l2->next;
        //     l1->next = l2;
        //     l2->next = tmp1;
        //     l2 = tmp2;
        //     l1 = tmp1;
        // }

        // 分为两个 数组，进行插入
        insertTwoReveList(l1, l2);
    }
    // helper 后序递归插入
    void insertTwoReveList(ListNode* &l1, ListNode *l2){
        if(l2 == nullptr){
            return ;
        }
        insertTwoReveList(l1, l2->next);
        ListNode *tmp1 = l1;
        l1->next = l2;
        l2->next = tmp1;
        l1 = tmp1;
    }
};