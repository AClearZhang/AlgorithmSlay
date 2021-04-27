/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\JZOffer\22.ListDaoshuK.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-04-27 16:13:49
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-04-27 16:16:36
 * @Version             : 1.0
 * @Description         : 链表中倒数第k个
 */

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

#define For(x, y, z) for (int x = y; x < z; ++x)
typedef long long ll;
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
     * @Description: 两个指针  一个前k个，一个slow即可。 另一个方法  翻转链表 —— 然后找第k个。
     * @param {int} k
     * @return {*}
     * @notes: 
     */
    ListNode *getKthFromEnd(ListNode *head, int k)
    {
        ListNode *fast = head, *slow = head;
        For(i, 0, k)
        {
            fast = fast->next;
        }
        while (fast != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};