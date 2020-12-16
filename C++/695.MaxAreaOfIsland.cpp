/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\695.MaxAreaOfIsland.cpp
 * @Author              : AClearZhang
 * @Date                : 2020-12-15 22:32:09
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2020-12-16 10:22:33
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
#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <windows.h>

using namespace std;
class Solution
{
public:
    /**
     * @Description: 使用深度优先搜索递归调用； 相当于先序遍历 —— 先搜索当前的位置，然后再深入/递归到 循环调用自身，找到周围的岛屿 ++。
     * @Param: 
     * @Return: 
     * @Notes: 
     */
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int max = 0, now = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
            {
                //r c 找到位置下面开始dfs
                if (grid[i][j])
                {
                    now = dfs(grid, i, j);
                    max = max < now ? now : max;
                }
            }
        return max;
    }
protected:
    int dfs(vector<vector<int>> &grid, int r, int c)
    {
        int rel = 0;

        // 限定防止在边缘  或者 跑出递归的边界
        // 注意边缘也是可以为1的！
        if (r > -1 && r < grid.size() && c > -1 && c < grid[0].size() && grid[r][c])
        {
            int di[] = {-1, 1, 0, 0}, dj[] = {0, 0, -1, 1}; //分别对应上下左右深搜方向
            // 相当于先序遍历开始；
            grid[r][c] = 0;
            rel += 1;
            // 再进行深搜
            for (int i = 0; i < 4; i++)
            {
                rel += dfs(grid, r + di[i], c + dj[i]);
            }
        }
        return rel;
    }
};

int main()
{
    vector<vector<int>> arr = { {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                                {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                                {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
                                {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0} };
    vector<vector<int>> arr1 = {{0,0,0,0,0,0,0,0}};
    vector<vector<int>> arr2 = {{1,1,0,0,0},{1,1,0,0,0},{0,0,0,1,1},{0,0,0,1,1}};
    Solution so;
    // int maxArea = so.maxAreaOfIsland(arr);
    int maxArea = so.maxAreaOfIsland(arr2);
    cout << "当前最大的面积为：" << maxArea << endl;    
    system("pause");
    return 0;
}