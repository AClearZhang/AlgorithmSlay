/*
 * @FilePath            : \AlgorithmInterview\AlgorithmSlay\C++\Interview\Baidu\qiuzhao\No1.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-04-18 10:55:23
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-10-18 20:03:31
 * @Version             : 1.0
 * @Description         : 美团第二道题
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



#define For(x,y,z) for(int x = y; x < z;++x)
typedef long long ll;


void dfs( vector<vector<pair<int, int>>>& graph,  pair<int, int>& res, vector<pair<int, int>>& track, set<int>& visited, int s){
    visited.insert(s);
    if( s == graph.size()-1 ){
        // 到达最后一点, 开始找最小的
        int tan=0, time=0;
        for( auto tmp : track ){
            tan += tmp.first;
            time += tmp.second;
        }
        
        if(  res.first > tan  || (res.first == tan && res.second > time)){
            res.first = tan;
            res.second = time;   
        }
        visited.erase(s);
        return ;
    }

    // visited
    for(int i=1; i < graph.size(); i++){
        if( graph[s][i].first == INT_MAX || graph[s][i].second == INT_MAX){
            continue;
        }
        track.push_back({ graph[s][i] });
        dfs( graph, res, track, visited, i);
        track.pop_back();
    }
    visited.erase(s);
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n, vector<pair<int, int>>(n, {INT_MAX, INT_MAX}));
    pair<int, int> res = { INT_MAX, INT_MAX };
    vector<pair<int, int>> track;
    set<int> visited;
    
    for( int i = 0; i< m ; i++){
        int edg1, edg2, tan, time;
        cin >> edg1 >> edg2 >> tan >> time;
        graph[edg1-1][edg2-1] = {tan, time};
        graph[edg2-1][edg1-1] = {tan, time};
    }
    dfs( graph, res, track, visited, 0 );
    cout << res.first << " " << res.second << endl;
    system("pause");
    return 0;
}


