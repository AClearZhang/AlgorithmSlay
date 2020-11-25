/*
 * @FilePath            : \AlgorithmSlay\C++\88.Merge Sorted Array.cpp
 * @Author              : AClearZhang
 * @Date                : 2020-11-25 15:12:28
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2020-11-25 16:21:38
 * @Version             : 1.0
 * @Description         : 归并两个有序数组 —— 双指针、数组系列
 * 
 * 给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。

说明：
初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。
你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
 

示例：
输入：
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3
输出：[1,2,2,3,5,6]
 
提示：
-10^9 <= nums1[i], nums2[i] <= 10^9
nums1.length == m + n
nums2.length == n

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <windows.h>
#include <algorithm>
#include <vector>

using namespace std;

// 迭代器 类似于 STL的指针 0
	// 4 ms	9.3 MB	C++
class Solution1 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>::iterator it1 = nums1.begin() + m;
        // vector<int>::iterator it2 = nums2.begin();
        for(auto a:nums2){
            *it1++ = a;
        }
        sort(nums1.begin(), nums1.end());
    }
};


// 指针1
// 执行用时：
// 0 ms
// , 在所有 C++ 提交中击败了
// 100.00%
// 的用户
// 内存消耗：
// 9.3 MB
// , 在所有 C++ 提交中击败了
// 10.52%
// 的用户
// 炫耀一下:
class Solution2 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        // // int* it1 = &(nums1+m); //error: no match for 'operator+' (operand types are 'std::vector<int>' and 'int')
        // vector<int>* it1 = &nums1+m; //error: no match for 'operator+' (operand types are 'std::vector<int>' and 'int') //因为 nums1 后面没有vector了 所以出错！
        // vector<int>* it1 = new vector<int>[5];  //新建5个vector 向量， it1[0].push_back()...
        

        int* it1 = &nums1[m];
        if (n == 0)   //【重点！】判断为空，防止为空引用。
        {
            return ;
        }
        
        int* it2 = &nums2[0];
        // vector<int>* it2 = &nums2;
        
        // cout << "I am in the function." << endl;
        // // for(int i=0;i<n;i++){
        // //     cout << *it1[i] << " ";
        // // }
        // // cout << endl;
        // for(auto num: *it2){
        //     cout << num << " ";
        // }
        // for(auto a:nums2){
        //     *it1 = a;
        //     it1++;
        // }// 不对因为  error: no match for 'operator=' (operand types are 'std::vector<int>' and 'int')！
        for(int i=0;i<n;i++){
            *it1++ = *it2++;
        }
        sort(nums1.begin(), nums1.end());
    }
};

// 指针2 —— 错误，这个类 用来得出 vector指针的经验.
class Solution3 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        // int* it1 = &(nums1+m); //error: no match for 'operator+' (operand types are 'std::vector<int>' and 'int')
        vector<int>* it1 = &nums1+m; //error: no match for 'operator+' (operand types are 'std::vector<int>' and 'int') //因为 nums1 后面没有vector了 所以出错！
        vector<int>* it11 = new vector<int>[5];  //新建5个vector 向量， it1[0].push_back()...
        

        // int* it1 = &nums1[m];
        // int* it2 = &nums2[0];
        vector<int>* it2 = &nums2;
        
        cout << "I am in the function." << endl;
        // for(int i=0;i<n;i++){
        //     cout << *it1[i] << " ";
        // }
        // cout << endl;
        for(auto num: *it2){
            cout << num << " ";
        }
        // for(auto a:nums2){
        //     *it1 = a;
        //     it1++;
        // }// 不对因为  error: no match for 'operator=' (operand types are 'std::vector<int>' and 'int')！
        sort(nums1.begin(), nums1.end());
    }
};

int main(){

    // vector<int> input1 = {1,2,3,0,0,0}, input2={2,5,6};
    // int m=3,n=3;
    vector<int> input1 = {1}, input2={};
    int m=1,n=0;
    Solution2 s;
    s.merge(input1,m, input2, n);
    cout << "now the input1 is: " << endl;
    for(auto num: input1){
        cout << num << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}



