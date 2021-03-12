/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\36.ValidSudoku.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-03-12 22:35:45
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-03-13 00:07:09
 * @Version             : 1.0
 * @Description         : 有效的 数独基础判断
 * 36. 有效的数独
判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。


上图是一个部分填充的有效的数独。

数独部分空格内已填入了数字，空白格用 '.' 表示。

示例 1:

输入:
[
  ["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
输出: true
示例 2:

输入:
[
  ["8","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
输出: false
解释: 除了第一行的第一个数字从 5 改为 8 以外，空格内其他数字均与 示例1 相同。
     但由于位于左上角的 3x3 宫内有两个 8 存在, 因此这个数独是无效的。
说明:

一个有效的数独（部分已被填充）不一定是可解的。
只需要根据以上规则，验证已经填入的数字是否有效即可。
给定数独序列只包含数字 1-9 和字符 '.' 。
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
     * @Description: 方法一：穷举 O(N^3)  方法二：牺牲空间换时间，打表
     * @param {*}
     * @return {*}
     * @notes: 
     */
    bool isValidSudoku(vector<vector<char>>& board) {
        // int m = 9, n =9;
        // for(int n=0;n<9;n++){
        //     if(board[i][n] == ch || board[n][j]==ch){
        //         return false;
        //     }
        //     // 九宫格有无 重复; 向下取整
        //     if(board[(i/3)*3+n%3][(j/3)*3+n/3] == ch){ //【key】board[(i/3)*3+n/3][(j/3)*3+n%3]  一样一样的
        //         return false;
        //     }
        // }
        // return true;
        
        // start 空间换时间
        // 记录某行，某位数字是否已经被摆放
        vector<vector<bool>> row(9, vector<bool>(9, false));
        // 记录某列，某位数字是否已经被摆放
        vector<vector<bool>> col(9, vector<bool>(9, false));

        // 记录某 3x3 宫格内，某位数字是否已经被摆放
        vector<vector<bool>> block(9, vector<bool>(9, false));


        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j]-'1';// gai cuowu atoi(&board[i][j])-1;
                    if(!row[i][num] && !col[j][num] && !block[i/3+(i/3)*2+j/3][num]){  //block 不对
                        // 不存在摆放。
                        row[i][num]=true;
                        col[j][num]=true;
                        block[i/3+(i/3)*2+j/3][num]=true;
                    }else{
                        return false;
                    }
                }
            }
        }
        return true;
    }
};