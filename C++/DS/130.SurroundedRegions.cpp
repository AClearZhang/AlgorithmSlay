/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\DS\130.SurroundedRegions.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-03-26 21:53:25
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-03-26 22:26:18
 * @Version             : 1.0
 * @Description         : 被围困的区域  —— 进一步牛刀小用--学习使用union find抽象问题、解决问题的能力。
 * 130. 被围绕的区域
给你一个 m x n 的矩阵 board ，由若干字符 'X' 和 'O' ，找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
 

示例 1：


输入：board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
输出：[["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
解释：被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。
示例 2：

输入：board = [["X"]]
输出：[["X"]]
 

提示：

m == board.length
n == board[i].length
1 <= m, n <= 200
board[i][j] 为 'X' 或 'O'
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

/**
 * @Description: 
 * @param {*}
 * @return {*}
 * @notes: 把边界的'O'变成‘1’，然后遍历，遇见‘1’恢复成‘O’，其余都变成'X'
 */
class Solution {
public:
    void solve(vector<vector<char>>& board) {
         if(board.size()==0) return;
    
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++)//左右边界
        {
            dfs(board,i,0);
            dfs(board,i,n-1);
        }
        for(int j=1;j<n-1;j++)//上下边界
        {
            dfs(board,0,j);
            dfs(board,m-1,j);
        }
        // 将1变位0， 其它的变为X
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='1') board[i][j]='O';//边界恢复成‘O’
                else
                {
                    board[i][j]='X';//其余全为'X'
                }
            }
        }

    }

    void dfs(vector<vector<char>>& board,int i,int j)//把边界的‘O’变成'1’
    {
        if(i>=0&&j>=0&&i<board.size()&&j<board[0].size()&&board[i][j]=='O') 
        {
            board[i][j]='1';
            dfs(board,i+1,j);
            dfs(board,i-1,j);
            dfs(board,i,j+1);
            dfs(board,i,j-1);
        }
    }
};

