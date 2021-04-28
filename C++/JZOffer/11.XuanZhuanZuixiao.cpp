/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\JZOffer\11.XuanZhuanZuixiao.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-04-28 23:44:48
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-04-29 00:03:45
 * @Version             : 1.0
 * @Description         : 旋转数组最小数字
 */
#include <algorithm>
#include <cmath>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <set>
#include <deque>  
#include <list>

using namespace std;




class Solution {
public:
    int minArray(vector<int>& numbers) {
        int n = numbers.size();
        int left = 0, right = n-1;
        // if(n==0)  return None;
        if(n==1)  return numbers[left];
        while(left<right){
            int mid = left + (right-left)/2;
            if(numbers[mid]< numbers[right]){
                right = mid;
            }else if(numbers[mid]> numbers[right]){
                left = mid + 1;
            }else{
                right -= 1;
            }
        }
        return numbers[left];
    }
};
