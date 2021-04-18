/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\Interview\Tencent\No4.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-04-18 20:48:18
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-04-18 21:59:11
 * @Version             : 1.0
 * @Description         : 
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



void dfs(vector<vector<int>>& graph, vector<vector<int>>& res, vector<int> &tmp, int s){
    tmp.push_back(s);
    if( s== (graph.size()-1)){
        res.push_back(tmp);
        tmp.pop_back(); // li kai
        return ;
    }

    // neibot
    for(int vertex:graph[s]){
        dfs(graph, res, tmp, vertex);
    }
    tmp.pop_back();
}

int main(){

    vector<vector<int>> graph;
    int testNum;
    cin >> testNum;
    while(testNum--){
        int n, m;
        cin >> n >> m;
        while(m--){
            int tmp1 , tmp2;
            cin >> tmp1 >> tmp2;
            if(tmp1 > tmp2){
                swap(tmp1, tmp2);
            }
            graph[tmp1-1].push_back(tmp2-1);
        }
        vector<vector<int>> res;
        vector<int> tmp;
        // 找1开头的最小路径
        dfs(graph, res, tmp, 1);

    }


    system("pause");
    return 0;
}

