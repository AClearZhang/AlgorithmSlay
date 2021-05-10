/*
 * @FilePath            : \project\AlgorithmSlay\C++\Interview\Xiaomi\No2.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-04-29 20:06:34
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-05-10 10:39:49
 * @Version             : 1.0
 * @Description         : 
 */

// #include<iostream>
// #include<list>
// #include <windows.h>
// using namespace std;
 
// list<int> list1;
// int total=0;
// void find(int sum, int n)
// {
//     //递归出口
//     if(sum <= 0 || n <= 0)
//         return;
 
//     //输出找到的结果
//     if(sum == n)    //表示找到了一个
//     {
//         // list1.reverse();    //使输出顺序更规范
//         cout << n ;
//         for(auto i = list1.rbegin(); i != list1.rend(); i--)
//             cout << " "<< *i;
//         cout <<  endl;
//         total++;
//         // list1.reverse();
//     }
 
//     list1.push_front(n);
//     find(sum-n, n-1);    //如果放入n，则从剩余n-1个数中填满sum-n
//     list1.pop_front();
//     find(sum, n-1);        //如果不放入n，从n-1个数中填满sum
// }
 
// int main()
// {
//     // int sum, n;
//     // cout<<"Please Input n&sum:"<<endl;
//     // cin>>n>>sum;
//     // find(sum, n);
//     // cout<<"Total:"<<total<<endl;
//     string str;
//     char ch;
//     cin >> str;
//     cin >> ch;
//     string::iterator it;
//     for (it = str.begin(); it < str.end(); it++)
//     {
//         if (*it == ch)
//         {
//             str.erase(it);
//             it--;
//             /*
//             it--很重要，因为使用erase()删除it指向的字符后，后面的字符就移了过来，
//             it指向的位置就被后一个字符填充了，而for语句最后的it++，又使it向后移
//             了一个位置，所以就忽略掉了填充过来的这个字符。在这加上it--后就和for
//             语句的it++抵消了，使迭代器能够访问所有的字符。
//             */
//         }
//     }
//     cout << str;
//     system("pause");
//     return 0;
// }


#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <windows.h>

using namespace std;

typedef long long ll;
#define For(x,y,z) for(ll x=y;x<z;x++)


int main(){
    unordered_map<char, int>   mapBad;
    string badKeyboard;
    string inputs;
    cin >> badKeyboard; 
    cin >> inputs;
    For(i, 0, badKeyboard.size()){
        mapBad[badKeyboard[i]]++;
    }
    for(auto it=inputs.begin(); it<inputs.end();it++){
     
        // UP Words
        if(*it>='A'&&*it<='Z' && mapBad.count('+')>0){
            inputs.erase(it);
            it--;
        }else if(mapBad.count(*it)>0 || mapBad.count(toupper(*it))>0){// exist
            inputs.erase(it);
            it--;
        }
        cout << *it << " ";
    }
    cout << endl;
    cout << inputs;
    system("pause");
    return 0;
}
