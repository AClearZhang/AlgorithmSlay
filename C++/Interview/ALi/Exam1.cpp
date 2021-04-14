/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\Interview\ALi\Exam1.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-04-14 09:12:23
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-04-14 09:45:13
 * @Version             : 1.0
 * @Description         : 题目1
 * 
 */
#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

#define For(x,y,z) for(int x = y; x<z;x++)

typedef long long ll;



int main(){
    int n;
    vector<int> inputs;
    cin >> n;
    For(i, 0, n){
        int tmp;
        cin >> tmp;
        inputs.push_back(tmp);
    }
    int max = 0;
    For(i, 0, n){
        int l = i, r=i;
        int now = inputs[i];
        while(l>=0 && inputs[l]>=now) l--;
        while(r<n && inputs[r]>=now) r++;
        // cout << "l:" << l << "  r:" << r << endl;
        int windows = (r-l-1)>=now?now:max;
        max = windows>max?windows:max;
    }
    // cout << "max is:" << max << endl;
    system("pause");
    return 0;
}



