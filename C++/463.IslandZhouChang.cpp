/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\463.IslandZhouChang.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-04-23 09:19:24
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-04-23 09:35:07
 * @Version             : 1.0
 * @Description         : 岛屿周长
 * 463. 岛屿的周长
给定一个 row x col 的二维网格地图 grid ，其中：grid[i][j] = 1 表示陆地， grid[i][j] = 0 表示水域。

网格中的格子 水平和垂直 方向相连（对角线方向不相连）。整个网格被水完全包围，但其中恰好有一个岛屿（或者说，一个或多个表示陆地的格子相连组成的岛屿）。

岛屿中没有“湖”（“湖” 指水域在岛屿内部且不和岛屿周围的水相连）。格子是边长为 1 的正方形。网格为长方形，且宽度和高度均不超过 100 。计算这个岛屿的周长。

 

示例 1：



输入：grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
输出：16
解释：它的周长是上面图片中的 16 个黄色的边
示例 2：

输入：grid = [[1]]
输出：4
示例 3：

输入：grid = [[1,0]]
输出：4
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
    vector<int> direction{-1, 0, 1, 0, -1};
    int islandPerimeter(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        For(i, 0, m){
            For(j, 0, n){
                if(grid[i][j] == 1){
                    return dfs(grid, i, j);
                }
            }
        }
    }
     // helper dfs // 返回当前的遇到的周长 —— 关键：表格边+1； 海洋边+1；重复则返回
    int dfs(vector<vector<int>>& grid, int row,int col){
        int res=0;
        if(row>=0 && row<grid.size() && col>=0 && col<grid[0].size()){
            if(grid[row][col] == 1){
                grid[row][col] = 2;
                For(i, 0, 4){
                    res+=dfs(grid, row+direction[i], col+direction[i+1]);
                }
                return res;
            }else if(grid[row][col] == 0){ // 遇到海
                return 1;
            }
            else{
                // '2'重复 返回0
                return 0;
            }
        }else{
            // 表格边
            return 1;
        }
    }
};