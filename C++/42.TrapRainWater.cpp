/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\42.TrapRainWater.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-03-19 22:37:15
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-03-19 22:58:16
 * @Version             : 1.0
 * @Description         : 接雨水
 * 42. 接雨水
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

 

示例 1：



输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
输出：6
解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 
示例 2：

输入：height = [4,2,0,3,2,5]
输出：9
 */
#include <algorithm>
#include <cmath>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;


class Solution {
public:
    /**
     * @Description: 方法一：暴力解法—— O(N^2) 每次都寻找左右两边最大的中的 最小的一个，减去自身即为储水量。
     * @param {*}
     * @return {*}
     * @notes: 
     */
    int trap(vector<int>& height) {
        if(height.empty()) return 0;
        int ans = 0;
        for(int i = 1; i<(height.size()-1); i++){
            int l_max = 0;
            for(int j = 0; j<i;j++){
                l_max = max(l_max, height[j]);
            }
            int r_max = 0;
            for(int b = i+1; b<height.size() ;b++){
                r_max = max(r_max, height[b]);
            }
            int temp = (min(l_max, r_max) - height[i]);
            if( temp > 0){
                ans += temp;
            }
            // cout << "now ans is:" << ans << endl;
        }
        return ans;
    }
    /**
     * @Description: 方法二：添加备忘录；另一种意义上的备忘录，进一步降低时间复杂度。
     * @param {*}
     * @return {*}
     * @notes: 首先计算出 l_max 和 r_max 就避免了平方的时间复杂度。
     */
    int trap(vector<int>& height){
        
    }
};
