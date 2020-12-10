/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\1011.CapacityToShipPackInDDays.cpp
 * @Author              : AClearZhang
 * @Date                : 2020-12-10 11:19:13
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2020-12-10 20:49:15
 * @Version             : 1.0
 * @Description         : 在D天内送达包裹的能力
 * 
 * 传送带上的包裹必须在 D 天内从一个港口运送到另一个港口。

传送带上的第 i 个包裹的重量为 weights[i]。每一天，我们都会按给出重量的顺序往传送带上装载包裹。我们装载的重量不会超过船的最大运载重量。

返回能在 D 天内将传送带上的所有包裹送达的船的最低运载能力。

 

示例 1：

输入：weights = [1,2,3,4,5,6,7,8,9,10], D = 5
输出：15
解释：
船舶最低载重 15 就能够在 5 天内送达所有包裹，如下所示：
第 1 天：1, 2, 3, 4, 5
第 2 天：6, 7
第 3 天：8
第 4 天：9
第 5 天：10

请注意，货物必须按照给定的顺序装运，因此使用载重能力为 14 的船舶并将包装分成 (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) 是不允许的。 
示例 2：

输入：weights = [3,2,2,4,1,4], D = 3
输出：6
解释：
船舶最低载重 6 就能够在 3 天内送达所有包裹，如下所示：
第 1 天：3, 2
第 2 天：2, 4
第 3 天：1, 4
示例 3：

输入：weights = [1,2,3,1,1], D = 4
输出：3
解释：
第 1 天：1
第 2 天：2
第 3 天：3
第 4 天：1, 1
 

提示：

1 <= D <= weights.length <= 50000
1 <= weights[i] <= 500

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/capacity-to-ship-packages-within-d-days
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <windows.h>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    /**
     * @description: 1、首先寻找所有货物重量 2、查找当前mid载重的天数 3、二分查找，找最低载重——即左侧界
     * @param {*}
     * @return {*}
     * @notes: 注意：最低包裹限制要  大于等于最小的包裹。
     */
    int shipWithinDays(vector<int>& weights, int D) {
        auto pair = findMaxMinBoatWeight(weights);
        int n = pair.first, max = pair.second;
        if(n==0) return 1;
        int left = max,right = n;
        cout << "max:" << max << ",n:" << n << endl;
        while(left<=right){
            int mid = left + (right - left)/2;
            int days = canDaysInboat(weights, mid);
            if(days <= D){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        if(left >= n+1 || canDaysInboat(weights,left)>D) return -1;
        return left;
    }
    int canDaysInboat(vector<int> weights, int boat){
        int sum = 0, days=1;
        for(auto w : weights){
            sum += w;
            if(sum>boat){
                days+=1;
                sum = w;
            }
        }
        return days;

    }
    pair<int,int> findMaxMinBoatWeight(vector<int> weights){
        int sum = 0,max = 0;
        for(auto w : weights){
            sum+=w;
            max = w > max ? w : max ;
        }
        pair<int,int> res = {sum, max};
        return res;
    }
};


int main(){

    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    // vector<int> arr = {3,2,2,4,1,4};
    // vector<int> arr = {1,2,3,1,1};
    int D = 5;
    // int D = 3; 
    Solution so;
    int ans = so.shipWithinDays(arr, D);
    cout << "船只的最低载重量为：" << ans << endl;

    system("pause");
    return 0;
}
