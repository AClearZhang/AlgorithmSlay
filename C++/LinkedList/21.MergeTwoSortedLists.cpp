/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\LinkedList\21.MergeTwoSortedLists.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-01-20 18:44:11
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-01-20 19:08:15
 * @Version             : 1.0
 * @Description         : 合并两个有序的链表 —— 升序
 * 21. 合并两个有序链表
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

 

示例 1：


输入：l1 = [1,2,4], l2 = [1,3,4]
输出：[1,1,2,3,4,4]
示例 2：

输入：l1 = [], l2 = []
输出：[]
示例 3：

输入：l1 = [], l2 = [0]
输出：[0]
 

提示：

两个链表的节点数目范围是 [0, 50]
-100 <= Node.val <= 100
l1 和 l2 均按 非递减顺序 排列
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
     * @Description: 将 l2 插入到 l1中
     * @param {*}
     * @return {*}
     * @notes: 
     */
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *ans = new ListNode(-100);
        ans->next = l1;
        l1 = ans;
        while(l2){
            if(l2->val>=l1->val && l2->val<=l1->next->val){
                ListNode* tmp = l1->next;
                l1->next = l2;
                l2->next = tmp;
                l1 = l2;
                l2 = l2->next;
            }else{
                l1 = l1->next;
            }
        }
        return ans->next;
    }
};


