/*
 * @FilePath            : \AlgorithmInterview\AlgorithmSlay\C++\TestAutum.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-09-13 11:45:51
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-09-14 22:02:36
 * @Version             : 1.0
 * @Description         : 秋天。
 */
#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

#define For(x, y, z) for (ll x = y; x < z; ++x)
typedef long long ll;

int main()
{
    cout << "***********测试 list 剪切API." << endl;
    list<int> testList1{1, 2, 4};
    list<int> testList2(4, 12);
    list<int> testList3(testList1.begin(), testList1.end());
    int a[] = {3, 5, 7, 9};
    vector<int> testVec1(a, a + (sizeof(a) / sizeof(a[0])));
    vector<int> testVec2{6, 8, 9, 10};
    for (list<int>::iterator it = testList2.begin(); it != testList2.end(); it++)
    {
        cout << "now list is :" << *it << endl;
    }
    for (auto item : testList1)
    {
        cout << item << endl;
    }
    // testVec1.insert(testVec1.begin(), testVec2.begin(), testVec2.end());

    testList1.splice(testList1.begin(), testList2, testList2.begin(), testList2.end()); // 用下面的
    // testList1.splice(next(testList1.begin(), 2), testList2, testList2.begin(), testList2.end());
    cout << "After list1 splice list2:" << endl;
    for (auto item : testList1)
    {
        cout << item << " ";
    }
    cout << endl;
    // 测试 insert
    std::vector<int> myvector(3, 100);
    std::vector<int>::iterator it;

    it = myvector.begin();
    it = myvector.insert(it, 200);

    myvector.insert(it, 2, 300);
    cout << "reset myvector before:" << endl;
    for(auto i : myvector){
        cout << i << endl;
    }
    
    // "it" no longer valid, get a new one:
    it = myvector.begin();

    std::vector<int> anothervector(2, 400);
    myvector.insert(it + 2, anothervector.begin(), anothervector.end());

    int myarray[] = {501, 502, 503};
    myvector.insert(myvector.begin(), myarray, myarray + 3);

    std::cout << "myvector contains:";
    for (it = myvector.begin(); it < myvector.end(); it++)
        std::cout << ' ' << *it;
    std::cout << '\n';

    system("pause");
    return 0;
}
