/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\695.MaxAreaOfIsland.cpp
 * @Author              : AClearZhang
 * @Date                : 2020-12-15 22:32:09
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2020-12-15 22:34:57
 * @Version             : 1.0
 * @Description         : 岛屿的最大面积
 * 695. 岛屿的最大面积
给定一个包含了一些 0 和 1 的非空二维数组 grid 。

一个 岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在水平或者竖直方向上相邻。你可以假设 grid 的四个边缘都被 0（代表水）包围着。

找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为 0 。)

 

示例 1:

[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
对于上面这个给定矩阵应返回 6。注意答案不应该是 11 ，因为岛屿只能包含水平或垂直的四个方向的 1 。

示例 2:

[[0,0,0,0,0,0,0,0]]
对于上面这个给定的矩阵, 返回 0。

 

注意: 给定的矩阵grid 的长度和宽度都不超过 50。
 */
#include <iostream>
#include <map>
#include <vector>
#include <windows.h>
#include <unordered_map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {

    }
};


int main(){
    // vector<int> arr = {1,1,1,2,2,3};
    vector<int> arr = {1};
    // int k = 2;
    int k = 1;
    Solution so;
    auto rel = so.topKFrequent(arr, k);
    for(auto r:rel){
        cout << r << endl;
    }

    system("pause");
    return 0;
}