/*
 * @FilePath            : \AlgorithmInterview\AlgorithmSlay\C++\LinkedList\21.MergeTwoSortedLists.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-01-20 18:44:11
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-09-27 22:50:36
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

/**
 * @Description: 双向链表有序添加
 * @param {*}
 * @return {*}
 * @notes: 
 * 

 void addByOrder(HeroNode2 node) {
        HeroNode2 temp = head;
        //头节点的情况此时链表没有数据所以直接插入就好
        if (head.next == null) {
            head.next = node;
            node.pre = head;
            //直接结束掉此方法
            return;
        }
        //这个标记为标记是否在元素最后插入还是在中间插入
        boolean flag = false;
        //这里的temp是所插入元素的前节点
        while (temp.next != null) {
            if (temp.next.no >= node.no) {
                flag = true;
                break;
            }
            temp = temp.next;
        }
        if (flag) {
            node.pre = temp;
            node.next = temp.next;
            temp.next.pre = node;
            temp.next = node;

        } else {
            temp.next = node;
            node.pre = temp;
        }


    }
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
     * @notes: 【注意非递归的：l1->next==nullptr 】 【注意递归的：小的被留下(最终返回时构建了)  并递归小的下一个】
     */
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *ans = new ListNode(-100);
        ans->next = l1;
        l1 = ans;
        while(l2){
            if(l1->next==nullptr || (l2->val>=l1->val && l2->val<=l1->next->val) ){
                ListNode* tmp1 = l1->next;
                ListNode* tmp2 = l2->next;
                l1->next = l2;
                l2->next = tmp1;
                l1 = l2;
                l2 = tmp2;
            }else{
                l1 = l1->next;
            }
        }
        return ans->next;
    }
    // 101 dalao递归写法——顺序递归 ； 返回时构建链表 并返回当前构建的链表。
    //  【注意递归的：小的被留下(最终返回时构建了)  并递归小的下一个】
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1){
            return l2;
        }
        if(!l2){
            return l1;
        }

        // 注意base case(前序) 和 返回当前最小值(的后序)；递归回溯的策略都有。
        if(l1->val > l2->val){
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
        else{
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
    }

};


