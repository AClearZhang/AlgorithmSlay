/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\934.ShortestBridge.cpp
 * @Author              : AClearZhang
 * @Date                : 2020-12-23 14:54:07
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2020-12-24 19:57:11
 * @Version             : 1.0
 * @Description         : 最短的桥
 * 934. 最短的桥
在给定的二维二进制数组 A 中，存在两座岛。（岛是由四面相连的 1 形成的一个最大组。）

现在，我们可以将 0 变为 1，以使两座岛连接起来，变成一座岛。

返回必须翻转的 0 的最小数目。（可以保证答案至少是 1。）

 

示例 1：

输入：[[0,1],[1,0]]
输出：1
示例 2：

输入：[[0,1,0],[0,0,0],[0,0,1]]
输出：2
示例 3：

输入：[[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
输出：1
 

提示：

1 <= A.length = A[0].length <= 100
A[i][j] == 0 或 A[i][j] == 1
 */

#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <windows.h>

using namespace std;

class Solution
{
public:
    /**
     * @Description: 岛屿最短距离？首先找到一个岛屿 ； 然后从这个岛屿广搜到下个岛屿。出来最短距离。
     * @Param: 
     * @Return: 
     * @Notes: 【注意：下方大佬的方法， 比我的快！100ms  me:188ms】
     * // 也可以不用，因为可以设置为 0；【小技巧】
     */
    vector<int> direction = {-1, 0, 1, 0, -1};
    int shortestBridge(vector<vector<int>> &A)
    {
        if (A.empty())
            return -1;

        int m = A.size(), n = A[0].size();
        queue<pair<int, int>> points;                            // dfs 将第一个岛屿加入到queue中。
        vector<vector<bool>> visited(m, vector<bool>(n, false)); // 也可以不用，因为可以设置为 0；【小技巧】

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                // 搜索到第一个1 即break；
                if (A[i][j] == 0)
                    continue;
                dfs(A, visited, points, i, j);
                break;
            }
            if (!points.empty())
                break;
        }

        int dis = -1;
        // 有了queue，开始bfs
        while (!points.empty())
        {
            int sz = points.size();
            for (int j = 0; j < sz; ++j)
            {
                pair<int, int> p = points.front();
                points.pop();
                //结束条件 和 剪枝
                if (A[p.first][p.second] == 1)
                {
                    // 当前数值有1
                    return dis;
                }

                // 邻域入队----除却自身
                for (int k = 0; k < 4; ++k)
                {
                    //上下左右邻域入队 且 不能被访问过
                    int r_new = p.first + direction[k], c_new = p.second + direction[k + 1];
                    if (r_new >= 0 && r_new < A.size() && c_new >= 0 && c_new < A[0].size() && !visited[r_new][c_new]) // 【小心越界】
                    {
                        points.emplace(r_new, c_new);
                        visited[r_new][c_new] = true;
                    }
                }
            }
            dis++;
        }
        return dis;
    }
    // 深度优先搜索，找到第一个岛屿;联通的岛屿
    void dfs(vector<vector<int>> &A, vector<vector<bool>> &visited, queue<pair<int, int>> &points, int r, int c)
    {
        if (r >= 0 && r < A.size() && c >= 0 && c < A[0].size() && A[r][c]) // && A[r][c]
        {
            // do
            points.emplace(r, c);
            A[r][c] = 0;
            visited[r][c] = true;
            // printf("我当前位置为：[%d, %d]\n", r, c);
            for (int k = 0; k < 4; ++k)
            {
                // 四个方向寻找
                dfs(A, visited, points, r + direction[k], c + direction[k + 1]);
            }
        }
    }
};

/**
 * @Description: 101 dalao's solution.
 * @Param: 
 * @Return: 
 * @Notes: 
 */
