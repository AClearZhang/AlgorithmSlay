/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\692.TopKFrequentWords.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-04-12 15:56:16
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-04-12 19:53:48
 * @Version             : 1.0
 * @Description         : 前k个高频词
 * 692. 前K个高频单词
给一非空的单词列表，返回前 k 个出现次数最多的单词。

返回的答案应该按单词出现频率由高到低排序。如果不同的单词有相同出现频率，按字母顺序排序。

示例 1：

输入: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
输出: ["i", "love"]
解析: "i" 和 "love" 为出现次数最多的两个单词，均为2次。
    注意，按字母顺序 "i" 在 "love" 之前。
 

示例 2：

输入: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
输出: ["the", "is", "sunny", "day"]
解析: "the", "is", "sunny" 和 "day" 是出现次数最多的四个单词，
    出现次数依次为 4, 3, 2 和 1 次。
 

注意：

假定 k 总为有效值， 1 ≤ k ≤ 集合元素数。
输入的单词均由小写字母组成。
 */
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;


#define For(x,y,z) for (int x = y; x <= z; ++x)
typedef long long ll;

class Solution {
public:
    /**
     * @Description: 输入并返回前k个排序.  先输入进入、再排序；先按照value降序  再按照str大小升序.
     * @param {int} k
     * @return {*}
     * @notes: 
     */
    static bool cmp(const pair<string, int>& a, const pair<string, int>& b){
        return (a.second > b.second) || (a.second==b.second && a.first.compare(b.first) < 0 );
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        // 直接暴力 排序查找 
        // 牺牲空间换取时间
        int n = words.size();
        unordered_map<string, int> str_map;
        vector<string> res;
        for( string s:words){
            str_map[s]++;
        }
        vector<pair<string, int>> tmp_map(str_map.begin(), str_map.end());
        sort(tmp_map.begin(), tmp_map.end(), cmp);
        int i;
        For(i, 0, k-1){
            res.push_back(tmp_map[i].first);
        }
        return res;
    }
};