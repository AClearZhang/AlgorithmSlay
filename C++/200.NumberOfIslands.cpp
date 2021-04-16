/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\200.NumberOfIslands.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-04-16 15:22:50
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-04-16 15:42:50
 * @Version             : 1.0
 * @Description         : 岛屿个数
 * 200. 岛屿数量
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。

此外，你可以假设该网格的四条边均被水包围。

 

示例 1：

输入：grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
输出：1
示例 2：

输入：grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
输出：3
 

提示：

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] 的值为 '0' 或 '1'
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
#include <vector>

using namespace std;


#define For(x,y,z) for(int x = y; x < z;++x)


class Solution {
public:
    /**
     * @Description: 寻找岛屿个数  使用dfs并且设置 visited和递归 方向
     * @param {*}
     * @return {*}
     * @notes: 注意 合法数值
     */
    int *direction = new int[5] {-1, 0, 1, 0, -1};
    int numIslands(vector<vector<char>>& grid) {
        int res=0;
        int m=grid.size(), n=grid[0].size();
        For(i, 0, m){
            For(j, 0, n){
                if(grid[i][j] == '1'){
                    res+=1;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }
    // helper dfs
    void dfs(vector<vector<char>>& grid, int row,int col){
        if(row>=0 && row<grid.size() && col>=0 && col<grid[0].size()){
            if(grid[row][col] == '1'){
                grid[row][col] = '2';
                For(i, 0, 4){
                    dfs(grid, row+*(direction+i), col+*(direction+i+1));
                }
            }else{
                return ;
            }
        }else{
            return ;
        }
    }
};