class Solution1
{
public:
    vector<int> direction{-1, 0, 1, 0, -1};
    // 主函数
    int shortestBridge(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> points;
        // dfs寻找第一个岛屿，并把1全部赋值为2
        bool flipped = false;
        for (int i = 0; i < m; ++i)
        {
            if (flipped)
                break;
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1)
                {
                    dfs(points, grid, m, n, i, j);
                    flipped = true;
                    break;
                }
            }
        }
        // bfs寻找第二个岛屿，并把过程中经过的0赋值为2
        int x, y;
        int level = 0;
        while (!points.empty())
        {
            ++level;
            int n_points = points.size();
            while (n_points--)
            {
                auto [r, c] = points.front();
                points.pop();
                for (int k = 0; k < 4; ++k)
                {
                    x = r + direction[k], y = c + direction[k + 1];
                    if (x >= 0 && y >= 0 && x < m && y < n)
                    {
                        if (grid[x][y] == 2)
                        {
                            continue;
                        }
                        if (grid[x][y] == 1)
                        {
                            return level;
                        }
                        points.push({x, y});
                        grid[x][y] = 2;
                    }
                }
            }
        }
        return 0;
    }
    // 辅函数
    void dfs(queue<pair<int, int>> &points, vector<vector<int>> &grid, int m, int n, int i, int j)
    {
        if (i < 0 || j < 0 || i == m || j == n || grid[i][j] == 2)
        {
            return;
        }
        if (grid[i][j] == 0)
        {
            points.push({i, j});
            return;
        }
        grid[i][j] = 2;
        dfs(points, grid, m, n, i - 1, j);
        dfs(points, grid, m, n, i + 1, j);
        dfs(points, grid, m, n, i, j - 1);
        dfs(points, grid, m, n, i, j + 1);
    }
};

/**
 * @Description: 根据题解 修改第二版/最终版
 * @Param: 
 * @Return: 
 * @Notes: 【通过 设置为2，进行剪枝访问。】
 */
class Solution2
{
public:
    /**
     * @Description: 岛屿最短距离？首先找到一个岛屿 ； 然后从这个岛屿广搜到下个岛屿。出来最短距离。
     * @Param: 
     * @Return: 
     * @Notes: 【注意：下方大佬的方法， 比我的快！100ms  me:188ms】
     */
    vector<int> direction = {-1, 0, 1, 0, -1};
    int shortestBridge(vector<vector<int>> &A)
    {
        if (A.empty())
            return -1;

        int m = A.size(), n = A[0].size();
        queue<pair<int, int>> points;                            // dfs 将第一个岛屿加入到queue中。
        vector<vector<bool>> visited(m, vector<bool>(n, false)); // 也可以不用，因为可以设置为 0；【小技巧】

        bool findOneIs = false;
        for (int i = 0; i < m; ++i)
        {
            if(findOneIs) break;
            for (int j = 0; j < n; ++j)
            {
                // 搜索到第一个1 即break；
                if (A[i][j]){
                    dfs(A, visited, points, i, j);
                    findOneIs = true;
                    break;
                }
            }
        }

        int dis = -1;
        // int dis = 0; // 因为周边0的也加上了。
        // 有了queue，开始bfs
        while (!points.empty())
        {
            int sz = points.size();
            for (int j = 0; j < sz; ++j)
            {
                pair<int, int> p = points.front();
                points.pop();
                //结束条件 和 剪枝
                if (A[p.first][p.second] == 1)
                {
                    // 当前数值有1
                    return dis;
                }

                // 邻域入队----除却自身
                for (int k = 0; k < 4; ++k)
                {
                    //上下左右邻域入队 且 不能被访问过
                    int r_new = p.first + direction[k], c_new = p.second + direction[k + 1];
                    if (r_new < 0 || r_new >= A.size() || c_new < 0 || c_new >= A[0].size()|| visited[r_new][c_new] || A[r_new][c_new] == 2){
                        continue;
                    }
                    points.emplace(r_new, c_new);
                    visited[r_new][c_new] = true;
                
                }
            }
            dis++;
        }
        return dis;
    }
    // 深度优先搜索，找到第一个岛屿;联通的岛屿
    void dfs(vector<vector<int>> &A, vector<vector<bool>> &visited, queue<pair<int, int>> &points, int r, int c)
    {
        if (r < 0 || r >= A.size() || c < 0 || c >= A[0].size() || A[r][c]==0 || A[r][c] ==2) // && A[r][c]
            return ;
        if(A[r][c] == 1){  A[r][c] = 2; }
        
        points.emplace(r, c);
        // A[r][c] = 0;
        visited[r][c] = true;
            // printf("我当前位置为：[%d, %d]\n", r, c);
        for (int k = 0; k < 4; ++k)
        {
            // 四个方向寻找
            dfs(A, visited, points, r + direction[k], c + direction[k + 1]);
            // if (x < 0 || x >= a.length || y < 0 || y >= a[0].length || visited[x][y] || a[x][y] == 0|| a[x][y] == 2) {
            //     continue;
            // }

        }

    }
};


