/*
 * @FilePath            : \project\AlgorithmSlay\C++\JZOffer\10-II.QingWaTiaoTaiJie.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-10-14 20:40:28
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-10-14 21:24:17
 * @Version             : 1.0
 * @Description         : 第二章 面试需要的基础知识
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
    int numWays(int n) {
        if( n==0){
            return 1;
        }
        if( n <=2 ){
            return n;
        }

        int tmpOne = 1;
        int tmpTwo = 2;
        int res = 0;
        For(i, 3, n+1){
            res = (tmpOne + tmpTwo) % (int)(1e9 + 7);
            tmpOne = tmpTwo;
            tmpTwo = res;
        }
        
        return res;
    }
};


int main(){

    Solution s;
    cout << s.numWays(5)<< endl;

    system("pause");
    return 0;
}


