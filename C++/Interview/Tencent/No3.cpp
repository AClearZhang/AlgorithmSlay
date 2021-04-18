/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\Interview\Tencent\No3.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-04-18 20:48:14
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-04-18 21:39:31
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
    double R1, X1, Y1, X3, Y3;
    cin >> R1 >> X1 >> Y1 >> X3 >> Y3;
    double dis = sqrt(pow(Y1-Y3,2) + pow(X1-X3,2));
    double r = (dis+R1) /2;
    if(Y1 == 0){
        cout << r << 0 << r << endl;
    }else{
        cout << 0 << r << r << endl;
    }
    

    system("pause");
    return 0;
}