class Solution3
{
public:
    /**
     * @Description: 岛屿最短距离？首先找到一个岛屿 ； 然后从这个岛屿广搜到下个岛屿。出来最短距离。
     * @Param: 
     * @Return: 
     * @Notes: 【注意：下方大佬的方法， 比我的快！100ms  me:188ms】
     */
    vector<int> direction = {-1, 0, 1, 0, -1};
    int shortestBridge(vector<vector<int>> &A)
    {
        if (A.empty())
            return -1;

        int m = A.size(), n = A[0].size();
        queue<pair<int, int>> points;                            // dfs 将第一个岛屿加入到queue中。
        vector<vector<bool>> visited(m, vector<bool>(n, false)); // 也可以不用，因为可以设置为 0；【小技巧】
    
        bool findOneIs = false;
        for (int i = 0; i < m; ++i)
        {
            if(findOneIs) break;
            for (int j = 0; j < n; ++j)
            {
                // 搜索到第一个1 即break；
                if (A[i][j]){
                    dfs(A, visited, points, i, j);
                    findOneIs = true;
                    break;
                }
            }
        }

        int dis = 0;
        // 有了queue，开始bfs
        while (!points.empty())
        {
            int sz = points.size();
            for (int j = 0; j < sz; ++j)
            {
                pair<int, int> p = points.front();
                points.pop();
                // 【当前位置不需要，直接 visit中，减少时间复杂度】

                // 邻域入队----除却自身，且 去除越界值减少时间复杂度
                // 但是 Big O时间复杂度不变。
                for (int k = 0; k < 4; ++k)
                {
                    //上下左右邻域入队 且 不能被访问过
                    int r_new = p.first + direction[k], c_new = p.second + direction[k + 1];
                    if (r_new >= 0 && r_new < A.size() && c_new >= 0 && c_new < A[0].size() && !visited[r_new][c_new]) // 【小心越界】
                    {
                        // visit
                        if(A[r_new][c_new] == 1) return dis;

                        // 其它等于零.
                        points.emplace(r_new, c_new);
                        visited[r_new][c_new] = true;
                    }
                }
            }
            dis++;
        }
        return dis;
    }
    // 深度优先搜索，找到第一个岛屿;联通的岛屿
    void dfs(vector<vector<int>> &A, vector<vector<bool>> &visited, queue<pair<int, int>> &points, int r, int c)
    {
        if (r >= 0 && r < A.size() && c >= 0 && c < A[0].size() && A[r][c]) // && A[r][c]
        {
            // do
            points.emplace(r, c);
            A[r][c] = 0;
            visited[r][c] = true;
            // printf("我当前位置为：[%d, %d]\n", r, c);
            for (int k = 0; k < 4; ++k)
            {
                // 四个方向寻找
                dfs(A, visited, points, r + direction[k], c + direction[k + 1]);
            }
        }
    }
};

int main()
{

    // vector<vector<int>> arr = {{0, 1}, {1, 0}};
    // vector<vector<int>> arr = {{0, 1, 0}, {0, 0, 0}, {0, 0, 1}};
    vector<vector<int>> arr = {{1, 1, 1, 1, 1}, {1, 0, 0, 0, 1}, {1, 0, 1, 0, 1}, {1, 0, 0, 0, 1}, {1, 1, 1, 1, 1}};
    Solution so;
    Solution1 so1;
    Solution2 so2;
    Solution2 so3;
    // int distance = so.shortestBridge(arr);
    int distance = so3.shortestBridge(arr);
    cout << "两个桥之前最小的距离为：" << distance << endl;
    system("pause");
    return 0;
}