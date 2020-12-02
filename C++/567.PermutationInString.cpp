/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\567.PermutationInString.cpp
 * @Author              : AClearZhang
 * @Date                : 2020-12-02 16:59:09
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2020-12-02 17:26:19
 * @Version             : 1.0
 * @Description         : 字符串的排列 —— 数组类 算法思维问题。
 * 给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。

换句话说，第一个字符串的排列之一是第二个字符串的子串。

示例1:

输入: s1 = "ab" s2 = "eidbaooo"
输出: True
解释: s2 包含 s1 的排列之一 ("ba").
 

示例2:

输入: s1= "ab" s2 = "eidboaoo"
输出: False
 

注意：

输入的字符串只包含小写字母
两个字符串的长度都在 [1, 10,000] 之间

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutation-in-string
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
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> need, window; // need最小子串有效字符，window也是有效最小子串字符；左右窗口大小由 [left, right)控制
        int left=0, right=0, valid=0;
        for(char c:s1) need[c]++;

        int start = 0, len = INT_MAX;

        while( right < s2.size() ){
            // 右边的添加到窗口  扩大窗口
            char r = s2[right];
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
                if( len ==  s1.size() ){
                    return true;
                }
                // window[s[left]]--;
                char l = s2[left];
                left++;
                
                // 更新窗口 以及 最终结果判定
                if(need.count(l) > 0){
                    window[l]--;
                    if(window[l] < need[l])
                        valid--;
                }
                
            }
        }
        
        return false;
    }
};

int main()
{
    string s1 = "ab", s2 = "eidbaooo";
    Solution s;
    bool bo = s.checkInclusion(s1,s2);
    cout<<"是否包含最小子串：" << bo << endl;
    system("pause");
    return 0;
}
