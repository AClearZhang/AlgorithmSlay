/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\JZOffer\29.ShunShiZhen.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-04-28 23:11:58
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-04-28 23:38:15
 * @Version             : 1.0
 * @Description         : 顺时针打印矩阵
 */
#include <algorithm>
#include <cmath>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <set>
#include <deque>  // 失策 是想到了有双向链表性质的deque--很多缺点——没想到自己用底层的 数据结构去合成！
#include <list>

using namespace std;


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return {};
        vector<int> res;
        int m = matrix.size(), n = matrix[0].size();
        // 确定上下左右四条边的位置
        int up = 0, down = m - 1, left = 0, right = n - 1;
        while (true)
        { 
            // 不断寻找和缩小左右上下边界
            // 一直到上下边界诶重合结束
            int i = up, j = left;
            // you
            while(j<=right) res.push_back(matrix[i][j++]);
            up +=1,i=up,j=right;
            if(up>down) break;
            // xia
            while(i<=down) res.push_back(matrix[i++][j]);
            //zuo
            right -= 1,i=down, j=right;
            while(j>=left) res.push_back(matrix[i][j--]);
            // shang
            down-=1, i=down, j=left;
            if(up>down) break;
            while(i>=up) res.push_back(matrix[i--][j]);
            left+=1;
        }
        return res;
    }
};
