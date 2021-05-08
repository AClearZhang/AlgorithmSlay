/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\DS\232.UsingStackImpleQueue.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-05-08 17:41:45
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-05-08 17:44:39
 * @Version             : 1.0
 * @Description         : 使用栈实现队列
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
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
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

    
    /** Get the front element. */
    int peek() {
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
        return tmp;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        if(s2.empty() && s1.empty()){
            return true;
        }
        return false;
    }
    
private:
    stack<int> s1;
    stack<int> s2;
};

