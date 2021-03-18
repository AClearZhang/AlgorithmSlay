/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\Basics\FastPow.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-03-18 22:30:41
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-03-18 22:37:55
 * @Version             : 1.0
 * @Description         : 快速幂算法 based on 372 superpow
 *  使用二进制 实现，一半一半的 幂运算
 */

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;


/**
 * @Description:  关键是 维持x每次自身相乘（作为底数 或2^0 1 2……）； 当发现二进制有1时，才成当前x。
 * @param {int} x 底数
 * @param {int} n 幂
 * @return {*}
 * @notes: 
 */
int FastPow(int x, int n){
    int res = 1;
    while(n){
        if(n&1){
            // n 当前位置为1 ；获取
            res*=x;
        }
        x *= x;
        n >>= 1; // 二进制 右移一位；目的是取到下一个低位 二进制。
    }
    return res;
}

int main(){
    int res = FastPow(2, 10);
    cout << "当前2^10 数值为：" << res << endl;

    system("pause");
    return 0;
}
 