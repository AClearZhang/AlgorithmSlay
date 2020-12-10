/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\875.KoEatingBananas.cpp
 * @Author              : AClearZhang
 * @Date                : 2020-12-10 11:17:08
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2020-12-10 11:37:34
 * @Version             : 1.0
 * @Description         : koko 吃香蕉问题——涉及 二分查找问题
 * 
 * 珂珂喜欢吃香蕉。这里有 N 堆香蕉，第 i 堆中有 piles[i] 根香蕉。警卫已经离开了，将在 H 小时后回来。

珂珂可以决定她吃香蕉的速度 K （单位：根/小时）。每个小时，她将会选择一堆香蕉，从中吃掉 K 根。如果这堆香蕉少于 K 根，她将吃掉这堆的所有香蕉，然后这一小时内不会再吃更多的香蕉。  

珂珂喜欢慢慢吃，但仍然想在警卫回来前吃掉所有的香蕉。

返回她可以在 H 小时内吃掉所有香蕉的最小速度 K（K 为整数）。

 

示例 1：

输入: piles = [3,6,7,11], H = 8
输出: 4
示例 2：

输入: piles = [30,11,23,4,20], H = 5
输出: 30
示例 3：

输入: piles = [30,11,23,4,20], H = 6
输出: 23
 

提示：

1 <= piles.length <= 10^4
piles.length <= H <= 10^9
1 <= piles[i] <= 10^9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/koko-eating-bananas
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */


#include <iostream>
#include <windows.h>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;


class Solution {
public:
    /**
     * @description: 分析：1、首先暴力搜索方法思考  2、其次，用二分搜索，替代暴力搜索  3、直接二分搜索可以的堆树的  左侧界
     * @param {*}
     * @return {*}
     * @notes: 
     */
    int minEatingSpeed(vector<int>& piles, int H) {
        int n = findMaxNum(piles);
        int left=0, right = n;
        while(left < right){
            int mid = left + (right - left) /2;
            


        }

    }
    int findMaxNum(vector<int> piles){
        // vector<int>::iterator p = piles.begin();
        int max = 0;
        for(auto p : piles){
            if(p>max){
                max = p;
            }
        }
        return max;
    }
};

int main(){



    system("pause");
    return 0;
}



