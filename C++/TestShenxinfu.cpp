/*
 * @FilePath            : \AlgorithmInterview\AlgorithmSlay\C++\TestShenxinfu.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-10-09 19:48:24
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-10-09 20:29:35
 * @Version             : 1.0
 * @Description         : 加密和解密
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


#define For(x,y,z) for(ll x = y; x < z;++x)
typedef long long ll;

string dec(string str, int up_char_offset, int low_char_offset){
    string res;
    for( char ch : str ){
        // 大写
        if(ch>='A' && ch <= 'Z'){
            res.push_back( (char)(  (ch - 'A' + up_char_offset + 26) % 26 + 65)  );
        }else if (ch >= 'a' && ch <= 'z')
        {
            res.push_back( (char)( (ch - 'a' + low_char_offset + 26) % 26 + 97) );
        }else{
            res.push_back(ch);
        }
        
    }
    cout << res << endl;
    return res;

}


int main(int argc, char const *argv[])
{
    cout << dec("Def Z", -1, 1) << endl;
    system("pause");
    return 0;
}

