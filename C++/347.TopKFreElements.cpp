/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\347.TopKFreElements.cpp
 * @Author              : AClearZhang
 * @Date                : 2020-12-14 22:05:18
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2020-12-15 11:35:28
 * @Version             : 1.0
 * @Description         : 347. 前 K 个高频元素
给定一个非空的整数数组，返回其中出现频率前 k 高的元素。

 

示例 1:

输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]
示例 2:

输入: nums = [1], k = 1
输出: [1]
 */
#include <iostream>
#include <map>
#include <vector>
#include <windows.h>
#include <unordered_map>
#include <algorithm>

using namespace std;
typedef  pair<int,int> PAIR;

class Solution {
public:
    /**
     * @Description: 思路：首先使用map进行频率统计； 然后 排序value大小；最后 返回前k个的 key
     * @Param: 
     * @Return: 
     * @Notes: 
     */
    
    static bool cmp(const pair<int,int> &a, const pair<int,int> &b){
        return a.second > b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> sta;
        // 比较仍需要转存到 vector中
        //开始统计
        for(auto a:nums){
            sta[a]++;
        }
        vector<PAIR> vec(sta.begin(), sta.end()); // 【关键】

        sort(vec.begin(), vec.end(), cmp);
        vector<int> rel;
        for(auto s:sta){
            if(--k<0) break;
            rel.push_back(s.first);
        }
        return rel;
    }
};

int main(){
    vector<int> arr = {1,1,1,2,2,3};
    int k = 2;
    Solution so;
    auto rel = so.topKFrequent(arr, k);
    for(auto r:rel){
        cout << r << endl;
    }

    system("pause");
    return 0;
}