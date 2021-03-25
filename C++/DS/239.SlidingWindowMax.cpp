/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\DS\239.SlidingWindowMax.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-03-25 11:15:54
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-03-25 16:10:22
 * @Version             : 1.0
 * @Description         : 滑动窗口的最大值
 * 239. 滑动窗口最大值
给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

返回滑动窗口中的最大值。

 

示例 1：

输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
输出：[3,3,5,5,6,7]
解释：
滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
示例 2：

输入：nums = [1], k = 1
输出：[1]
示例 3：

输入：nums = [1,-1], k = 1
输出：[1,-1]
示例 4：

输入：nums = [9,11], k = 2
输出：[11]
示例 5：

输入：nums = [4,-2], k = 2
输出：[4]
 

提示：

1 <= nums.length <= 105
-104 <= nums[i] <= 104
1 <= k <= nums.length
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
 * @Description: 新建 单调队列结构，解决  每次都要把队列尾入头出，每次push也要把 比当前入队元素大的值出队。
 *                  这样就保证了队的开头是最大的了。
 * @param {*}
 * @return {*}
 * @notes:  【关键】 败在了push的删除上面！！！  
 */
class MonoQueue
{
public:
    void push(int num)
    {
        // 【核心部分】
        // 队尾进， 一直压扁小于自己的
        // list<int>::reverse_iterator rit = this->queue.rbegin();
        // for(;rit!=this->queue.rend();++rit){
        //     if(*rit > num){
        //         break;
        //     }
        //     // 其它的直接pop
        //     this->queue.pop_back();
        // }
        // list<int>::iterator it=this->queue.begin();
        // for(; it!=this->queue.end() ;it++){
        //     if(*it<num){
        //         break;
        //     }
        // }

        // // 直接在末尾加
        // this->queue.insert(it, num);

        // 巧妙地删除【关键！！！】
        while (!queue.empty() && queue.back() < num)
        {
            this->queue.pop_back();
        }
        this->queue.push_back(num);
    }
    void pop(int num)
    {
        // 必要的加！ 因为防止出队的是下一个大的， 出队应该出上一次已成的最大的。
        if (this->queue.front() == num)
        {
            this->queue.pop_front();
        }
    }
    int size()
    {
        return this->queue.size();
    }
    int max()
    {
        // 对头即为最大
        return this->queue.front();
    }

private:
    // 内部使用 双向链表实现
    list<int> queue;
};

class Solution
{
public:
    /**
     * @Description:  先将k个数组数据入队，再将 剩下的一步步比较和入队。
     * @param {int} k
     * @return {*}
     * @notes: 
     */
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int all_in_ans = nums.size() - k + 1;
        vector<int> ans(all_in_ans, 0);
        MonoQueue *m_queue = new MonoQueue();
        for (int i = 0; i < k; i++)
        {
            m_queue->push(nums[i]);
        }
        ans[0] = m_queue->max();

        // 剩下的——开始滑动
        for (int i = k; i < nums.size(); i++)
        {
            m_queue->pop(nums[i - k]);
            m_queue->push(nums[i]);
            ans[i - k + 1] = m_queue->max();
        }
        return ans;
    }
};

/**
 * @Description: 方法二： 单调队列——直接使用 deque 实现
 * @param {*}
 * @return {*}
 * @notes: 
 */
class Solution
{
public:
    /**
     * @Description:  先将k个数组数据入队，再将 剩下的一步步比较和入队。
     * @param {int} k
     * @return {*}
     * @notes: 
     */
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int all_in_ans = nums.size() - k + 1;
        vector<int> ans(all_in_ans, 0);
        deque<int> q;
        for (int i = 0; i < k; i++)
        {
            while (!q.empty() && q.back() < nums[i])
            {
                q.pop_back();
            }
            q.push_back(nums[i]);
        }

        ans[0] = q.front();

        // 剩下的——开始滑动
        for (int i = k; i < nums.size(); i++)
        {
            if(!q.empty() && q.front() == nums[i-k]) q.pop_front();
            while (!q.empty() && q.back() < nums[i])
            {
                q.pop_back();
            }
            q.push_back(nums[i]);
            ans[i - k + 1] = q.front();
        }
        return ans;
    }
};



/**
 * @Description: 方法三： 基于方法二 合并在一起。
 * @param {*}
 * @return {*}
 * @notes: 
 */
class Solution
{
public:
    /**
     * @Description:  先将k个数组数据入队，再将 剩下的一步步比较和入队。
     * @param {int} k
     * @return {*}
     * @notes: 
     */
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int all_in_ans = nums.size() - k + 1;
        vector<int> ans(all_in_ans, 0);
        deque<int> q;
        for (int i = 0; i < nums.size(); i++)
        {
            if(i>=k) { // pop
                if(!q.empty() && q.front() == nums[i-k]) q.pop_front();
            }


            while (!q.empty() && q.back() < nums[i])
            {
                q.pop_back();
            }
            q.push_back(nums[i]);

            
            if(i>=k-1){
                ans[i - k + 1] = q.front();
            }
        }
        return ans;
    }
};
