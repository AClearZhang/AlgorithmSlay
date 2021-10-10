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
    vector<int> split(string inputs, char del)
    {
        stringstream strStream(inputs);
        vector<int> res;
        string tmp;

        while (getline(strStream, tmp, del))
        {
            res.push_back(atoi(tmp.c_str()));
        }
        return res;
    }

    double findDistance(vector<double> zhiXin, vector<int> point){
        return sqrt(pow((point[0]-zhiXin[0]), 2) + pow((point[1] - zhiXin[1]), 2));
    }


    int get_index(vector<string> points)
    {
        vector<vector<int>> pointsReal;
        
        int xx = 0, yy = 0;
        for(string p : points){
            vector<int> res = split(p, ',');
            xx += res[0];
            yy += res[1];
            pointsReal.push_back(res);
        }
        int num = pointsReal.size();
        vector<double> zhiXin = { float(xx)/num, float(yy)/num };
        
        int resLocate = 0;
        double minDistance = INT_MAX;
        for(int i = 0 ; i < num ;i++ ){
            double distance = findDistance(zhiXin, pointsReal[i]);
            if( distance < minDistance ){
                minDistance = distance;
                resLocate = i;
            }
        }
        return resLocate;
    }
};


int main(int argc, char const *argv[])
{
    Solution s;
    vector<string> points = {"1,1", "2,2", "1,2", "1,3"};
    cout <<  s.get_index(points) << endl;

    system("pause");
    return 0;
}
