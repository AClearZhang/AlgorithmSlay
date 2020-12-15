/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\STL\SortMethods.cpp
 * @Author              : AClearZhang
 * @Date                : 2020-12-10 22:37:11
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2020-12-14 22:02:16
 * @Version             : 1.0
 * @Description         : 实现各种经典的排序方法
 * 
 */

#include <algorithm>
#include <iostream>
#include <vector>
#include <windows.h>
#include <string>


using namespace std;

/**
 * @description: 
 * @param {*}
 * @return {*}
 * @notes: 注意：全部采用 左闭右闭的二分写法
 */
class SortMethods{
public:

    /**
     * @Description: 快速排序也属于 交换排序的一种
     * @Param: 
     * @Return: 
     * @Notes: 快速排序是对 冒泡排序的一种改进。
     */
    void QuickSort(vector<int> &nums, int left, int right){
        //快速排序
        if(left < right){
            int pivot = Partition(nums, left, right);
            QuickSort(nums, left, pivot-1);
            QuickSort(nums, pivot+1, right);
        }
    }
    int Partition(vector<int> &nums, int left, int right){
        // 划分先将大的放在low，然后将小的放在high
        // 枢轴值选择low
        int pivot = nums[left];
        while( left<right ){
            while(left<right && nums[right] >= pivot) right--; //【注意】 这里要 >= 下面要 <= 少了！！！
            nums[left] = nums[right];
            while(left<right && nums[left] <= pivot) left++;
            nums[right] = nums[left];
        }
        // 最终指针落在了 left上，为枢轴值 存放位置
        nums[left] = pivot;
        return left;
    }

    /**
     * @description: 
     * @param {*}
     * @return {*}
     * @notes:  这是冒大泡 —— 最经典的方法；下面还有进阶版。
     */
    void bubble_sort_general(vector<int> &nums, int n){ // 高到低排好序。
        int temp;
        for( int i = 0; i < n-1; i++ ){
            for( int j = 0; j < n-i-1 ; j++){ // 冒泡——小到大位置  找最大泡泡
                if(nums[j] > nums[j+1]){
                    temp = nums[j+1];
                    nums[j+1] = nums[j];
                    nums[j] = temp;
                }
            }
        }

    }
    /**
     * @Description: 
     * @Param: 
     * @Return: 
     * @Notes: 
     */
    void bubble_sort_pro(vector<int> &nums, int n){ // 冒泡排序进阶版
        bool swapped;
        for( int i = 0; i < n-1; i++ ){
            swapped = false;
            for( int j = 0; j < n-i-1 ; j++ ){
                if(nums[j] > nums[j+1]){
                    swap(nums[j], nums[j+1]);
                    swapped = true;
                }
            }
            if(!swapped){ // 如果后续已经排好序了，就退出就好了。【加速一些了】
                break;
            }
        }
    }
// -------------------------
    /**
     * @description: 找到最小的值并与其交换，从低到高位置交换
     * @param {*}
     * @return {*}
     * @notes: 选择排序
     */
    void selection_sort(vector<int> &nums, int n){ // 找到最小的值并与其交换，从低到高位置交换
        int minAddr;
        for(int i = 0; i < n-1;i++){
            minAddr = i;
            for(int j = i+1;j<n;j++){
                if(nums[j] < nums[minAddr]){
                    minAddr = j;
                }
            }
            swap(nums[i], nums[minAddr]);
        }
    }

// -------------------
    /**
     * @Description: 开始插入排序
     * @Param: 
     * @Return: 
     * @Notes: 
     */
    void insertion_sort(vector<int> &nums, int n){ // 一般的插入排序，从低到高 排好序。
        for(int i = 0; i < n ;i++){
            for( int j = i; j > 0 && nums[j] < nums[j-1] ;j-- ){ // 内部从后往前插入
                swap(nums[j], nums[j-1]);
            }
        }
    }
    
