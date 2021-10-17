/*
 * @FilePath            : \AlgorithmInterview\AlgorithmSlay\C++\Interview\MTuan\qiuzhao\No2.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-04-18 10:55:23
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-10-17 14:26:01
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


int main(){
    int n;
    cin >> n;
    vector<int> a(n, 0);
    vector<int> b(n, 0);
    vector<int> rel(n, 0);
    rel[0] = 1, a[0] = 1, b[0] = 1;
    
    For(i, 1, n){
        int tmp;
        cin >> tmp;
        a[i] = tmp;
    }
    For(i, 1, n){
        int tmp;
        cin >> tmp;
        b[i] = tmp;
    }
    For(i, 1, n){
        rel[i] = a[i] * rel[b[i]-1];
    }
    For(i, 0, n-1){
        cout << rel[i] << " ";
    }
    cout << rel[n-1] << endl;
    

    
    system("pause");
    return 0;
}


