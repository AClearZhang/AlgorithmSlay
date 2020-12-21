/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\79.WordSearch.cpp
 * @Author              : AClearZhang
 * @Date                : 2020-12-21 10:13:34
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2020-12-21 16:24:39
 * @Version             : 1.0
 * @Description         : 79. 单词搜索
给定一个二维网格和一个单词，找出该单词是否存在于网格中。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

 

示例:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

给定 word = "ABCCED", 返回 true
给定 word = "SEE", 返回 true
给定 word = "ABCB", 返回 false
 * 
 */

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

class Solution
{
public:
    vector<int> direction{-1, 0, 1, 0, -1};
    /**
     * @Description: 搜索是否粗拿在子字符串
     * @Param: 
     * @Return: 
     * @Notes: 
     */
    bool exist(vector<vector<char>> &board, string word)
    {
        // 注意 原始边界！
        if (board.empty())
            return false;

        // vector<char> track;
        int count = 0;              // 此处不用 计数的，只需要看位置。
        bool rel = false;
        int m = board.size(), n = board[0].size();
        vector<vector<bool>>  visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                dfsWordExit(board, i, j, rel, 0, visited, word);
            }
        }
        return rel;
    }
    /**
     * @Description: 对应辅助函数，进行深搜 并寻找单词。
     * @Param: 
     * @Return: 通过 rel 是否存在返回：true or false;
     * @Notes: 
     */
    void dfsWordExit(vector<vector<char>> &board, int r, int c, bool &rel, int count, vector<vector<bool>> &visited,string &word)
    {
        // 关键在深搜
        // 边缘结束
        if(r<0 || r>=board.size() || c<0 || c>=board[0].size()||count>word.length() || rel || visited[r][c])  return;
        // if(board[r][c]!=word[count]) return ;
        // 结束条件
        if (word.length() == count)  // 因为有了上面那个条件，所以这可以用-1；
        {
            rel = true;
            return;
        }

        //do
        if (board[r][c] == word[count])   //边缘没处理好 使得出现语法错误！不应该
        {
            // cout << "i am in and word is:" << word[count] << endl; 
            // 才开始深搜
            count++;
            visited[r][c] = true;
            for (int k = 0; k < 4; ++k)
            {
                dfsWordExit(board, r + direction[k], c + direction[k + 1], rel, count, visited, word);
            }
            // 还原错误了
            // 回溯返回状态
            count--;
            visited[r][c] = false;
        }

        return;
    }
    /**
     * @Description: 修改dfs为大佬的写法去除冗余
     * @Param: pos修改；添加 visited —— 反之返回重复；即去除已访问过的，防止回溯到。
     * @Return: 
     * @Notes: 
     */
    void dfsWordExit1(vector<vector<char>> &board, int r, int c, bool &rel, int pos, vector<vector<bool>> &visited,string &word)
    {
        // 关键在深搜
        // 边界约束
        if(r<0 || r>=board.size() || c<0 || c>=board[0].size()||pos>word.length() )  return;
        // 未找到---提前结束条件
        if(board[r][c]!=word[pos]|| rel || visited[r][c]) return ;
        // 找到的结束条件
        if (word.length()-1 == pos)  // 因为有了上面那个条件，所以这可以用-1；
        {
            rel = true;
            return;
        }

        //do

        // cout << "i am in and word is:" << word[pos] << endl; 
        // 才开始深搜
        visited[r][c] = true;
        for (int k = 0; k < 4; ++k)
        {
            dfsWordExit1(board, r + direction[k], c + direction[k + 1], rel, pos+1, visited, word);
        }
    
        // 回溯返回状态
        visited[r][c] = false;   //回溯去除，说明当前节点不能往下了；但是可以作为最后的中间件。所以false。
        return;
    }
};

int main()
{
    vector<vector<char>> arr = {{'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}};
    // string word = "ABCCED";
    string word = "ABCB";   //会报错，注意已经访问过的  不要再重复访问了。
    // for(int i = 0;i<word.length();++i){
    //     cout<<word[i] << endl;
    // }
    Solution so;
    auto rel = so.exist(arr, word);
    cout << "是否存在当前word：" << rel << endl;
    system("pause");
    return 0;
}
