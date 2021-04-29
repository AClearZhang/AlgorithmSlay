/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\Interview\360\SortArr.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-04-29 09:46:20
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-04-29 14:04:39
 * @Version             : 1.0
 * @Description         : 0 1 2 三者进行排序
 */

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

#define For(x, y, z) for (int x = y; x < z; ++x)
typedef long long ll;

/**
 * @Description: 关键是 while()很是陷阱——容易陷入循环，且 容易过去。要有很多限制条件。
 * @param {vector<int>} &arr
 * @return {*}
 * @notes: 
 */
void sortArr(vector<int> &arr)
{
    int n = arr.size();
    int p0 = 0, p1 = 0, p2 = n - 1;
    while (arr[p0] == 0 && p0 < n)
    {
        p0++;
    }
    while (arr[p2] == 2 && p2 > 0)
    {
        p2--;
    }
    p1 = p0;
    while (p1 <= p2)
    {

        if (arr[p1] == 2)
        {
            swap(arr[p1], arr[p2]);
            while (arr[p2] == 2 && p2 >= 0)
            {
                p2--;
            }
        }else if(arr[p1] == 0){
            swap(arr[p1], arr[p0]);
            while (arr[p0] == 0 && p0 < n)
            {
                p0++;
            }
        }

        if(p1<p0){
            p1 = p0;
        }
        while(arr[p1]==1 && p1<=p2){
            p1++;
        }
        // cout << p0 << " " << p1 << " " << p2 << endl;
    }
}

int main()
{
    vector<int> arr{2,0,1,2,0,1,0};
    sortArr(arr);
    for(auto a:arr){
        cout << a << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}
