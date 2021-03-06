/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\151.ReverseWordsInStr.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-04-13 10:45:03
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-04-13 11:34:13
 * @Version             : 1.0
 * @Description         : 翻转字符串中的单词
 * 151. 翻转字符串里的单词
给定一个字符串，逐个翻转字符串中的每个单词。

说明：

无空格字符构成一个 单词 。
输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 

示例 1：

输入："the sky is blue"
输出："blue is sky the"
示例 2：

输入："  hello world!  "
输出："world! hello"
解释：输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
示例 3：

输入："a good   example"
输出："example good a"
解释：如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
示例 4：

输入：s = "  Bob    Loves  Alice   "
输出："Alice Loves Bob"
示例 5：

输入：s = "Alice does not even like bob"
输出："bob like even not does Alice"
 

提示：

1 <= s.length <= 104
s 包含英文大小写字母、数字和空格 ' '
s 中 至少存在一个 单词
 
 */
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <sstream>

using namespace std;

#define For(x,y,z) for(int x=y; x<z; ++x)
typedef long long ll;

class Solution {
public:
    vector<string> split(string inputs, char del){
        stringstream strStream(inputs);
        vector<string> res;
        string tmp;
        
        while(getline(strStream, tmp, del)){
            res.push_back(tmp);
        }
        return res;
    }

    /**
     * @Description: 先分割；再倒序输出.
     * @param {string} s
     * @return {*}
     * @notes: 
     */
    string reverseWords(string s) {
        vector<string> strSplit;
        strSplit = this->split(s, ' ');
        string res;
        // 倒序输出并添加空格
        vector<string>::reverse_iterator rit;
        for(rit = strSplit.rbegin();  rit!=strSplit.rend()-1;rit++ ){
            if(*rit != " "){
                res+=*rit;
                res.push_back(' ');
            }
        }
        if(*rit != " "){
            res+=*rit;
        }else{//说明前面最后一个 加了" "
            res.erase(res.size()-1);
        }
        return res;
    }
};