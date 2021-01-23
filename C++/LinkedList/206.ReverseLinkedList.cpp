/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\LinkedList\206.ReverseLinkedList.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-01-20 16:43:31
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-01-23 19:26:11
 * @Version             : 1.0
 * @Description         : 反转列表
 * 206. 反转链表
反转一个单链表。

示例:

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
进阶:
你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
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
     * @Description: 我的解法——递归耗费时间，直接使用两个指针操作
     * @param {*}
     * @return {*}
     * @notes: 
     */
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return nullptr;
        // 虚拟指针对标head
        ListNode* pre = new ListNode();

        // 递归
        reverseList(head, pre);
        return pre->next;
    }
    // 辅助函数堆栈式的递归
    ListNode* reverseList(ListNode* head, ListNode* &pre){
        if(head->next == nullptr) {
            pre->next = head;
            return head;
        }

        ListNode* tmp = reverseList(head->next, pre);
        //相对于 插入一个节点tmp之后
        head->next = tmp->next;
        tmp->next = head;
        return head;
    }
    /**
     * @Description: 单独101 dalao —— 递归/非递归方法，每次都是以前序 插入方式递归
     * @param {*}
     * @return {*}
     * @notes: 【技巧】 null在前面
     */
    ListNode* reverseList1(ListNode* head, ListNode* prev = nullptr){
        if(!head){
            return prev;
        }
        ListNode* next = head->next;
        head->next = prev;
        return reverseList(next, head);
    }
    // 非递归方式
    ListNode* reverseList1(ListNode* head) {
        ListNode* prev = nullptr, *next;

        while(head){
            next = head->next;
            head->next = prev;
            prev=head;
            head = next;
        }
        return prev;

    }
    
};

class Solution {
public:
    /**
     * @Description: dong's —— 秀操作技巧
     * @param {*}
     * @return {*}
     * @notes: 【注意】递归函数名称一定要 知晓定义意义：
     *              输入一个节点head，将“以head为起点”的链表翻转，并返回“翻转完成后的链表头结点”。
     */
    // 方法1： 后序的递归
    ListNode* reverse(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* last = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return last;
    }
    //进阶1：递归 翻转前n个值
    ListNode* reverseN(ListNode* head, int n, ListNode* &successor){
        // base case
        if(n == 1){
            successor = head->next;
            return head;
        }

        ListNode* last = reverseN(head->next, n-1, successor);
        head->next->next = head;
        head->next  = successor;
        return last;
    }
    //进阶2：递归 从m开始翻转n个
    ListNode* reverseAfter(ListNode* head, int m, int n){
        // base case
        if(m == 1){
            ListNode* suc = nullptr;
            return reverseN(head, n, suc);
        }
        head->next = reverseAfter(head->next, m-1, n);
        
        return head;
    }
    //进阶3(类似进阶2)：递归  给一个索引区间[m,n]（索引从1开始）仅仅翻转区间中的链表元素
    ListNode* reverseBetween(ListNode* head, int m, int n){
        // base case
        if(m == 1){
            ListNode* suc = nullptr;
            return reverseN(head, n, suc);
        }
        head->next = reverseBetween(head->next, m-1, n-1);
        
        return head;
    }


};
