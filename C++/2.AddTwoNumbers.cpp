/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\2.AddTwoNumbers.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-03-31 11:29:45
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-03-31 15:28:07
 * @Version             : 1.0
 * @Description         : 两数相加
 * 2. 两数相加
给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

 

示例 1：


输入：l1 = [2,4,3], l2 = [5,6,4]
输出：[7,0,8]
解释：342 + 465 = 807.
示例 2：

输入：l1 = [0], l2 = [0]
输出：[0]
示例 3：

输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
输出：[8,9,9,9,0,0,0,1]
 

提示：

每个链表中的节点数在范围 [1, 100] 内
0 <= Node.val <= 9
题目数据保证列表表示的数字不含前导零
 */

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

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
     * @Description: 从尾到前 联合起来。
     * @param {ListNode} *l1
     * @param {ListNode} *l2
     * @return {*}
     * @notes: 
     */
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head=new ListNode(0), *now = head;
        int pre = 0;
        while(l1!=nullptr || l2!=nullptr){
            if(l1!= nullptr && l2!=nullptr){
                int res = l1->val + l2->val + pre;
                pre = res/10;
                ListNode *cur = new ListNode(res%10);
                now->next = cur;
                now = cur;
                l1 = l1->next;
                l2 = l2->next;
            }else if(l1!=nullptr && l2==nullptr){
                int res = l1->val + pre;
                pre = res/10;
                ListNode *cur = new ListNode(res%10);
                now->next = cur;
                now = cur;
                l1 = l1->next;
            }else if(l1==nullptr && l2!=nullptr){
                int res = l2->val + pre;
                pre = res/10;
                ListNode *cur = new ListNode(res%10);
                now->next = cur;
                now = cur;
                l2 = l2->next;
            }
        }// 数值链接完毕。
        // 是否有进位
        if(pre!=0){
            ListNode *cur = new ListNode(pre);
            now->next = cur;
            now = cur;
        }
        return head->next;
    }
};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */