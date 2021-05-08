/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\JZOffer\09.ZhanShiXianDuiLie.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-05-08 17:10:02
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-05-08 17:23:12
 * @Version             : 1.0
 * @Description         : 使用两个栈实现队列
 * 剑指 Offer 09. 用两个栈实现队列
用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )

 

示例 1：

输入：
["CQueue","appendTail","deleteHead","deleteHead"]
[[],[3],[],[]]
输出：[null,null,3,-1]
示例 2：

输入：
["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
[[],[],[5],[2],[],[]]
输出：[null,-1,null,null,5,2]
提示：

1 <= values <= 10000
最多会对 appendTail、deleteHead 进行 10000 次调用
通过次数174,443提交次数240,949
 */
#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

#define For(x, y, z) for (ll x = y; x < z; ++x)
typedef long long ll;


/**
 * @Description: 使用两个栈 实现队列 —— 进和出
 * @param {*}
 * @return {*}
 * @notes: 关键：s1设置为队尾， s2设置为对头
 *              ① 出栈的时候如果为空，则 s1入s2; 再出队。
 *              ② 入栈则放到s1里面。
 *              ③ 如果 s1和s2同时为空——出栈的时候  则为空队列  返回-1。
 */
class CQueue {
public:
    CQueue() {
    }
    
    void appendTail(int value) {
        s1.push(value);
    }
    
    int deleteHead() {
        if(s2.empty()){
            while(!s1.empty()){
                int s = s1.top();
                s1.pop();
                s2.push(s);
            }
        }
        if(s2.empty() && s1.empty()){
            return -1;
        }

        // 有数值
        int tmp = s2.top();
        s2.pop();
        return tmp;
    }
private:
    stack<int> s1;
    stack<int> s2;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
