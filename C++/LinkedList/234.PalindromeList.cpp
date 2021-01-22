/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\LinkedList\234.PalindromeList.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-01-21 11:52:18
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-01-22 15:27:33
 * @Version             : 1.0
 * @Description         : 判断链表是否回文
 * 234. 回文链表
请判断一个链表是否为回文链表。

示例 1:

输入: 1->2
输出: false
示例 2:

输入: 1->2->2->1
输出: true
进阶：
你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
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

class Solution {
public:
    /**
     * @Description: 总体思路：先找到中间节点，然后 中间节点传入辅助函数进行回溯的判断。
     * @param {*}
     * @return {*}
     * @notes: 
     */
    bool isPalindrome1(ListNode* head) {
        if(head == nullptr) return true;
        // 寻找中点
        int mid = 0;
        ListNode* p = head;
        while(p){
            p = p->next;
            mid++;
        }
        mid = ceil((float)mid/2);       //【注意】这里1 
        printf("now mid is:%d\n", mid);
        p = head;
        while(mid--){
            p = p->next;
        }
        bool flag = true;
        isPalindrome(p, head, flag);
        return flag;
    }
    // 辅助函数
    ListNode* isPalindrome(ListNode* mid, ListNode* head, bool &flag){
        if(mid == nullptr){
            return head;
        }
        ListNode*tmp = isPalindrome(mid->next, head, flag);
        cout << mid->val<<endl;
        cout << tmp->val << endl;
        if(mid->val != tmp->val) flag = false;  //【注意】这里2
        return tmp->next;    //【注意】这里3
    }
    /**
     * @Description: 101 dalao的方法：先用快慢指针赵道链表中点，然后链表切成两半；
     *              再把后半段翻转；最后 比较两段是否相等。
     * @param {*}
     * @return {*}
     * @notes: 
     */
    bool isPalindrome(ListNode* head) {
        if(!head||!head->next){
            return true;
        }
        // 快2倍 找链表中点
        ListNode* slow = head,*fast = head;
        while(fast->next && fast->next->next){
            // 必须要求下下个都要有，因为走两步
            slow = slow->next;  // 此时下一个即为中点 要反转的链表开头。
            fast = fast->next->next;
        }
        slow->next = reverseList(slow->next, nullptr);
        slow = slow->next;
        // 比较
        while(slow){
            if(slow->val != fast->val) return false;
            slow = slow->next;
            fast = fast->next;
        }
        // 全部相等
        return true;

    }
    // 辅助函数 —— 翻转链表
    ListNode* reverseList(ListNode* head, ListNode* prev){
        if( head == nullptr) return prev;
        // 开始递归两两前序翻转 （而这里没有回溯
        ListNode* next = head->next;
        head->next = prev;
        return reverseList(next, head);
    }
    
};