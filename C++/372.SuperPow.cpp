/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\372.SuperPow.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-03-18 15:42:46
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-03-18 20:51:49
 * @Version             : 1.0
 * @Description         : 超级次方
 * 372. 超级次方
你的任务是计算 ab 对 1337 取模，a 是一个正整数，b 是一个非常大的正整数且会以数组形式给出。

 

示例 1：

输入：a = 2, b = [3]
输出：8
示例 2：

输入：a = 2, b = [1,0]
输出：1024
示例 3：

输入：a = 1, b = [4,3,3,8,5,2]
输出：1
示例 4：

输入：a = 2147483647, b = [2,0,0]
输出：1198
 

提示：

1 <= a <= 231 - 1
1 <= b.length <= 2000
0 <= b[i] <= 9
b 不含前导 0
 */

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;



class Solution {
public:
    /**
     * @Description: 方法一：【未加超级幂】  模运算——拆解为递归 +有公式； 幂运算——使用快速幂 运算的公式。
     * @param {int} a
     * @return {*}
     * @notes: 
     */
    int base = 1337;
    int mypow(int a, int k){
        a %= base;
        int res = 1;
        for(int i = 0; i < k ; i++){
            res *= a;
            res %= base;
        }
        return res;
    }
    int superPow(int a, vector<int>& b) {
        if(b.empty())  return 1;

        int k = b.back();
        b.pop_back();

        // 开始递归
        int left = mypow(a, k);
        int right = mypow(superPow(a, b), 10);
        return (left * right) % 1337;
    }

    /**
     * @Description: 方法二：【加之 超级幂】  模运算——拆解为递归 +有公式； 幂运算——使用快速幂 运算的公式。
     * @param {int} a
     * @return {*}
     * @notes: 
     */
    int base = 1337;
    // 修改mypow
    int mypow(int a, int k){
        // 注意递归时——必须要有 base结束的边界！
        if(k == 0) return 1;
        a %= base; // 这个必须加上！因为不加就会溢出！
        
        if(k%2 != 0){
            // k是奇数
            return (a * mypow(a, k-1))%base;
        }else{
            // k 是偶数
            int temp = mypow(a, k/2);
            return temp*temp % base;
        }
    }
    int superPow(int a, vector<int>& b) {
        if(b.empty())  return 1;

        int k = b.back();
        b.pop_back();

        // 开始递归
        int left = mypow(a, k);
        int right = mypow(superPow(a, b), 10);
        return (left * right) % 1337;
    }
};