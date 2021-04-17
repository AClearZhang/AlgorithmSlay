/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\Interview\360\ABSub.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-04-17 16:34:07
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-04-17 16:56:17
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
#include <vector>

using namespace std;



#define For(x,y,z) for(int x = y; x < z;++x)


int subString(string & a, int& count){
    while(true){
        int now = 0;
        string tmp = a;

        queue<int> q;
        For(i, 0, a.size()){
            if(a[i] == 'a'){
                q.push(i);
            }
        }

        // sub
        
        int sz = q.size();
        while(sz--){
            int pot = q.front();
            q.pop();

            // visit
            if(pot+1< a.size() && a[pot]== 'a' && a[pot+1] == 'b'){
                tmp.replace(pot+now, 2, "bba");
                now += 1;
                cout << "now tmp is:" << tmp << endl;
            }
        }
        cout << "count :" << count << ", now:" << now << endl;
        if(now == 0){
        // stop
            return count;
        }
        a = tmp;
        count += now;

    }

    
}



int main(){
    
    string inputs;
   	cin >> inputs;
    int count = 0;
    cout << subString(inputs, count) << endl;
    
    system("pause");
    return 0;
}
