/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\Interview\Tencent\No2.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-04-18 20:48:07
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-04-18 22:05:23
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
    string s, t;
    int q;
    int x, y;
    cin >> s;
    cin >> t;
    cin >> q;
    while(q--){
        cin >> x >> y;
        int numS = s.size() - x + 1;
        int numT = t.size() - y + 1;
        int tmpX = x, tmpY = y;
        int max = 0;
        while( s[x-1] >= t[y-1] && x<=s.size() && y<=t.size()){
            // y ++
            y++;
            while(y<=t.size()){
                if(s[x-1] < t[y-1]){
                    int resM =  s.size() - x + t.size() - y + 2;
                    max = max>resM ?max:resM;
                    break;
                }
                y++;
            }

            y = tmpY;
            x++;
            while(x<=s.size()){
                if(s[x-1] < t[y-1]){
                    int resM =  s.size() - x + t.size() - y + 2;
                    max = max>resM ?max:resM;
                    break;
                }
                x++;
            }
        }
        if(max != 0 && s[x-1] < t[y-1]){
            cout << max << endl;
        }else{
            cout << numT << endl;
        }

    }

    system("pause");
    return 0;
}
