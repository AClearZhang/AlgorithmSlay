/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\DynamicProgram\435.NonOverlapInterval.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-03-08 23:30:07
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-03-09 12:02:37
 * @Version             : 1.0
 * @Description         : 贪婪算法 + DP —— 区间调度问题。
 * 435. 无重叠区间
给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。

注意:

可以认为区间的终点总是大于它的起点。
区间 [1,2] 和 [2,3] 的边界相互“接触”，但没有相互重叠。
示例 1:

输入: [ [1,2], [2,3], [3,4], [1,3] ]

输出: 1

解释: 移除 [1,3] 后，剩下的区间没有重叠。
示例 2:

输入: [ [1,2], [1,2], [1,2] ]

输出: 2

解释: 你需要移除两个 [1,2] 来使剩下的区间没有重叠。
示例 3:

输入: [ [1,2], [2,3] ]

输出: 0

解释: 你不需要移除任何区间，因为它们已经是无重叠的了。
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
    /**
     * @Description: 重点在于。end <= zuoStart{count++};
     * @param {*}
     * @return {*}
     * @notes: 
1.从区间集合 intvs 中选择一个区间 x，这个 x 是在当前所有区间中结束最早的（end 最小）。

2. 把所有与 x 区间相交的区间从区间集合 intvs 中删除。

3. 重复步骤 1 和 2，直到 intvs 为空为止。之前选出的那些 x 就是最大不相交子集。
     */
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return 0;
        // 按照end 从小到大排序。
        sort(intervals.begin(), intervals.end(), cmpare);
        
        // 执行贪婪算法
        int count = 1; // 至少一个
        int end_right = intervals[0][1];
        for(int i = 0; i<intervals.size() ;i++){
            int start = intervals[i][0];
            if(end_right <= start){
                // 此时不重叠 加加
                count++;
                // 更换 end_right
                end_right = intervals[i][1];
            }
        }
        // 最长不重叠 为count;
            // 所以需要擦除  n-count
        return intervals.size()-count;
    }
    static bool cmpare(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }
};
