/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\Basics\BinarySearch.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-03-27 12:01:45
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-03-27 12:08:16
 * @Version             : 1.0
 * @Description         : 二分搜索
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
#include <vector>

using namespace std;


int right_bound(vector<int> nums, int target){
    if(nums.size() == 0)  return -1;
    int left = 0, right = nums.size();
    
    while(left<right){
        int mid = (right-left)/2 + left;
        if(nums[mid] == target) {
            left = mid+1;
        }else if(nums[mid] < target){
            left = mid+1;
        }else if(nums[mid] > target){
            right = mid;
        }
    }
    if(left == 0) return -1;
    return nums[left-1] == target ?left-1:-1;
}

int main(){
    vector<int> test = {1,2,2,4};
    int res = right_bound(test, 13);
    cout << "The result is:" << res << endl;
    system("pause");
    return 0;
}