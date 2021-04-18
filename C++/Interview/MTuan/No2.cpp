/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\Interview\MTuan\No2.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-04-18 10:55:23
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-04-18 11:10:19
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

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    // map<ll, ll, greater<ll>> aSoli, bSoli; // max heap
    int resA=0, resB=0;
    // A soilder
    while(n--){
        ll x, y;
        cin >> x >> y;
        if( y >= k){
            resA+= x*y;
        }
        // aSoli[y] = x;
    }

    // B soilder
    while(m--){
        ll x, y;
        cin >> x >> y;
        if( y >= k){
            resB+= x*y;
        }
        // bSoli[y] = x;
    }
    cout << resA << " "<< resB << endl;
    if(resA > resB) {
        cout << "A" << endl;
    }else{
        cout << "B" << endl;
    }
    system("pause");
    return 0;
}