    /**
     * @Description: 希尔排序——搜小增量排序
     * @Param: 
     * @Return: 
     * @Notes: 最nb的是 结合直接排序进行思考。
     */
    void ShellSort(vector<int> &nums, int n){
        // 相比于直接排序，shell 数组增量从dk = n/2开始；然后 主键除以二向下取整——d_i+1 = floor(d_i/2)
        // 【重点】逻辑上注意：dk为数组个数==数组增量； 同时每个小数组内有n/dk 个元素。
        int dk; // 对应的初始化 增量；
        for( dk=n/2; dk>=1 ; dk = dk/2){//即：一直 缩小增量dk 进行排序。为了得到增序序列。
            //再在每个 dk小组中进行插入排序
            for(int i = dk; i<n ; i++ ){// 1、当前步长dk个数组的驱动，驱动去每个dk大数组；  2、———再进一层 for是每个小数组里面 n/dk个元素排序。
                for( int j = i; (j-dk)>=0 && nums[j] < nums[j-dk] ; j-=dk){  // 注意：关键是这个地方的 `(j-dk)>=0 && `  不能越界的基础上，还要判断是否要进行交换。
                    swap(nums[j], nums[j-dk]);
                }
            
            }
        }

    }

// -------
    /**
     * @Description: 归并排序实现
     * @Param: 
     * @Return: 
     * @Notes: 
     */
    void merge_sort(vector<int> &nums, int l,int r,vector<int> &temp){ //左闭右开
        if(l+1>=r){
            return ;
        }
        //divide
        int m = l + (r-l)/2;
        merge_sort(nums,l,m,temp);
        merge_sort(nums,m,r,temp);
        //conquer 
        int p = l, q = m, i = l;
        while(p<m || q<r){
            if(q>=r || (p < m && nums[p] <= nums[q])){
                temp[i++] = nums[p++];
            }else {
                temp[i++] = nums[q++];
            }
        }
        for(i = l; i < r; ++i){
            nums[i] = temp[i];
        }
    }
    // 二路-归并排序———【关键是将以有序的左右两端直接 归并Merge()方法】【分治 —— 直接用递归】
    // 左闭右闭
    void mergeSortInWD(vector<int> &nums, int left, int right, vector<int> &temp){
        if(left < right){
            int mid = left + (right-left)/2;
            mergeSortInWD(nums, left, mid, temp);
            mergeSortInWD(nums, mid+1, right, temp);
            // conquer 归并开始
            // merge(nums, left,mid,right);
            int i,j,k;
            // vector<int> temp = nums;
            for( i=left,j=mid+1,k=i; i<=mid && j <= right ;k++){
                if(nums[i] <= nums[j]){
                    temp[k]  = nums[i++];
                }else{
                    temp[k] = nums[j++];
                }
            }
            // 剩下的直接复制到nums数组中
            while(i<=mid) temp[k++] = nums[i++];
            while(j<=right) temp[k++] = nums[j++];
            // 将nums稳定不变的;temp是交换件
            // 因为return 只是中间的几个，所以原样子赋值给nums，不改变nums
            for(i = j=left;j<=k;i++, j++){
                nums[i] = temp[j];
            }

            // int k = 0;
            // int i = left;
            // int j = mid + 1;
            // while (i <= mid && j <= right) {   【上方可换为这个】
            //     if (nums[i] < nums[j]){
            //         temp[k++] = nums[i++];
            //     }
            //     else{
            //         temp[k++] = nums[j++];
            //     }
            // }
            // if (i == mid + 1) {
            //     while(j <= right)
            //         temp[k++] = nums[j++];
            // }
            // if (j == right + 1) {
            //     while (i <= mid)
            //         temp[k++] = nums[i++];
            // }
            // for (j = 0, i = left ; j < k; i++, j++) {
            //     nums[i] = temp[j];
            // }

        }

    }
    // void merge(vector<int> nums, int left, int mid, int right){
    //     //k 控制A中； i j 控制temp中小的放入nums中
    //     int i,j,k;
    //     vector<int> temp = nums;
    //     for( i=left,j=mid+1,k=i; i<=mid && j <= right ;k++){
    //         if(nums[i] <= nums[j]){
    //             temp[k]  = nums[i++];
    //         }else{
    //             temp[k] = nums[j++];
    //         }
    //     }
    //     // 剩下的直接复制到nums数组中
    //     while(i<=mid) temp[k++] = nums[i++];
    //     while(j<=right) temp[k++] = nums[j++];
    //     // 将nums稳定不变的;temp是交换件
    //     // 因为return 只是中间的几个，所以原样子赋值给nums，不改变nums
    //     for(i = j=left;j<=k;i++, j++){
    //         nums[i] = temp[j];
    //     }
    // }

};


int main(){
    vector<int> arr = {8,9,1,7,2,3,5,4,6,0};
    // vector<int> arr = {2,0};
    int n = 10;
    SortMethods sortMethods;
    // sortMethods.ShellSort(arr, n);
    vector<int> temp={8,9,1,7,2,3,5,4,6,0};
    // sortMethods.merge_sort(arr,0, n, temp); //成功归并算法.  左闭右开
    sortMethods.mergeSortInWD(arr,0, n-1, temp); //成功归并算法.  左闭右闭
    // sortMethods.mergeSortInWD1(arr,0, n-1); //成功归并算法.  左闭右闭
    cout << "当前数值的排序为：";
    for(auto a: arr){
        cout << a << "  ";
    }
    cout << "结束" << endl;
    system("pause");
    return 0;
}

