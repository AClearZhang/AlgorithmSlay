/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\204.CountPrimes.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-04-26 22:31:34
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-04-26 22:41:19
 * @Version             : 1.0
 * @Description         : 计算质数
 * 204. 计数质数
统计所有小于非负整数 n 的质数的数量。

 

示例 1：

输入：n = 10
输出：4
解释：小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
示例 2：

输入：n = 0
输出：0
示例 3：

输入：n = 1
输出：0
 

提示：

0 <= n <= 5 * 106
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
    int countPrimes(int n) {
        vector<bool> isPrimes(n, true);
        for(int i = 2; i*i<n;i++){
            if(isPrimes[i]){
                for(int j = i*i;j<n;j+=i){
                    isPrimes[j] = false;
                }
            }
        }

        int count = 0;
        For(i, 2, n){
            if(isPrimes[i]){
                count ++;
            }
        }
        return count;
    }   
};