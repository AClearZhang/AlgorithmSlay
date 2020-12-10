/*
 * 
 *    ┏┓　　　┏┓
 *  ┏┛┻━━━┛┻┓
 *  ┃　　　　　　　┃
 *  ┃　　　━　　　┃
 *  ┃　＞　　　＜　┃
 *  ┃　　　　　　　┃
 *  ┃...　⌒　...　┃
 *  ┃　　　　　　　┃
 *  ┗━┓　　　┏━┛
 *      ┃　　　┃　
 *      ┃　　　┃
 *      ┃　　　┃
 *      ┃　　　┃  神兽保佑
 *      ┃　　　┃  代码无bug　　
 *      ┃　　　┃
 *      ┃　　　┗━━━┓
 *      ┃　　　　　　　┣┓
 *      ┃　　　　　　　┏┛
 *      ┗┓┓┏━┳┓┏┛
 *        ┃┫┫　┃┫┫
 *        ┗┻┛　┗┻┛
 */

/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\81.SearchInRotatedSortedArray-ii.cpp
 * @Author              : AClearZhang
 * @Date                : 2020-12-03 10:47:32
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2020-12-10 10:24:33
 * @Version             : 1.0
 * @Description         : 搜索旋转排序数组II
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,0,1,2,2,5,6] 可能变为 [2,5,6,0,0,1,2] )。

编写一个函数来判断给定的目标值是否存在于数组中。若存在返回 true，否则返回 false。

示例 1:

输入: nums = [2,5,6,0,0,1,2], target = 0
输出: true
示例 2:

输入: nums = [2,5,6,0,0,1,2], target = 3
输出: false
进阶:

这是 搜索旋转排序数组 的延伸题目，本题中的 nums  可能包含重复元素。
这会影响到程序的时间复杂度吗？会有怎样的影响，为什么？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <cmath>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <windows.h>

using namespace std;


// 思路：本题虽然有循环，但是内部也还是有递增的序列； 
// 仍然可以找到一边的 递增序列；进行log(n)的二分查找。
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==0) return false;
        // int split;
        int left=0, right = n;
        //外部寻找 有序数组
        while(left < right){
            int mid = left + (right-left)/2;
            if(nums[mid] == target) return true;  // 错了拿出来
            
             // 少边界！！！ 相等时候，
            if( nums[mid] == nums[right-1] ) right -= 1;
            // 内部在有序内 真正的二分查找
            else if( nums[mid] < nums[right-1] ){
                // 说明右边是排好序的
                // if(target < nums[mid]){
                //     right = mid;
                // }else{
                //     right-=1;
                // }
                if(target >= nums[mid] && target <= nums[right-1]){
                    // 做靠谱的事情， 剩下未知的交给 else
                    // right = mid;
                    left = mid + 1;

                }else{// 不在右边
                    // right-=1;
                    right = mid;
                }

                //--- 下面的太慢了
                // // auto a = this->binarySearch(nums.begin(), target);
                // int low = mid+1, high = right;
                // while( low < high){
                //     int midRight = low+ (high-low)/2;
                //     if(nums[midRight] == target){
                //         return true;
                //     }else if(nums[midRight] < target){
                //         low = midRight+1;
                //     }else high = midRight;
                // }
                // // 跳出来就是未找到.
                // right = mid;
            }else{ // (nums[mid] > nums[left]) 错误！
                // 左边排好序  左边二分查找
                if(target>=nums[left] && target <= nums[mid-1]){  // 错了  ——  23 4|512   找1就不行！
                    // left = mid + 1;
                    right = mid;
                }else{
                    left= mid + 1;
                }


                //-----下面的太慢了！
                // int low = left, high = mid;
                // while( low < high){
                //     int midLeft = low+ (high-low)/2;
                //     if(nums[midLeft] == target){
                //         return true;
                //     }else if(nums[midLeft] < target){
                //         low = midLeft+1;
                //     }else high = midLeft;
                // }
                // // 说明左边未找到
                // left = mid + 1;
            }
           
        }
        // 循环结束，二分查找 还是没能找到，返回false
        return false;
    }

    // int binarySearch(vector<int> &nums, int target){
    //     int n = nums.size();
    //     if (n == 0) return -1;
    //     int left = 0;
    //     int right = n ;
    //     // 查找所以等于
    //     while (left < right)
    //     {
    //         int mid = left + (right - left)/2;
    //         if (nums[mid] == target)
    //         {
    //             return mid;
    //         }
    //         else if (nums[mid] > target)
    //         {
    //             right = mid;
    //         }
    //         else if (nums[mid] < target)
    //         {
    //             left = mid + 1;
    //         }
    //     }
    //     return -1; // 表示未查找到。
    // }
};


int main(){
    // vector<int> arr = {2,5,6,0,0,1,2};
    // vector<int> arr = {1,1,1,3,1};
    // vector<int> arr = {1};
    // vector<int> arr = {1,1,3};
    // vector<int> arr = {3,5,1};
    vector<int> arr = {2,2,2,0,1};

    int target = 0;
    // int target = 1;
    Solution so;
    bool answer = so.search(arr,target);
    cout<<"answer is : "<< answer << endl;

    system("pause");
    return 0;
}
