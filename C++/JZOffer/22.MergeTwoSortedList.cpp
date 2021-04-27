/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\JZOffer\22.MergeTwoSortedList.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-04-27 15:45:13
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-04-27 15:58:21
 * @Version             : 1.0
 * @Description         : 合并两个有序数组
 * 
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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @Description: 方法一 迭代——连接到虚拟节点上
     * @param {*}
     * @return {*}
     * @notes: 
     */
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // 一个虚拟节点，一个 向后遍历的 移动节点。
        ListNode *dummyNode = new ListNode(-1), *pre = dummyNode;
        while(l1!= nullptr && l2!=nullptr){
            if(l1->val < l2->val){
                pre->next = l1;
                pre = l1;
                l1 = l1->next;
            }else{
                pre->next = l2;
                pre = l2;
                l2 = l2->next;
            }
        }
        if(l1==nullptr){
            pre->next = l2;
        }else{
            pre->next = l1;
        }
        return dummyNode;
    }
};

class Solution{
public:

    /**
     * @Description: 关键：找出小的，继续让大的进行递归合并  返回小的。自己 后序链接。
     * @param {*}
     * @return {*}
     * @notes: 
     */
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // base case
        if(!l1){
            return l2;
        }
        if(!l2){
            return l1;
        }

        // digui
        if(l1->val < l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }else{
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }

};