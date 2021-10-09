/*
 * @FilePath            : \AlgorithmInterview\AlgorithmSlay\C++\Interview\58TC\No1.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-10-09 20:55:57
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-10-09 21:02:44
 * @Version             : 1.0
 * @Description         : 促销啤酒 需要至少准备多少瓶
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
     * @param totalNum int整型 计划售卖总数量
     * @param exchangeNum int整型 兑换比例，如5个可兑换1个，则该参数为5
     * @return int整型
     */
    int calculateExtraNum(int totalNum, int exchangeNum) {
        // 结束条件
        if(totalNum < exchangeNum){
            return 0;
        }
        
        return totalNum/exchangeNum + calculateExtraNum(totalNum/exchangeNum + totalNum%exchangeNum, exchangeNum);
    }
};
