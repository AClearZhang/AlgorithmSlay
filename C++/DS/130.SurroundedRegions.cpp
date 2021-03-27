/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\DS\130.SurroundedRegions.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-03-26 21:53:25
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-03-27 10:19:30
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
#include "UnionFind.h"

using namespace std;

/**
 * @Description: 大材小用 —— 并查集分类 并动态连接 边界处的O为一类；虚拟出一个 dummy节点 进行处理分类。
 * @param {*}
 * @return {*}
 * @notes: 我们的思路是把所有边界上的 OO 看做一个连通区域。遇到 OO 就执行并查集合并操作，这样所有的 OO 就会被分成两类

和边界上的 OO 在一个连通区域内的。这些 OO 我们保留。
不和边界上的 OO 在一个连通区域内的。这些 OO 就是被包围的，替换。
由于并查集我们一般用一维数组来记录，方便查找 parants，所以我们将二维坐标用 node 函数转化为一维坐标。

 */
class Solution {
public:
    /**
     * @Description: 首先将 边界处的O连通到dummy上；然后 附近的O与四周的O连通； 最后边界上一类的O不变，其它的O 变为X.
     * @param {*}
     * @return {*}
     * @notes: 
     */
    void solve(vector<vector<char>>& board) {
        vector<int> direction = {-1, 0, 1, 0, -1};
        int m = board.size(), n = board[0].size();
        UnionFind *unionSearch = new UnionFind(m*n+1);
        int dummy = m*n;
        for(int i = 0; i<m ;i++){
            for(int j = 0; j<n ;j++){
                if(board[i][j] == 'O'){
                    if( i == 0 || i==(m-1)||j==0||j==(n-1)){
                        // 边界处
                        unionSearch->unionRoot(dummy, node(i,j,n));
                    }else{
                        // 非边界处，与四周的O相连接
                        for(int k = 0;k<4;k++){
                            int iNew=i+direction[k], jNew=j+direction[k+1];
                            if(board[iNew][jNew] == 'O'){
                                // 当前新的是 O，则连接起来
                                unionSearch->unionRoot(node(i,j,n), node(iNew, jNew,n));
                            }
                        }
                    }

                }
            }
        }

        // 开始找非dummy一类的 O，替换为X
        for(int i = 0; i<m ;i++){
            for(int j = 0; j<n ;j++){
                if(!unionSearch->connected(dummy, node(i,j,n))&& board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
    // helper 将i，j二维数组变换成一维数组
    int node(int i, int j, int n){
        return i*n + j;    
    }
};

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

