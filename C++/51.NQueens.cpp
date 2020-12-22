/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\51.n_queens.cpp
 * @Author              : AClearZhang
 * @Date                : 2020-12-21 22:51:42
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2020-12-22 15:12:24
 * @Version             : 1.0
 * @Description         : n皇后问题
 * 51. N 皇后
n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。



上图为 8 皇后问题的一种解法。

给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。

每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

 

示例：

输入：4
输出：[
 [".Q..",  // 解法 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // 解法 2
  "Q...",
  "...Q",
  ".Q.."]
]
解释: 4 皇后问题存在两个不同的解法。
 

提示：

皇后彼此不能相互攻击，也就是说：任何两个皇后都不能处于同一条横行、纵行或斜线上。
 */
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;
/**
 * @Description: 注意之前的wordsearch是图类型的求解。这里是构建起了搜索树进行求解——所以不需要在【外围】一一边遍历。
 * @Param: 
 * @Return: 
 * @Notes: 
 */
class Solution {
public:
    /**
     * @Description: n皇后问题求解
     * @Param: 
     * @Return: 
     * @Notes: 
     */
    vector<vector<string>> solveNQueens(int n) {
        if(n==0) return {{}};
        int cur = 0;  // 默认从第零行开始
        vector<int> visited(n, -1);  // 记录每一列对应设置的 行号【cur】
        vector<vector<string>> ans;
        vector<string> track(n);
        // 外面不需要---
        // for(int i =0;i<n;++i){
        dfsAllLocation(ans, track, cur, n, visited);
        // }
        return ans;
    }
    // n皇后的辅助函数
    // 进行回溯的遍历 —— 【关键是 又一次看作是决策树进行深搜。
    // 其中新增 剪枝多余的部分 ——  【遍历之外，去想怎么符合题目去做（除却 新建数组等方法的封装等。）
    void dfsAllLocation(vector<vector<string>> &ans, vector<string> &track, int cur, int n, vector<int> &visited){
        // 边界的话返回
        // if(cur < 0 || cur >= n || col < 0 || col >= n )  return ;
        // 重复访问过列 —— 剪枝时候会考虑
        // if(visited[col] >=0) return ;

        // 符合最终大小，入数组
        if(cur == n ){ // n
            ans.push_back(track);
            return ;
        }

       
        // 状态节点和 路径记录
        for(int i = 0; i < n ;++i){
            // 剪枝
            if(!isValid( cur, i, visited)){
                //如果 已经在位置上了，重复了则  剪枝
                continue;
            }
            
            // do处理
            string s(n,'.');
            s[i] = 'Q';
            track[cur] = s;
                //访问标记
            visited[i] = cur;
                //开始深搜
            dfsAllLocation(ans, track, cur+1, n, visited);
                // 返回当前状态
            visited[i] = -1;

        }
    }
    // 判断是否 有效位置
    bool isValid(int r, int c, vector<int> visited){
        //判断列是否有效
        if(visited[c] >= 0) { return false; }
        //判断斜方向是否有效
        for(int i = 0; i < visited.size() ;++i){
            if(visited[i] >=0 ){
                if(abs(c-i) == abs(r-visited[i])){
                    //存在斜方向
                    return false;
                }
            }
        }
        // 列和斜方向都没有
        return true;
    }

};

class Solution1 {
public:
    /**
     * @Description: 101大佬C++ 的解法.
     * @Param: 
     * @Return: 
     * @Notes: 
     */
    vector<vector<string>> solveNQueens(int n){
        vector<vector<string>> ans;
        if(n == 0){
            return ans;
        }
        vector<string> board(n, string(n, '.'));
        vector<bool> column(n, false), ldiag(2*n-1, false), rdiag(2*n-1,false);
        backtracking(ans, board, column, ldiag, rdiag, 0, n);
        return ans;
    }
    // 辅函数
    void backtracking(vector<vector<string>> &ans, vector<string> &board, vector<bool> &column, vector<bool> &ldiag, vector<bool> &rdiag, int row, int n){
        if(row == n){
            ans.push_back(board);
            return ;
        }
        for ( int i = 0; i < n ; i++){
            //剪枝
            // if(column[i] || ldiag[n-row+i-1] || rdiag[row+i+1]){
            if(column[i] || ldiag[row-i+n-1] || rdiag[row+i]){
                continue;
            }
            // 修改当前节点/选择边状态 进行下一个搜索
            board[row][i] = 'Q';
            // column[i] = ldiag[n-row+i-1] = rdiag[row+i+1] = true;
            column[i] = ldiag[row-i+n-1] = rdiag[row+i] = true;
            // 递归子节点
            backtracking(ans, board, column, ldiag, rdiag, row+1, n);
            // 回改当前节点状态
            board[row][i] = '.';
            // column[i] = ldiag[n-row+i-1] = rdiag[row+i+1] = false;
            column[i] = ldiag[row-i+n-1] = rdiag[row+i] = false;
        }
    }

};

int main()
{
    vector<int> arr = {1,2,3,4,5};
    Solution1 so;
    auto queens = so.solveNQueens(4);

    cout << "[" << endl ;
    for(auto q:queens){
        cout << "[ "  ;
        for(auto q1 : q){
            cout << q1 << "," << endl;
        }
        cout << "]," << endl;
    }
    cout << "]" << endl;
    system("pause");
    return 0;
}
