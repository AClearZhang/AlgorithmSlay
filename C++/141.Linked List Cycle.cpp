/*
 * @FilePath            : \project\AlgorithmSlay\C++\141.Linked List Cycle.cpp
 * @Author              : AClearZhang
 * @Date                : 2020-11-25 22:26:03
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2020-11-28 00:06:02
 * @Version             : 1.0
 * @Description         : 给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。注意，pos 仅仅是用于标识环的情况，并不会作为参数传递到函数中。

说明：不允许修改给定的链表。

进阶：
你是否可以使用 O(1) 空间解决此题？
 

示例 1：
输入：head = [3,2,0,-4], pos = 1
输出：返回索引为 1 的链表节点
解释：链表中有一个环，其尾部连接到第二个节点。

示例 2：
输入：head = [1,2], pos = 0
输出：返回索引为 0 的链表节点
解释：链表中有一个环，其尾部连接到第一个节点。

示例 3：
输入：head = [1], pos = -1
输出：返回 null
解释：链表中没有环。
 

提示：

链表中节点的数目范围在范围 [0, 104] 内
-105 <= Node.val <= 105
pos 的值为 -1 或者链表中的一个有效索引

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/linked-list-cycle-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */



#include <iostream>
#include <windows.h>
#include <algorithm>
#include <vector>

using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(-1), next(NULL) {}  // 因为添加了 下面一行，所以要想新建一个节点  必须有个默认构造函数。
    ListNode(int x) : val(x), next(NULL) {}
};


// slow fast指针，
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
    /**
     * @description: 
     * @param {*}
     * @return {*}
     * @notes:  首先fast走两步， slow走一步；
     *                  当快指针走到头为null了，返回没有环路；
     *                  如果有还，快指针超过满指针；而 快慢指针第一次相遇时，即为当前指针
     */    
        // ListNode* slow = head, *fast = head->next;
        ListNode* slow = head, *fast = head;  //注意 需要直接从头开始 2步；1步.
        // int count = 0;
        while(fast!=nullptr && fast->next!=nullptr){
            // cout <<  count++ << endl;
            fast = fast->next->next;
            slow = slow->next;
            // if( fast == slow ) return slow;  //注意这里返回的 不一定是链表中！要返回链表中！
                                                //而且 也不一定slow-> next 就是链中。

            if(fast == slow){
                slow = head;
                while( slow != fast ){
                    slow = slow->next;
                    fast = fast->next;
                }
                return fast;
            }
        }
        // 一步步走，slow放head；第二次相遇 是链中。

        // 未找到返回 nullptr.
        return nullptr;
    }
};

//判断有没有环路
class Solution {
public:
    bool hasCycle(ListNode *head) {
        //true &  false
        ListNode* fast = head, * slow = head;
        while(fast!=nullptr && fast->next!=nullptr){
            fast = fast->next->next;
            slow = slow->next;
            if( fast==slow ){
                return true;
            }
        }
        return false;
    }
};




int main(){

    // vector<int> input1 = {1,2,3,0,0,0}, input2={2,5,6};
    // int m=3,n=3;
    // vector<int> input1 = {1}, input2={};
    // int m=1,n=0;
    // Solution2 s;
    // s.merge(input1,m, input2, n);
    // cout << "now the input1 is: " << endl;
    // for(auto num: input1){
    //     cout << num << " ";
    // }
    // cout << endl;
    

    // 数据结构 构建列表
    int list[] = {3,2,0,4};
    ListNode* preHead = nullptr;
    preHead = new ListNode;
    ListNode* cur = preHead; //尾插入，当前节点
    for(auto i : list){
        auto* node = new ListNode(i);
        cur->next = node;
        cur = cur->next;
    }
    ListNode* head = preHead->next;
    cur->next = head->next;
    Solution s;
    ListNode* a = s.detectCycle(head);
    if(!a){
        printf("不存在环路！");
    }else{
        cout<< "存在环路且当前环路的val值为： " << a->val << endl;
    }

    system("pause");
    return 0;
}




