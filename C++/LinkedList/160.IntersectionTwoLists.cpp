/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\LinkedList\160.IntersectionTwoLists.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-01-21 11:49:43
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-01-22 00:03:25
 * @Version             : 1.0
 * @Description         : 两个链表，判断链表是否相交于一点，并求 这个相交节点。
 * 160. 相交链表
编写一个程序，找到两个单链表相交的起始节点。

如下面的两个链表：



在节点 c1 开始相交。

 

示例 1：



输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
输出：Reference of the node with value = 8
输入解释：相交节点的值为 8 （注意，如果两个链表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,0,1,8,4,5]。在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。
 

示例 2：



输入：intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
输出：Reference of the node with value = 2
输入解释：相交节点的值为 2 （注意，如果两个链表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [0,9,1,2,4]，链表 B 为 [3,2,4]。在 A 中，相交节点前有 3 个节点；在 B 中，相交节点前有 1 个节点。
 

示例 3：



输入：intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
输出：null
输入解释：从各自的表头开始算起，链表 A 为 [2,6,4]，链表 B 为 [1,5]。由于这两个链表不相交，所以 intersectVal 必须为 0，而 skipA 和 skipB 可以是任意值。
解释：这两个链表不相交，因此返回 null。
 

注意：

如果两个链表没有交点，返回 null.
在返回结果后，两个链表仍须保持原有的结构。
可假定整个链表结构中没有循环。
程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。
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
     * @Description: 我们可以先遍历一遍 数一数几个。然后重复一样的找。
     * @param {*}
     * @return {*}
     * @notes: 
     */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p1 = headA, *p2 = headB;
        int num1 = 0, num2 = 0;
        while(p1){
            num1++;
            p1 = p1->next;
        }
        while(p2){
            num2++;
            p2 = p2->next;
        }
        if(num1 == 0 || num2 == 0) return nullptr;
        p1 = headA, p2 = headB;
        if(num1 > num2){
            for(int i = 0;i<(num1-num2);i++){
                p1=p1->next;
            }

        }else if(num1 < num2){
            for(int i = 0; i< (num2-num1);i++){
                p2 = p2->next;
            }
        }
        // 并行运动
        while(p1 != p2){
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
    // 101 dalao做法    
    // 每次都前进。直到 a+b+c
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode*l1=headA, *l2=headB;
        while(l1!=l2){
            l1 = l1?l1->next:headB;
            l2 = l2?l2->next:headA;
        }
        return l1;
    }

};
