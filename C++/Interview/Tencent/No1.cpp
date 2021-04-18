/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\Interview\Tencent\No1.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-04-18 20:19:49
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-04-18 20:43:03
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


int main(){
    unordered_map<int, int> inputs;
    int n,m;
    cin >> n >> m;
    cin.get();
    For(i, 0, n){
        int tmp;
        cin >> tmp;
        inputs[tmp]++;
    }
    cin.get();
    while(m--){
        int weight;
        cin >> weight;
        bool isFound = false;
        for(auto in :inputs){
            // int res = ;
            if(inputs.count(weight + in.first) > 0){
                isFound = true;
                cout << in.first << " "<< weight + in.first << endl;
                break;
            }
        }
        if(isFound == false){
            cout << -1 << " " << -1 <<endl;
        }
    }

    // for(auto in:inputs){
    //     cout << in.first << " " << in.second << endl;
    // }
    system("pause");
    return 0;
}

