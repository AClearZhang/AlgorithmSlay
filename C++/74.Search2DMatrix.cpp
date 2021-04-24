/*
 * @FilePath            : \project\AlgorithmSlay\C++\74.Search2DMatrix.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-04-25 00:27:05
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-04-25 00:30:50
 * @Version             : 1.0
 * @Description         : 搜索二维矩阵
 * 74. 搜索二维矩阵
编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：

每行中的整数从左到右按升序排列。
每行的第一个整数大于前一行的最后一个整数。
 

示例 1：


输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
输出：true
示例 2：


输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
输出：false
 

提示：

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104
 */

#include <vector>
#include <iostream>
#include <queue>

using namespace std;

#define For(x,y,z) for(int x=y; x<z; x++)



class Solution {
public:
    /**
     * @Description: 对应使用 二分搜索即可。
     * @param {int} target
     * @return {*}
     * @notes: 注意都是 n —— 从而将二维矩阵化为 1维得到答案。
     */
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()||matrix[0].empty())return 0;
        int left=0,right=matrix.size()*matrix[0].size()-1;
        int n=matrix[0].size();
        while(left<=right)//循环结束的条件为区间内没有元素了
        {
            int mid=left+((right-left)/2);
            if(matrix[mid/n][mid%n]>target)right=mid-1;
            else if(matrix[mid/n][mid%n]<target)left=mid+1;
            else return true;
        }
        return false;
    }
};