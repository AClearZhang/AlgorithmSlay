/*
 * @FilePath            : \AlgorithmInterview\AlgorithmSlay\C++\Interview\58TC\No2.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-10-09 21:03:17
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-10-09 21:13:42
 * @Version             : 1.0
 * @Description         : 
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
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param str string字符串 
     * @return int整型
     */
    int StringSplit(string str) {
        // 每次 左右遍历统计 a  b的个数; 固定一边 左右指针去做
        int r = count(str.begin(), str.end(), 'b'); 
        int l = 0;
        int res = 0;
        for( int i = 0; i<str.size() ; i++){
            if( i!= (str.size() -1 ) && str[i]=='a' ) l++;
            if(str[i] == 'b') r--;
            res = max(res, l+r);
        }
        return res;
    }
};
