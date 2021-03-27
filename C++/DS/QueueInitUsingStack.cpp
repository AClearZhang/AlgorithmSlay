/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\DS\QueueInitUsingStack.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-03-27 11:22:32
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-03-27 11:29:09
 * @Version             : 1.0
 * @Description         : 使用双栈 实现队列
 * 
 */
#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * @Description: 双栈， s1作为尾部的入队， s2作为头部的出队。（）
 * @param {*}
 * @return {*}
 * @notes: 
 */
class MyQueue
{
public:
    MyQueue()
    {
        // 构造函数
    }
    /** 添加元素到队尾 */
    void push(int x)
    {
        return s1.push(x);
    }

    /** 删除队头的元素并返回 */
    int pop()
    {
        
    }

    /** 返回队头元素 */
    int peek()
    {
        if (s2.empty())
            // 把 s1 元素压入 s2
            while (!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        return s2.top();
    }

    /** 判断队列是否为空 */
    bool empty()
    {
    }

private:
    stack<int> s1, s2;
};