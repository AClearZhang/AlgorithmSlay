/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\TestExam.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-04-11 16:41:22
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-04-11 18:00:07
 * @Version             : 1.0
 * @Description         : 考试实验
 */

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include<unordered_set>
#define For(x,y,z) for (int x = y; x <= z; ++x)
typedef long long ll;

using namespace std;

bool cmp(int a, int b){
    return a<b;
}

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a;
    for(int i = 1;i<=n;i++){
        for(int j = 1; j<=m ;j++){
            a.push_back(i*j);
        }
    }
    sort(a.begin(), a.end(), cmp);
    cout << a[k-1];

    system("pause");
    return 0;
}

// class Test
// {

// public:
//     Test() { x = 1; }

//     void print() { cout << x << "  " << y << endl; }

// private:
//     int x;

//     static int y;
// };

// int Test::y = 0;
// int f(int *a, int n)

// {

// int x=*(a+3);

//   for(int *pa=a+1; pa<a+n;pa++)

//    if(*pa>x) x=*pa;

//  return x; 

// }
// int main()
// {

//     Test t;

//     t.print();
//     int x[10]={23,46,78,99,16,24,56,90,67,44};
//     int res = f(x, 5);
//     cout << "The res is:" << res << endl;
//     system("pause");
//     return 0;
// }

// using namespace std;

// void s(float x, int &i)

// {

//     i = int(x);
// }

// int main()

// {
//     int n;
//     float x;

//     cin >> x;

//     s(x, n);

//     cout << n << endl;
//     system("pause");
// }
