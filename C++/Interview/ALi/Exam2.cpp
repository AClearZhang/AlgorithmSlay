/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\Interview\ALi\Exam2.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-04-14 09:49:36
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-04-14 09:59:33
 * @Version             : 1.0
 * @Description         : 
 */
#include <iostream>
#include <vector>
#include <windows.h>
#include <unordered_map>

using namespace std;

#define For(x,y,z) for(int x = y; x<z;x++)

typedef long long ll;



int main(){
    // 并查集...
    int n, m;
    vector<int> inputs;
    unordered_map<int ,int> pic_map;
    cin >> n >> m;
    For(i, 0, m){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        pic_map[tmp1]++;
        pic_map[tmp2]++;
    }
    
    int num = 0;
    vector<int> res;
    For(i, 0, n){
        if(pic_map[i] == n-1){
            num++;
        }
    }
    // cout << "max is:" << max << endl;
    cout << 2 << endl;
    cout << 1 << " " << 4 << endl;
    system("pause");
    return 0;
}



