/*
 * @FilePath            : \AlgorithmInterview\AlgorithmSlay\C++\Interview\MTuan\qiuzhao\No1.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-04-18 10:05:19
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-10-17 11:40:01
 * @Version             : 1.0
 * @Description         : 美团第一道
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
#include <unordered_set>
#include <map>
#include <vector>

using namespace std;



#define For(x,y,z) for(ll x = y; x < z;++x)
typedef long long ll;

vector<int> split(string str, char del){
    stringstream ssr(str);
    string tmp;
    vector<int> res;
    int count = 1;
    while(getline(ssr, tmp, del)){
        if( count % 2 == 0 ){
            // col
            // cout << "tmp:" << tmp << endl;
            res.push_back( atoi( tmp.substr(0, tmp.size() - 1).c_str() ) );
        }else{
            // row
            // cout << "tmp:" << tmp << endl;
            res.push_back( atoi(tmp.substr(1, tmp.size() - 1).c_str())  );
        }
        count ++;
        // res.push_back(tmp);
    }
    return res;
}


bool hasCycle( int pre, int cur, set<int>& visited, int n, vector<vector<int>>& adjMap){
    if( cur >=0 ){
        visited.insert(cur);
        
        for( int j = 0; j < n ; j++){
            if( adjMap[cur][j] == 1 ){
                adjMap[cur][j] = 0;
                if( j != pre ){
                    if( visited.find(j) != visited.end() ){
                        return true;
                    }else{
                        if( hasCycle(cur, j, visited, n, adjMap ) ){
                            return true;
                        }
                    }
                }
               
            }
        }
        return false;
    }
}

int main(){
    int num, n, m;
    cin >> num;
    while( num-- ){
        cin >> n >> m;
        vector<vector<int>> adjMap( n, vector<int>(n, 0));
        bool isTree = true;
            // 输入边
        cin.get();
        string inputs;
        getline(cin, inputs, '\n');
        vector<int> edg = split(inputs, ' ');
        for( int i = 0; i < m*2 ;i+=2){
            int r = edg[i], c = edg[i+1];
            adjMap[r-1][c-1] = 1;
            adjMap[c-1][r-1] = 1;
        }
        // dfs
        set<int> visited;
        if( hasCycle(-1, 0, visited, n, adjMap) || visited.size() == n ){
            cout << "No" << endl;
        }else{
            cout << "Yes" << endl;
        }
    }
    
    system("pause");
    return 0;
}
 