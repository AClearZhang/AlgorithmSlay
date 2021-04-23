/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\48.RotateImage.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-04-23 13:58:52
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-04-23 14:16:03
 * @Version             : 1.0
 * @Description         : 翻转图像
 * 48. 旋转图像
给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。

你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。

 

示例 1：


输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[[7,4,1],[8,5,2],[9,6,3]]
示例 2：


输入：matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
输出：[[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
示例 3：

输入：matrix = [[1]]
输出：[[1]]
示例 4：

输入：matrix = [[1,2],[3,4]]
输出：[[3,1],[4,2]]
 

提示：

matrix.length == n
matrix[i].length == n
1 <= n <= 20
-1000 <= matrix[i][j] <= 1000
 */
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

#define For(x,y,z) for(int x=y; x<z; x++)



class Solution {
public:
    /**
     * @Description: 技巧：先 上下翻转，然后再对角翻转即可
     * @param {*}
     * @return {*}
     * @notes: 
     */
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        For(i,0,m/2){
            matrix[i].swap(matrix[m-i-1]);
        }
        // 对角元素 互换
        For(i, 0, m){
            For(j, i+1, n){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};