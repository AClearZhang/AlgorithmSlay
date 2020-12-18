/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\417.PacificAtlanticWaterFlow.cpp
 * @Author              : AClearZhang
 * @Date                : 2020-12-15 22:34:29
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2020-12-18 20:25:36
 * @Version             : 1.0
 * @Description         : 417. 太平洋大西洋水流问题
给定一个 m x n 的非负整数矩阵来表示一片大陆上各个单元格的高度。“太平洋”处于大陆的左边界和上边界，而“大西洋”处于大陆的右边界和下边界。

规定水流只能按照上、下、左、右四个方向流动，且只能从高到低或者在同等高度上流动。

请找出那些水流既可以流动到“太平洋”，又能流动到“大西洋”的陆地单元的坐标。

 

提示：

输出坐标的顺序不重要
m 和 n 都小于150
 

示例：

 

给定下面的 5x5 矩阵:

  太平洋 ~   ~   ~   ~   ~ 
       ~  1   2   2   3  (5) *
       ~  3   2   3  (4) (4) *
       ~  2   4  (5)  3   1  *
       ~ (6) (7)  1   4   5  *
       ~ (5)  1   1   2   4  *
          *   *   *   *   * 大西洋

返回:

[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (上图中带括号的单元).
 */
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    /**
     * @Description: 为了能够一次性访问完成—— 使用大神的逆向DFS方法。
     * @Param: 
     * @Return: 
     * @Notes: 两个数组逆向流动，从低到高 记录能够抵达太平洋和大西洋的位置。
     */
    //设置深搜四个方向
    vector<int> direction{-1, 0, 1, 0, -1};
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &matrix)
    {
        vector<vector<int>> rel;
        if( matrix.empty() ) return {};
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<bool>> can_reach_p(m, vector<bool>(n, false));
        vector<vector<bool>> can_reach_a(m, vector<bool>(n, false));
        for( int i = 0; i<m ;++i ){
            // 从边上开始 深搜 逆流而上。
            dfs(matrix, can_reach_p, i, 0);
            dfs(matrix, can_reach_a, i, n-1);
        }
        for(int j=0;j<n;++j){
            dfs(matrix, can_reach_p, 0, j);
            dfs(matrix, can_reach_a, m-1, j);
        }

        // 判断哪个位置  两个海洋都能访问到。
        for(int i = 0; i<m ;i++){
            for(int j = 0; j < n ;j++){
                if(can_reach_p[i][j] && can_reach_a[i][j])
                    rel.push_back({i, j});
            }
        }
        return rel;
    }
    /**
     * @Description: 深搜，当前逆流而上能接触到哪些位置。
     * @Param: 
     * @Return: 
     * @Notes: 注意，这样子逆流而上， 同时又保证了只能访问一次【因为原地有了操作，不会再循环 重复访问了。】
     */
    void dfs(vector<vector<int>> &matrix, vector<vector<bool>> &can_reach, int r, int c){
        // 必须保证在范围内
        int m = matrix.size(), n = matrix[0].size();

        // 处理 —— 类似于先序遍历；所以 先设置，后深搜 —— 并且在深搜之前进行 约束规范；之后就不需要开头就约束 规范了!
        if(can_reach[r][c]) return;
        can_reach[r][c] = true;
        
        // 开始深搜
        for(int i = 0; i < 4 ;++i){
            int x = r + direction[i], y = c + direction[i+1];
            if( x >=0 && x<m&& y >=0 && y < n  && matrix[x][y] >= matrix[r][c]){ // 不会越界，因为这里限制了。
                dfs(matrix, can_reach, x, y);
            }

        }

    }

    /**
     * @Description: 太平洋和大西洋图中的深搜，寻找高地。
     * @Param: 
     * @Return: 
     * @Notes: 【注意】正向DFS容易死循环——到达已经访问过的图中，所以要有个 visit或原地设个标志……未完成
     */
    vector<vector<int>> pacificAtlantic1(vector<vector<int>> &matrix)
    {
        vector<vector<int>> rel;
        // 0 表示是否能进入太平洋；1 表示是否能进入大西洋。
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                //开始深搜返回 ocean
                vector<bool> ocean (2,false); 
                cout << "i am in" << endl;
                if (dfsHigh1(matrix, INT_MAX, i, j, ocean))
                {
                    rel.push_back({i, j});
                }
            }
        }
        return rel;
    }
    bool dfsHigh1(vector<vector<int>> &matrix, int bef, int r, int c, vector<bool> &ocean)
    {
        // 边界
        if (r < 0 || c < 0)
        {
            ocean[0] = true;
            return (ocean[0] && ocean[1]);
        } //可以进入太平洋
        else if (r >= matrix.size() || c >= matrix[0].size())
        {
            ocean[1] = true;
            return (ocean[0] && ocean[1]);
        } // 可以进入大西洋
        
        cout << "now matrix[r][c]: " << r << "," << c << ":" << matrix[r][c] << ";";
        // 未 越界
        if(matrix[r][c] <= bef){
            // 正经的基于当前位置进行流动
            return dfsHigh1(matrix, matrix[r][c], r-1, c, ocean) ||   
                   dfsHigh1(matrix, matrix[r][c], r+1, c, ocean)||
                   dfsHigh1(matrix, matrix[r][c], r, c-1, ocean) || 
                   dfsHigh1(matrix, matrix[r][c], r, c+1, ocean);
        }
        
    }
};

int main()
{
    vector<vector<int>> arr = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                               {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
                               {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
    vector<vector<int>> arr1 = {{0, 0, 0, 0, 0, 0, 0, 0}};
    vector<vector<int>> arr2 = {{1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {6,7,1,4,5}, {5, 1, 1, 2, 4}};
    vector<vector<int>> arr3 = {{1, 0, 0, 1}, {0, 1, 1, 0}, {0, 1, 1, 1}, {1, 0, 1, 1}};
    vector<vector<int>> arr4 = {};
    vector<vector<int>> arr5 = {{}, {1,1}};

    Solution so;
    // auto rel = so.pacificAtlantic(arr2);
    // auto rel = so.pacificAtlantic(arr4);
    auto rel = so.pacificAtlantic(arr5);

    cout << "当前可以流出的位置为：" << endl;
    for(auto r : rel){
        cout << "[" << r[0] << "," << r[1] << "]" << ", ";
    }
    cout << endl;

    system("pause");
    return 0;
}