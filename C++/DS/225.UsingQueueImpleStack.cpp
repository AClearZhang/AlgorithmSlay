/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\DS\225.UsingQueueImpleStack.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-05-08 17:30:24
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-05-08 17:39:29
 * @Version             : 1.0
 * @Description         : 使用队列实现栈
 * 
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
 * @Description: 
 * @param {*}
 * @return {*}
 * @notes: 记录栈顶元素；
 *          入栈队尾入队；
 *          出栈则前面n-1个数出队再入队。
 */
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        stackTop = x;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(q.empty()){
            return -1;
        }
        int sz = q.size()-1;
        while(sz--){
            int tmp = q.front();
            q.pop();
            q.push(tmp);
        }
        int tmp = q.front();
        stackTop = q.back();  // 【注意这里！！】
        q.pop();
        return tmp;
    }
    
    /** Get the top element. */
    int top() {
        return stackTop;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
private:
    int stackTop;
    queue<int> q;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */