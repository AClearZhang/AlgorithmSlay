/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\DynamicProgram\64.MiniPathSum.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-04-23 10:02:17
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-04-23 10:15:18
 * @Version             : 1.0
 * @Description         ：最小路径和
 * 64. 最小路径和
给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。

 

示例 1：


输入：grid = [[1,3,1],[1,5,1],[4,2,1]]
输出：7
解释：因为路径 1→3→1→1→1 的总和最小。
示例 2：

输入：grid = [[1,2,3],[4,5,6]]
输出：12
 

提示：

m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 100
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
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        // base
        // 因为只能向右和 向下进行，所以边缘设置为累加
        dp[0][0] = grid[0][0];
        For(i, 1, m){
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        For(j, 1, n){
            dp[0][j] = dp[0][j-1] + grid[0][j];
        }


        // dp目标进行
        // 目标结果为  上面和左面的 递推进行
        For(i, 1, m){
            For(j, 1, n){
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};


/**
 * @Description: 方法二 可以原地做。  状态压缩.
 * @param {*}
 * @return {*}
 * @notes: 
 */
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row=grid.size(), col = grid[0].size();
        if(row == 0 || col == 0) return 0;
        // 初始化
        for(int i = 1; i < row; i++) grid[i][0] += grid[i-1][0];
        for(int i = 1; i < col; i++) grid[0][i] += grid[0][i-1];
        // 原地遍历
        for(int i = 1; i < row; i++){
            for(int j = 1 ; j < col; j++)
                grid[i][j] += min(grid[i-1][j],grid[i][j-1]);
        }
        return grid[row-1][col-1];
    }
};