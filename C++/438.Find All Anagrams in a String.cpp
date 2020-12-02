/*
 * @FilePath            : \project\AlgorithmSlay\C++\438.Find All Anagrams in a String.cpp
 * @Author              : AClearZhang
 * @Date                : 2020-12-02 22:24:19
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2020-12-02 23:53:25
 * @Version             : 1.0
 * @Description         : 找出异位词
 * 给定一个字符串 s 和一个非空字符串 p，找到 s 中所有是 p 的字母异位词的子串，返回这些子串的起始索引。
字符串只包含小写英文字母，并且字符串 s 和 p 的长度都不超过 20100。

说明：
字母异位词指字母相同，但排列不同的字符串。
不考虑答案输出的顺序。

示例 1:

输入:
s: "cbaebabacd" p: "abc"

输出:
[0, 6]

解释:
起始索引等于 0 的子串是 "cba", 它是 "abc" 的字母异位词。
起始索引等于 6 的子串是 "bac", 它是 "abc" 的字母异位词。

示例 2:

输入:
s: "abab" p: "ab"

输出:
[0, 1, 2]

解释:
起始索引等于 0 的子串是 "ab", 它是 "ab" 的字母异位词。
起始索引等于 1 的子串是 "ba", 它是 "ab" 的字母异位词。
起始索引等于 2 的子串是 "ab", 它是 "ab" 的字母异位词。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-all-anagrams-in-a-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */



#include <iostream>
#include <vector>
#include <windows.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> need, window; // need最小子串有效字符，window也是有效最小子串字符；左右窗口大小由 [left, right)控制
        int left=0, right=0, valid=0;
        for(char c:p) need[c]++;

        int start = 0, len = INT_MAX;
        vector<int> ans_pos;
        while( right < s.size() ){
            // 右边的添加到窗口  扩大窗口
            char r = s[right];
            // window[s[right]]++;
            right++;                // 所以数据集是左闭右开的

            // 进行窗口内数据的一系列更新
            if(need.count(r) > 0){   
                window[r]++;
                if( window[r] == need[r])   // 关键
                    valid++;
            }

            /*** debug 输出的位置 ***/
            printf("window: [%d, %d)\n", left, right);
            /********************/

            while( valid == need.size() ){ 
                len = right-left;
                if( len ==  p.size() ){
                    // return true;
                    ans_pos.push_back(left);
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
        
        return ans_pos;
    }
};

int main()
{
    // string s = "cbaebabacd", t = "abc";
    string s = "abab", t = "ab";
    Solution so;
    auto ans = so.findAnagrams(s, t);
    for(auto tmp : ans){
        cout <<tmp << " ";
    }
    cout<<"异位词判断结束！" << endl;
    system("pause");
    return 0;
}

