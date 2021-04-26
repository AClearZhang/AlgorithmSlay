/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\BiteOperation\Charpter10.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-04-26 20:17:24
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-04-26 22:28:43
 * @Version             : 1.0
 * @Description         : 101google 大佬
 *                              位运算 全部题目
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

class Solution
{
public:
    /**
     * @Description: 172 阶乘后零的个数。
     * @param {int} n
     * @return {*}
     * @notes: 
     */
    int trailingZeroes(int n){
        int count = 0;
        while (n >= 5)
        {
            count += n / 5;
            n /= 5;
        }
        return count;
        // 递归方法。
        //  return n == 0 ?0: n/5 + trailingZeroes(n/5);
    }

};

class Solution
{
public:
    /**
     * @Description: 寻找只出现一次的数组 —— 用异或【 x^x=0  0^x=x  —— 一直异或下去得到唯一的一个值】
     * @param {*}
     * @return {*}
     * @notes: 
     */
    int singleNumber(vector<int> &nums)
    {
        int ans = 0;
        for (int num : nums)
        {
            ans ^= num;
        }
        return ans;
    }
};

class Solution
{
public:
    /**
     * @Description: 4次方的幂二进制的1 都在奇数位上。且 之后为1.
     * @param {int} n
     * @return {*}
     * @notes: 
     */
    bool isPowerOfFour(int n)
    {
        return (n > 0 && !(n & n - 1) && (n & 0x55555555));
    }
};

class Solution
{
public:
    /**
     * @Description: 寻找 二进制位不同的位置。
     * @param {int} x
     * @param {int} y
     * @return {*}
     * @notes: 
     */
    int hammingDistance(int x, int y)
    {
        int diff = x ^ y, ans = 0;
        while (diff)
        {
            ans += diff & 1;
            diff >>= 1;
        }
        return ans;
    }
};

class Solution
{
public:
    /**
     * @Description: 翻转 二进制位。 32个位。 左右移动运算。
     * @param {uint32_t} n
     * @return {*}
     * @notes: 
     */
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t ans = 0;
        for (int i = 0; i < 32; i++)
        {
            ans <<= 1;
            ans += n & 1;
            n >>= 1;
        }
        return ans;
    }
};
