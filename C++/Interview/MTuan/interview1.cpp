/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\Interview\MTuan\interview1.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-05-10 14:28:13
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-05-10 16:37:34
 * @Version             : 1.0
 * @Description         : 美团面试题目 —— 最大无重复字串个数。
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



class Solution {
public:
    /**
     * @Description: 我首先用这个做的。
     * @param {string} s
     * @return {*}
     * @notes: 
     */
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> need, window; // need最小子串有效字符，window也是有效最小子串字符；左右窗口大小由 [left, right)控制
        int left=0, right=0, valid=0;
        // for(char c:s1) need[c]++;

        int start = 0, max_len = 0;

        while( right < s.size() ){
            // 右边的添加到窗口  扩大窗口
            char r = s[right];
            // window[s[right]]++;
                           // 所以数据集是左闭右开的
            

            /*** debug 输出的位置 ***/
            printf("window: [%d, %d]\n", left, right);
            /********************/
            window[r]++;

            //边界还没有重复的就结束了
            if(window[r]==1){
                max_len = right+1-left>max_len?right+1-left:max_len;
            }
            
            // 进行窗口内数据的一系列更新
            if(window[r] > 1){   
                // 如果字符存在，缩小窗口并 移动到找到字符的下一个
                // 首先记录
                max_len = right-left>max_len?right-left:max_len; // 这个可以去掉。
                // 然后循环更新窗口
                char l = s[left];
                while( l != r ){
                    
                    window[l]--;
                    left++;
                    l = s[left];
                    cout << "in circle window[l]" << window[l] << endl;
                }
                window[l]--;
                left++;
            }
            right++; 
        }
        
        return max_len;
    }

    /**
     * @Description: dong 's做法
     * @param {string} s
     * @return {*}
     * @notes: 
     */
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