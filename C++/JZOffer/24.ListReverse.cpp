/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\JZOffer\24.ListReverse.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-04-13 10:29:23
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-04-27 15:16:14
 * @Version             : 1.0
 * @Description         : 翻转链表 剑指offer24
 * 
 */
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include<unordered_set>

using namespace std;

#define For(x,y,z) for(int x=y; x<z; ++x)
typedef long long ll;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /**
     * @Description: 即 相当于递归的从后向前了。迭代方法。
     * @param {*}
     * @return {*}
     * @notes: 
     */
    ListNode* reverseList(ListNode* head) {
        ListNode* pre=nullptr, *next=head;
        while(next){
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
};

class Solution {
public:
    /**
     * @Description: 即 相当于递归的从后向前了。迭代方法。
     * @param {*}
     * @return {*}
     * @notes: 
     */
    ListNode* reverseList(ListNode* head) {
        ListNode *pre=nullptr, *next = head;
        while(next){
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
};
