/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\Interview\MTuan\hg\No4.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-05-09 10:19:43
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-05-09 15:36:21
 * @Version             : 1.0
 * @Description         : 机器人题目
 * 
 */



#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

#define For(x, y, z) for (ll x = y; x < z; ++x)
typedef long long ll;


/**
 * @Description: 使用bfs 从后往前搜索。
 * @param {int} x
 * @param {int} y
 * @return {*}  返回搜搜中的最短路径/最小能量。
 * @notes: 
 */
int bfs(vector<vector<char>>& matrix, vector<vector<bool>>& visited, int x, int y,int m, int n) {
    // int m = matrix.size(), n = matrix[0].size();
    int dirs[4][2] = { {1,0},{0,1},{-1,0},{0,-1}};
    queue<vector<int>> q;  // 0 1为坐标； 2 为是否破坏过障碍——1为可破坏一次，0为不能破坏。
    int ans=0;  // 最少能量损耗。
    
    q.push({x, y, 1});
    
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            auto cur = q.front(); q.pop();
            auto i = cur[0];
            auto j = cur[1];
            auto z = cur[2];

            // solve
            if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || (matrix[i][j]=='*' && z==0)) {
                continue; // Don't use return!!!!　DFS return, BFS should only contine inside loop!!!
            }
            if(i == 0 && j==0){
                return ans;
            }

            // find closest
            visited[i][j] = true;
            for (const auto& dir : dirs) {
                auto ni = i + dir[0];
                auto nj = j + dir[1];
                if(matrix[i][j] == '*' && z==1){
                    z = 0;
                }
                q.push({ni, nj, z});
            }
        }
        ans++;
    }
    // 能够达到走里面return；达不到走外面 return -1
    return -1;
}


int main(){

    int m,n;
    cin >> m >> n;
    vector<vector<char>> grid(m, vector<char>(n,'.'));
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            char a;
            cin >> a;
            grid[i][j] = a;
            // cin >> grid[i][j];       
        }
    }

    vector<vector<bool>> visited(m, vector<bool>(n, false));
    cout << bfs(grid, visited, m-1, n-1, m ,n) << endl;
   
    return 0;
}