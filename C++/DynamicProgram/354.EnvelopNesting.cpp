/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\354.EnvelopNesting.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-02-02 16:08:24
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-02-02 17:41:08
 * @Version             : 1.0
 * @Description         : 信封嵌套问题
 * 354. 俄罗斯套娃信封问题
给定一些标记了宽度和高度的信封，宽度和高度以整数对形式 (w, h) 出现。当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。

请计算最多能有多少个信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。

说明:
不允许旋转信封。

示例:

输入: envelopes = [[5,4],[6,4],[6,7],[2,3]]
输出: 3 
解释: 最多信封的个数为 3, 组合为: [2,3] => [5,4] => [6,7]。
 */

#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <cmath>
#include <algorithm>

using namespace std;



class Solution {
public:
    /**
     * @Description: 按照最长递增子序列(一维)；首先将 数组w升序排序，h降序排序
     * @param {*}
     * @return {*}
     * @notes: 重点，h降序保证了 当w相同时，至多只有一个被选入递增子序列的h。
     */
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if(envelopes.empty()) {
            return 0;
        }
        sort(envelopes.begin(), envelopes.end(), cmp);
        // 提出第二维的数组
        vector<int> oper;
        for(auto e:envelopes){
            oper.push_back(e[1]);
        }

        // 使用LIS处理 oper返回嵌套信封的个数。
        return lengthOfLIS(oper);
    }
    // 辅助函数——辅助比较
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[0]<b[0] || (a[0] == b[0] && a[1] > b[1]);
    }
    /**
     * @Description: 最长递增子序列
     * @param {*}
     * @return {*}
     * @notes: 
     */
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        for(int i = 0; i<nums.size() ; i++){
            for(int j = 0; j<i ;j++){
                if(nums[i] > nums[j]){
                    // 表明当前状态 可由j+1 进行设置数值
                    dp[i] = max(dp[i], 1+dp[j]);
                }
            }
        }

        // 遍历找出最大的dp来
        int maxSeq = 1;
        for(int a:dp){
            maxSeq = a>maxSeq ? a : maxSeq ;
        }
        return maxSeq;
    }
};