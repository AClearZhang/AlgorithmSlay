/*
 * @FilePath            : \project\AlgorithmSlay\C++\Test1.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-04-25 10:28:29
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-04-25 10:32:44
 * @Version             : 1.0
 * @Description         : 
 */



#include <iostream>
#include <vector>
#include <windows.h>
#include <algorithm>
using namespace std;
int main()
{
    int num;
    cin >> num;
 
    vector<int> nums;
    int temp;
    for (int i = 0; i < num; ++i)
    {
        cin >> temp;
        nums.push_back(temp);
    }
 
    for (vector<int>::iterator itr = nums.begin(); itr != nums.end(); ++itr)
    {
        cout << *itr << endl;
    }
    int res = 0, i = 0, j=nums.size()-1;
    sort(nums.begin(), nums.end());
    while(i<j){
        res += nums[j--] - nums[i++];
    }
    cout << res << endl;
    system("pause");
    return 0;
}