/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\Baidu.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-04-11 20:20:23
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-04-12 10:55:51
 * @Version             : 1.0
 * @Description         : 百度编程笔试题目2
 */
#include <iostream>
#include <windows.h>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;


/**
 * @Description: 交换前k个元素
 * @param {string} &a
 * @param {string} &b
 * @param {int} k
 * @param {unordered_map<string, int>} &ans_str
 * @return {*}
 * @notes: 
 */
bool swap_str(string &a, string &b, int k, unordered_map<string, int> &ans_str){
    string tmp1 = a,tmp2 = b;
    tmp1 = tmp1.replace(tmp1.begin(),tmp1.begin()+k, tmp2.begin(),tmp2.begin()+k );
    tmp2 = tmp2.replace(tmp2.begin(),tmp2.begin()+k, a.begin(),a.begin()+k );
    if(ans_str.count(tmp1) && ans_str.count(tmp2)){
        return false; // 有了
    }else{
        a = tmp1;
        b = tmp2;
        ans_str[tmp1]++;
        ans_str[tmp2]++;
    }
    return true; // 交换成功

}

int main(){
    unordered_map<string, int> ans_str;
    int m, n;
    vector<string> inputs;
    while(cin >> n >> m){
        for(int i = 0;i<n;i++){
            string tmp;
            cin >> tmp;
            inputs.push_back(tmp);
        }
        // 输入完成
        
        for(int i = 0;i<=n-2;i++){
            for(int j=i+1;j<=n-1;j++){
                for(int k = m-1;k>0;k--){
                    if(!swap_str(inputs[i], inputs[j], k, ans_str)){
                        break;
                    }
                    if( k == 1){
                        k = m;
                    }
                }

            }
        }
        
        cout << "最终有：" << ans_str.size() << "个不同子串"<<endl;
    }
    system("pause");
    return 0;
}