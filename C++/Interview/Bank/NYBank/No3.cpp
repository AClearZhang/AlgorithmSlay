/*
 * @FilePath            : \project\AlgorithmSlay\C++\Interview\Bank\NYBank\No3.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-09-27 16:33:56
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-09-27 16:51:04
 * @Version             : 1.0
 * @Description         : 
 */
/*
 * @FilePath            : \project\AlgorithmSlay\C++\Interview\Bank\NYBank\No2.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-09-27 15:40:56
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-09-27 16:09:36
 * @Version             : 1.0
 * @Description         : 
 */

/*
 * @FilePath            : \project\AlgorithmSlay\C++\JZOffer\20.ShuZhiString.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-09-18 17:24:46
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-09-18 17:47:51
 * @Version             : 1.0
 * @Description         : 表示数值的字符串。。。状态机、、用例模拟编程。
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
#include <iomanip>

using namespace std;

#define For(x, y, z) for (ll x = y; x < z; ++x)
typedef long long ll;

/**
 * @Description: 一看AC通过了20就知道这事儿不简单，说一下我的解法！

写两个子函数，一个是判断是否为整数，一个判断是否为浮点数

对原字符串预处理，去掉首尾的空格

一次扫描看一下是否含有'e'或'E

如果有的话，直接返回(左半段是整数||左半段是小数)&&右半段是整数

如果没有的话，直接返回(s是小数||s是整数)
 * @param {*}
 * @return {*}
 * @notes: 
 */

class Solution
{
public:
    float compute_Entropy(string content){
        int num = content.size()-1;
        cout << "the num is" << num << endl;
        unordered_map<char, int> map;
        for( int i = 0; i < num ;i++ ){
            map[content[i]] ++;
        }
        vector<pair<char, int>> mapVec(map.begin(), map.end());
        float sum = 0.0;
        for(pair<char, int> v : mapVec){
            sum += float(v.second)/num * log2f(float(v.second)/num);
        }
        stringstream tmp;
        tmp << setprecision(2) << -sum;
        tmp >> sum;
        return sum;
    }
};


int main(int argc, char const *argv[])
{
    Solution s;
    string content = "AABB";
    cout << s.compute_Entropy(content) << endl;

    system("pause");
    return 0;
}
