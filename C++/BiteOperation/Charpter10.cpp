/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\BiteOperation\Charpter10.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-04-26 20:17:24
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-04-26 21:15:44
 * @Version             : 1.0
 * @Description         : 101google 大佬
 *                              位运算 全部题目
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
     * @Description: 寻找只出现一次的数组 —— 用异或【 x^x=0  0^x=x  —— 一直异或下去得到唯一的一个值】
     * @param {*}
     * @return {*}
     * @notes: 
     */
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int num:nums){
            ans ^= num;
        }
        return ans;
    }
};

class Solution {
public:
    /**
     * @Description: 寻找 二进制位不同的位置。
     * @param {int} x
     * @param {int} y
     * @return {*}
     * @notes: 
     */
    int hammingDistance(int x, int y) {
        int diff = x^y, ans=0;
        while(diff){
            ans += diff&1;
            diff >>= 1;
        }
        return ans;
    }
};


class Solution {
public:
    /**
     * @Description: 翻转 二进制位。 32个位。 左右移动运算。
     * @param {uint32_t} n
     * @return {*}
     * @notes: 
     */
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for(int i = 0; i<32; i++){
            ans <<=1;
            ans += n&1;
            n >>= 1;
        }
        return ans;
    }
};
