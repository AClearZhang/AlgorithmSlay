/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\76.MinimumWindowSubstring.cpp
 * @Author              : AClearZhang
 * @Date                : 2020-11-28 00:06:16
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2020-12-02 16:55:15
 * @Version             : 1.0
 * @Description         : 最小覆盖子串 —— 滑动窗口方法
 * 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
注意：如果 s 中存在这样的子串，我们保证它是唯一的答案。

 

示例 1：

输入：s = "ADOBECODEBANC", t = "ABC"
输出："BANC"
示例 2：

输入：s = "a", t = "a"
输出："a"
 

提示：

1 <= s.length, t.length <= 105
s 和 t 由英文字母组成
 

进阶：你能设计一个在 o(n) 时间内解决此问题的算法吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-window-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <iostream>
#include <windows.h>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

// 算法模板：
// class Solution {
// public:
//     string minWindow(string s, string t) {
//         // char*  cur, *pre;
//         // while( *pre!= s[s.size()-1]){
            
//         // }
//         unordered_map<char, int> need, window; // need.count('A')>0 //且 直接++ 就是0++；
//         int left=0, right=0, valid=0;
//         for(char c:t) need[c]++;
//         int needNum = 0;

//         while( right < s.size() ){
//             // 右边的添加到窗口  扩大窗口
//             window[s[right]]++;
//             right++;

//             // 进行窗口内数据的一系列更新
//             if(window[s[right]].count(s[right-1]) <= need.count(s[right-1]) && need.count(s[right-1])>0){
//                 valid++;
//             }

//             /*** debug 输出的位置 ***/
//             printf("window: [%d, %d)\n", left, right);
//             /********************/
        
//             //左边开始减少窗口
//             while( valid == t.size() ){   
//                 window.erase( (pair<char,int>(s[left], left)));
//                 left++;
//                 // 进行窗口内数据的一系列更新
                
//             }


//         }
        
 

//     }
// };

/**
 * @description: 所有字符的最小子串，~不存在重复字符。~   输入字符串是可以重复的！
 * @param {*} 
 * @return {*}
 * @notes: 
 */
class Solution1 {
public:
    string minWindow(string s, string t) {
        // char*  cur, *pre;
        // while( *pre!= s[s.size()-1]){
            
        // }
        unordered_map<char, int> need, window; // need最小子串有效字符，window也是有效最小子串字符；左右窗口大小由 [left, right)控制
        int left=0, right=0, valid=0;
        for(char c:t) need[c]++;
        // cout << "need size is : "  << need.size() << endl;

        int start = 0, len = INT_MAX;

        while( right < s.size() ){
            // 右边的添加到窗口  扩大窗口
            char r = s[right];
            // window[s[right]]++;
            right++;                // 所以数据集是左闭右开的

            // 进行窗口内数据的一系列更新
            // if(window.count(s[right-1]) <= need.count(s[right-1]) && need.count(s[right-1])>0){
            //     valid++;
            // }
            // 对左边窗口进行变化
            if(need.count(r) > 0){   // 会自动添加进来，设置为0了！ NO！删除 //need[r] > 0
                window[r]++;
                if( window[r] == need[r])
                    valid++;
            }

            /*** debug 输出的位置 ***/
            // printf("window: [%d, %d)\n", left, right);
            /********************/
            // for(pair<char,int> needC : need){
            //     cout<< "first:" << needC.first << "second:" << needC.second << " " ;
            // }
            // cout << endl;
            
            // cout << "need size0 is : "  << need.size() << endl;
            // cout << "valid is : "  << valid << endl;
            
            //左边开始减少窗口
            // if( window[r] == need[r])
            //         valid++;  
            // 有以上判断！   所以直接看 need.size() 即可

            while( valid == need.size() ){ 
                // for(pair<char,int> needC : need){
                //     cout<< "first:" << needC.first << "second:" << needC.second << " " ;
                // }
                // cout << endl;
                // cout << "t size is : "  << t.size() << endl;
                // cout << "need size is : "  << need.size() << endl;
                // cout << "window size is : "  << window.size() << endl;

                if( right-left < len ){
                    len = right - left;
                    start = left;
                }
                // window[s[left]]--;
                char l = s[left];
                left++;
                
                // 更新窗口 以及 最终结果判定
                if(need.count(l) > 0){
                    window[l]--;
                    if(window[l] < need[l])
                        valid--;
                }
                
            }
        }
        
        return len==INT_MAX? "" : s.substr(start, len) ;
        // return len == INT_MAX ?"":s.substr(start, len); 

    }
};

// 法二
class Solution {
public:
    string minWindow(string s, string t) {
        // char*  cur, *pre;
        // while( *pre!= s[s.size()-1]){
            
        // }
        unordered_map<char, int> need, window; // need.count('A')>0 且 直接++ 就是0++；// 注意window 只包括有效子串
        int left=0, right=0, valid=0;
        for(char c:t) need[c]++;
        int start = 0, len = INT_MAX;

        while( right < s.size() ){
            // 右边的添加到窗口  扩大窗口
            char c = s[right];
            right++;                // 所以数据集是左闭右开的

            // 进行窗口内数据的一系列更新
            // 只向窗口中添加 need有的
            if(need.count(c) > 0){
                window[c]++;
                if(window[c] == need[c]){
                    valid++;
                }
            }

            /*** debug 输出的位置 ***/
            printf("window++: [%d, %d)\n", left, right);
            /********************/
        
            //左边开始减少窗口
            while( valid == need.size() ){   
                if( right-left < len ){
                    len = right - left;
                    start = left;
                }
                char d = s[left];
                left++;
                // 进行窗口内数据的一系列更新
                // 1. 首先valid需要更新
                // 2. 然后更新 len 和窗口
                if(need.count(d)>0){
                    // 更新窗口
                    // if(window[d] == need[d])
                    //     valid--;
                    // window[d]--;
                    window[d]--;
                    if(window[d]<need[d]){ // 不同于模板 
                        valid--;
                    }
                }
                printf("window--: [%d, %d)\n", left, right);
                
            }


        }
        return len == INT_MAX ?"":s.substr(start, len); 

    }
};


int main(){
    // string s="ADOBECODEBANC", t="ABC";
    string s="aa", t="aa";
    // cout << s.size()<< "  " << t.size() << endl;
    Solution1 so;
    string rel = so.minWindow(s,t);
    cout << "最小子串为：" << rel << endl;

    system("pause");
    return 0;
}

