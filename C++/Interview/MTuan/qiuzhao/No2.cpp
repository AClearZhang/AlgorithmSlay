/*
 * @FilePath            : \AlgorithmInterview\AlgorithmSlay\C++\Interview\MTuan\qiuzhao\No2.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-04-18 10:55:23
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-10-17 15:12:27
 * @Version             : 1.0
 * @Description         : 美团第二道题
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

// 回溯思想 从字典序小的往大的开始找
void backTrack( vector<int>& nums, vector<int>& track, set<int>& visited, vector<vector<int>>& res ){
    if( track.size() == nums.size() ){
        res.push_back(track);
    }

    for( int i = 0; i < nums.size() ;i++ ){
        if( visited.count(nums[i]) || (track.size()+1) == nums[i]){
            continue;
        }
        
        visited.insert(nums[i]);
        track.push_back(nums[i]);
        backTrack(nums, track, visited, res);
        track.pop_back();
        visited.erase(nums[i]);

    }

}


int main(){
    int num;
    cin >> num;
    vector<int> nums, track;
    For(i, 0, num){
        nums.push_back(i+1);
    }
    vector<vector<int>> res;
    set<int> visited;
    backTrack( nums, track, visited, res );
    int resNum = res.size();
    cout << resNum << endl;

    For( i, 0,  resNum){
        For(j, 0, num-1){
            cout << res[i][j] << " ";
        }
        cout << res[i][num-1] << endl;
    }

    system("pause");
    return 0;
}


