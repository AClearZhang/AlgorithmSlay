/*
 * @FilePath            : \project\AlgorithmSlay\C++\36.SudokuSolver.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-03-12 21:19:58
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-03-12 22:27:44
 * @Version             : 1.0
 * @Description         : 解决数独
 * 37. 解数独
编写一个程序，通过填充空格来解决数独问题。

一个数独的解法需遵循如下规则：

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
空白格用 '.' 表示。



一个数独。



答案被标成红色。

提示：

给定的数独序列只包含数字 1-9 和字符 '.' 。
你可以假设给定的数独只有唯一解。
给定数独永远是 9x9 形式的。
 */

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    /**
     * @Description: 这里只用给出一个解——所以使用 回溯。暴力穷举即可。
     * @param {*}
     * @return {*}
     * @notes: 
     */
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board, 0, 0);
    }
    // helper——穷举每个位置 '1'--'9'.
        // 回溯对应位置的数独解； 若不符合则回溯；若找到一个解则返回 true
    bool backtrack(vector<vector<char>>& board, int i, int j){
        int m=9,n=9;
        if(j==n){
            return backtrack(board, i+1, 0);
        }
        if(i==m){
            return true; // 找到一个解
        }
        // weijia gai
            //wu1 shuzi zhijie return
        if(board[i][j]!='.'){
            return backtrack(board, i, j+1);
        }

        // 遍历回溯寻找
        for(char ch='1';ch<='9';ch++){
            if(!isValid(board,i,j,ch)){
                continue;       // wrong! return false;wrong!!
            }
            board[i][j] = ch;
            if(backtrack(board, i, j+1)){
                // found
                return true;
            }
            board[i][j] = '.'; //不符合就回溯
        }
        return false;
    }
    // helper's helper 判断当前位置是否符合填入 ch
    bool isValid(vector<vector<char>>& board, int i, int j, char ch){
        for(int n=0;n<9;n++){
            if(board[i][n] == ch || board[n][j]==ch){
                return false;
            }
            // 九宫格有无 重复; 向下取整
            if(board[(i/3)*3+n%3][(j/3)*3+n/3] == ch){ //【key】board[(i/3)*3+n/3][(j/3)*3+n%3]  一样一样的
                return false;
            }
        }
        return true;
    }
};