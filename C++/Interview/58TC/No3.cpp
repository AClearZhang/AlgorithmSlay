/*
 * @FilePath            : \AlgorithmInterview\AlgorithmSlay\C++\Interview\58TC\No3.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-10-09 21:14:16
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-10-09 21:43:07
 * @Version             : 1.0
 * @Description         : 推荐帖子排序
 * 
 */
#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <map>
#include <vector>

using namespace std;


#define For(x,y,z) for(ll x = y; x < z;++x)
typedef long long ll;


class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 基于输入的全量帖子列表、需推荐帖子数量和打散窗口的大小，返回最终满足打散条件且排好序的推荐结果
     * @param itemList string字符串vector 全量帖子列表
     * @param n int整型 最终推荐的帖子量
     * @param k int整型 打散窗口的大小
     * @return string字符串vector
     */
    vector<string> split(string str, char del){
        stringstream ss(str);
        string tmp;
        vector<string> res;
        while(getline(ss, tmp, del)){
            res.push_back(tmp);
        }
        return res;
    }


    static bool cmp(vector<string> a, vector<string> b){
        return atoi(a[1].c_str()) > atoi(b[1].c_str());
    }
    
    vector<string> recomInfoListSort(vector<string>& itemList, int n, int k) {
        vector<vector<string>> item2DList;

        for( auto item : itemList ){
            vector<string> rel = split(item, '#');
            item2DList.push_back(rel);
        }
        sort(item2DList.begin(), item2DList.end(), cmp);

        vector<string> res;
        unordered_map<string, int> pointMap;
        for(int i = 0; i < n ;i++){
            if( i%k == 0 ){
                pointMap.clear();
            }

                // 当前ctr 为-1为已取过
            for(auto vec : item2DList){
                if( pointMap.count(vec[2]) == 0 && atoi(vec[1].c_str()) >= 0 ){
                    res.push_back(vec[0] + '#' + vec[1] + '#' + vec[2]);
                    pointMap[vec[2]] ++;
                    vec[1] = -1;
                    break;
                }
            }

        }
        return res;
        // 40% 通过率
    }
};
