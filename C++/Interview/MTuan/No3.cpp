/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\Interview\MTuan\No3.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-04-18 11:18:17
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-04-18 11:43:13
 * @Version             : 1.0
 * @Description         : 美团第三道
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

bool cmp(const pair<char,int> &a, const pair<char,int> &b){
    return a.second < b.second;
}

int main(){

    int n;
    unordered_map<char, list<int>> mapTrain;
    unordered_map<char, int> mapOrder; // order
    int count = 0;
    cin >> n;
    while( n-- ){
        int z;
        char x1 , y;
        cin >> z >> x1 >> y;
        if(z == 1){
            // 1
            int x;
            x = atoi(&x1);

            mapTrain[y].push_back(x);
            if(mapOrder.count(y) == 0){
                // wu
                mapOrder[y] = count++;
            }
            
        }else{
            // 2
            char x = x1;
            int tmp1 = mapOrder[x], tmp2 = mapOrder[y];
            mapOrder[x] = tmp2;
            mapOrder[y] = tmp1;
        }


    }
    // sort 
    vector<pair<char, int>> testS(mapOrder.begin(), mapOrder.end());
    sort(testS.begin(), testS.end(), cmp);

    for(auto a: testS){
        list<int> list = mapTrain[a.first];
        for(auto b: list){
            cout << b << " ";
        }
    }
    cout << endl;

    system("pause");
    return 0;
}
