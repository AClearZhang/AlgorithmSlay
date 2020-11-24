/*
 * 
 * 　　┏┓　　　┏┓+ +
 * 　┏┛┻━━━┛┻┓ + +
 * 　┃　　　　　　　┃ 　
 * 　┃　　　━　　　┃ ++ + + +
 *  ████━████ ┃+
 * 　┃　　　　　　　┃ +
 * 　┃　　　┻　　　┃
 * 　┃　　　　　　　┃ + +
 * 　┗━┓　　　┏━┛
 * 　　　┃　　　┃　　　　　　　　　　　
 * 　　　┃　　　┃ + + + +
 * 　　　┃　　　┃
 * 　　　┃　　　┃ +  神兽保佑
 * 　　　┃　　　┃    代码无bug　　
 * 　　　┃　　　┃　　+　　　　　　　　　
 * 　　　┃　 　　┗━━━┓ + +
 * 　　　┃ 　　　　　　　┣┓
 * 　　　┃ 　　　　　　　┏┛
 * 　　　┗┓┓┏━┳┓┏┛ + + + +
 * 　　　　┃┫┫　┃┫┫
 * 　　　　┗┻┛　┗┻┛+ + + +
 * 
 */

/*
 * @FilePath            : \project\AlgorithmSlay\C++\18.FourSum.cpp
 * @Author              : AClearZhang
 * @Date                : 2020-11-20 21:54:51
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2020-11-24 23:23:03
 * @Version             : 1.0
 * @Description         : 此题为 kSum 总结题目中的一道.
给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

注意：
答案中不可以包含重复的四元组。

示例：
给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
满足要求的四元组集合为：
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/4sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <vector>
#include <windows.h>
#include <algorithm>

using namespace std;


// class Solution {
// public:
    
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//     /**
//      * @description: 注意 首先还是要防止重复
//      * @param {*}
//      * @return {*}
//      * @notes: 
//      */     
//     //法一： 继续用两层循环 + 双指针解决
//         // 首先边界和限定；然后排序；最后 进行循环查找，并注意 去除重复
//         vector<vector<int>> answer;
//         if(nums.empty() || nums.size() < 4)  return answer; 
//         sort(nums.begin(), nums.end());
//         for(int i=0; i<nums.size()-3 ;i++){
//             if(nums[i] > 0){ return answer; }
//             for( int j=i+1; j<nums.size()-2 ;j++ ){
//                 int head=j+1, tail = nums.size()-1;
//                 while(head<tail){
//                     int sum = nums[i] + nums[j] + nums[head] + nums[tail];
//                     if( sum == 0 ){
//                         answer.push_back(vector<int> {nums[i], nums[j], nums[head], nums[tail]});
//                         head++, tail--;
//                         while(head<tail && nums[head]==nums[head-1]) head++;
//                         while(head<tail && nums[tail]==nums[tail+1]) tail--;
//                     }else if(sum > 0){
//                         tail--;
//                     }else if(sum < 0){
//                         head++;
//                     }
//                 }
//             }
//         }
//         return answer;
//     }
// };

class Solution {
public:
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    /**
     * @description: 注意 首先还是要防止重复
     * @param {*}
     * @return {*}
     * @notes: 
     */     
    //法一： 继续用两层循环 + 双指针解决 
            // 以及附加 target
        // 首先边界和限定；然后排序；最后 进行循环查找，并注意 去除重复
        vector<vector<int>> answer;
        if(nums.empty() || nums.size() < 4)  return answer; 
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-3 ;i++){
            // if(nums[i] > target){ return answer; } //-11 No! 【错误！】
            //去除重复
            if(i>0 && nums[i] == nums[i-1]) continue;

            for( int j=i+1; j<nums.size()-2 ;j++ ){
                //去除重复
                if(j>i+1 && nums[j] == nums[j-1]) continue;
                int head=j+1, tail = nums.size()-1;
                
                while(head<tail){
                    int sum = nums[i] + nums[j] + nums[head] + nums[tail];
                    if( sum == target ){
                        answer.push_back(vector<int> {nums[i], nums[j], nums[head], nums[tail]});
                        head++, tail--;
                        while(head<tail && nums[head]==nums[head-1]) head++;
                        while(head<tail && nums[tail]==nums[tail+1]) tail--;
                    }else if(sum > target){
                        tail--;
                    }else if(sum < target){
                        head++;
                    }
                }
            }
        }
        return answer;
    }
};


int main(){

    Solution s;
    // vector<int> c = {-1, 0, 1, 2, -1, -4};
    // vector<int> c = {0,0,0,0};
    // vector<int> c = {34,55,79,28,46,33,2,48,31,-3,84,71,52,-3,93,15,21,-43,57,-6,86,56,94,74,83,-14,28,-66,46,-49,62,-11,43,65,77,12,47,61,26,1,13,29,55,-82,76,26,15,-29,36,-29,10,-70,69,17,49};
    // vector<int> c = {1, 0, -1, 0, -2, 2};
    vector<int> c = {1,-2,-5,-4,-3,3,3,5};
    vector<vector<int>> a = s.fourSum(c, -11);
    for (int i = 0; i < a.size(); i++)
    {
    for(int j = 0;j<4;j++){
        cout << a[i][j] << " ";
    }
    cout << endl;
    }
    printf("Hello World!\n");
    system("pause");
    return 0;
}



