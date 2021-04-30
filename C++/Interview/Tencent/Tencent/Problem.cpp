/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\Tencent\Problem.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-04-30 15:01:29
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-04-30 15:16:02
 * @Version             : 1.0
 * @Description         : 
 */
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

#define For(x, y, z) for (int x = y; x < z; ++x)
typedef long long ll;



int partition(vector<int>& nums, int left, int right ){
    int i = left+1;
    int j = right;
    int tmp = nums[left];
    while (i<=j)
    {
        while(nums[i] < tmp) i++;
        while(nums[j] > tmp) j--;
        if(i<j){
            swap(nums[i++], nums[j--]);
        }else{
            i++;
        }
    }
    swap(nums[j], nums[left]);
    return j;
}
void quickSort(vector<int>& nums, int left, int right){
    if(left < right){
        int j = partition(nums, left, right);
        quickSort(nums, left, j-1);
        quickSort(nums, j+1, right);
    }
}


int main(){
    vector<int> nums{2,5,6,1,8,9};
    quickSort(nums, 0, nums.size()-1);
    for(int a:nums){
        cout << a << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}



