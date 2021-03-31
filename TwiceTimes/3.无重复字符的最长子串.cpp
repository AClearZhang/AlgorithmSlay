/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\TwiceTimes\3.无重复字符的最长子串.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-03-31 10:59:28
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-03-31 11:14:35
 * @Version             : 1.0
 * @Description         : 二刷
 */

#include <iostream>
#include <map>
#include <vector>
#include <windows.h>
#include <unordered_map>

using namespace std;


class Solution {
public:

    int lengthOfLongestSubstring(string s){        
        unordered_map<char, int> windows;
        int res = 0;
        int left = 0, right = 0;
        while(right < s.size()){
            // 上来是左右闭的， 后序移动窗口后 本次都是左闭右开的。
            char r = s[right];
            right++;
            // 扩大窗口改变数据
            windows[r]++;

            while(windows[r] > 1){ // 缩小窗口的条件 // 有重复的
                char l = s[left];
                left++;
                // 更新左侧的windows数据.
                windows[l]--;  
            }
                // 更新最终的结果在哪？
                // 在这——因为一直更新的 到不再有重复的字母 为止.
            int now_res = right-left;  // 因为 左闭右开
            res = now_res>res?now_res: res ;
        }
        return res;
    }  
};