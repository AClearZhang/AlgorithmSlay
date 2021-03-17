/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\1109.CorporateFlightBookings.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-03-17 20:30:39
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-03-17 22:28:57
 * @Version             : 1.0
 * @Description         : 航班预定统计
 * 1109. 航班预订统计
这里有 n 个航班，它们分别从 1 到 n 进行编号。

有一份航班预订表 bookings ，表中第 i 条预订记录 bookings[i] = [firsti, lasti, seatsi] 意味着在从 firsti 到 lasti （包含 firsti 和 lasti ）的 每个航班 上预订了 seatsi 个座位。

请你返回一个长度为 n 的数组 answer，其中 answer[i] 是航班 i 上预订的座位总数。

 

示例 1：

输入：bookings = [[1,2,10],[2,3,20],[2,5,25]], n = 5
输出：[10,55,45,25,25]
解释：
航班编号        1   2   3   4   5
预订记录 1 ：   10  10
预订记录 2 ：       20  20
预订记录 3 ：       25  25  25  25
总座位数：      10  55  45  25  25
因此，answer = [10,55,45,25,25]
示例 2：

输入：bookings = [[1,2,10],[2,2,15]], n = 2
输出：[10,25]
解释：
航班编号        1   2
预订记录 1 ：   10  10
预订记录 2 ：       15
总座位数：      10  25
因此，answer = [10,25]
 

提示：

1 <= n <= 2 * 104
1 <= bookings.length <= 2 * 104
bookings[i].length == 3
1 <= firsti <= lasti <= n
1 <= seatsi <= 104
 */

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;



class Solution {
public:
    /**
     * @Description: 前缀和 之 使用数学运算小技巧——O(N) 时间内实现航班 数量统计。
     * @param {int} n
     * @return {*}
     * @notes: 
     */
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        // 首先构造 diff； 然后区间增加； 最后还原为 answers
        vector<int> diff(n, 0); // 初试全部0
        vector<int> answer(n, 0);

        // 区间增加
        for(int i = 0; i<bookings.size();i++){
            // 针对i 增加val；j+1  减少val
                // note: j+1>= len() 则不处理。
            int i_incre = bookings[i][0];
            int j1_sub = bookings[i][1];
            
            diff[i_incre-1] += bookings[i][2];
            if(j1_sub >= n){
                continue;
            }
            diff[j1_sub] -= bookings[i][2];
        }
        
        // 还原为answers
        answer[0] = diff[0];
        for(int i = 1; i<n  ;i++){
            answer[i] = answer[i-1] + diff[i];
        }
        return answer;
    }
};

