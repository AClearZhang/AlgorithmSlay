/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\TwiceTimes\206.翻转链表.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-03-30 11:16:05
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-03-30 15:14:31
 * @Version             : 1.0
 * @Description         : 
 */

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

#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <vector>

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
     * @Description: 单独101 dalao —— 递归/非递归方法，每次都是以前序 插入方式递归
     * @param {*}
     * @return {*}
     * @notes: 【技巧】 null在前面
     */
    ListNode *reverseList(ListNode *head)
    {
        // 递归方法
        ListNode *pre=nullptr, *next = head;
        
        // 非递归方法
        while(head != nullptr){
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
    /**
     * @Description: 递归方式
     * @param {ListNode} *head
     * @return {*}
     * @notes: 
     */
    ListNode *reverseList(ListNode *head)
    {
       if(head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* last = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return last;
    }
};