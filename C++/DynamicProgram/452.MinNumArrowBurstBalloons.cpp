/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\DynamicProgram\452.MinNumArrowBurstBalloons.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-03-08 23:31:17
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-03-09 12:07:22
 * @Version             : 1.0
 * @Description         : 贪婪+DP——用最少数量的箭 引爆气球。
 * 452. 用最少数量的箭引爆气球
在二维空间中有许多球形的气球。对于每个气球，提供的输入是水平方向上，气球直径的开始和结束坐标。由于它是水平的，所以纵坐标并不重要，因此只要知道开始和结束的横坐标就足够了。开始坐标总是小于结束坐标。

一支弓箭可以沿着 x 轴从不同点完全垂直地射出。在坐标 x 处射出一支箭，若有一个气球的直径的开始和结束坐标为 xstart，xend， 且满足  xstart ≤ x ≤ xend，则该气球会被引爆。可以射出的弓箭的数量没有限制。 弓箭一旦被射出之后，可以无限地前进。我们想找到使得所有气球全部被引爆，所需的弓箭的最小数量。

给你一个数组 points ，其中 points [i] = [xstart,xend] ，返回引爆所有气球所必须射出的最小弓箭数。

 
示例 1：

输入：points = [[10,16],[2,8],[1,6],[7,12]]
输出：2
解释：对于该样例，x = 6 可以射爆 [2,8],[1,6] 两个气球，以及 x = 11 射爆另外两个气球
示例 2：

输入：points = [[1,2],[3,4],[5,6],[7,8]]
输出：4
示例 3：

输入：points = [[1,2],[2,3],[3,4],[4,5]]
输出：2
示例 4：

输入：points = [[1,2]]
输出：1
示例 5：

输入：points = [[2,3],[2,3]]
输出：1
 */
#include <iostream>
#include <cmath>
#include <windows.h>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() == 0) return 0;
        // 按照end 从小到大排序。
        sort(points.begin(), points.end(), cmpare);
        
        // 执行贪婪算法
        int count = 1; // 至少一个
        int end_right = points[0][1];
        for(int i = 0; i<points.size() ;i++){
            int start = points[i][0];
            if(end_right < start){          //【关键】 类似于435 但是此处相等也算是 重叠了！去嗲了 等于号。
                // 此时不重叠 加加
                count++;
                // 更换 end_right
                end_right = points[i][1];
            }
        }
        // 最长不重叠 为count;
            // 需要至少射出 cont个箭放个 扎破气球。
        return count;
    }
    static bool cmpare(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }
};
