/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\LinkedList\25.InverseListInKGroup.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-01-30 11:49:57
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-01-31 00:58:27
 * @Version             : 1.0
 * @Description         : K个一组翻转链表
 * 25. K 个一组翻转链表
给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。

k 是一个正整数，它的值小于或等于链表的长度。

如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

 

示例：

给你这个链表：1->2->3->4->5

当 k = 2 时，应当返回: 2->1->4->3->5

当 k = 3 时，应当返回: 3->2->1->4->5

 

说明：

你的算法只能使用常数的额外空间。
你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
 */

#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <cmath>
#include <algorithm>

using namespace std;


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
     * @Description: 一点点实现  kGroup翻转链表。
     * @param {*}
     * @return {*}
     * @notes: 框架思想——①根据链表又可以迭代+递归；逐步分解为简单的2 进行迭代；②又因为仍需要继续重复（递归）后两个  所以使用递归。
     *              ③——注意 base case直到— 不符合个数位置，返回head;
     */
    ListNode* reverseKGroup(ListNode* head, int k) {
        // base case
        if(head == nullptr) return nullptr;
        // 寻找last 如果未到达则直接返回了。
        ListNode *headNew = head, * last=head;
        for(int i = 0; i<k ;i++){
            // 如果k个未找到直接返回.
            if( last == nullptr ) return head;
            last = last->next; // 到达边境
        }

        //因为足够了：先翻转当前  再翻转接下来的可能。
        ListNode *newHead = reverse(headNew, last);
        head->next = reverseKGroup(last, k);
        return newHead;
    }
    // 拆解为简单的1：全部迭代翻转
    ListNode* reverse(ListNode* head){
        ListNode *pre=nullptr, *next=head;
        
        while(head!=nullptr){
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
    // 拆解为简单的2： [head,last)  迭代翻转
    ListNode* reverse(ListNode* head, ListNode* last){
        ListNode *pre=nullptr, *next = head->next;
        while(head != last){
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
};