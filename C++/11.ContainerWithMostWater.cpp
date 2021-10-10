/*
 * @FilePath            : \AlgorithmInterview\AlgorithmSlay\C++\11.ContainerWithMostWater.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-10-09 16:31:07
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-10-09 16:37:58
 * @Version             : 1.0
 * @Description         : 盛水最多的容器
 * 11. 盛最多水的容器
给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0) 。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器。

 

示例 1：



输入：[1,8,6,2,5,4,8,3,7]
输出：49 
解释：图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
示例 2：

输入：height = [1,1]
输出：1
示例 3：

输入：height = [4,3,2,1,4]
输出：16
示例 4：

输入：height = [1,2,1]
输出：2
 

提示：

n == height.length
2 <= n <= 105
0 <= height[i] <= 104
 * 
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
     * @Description: 双指针问题，  证明了每次取最大的高度  即可.
     * @param {*}
     * @return {*}
     * @notes: 
     */
    int maxArea(vector<int>& height) {
        int res = 0;
        int l = 0, r = height.size()-1;
        while(l < r){
            int nowHeight = height[l] < height[r] ? height[l++] : height[r--];   // 注意此处 后++/ --
            res = max(res, (r - l + 1)*nowHeight); 
        }
        return res;
    }
};


int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}


