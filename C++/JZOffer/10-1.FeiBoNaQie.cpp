/*
 * @FilePath            : \project\AlgorithmSlay\C++\JZOffer\10-1.FeiBoNaQie.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-09-17 11:13:18
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-09-17 11:34:26
 * @Version             : 1.0
 * @Description         : 剑指 Offer 10- I. 斐波那契数列
写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项（即 F(N)）。斐波那契数列的定义如下：

F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
斐波那契数列由 0 和 1 开始，之后的斐波那契数就是由之前的两数相加而得出。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

 

示例 1：

输入：n = 2
输出：1
示例 2：

输入：n = 5
输出：5
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

/**
 * @Description: 非常耗费时间； 优化状态.
 * @param {*}
 * @return {*}
 * @notes: 
 */
class Solution {
public:
    Solution(int a=0):val(a){
        cout << "init finished!" << endl;
    }
    int fib(int n) {
        // base
        if(n == 0 || n == 1){
            return n;
        }

        // recursion
        int vision = 7 + pow(10, 9);  // 
        return (fib(n-1) + fib(n-2)) % vision;
    }
    int val = 0;
};

/**
 * @Description: 优化只需要两个 状态进行正向迭代即可.
 * @param {*}
 * @return {*}
 * @notes: 
 */
class Solution2 {
public:
    int fib(int n) {
		if (n == 0 || n == 1)
			return n;

		int a = 1, b = 0;
		for (int i = 1; i < n; i++) {
			a = a + b;
			b = a - b;
			a %= 1000000007;
		}
		return a;
	}
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.fib(10) << endl;
    system("pause");
    return 0;
}

