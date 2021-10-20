/*
 * @FilePath            : \AlgorithmInterview\AlgorithmSlay\C++\Interview\Baidu\qiuzhao\No2.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-10-18 21:24:39
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-10-20 17:07:02
 * @Version             : 1.0
 * @Description         : 百度第二道题
 *
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
#include <map>
#include <vector>

using namespace std;



#define For(x,y,z) for(int x = y; x < z;++x)
typedef long long ll;


int main(){
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    unordered_map<int, list<int> > mapNum; // 映射找到3个count；对应 所引出位置  key:num value:point
    for( int i = 0; i<n ;i++  ){
        cin >> arr[i];
        if( mapNum.find(arr[i]) != mapNum.end() ){
            // 如果存在这个数，list 继续push
            mapNum[arr[i]].push_back(i);
        }else{
            // 不存在则 新建添加
            
            mapNum[arr[i]].push_back(i); // 已经新建了。
        }
    }
    int l = 0, r = arr.size()-1, m = 0;
    int res = -1;
    // 分析：左右滑动，左边最大 能到多高h；右边最大 能到多low；中间在这个 low high范围内寻找是否为最小值
    for( auto pairItem : mapNum ){
        if( pairItem.second.size() >= 3 ){// 三个以上才可能存在当前的结果
            int now = pairItem.first;
            l = pairItem.second.front();
            r = pairItem.second.back();
            int low = 0, high = arr.size() - 1;
            while ( low < r && arr[low++] <= arr[l] )
            {
                // low ++;
            }
            while ( l < high &&  arr[high--] <= arr[r] )
            {
                // high --;
            }
            // 提前结束的情况
            if( low < l || high > r ){
                continue;
            }
            // 最终验证 中间的范围内[low, high]
            if( low >= high ){
                // 超越了 说明 中间就一个就是最小的
                res = now;
            }
                // 其它情况看 [low, high] 范围内now 是否为最小的
            while( low <= high &&  arr[low] >= now && arr[high] >= now){
                low++;
                high--;
            }
        }
    }
    cout << res << endl;
    system("pause");
    return 0;
}


