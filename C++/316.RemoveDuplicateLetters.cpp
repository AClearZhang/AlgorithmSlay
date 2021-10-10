/*
 * @FilePath            : \AlgorithmInterview\AlgorithmSlay\C++\316.RemoveDuplicateLetters.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-10-09 16:48:48
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-10-10 19:43:08
 * @Version             : 1.0
 * @Description         : 去除重复字母
 * 
 * 316. 去除重复字母
给你一个字符串 s ，请你去除字符串中重复的字母，使得每个字母只出现一次。需保证 返回结果的字典序最小（要求不能打乱其他字符的相对位置）。

注意：该题与 1081 https://leetcode-cn.com/problems/smallest-subsequence-of-distinct-characters 相同

 

示例 1：

输入：s = "bcabc"
输出："abc"
示例 2：

输入：s = "cbacdcbc"
输出："acdb"
 

提示：

1 <= s.length <= 104
s 由小写英文字母组成
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
#include <map>
#include <vector>

using namespace std;



#define For(x,y,z) for(ll x = y; x < z;++x)
typedef long long ll;

class Solution {
public:

    /**
     * @Description: 使用栈  每次容器未访问过（因为字母要唯一）；  容器不为空且栈顶元素大于当前元素 要出栈。
     * @param {string} s
     * @return {*}
     * @notes: 
     */
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> strMap;
        for(char ch : s){
            strMap[ch] ++;
            // cout << "strmap[" << ch << "]:" << strMap[ch] << endl;
        }

        vector<int> visited(26, 0);
        stack<char> stackStr;
        for(char ch : s){
            if(!visited[ch - 'a']){
                // 一直进行判断  去除大的，而且后面有的时候
                while(!stackStr.empty() && stackStr.top() > ch){
                    // cout << stackStr.top() << endl;
                    if(strMap[stackStr.top()] > 0){ //  后面还有的话  // 不可以使用count 是计算有多少个key，一直有；而是使用里面的 num有几个！
                        visited[stackStr.top() - 'a'] = 0;
                        // cout << "strmap[" << ch << "]:" << strMap[ch] << endl;
                        // cout << "pop while:" << stackStr.top() << endl;
                        stackStr.pop();
                    }else{
                        break;
                    }
                }

                // stack为空 或者 当前元素唯一或不大于当前栈顶元素
                // 都是直接入栈
                visited[ch - 'a'] = 1;
                stackStr.push(ch);
                // cout << "not visited push ch:" << ch << endl;
            }
            // 访问过 --
            strMap[ch] --;
            
        }
        string res;
        while(!stackStr.empty()){
            res.push_back(stackStr.top());
            stackStr.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};


int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.removeDuplicateLetters("cbacdcbc") << endl;
    system("pause");
    return 0;
}
