/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\Interview\MTuan\No1.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-04-18 10:05:19
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-04-18 11:01:54
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
#include <map>
#include <vector>

using namespace std;



#define For(x,y,z) for(ll x = y; x < z;++x)
typedef long long ll;

vector<string> split(string str, char del){
    stringstream ssr(str);
    string tmp;
    vector<string> res;
    while(getline(ssr, tmp, del)){
        res.push_back(tmp);
    }
    return res;
}

bool cmp(const pair<ll,ll> &a, const pair<ll,ll> &b){
    return b.second < a.second;
}


ll main(){
    
    ll n;
    map<ll, ll> idMap;
    cin >> n;
    cin.get();
    while(n--){
        string inputs, ID, POPIS;
        // cin >> inputs >> ID >> POPIS;
        // getchar();
        getline(cin, inputs, '\n');
        // getchar();
        // cout << inputs << endl;
        if(inputs == "query"){
            // query
            if(idMap.empty()){
                cout << "null" << endl;
                continue;
            }else if(idMap.size() == 1){
                cout << idMap.begin()->first << endl;
                continue;
            }

            // more
            vector<pair<ll,ll>> sortPop(idMap.begin(), idMap.end());
            sort(sortPop.begin(), sortPop.end(), cmp);
            if(sortPop.size()<=10){
                vector<pair<ll,ll>>::iterator it;
                for(it = sortPop.begin(); it<(sortPop.end()-1) ;it++){
                    cout << it->first << " ";
                }
                cout << it->first << endl;

            }else
            {
                For(i, 0, 9){
                    cout << sortPop[i].first << " ";
                }
                cout << sortPop[9].first << endl;
            }
            
            
        }else{
            // append
            vector<string> appendStr = split(inputs, ' ');
            stringstream ssr1(appendStr[1]), ssr2(appendStr[2]);
            
            ll id, popIs;
            ssr1 >> id;
            ssr2 >> popIs;
            idMap[id] += popIs;
        }

    }

    system("pause");
    return 0;
}
 