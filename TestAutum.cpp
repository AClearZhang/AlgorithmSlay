/*
 * @FilePath            : \project\AlgorithmSlay\TestAutum.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-09-13 11:45:51
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-09-18 17:49:11
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

vector<string> split(string inputs, char del)
{
    stringstream strStream(inputs);
    vector<string> res;
    string tmp;

    while (getline(strStream, tmp, del))
    {
        res.push_back(tmp);
    }
    return res;
}

/**
     * @Description: 先分割；再倒序输出.
     * @param {string} s
     * @return {*}
     * @notes: 
     */
string reverseWords(string s)
{
    vector<string> strSplit;
    strSplit = split(s, ' ');
    string res;
    // 倒序输出并添加空格
    vector<string>::reverse_iterator rit;
    for (rit = strSplit.rbegin(); rit != strSplit.rend() - 1; rit++)
    {
        if (*rit != " ")
        {
            res += *rit;
            res.push_back(' ');
        }
    }
    if (*rit != " ")
    {
        res += *rit;
    }
    else
    { //说明前面最后一个 加了" "
        res.erase(res.size() - 1);
    }
    return res;
}
/**
     * @Description: 设置 去除单词前后额空格
     * @param {*}
     * @return {*}
     * @notes: 
     */
void trim(string &s)
    {
        if (s.size() == 0)
            return;

        while (!s.empty() && s[0] == ' ')
            s.erase(0, 1);
        while (!s.empty() && s[s.size() - 1] == ' ')
            s.erase(s.size() - 1, 1);
        return; // 注意直接在string上做， 有可能全部去除了。
    }
/**
     * @Description: 先分割；再倒序输出. 添加去除 多余空格
     * @param {string} s
     * @return {*}
     * @notes: 
     */
string reverseWords2(string s)
{
    trim(s); // 左右去除空格.
    vector<string> strSplit;
    strSplit = split(s, ' ');
    string res;
    // 倒序输出并添加空格
    for (int i = strSplit.size() - 1; i > 0; i--)
    {
        string tmp = strSplit[i];
        trim(tmp);
        if (tmp != "" && tmp != " ")
        {
            res += tmp;
            res.push_back(' ');
        }
    }

    string tmp = strSplit.front();
    trim(tmp);
    if (tmp != "" && tmp != " ")
    {
        res += tmp;
    }
    else
    {
        res.erase(res.size() - 1);
    }
    return res;
}

string reverseWords3(string s)
{
    trim(s); // 左右去除空格.
    vector<string> strSplit;
    strSplit = split(s, ' ');
    string res;
    // 倒序输出并添加空格
    vector<string>::reverse_iterator rit;
    for (rit = strSplit.rbegin(); rit != strSplit.rend() - 1; rit++)
    {
        string tmp = *rit;
        trim(tmp);
        if (tmp != "" && tmp != " ")
        {
            res += tmp;
            res.push_back(' ');
        }
    }

    string tmp = *rit;
    trim(tmp);
    if (tmp != "" && tmp != " ")
    {
        res += tmp;
    }
    else
    {
        res.erase(res.size() - 1);
    }
    return res;
}

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
    for (auto i : myvector)
    {
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

    cout << "***********String Test" << endl;
    string testStr = "  Bob    Loves  Alice   ";
    vector<string> result;
    result = split(testStr, ' ');
    for (auto rel : result)
    {
        cout << rel << " ";
    }
    cout << endl;
    cout << "reverse words is:" << reverseWords(testStr) << endl;
    cout << "reverse words2 is:" << reverseWords2(testStr) << endl;
    cout << "reverse words3 is:" << reverseWords3(testStr) << endl;
    cout << testStr.size() << endl;

    system("pause");
    return 0;
}
