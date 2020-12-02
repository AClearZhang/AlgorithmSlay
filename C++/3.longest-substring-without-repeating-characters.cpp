/*
 * @FilePath            : \project\AlgorithmSlay\C++\3.longest-substring-without-repeating-characters.cpp
 * @Author              : AClearZhang
 * @Date                : 2020-12-03 00:06:48
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2020-12-03 01:20:12
 * @Version             : 1.0
 * @Description         : 无重复字符的最长子串
 * 
 * 
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: s = "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

示例 2:

输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

示例 3:

输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

示例 4:

输入: s = ""
输出: 0
 

提示：
0 <= s.length <= 5 * 104
s 由英文字母、数字、符号和空格组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */


#include <iostream>
#include <map>
#include <vector>
#include <windows.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
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
                max_len = right-left>max_len?right-left:max_len;
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
};

int main()
{
    // string s = "abcabcbb";
    // string s = "bbbb";
    // string s = "pwwkew";
    // string s = "";
    string s = " ";
    Solution so;
    int num = so.lengthOfLongestSubstring(s);
    cout<<"最长子串的长度为：" << num << endl;
    system("pause");
    return 0;
}
