/*
 * @FilePath            : \project\AlgorithmSlay\C++\DynamicProgram\887.EggDropSuper.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-03-06 13:12:43
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-03-06 18:13:05
 * @Version             : 1.0
 * @Description         : 最坏情况 至少掉落几次 找到这个楼层F
 * 887. 鸡蛋掉落
你将获得 K 个鸡蛋，并可以使用一栋从 1 到 N  共有 N 层楼的建筑。

每个蛋的功能都是一样的，如果一个蛋碎了，你就不能再把它扔下去。如果某个蛋扔下后没有摔碎，则可以将蛋捡起重复使用。

你知道存在楼层 F ，满足 0 <= F <= N 任何从高于 F 的楼层落下的鸡蛋都会碎，从 F 楼层或比它低的楼层落下的鸡蛋都不会破。

每次移动，你可以取一个鸡蛋（如果你有完整的鸡蛋）并把它从任一楼层 X 扔下（满足 1 <= X <= N）。

你的目标是确切地知道 F 的值是多少。

无论 F 的初始值如何，你确定 F 的值的最小移动次数是多少？

 

示例 1：

输入：K = 1, N = 2
输出：2
解释：
鸡蛋从 1 楼掉落。如果它碎了，我们肯定知道 F = 0 。
否则，鸡蛋从 2 楼掉落。如果它碎了，我们肯定知道 F = 1 。
如果它没碎，那么我们肯定知道 F = 2 。
因此，在最坏的情况下我们需要移动 2 次以确定 F 是多少。
示例 2：

输入：K = 2, N = 6
输出：3
示例 3：

输入：K = 3, N = 14
输出：4
 

提示：

1 <= K <= 100
1 <= N <= 10000
 */

#include <iostream>
#include <cmath>
#include <windows.h>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @Description: nb 的另一个方法。
     * @param {int} k
     * @param {int} n
     * @return {int} 最终返回 遍历到的m. 
     * @notes: 关键1：逆向思维的DP[K][m] == N //同样也是目标。
     *              表示当前有K个鸡蛋，最多可以尝试扔m次；
     *                求在这个状态下， 最多可以测试多少楼层——N。
     *         关键2：状态转移方程：上楼+下楼+1 = 总的楼层数目。== dp[K][m]
     */
    int superEggDrop(int K, int N) {
        vector<vector<int>> dp(K+1, vector<int>(N+1, 0));
        // base 0

        // dp start
        int m=0;
        for(;dp[K][m]<N;){
            m++;
        // for( m=1;dp[K][m]<N;m++){  // 会报错  超出int范围
            for(int i=1;i<=K;i++){
                dp[i][m] = dp[i][m-1]+dp[i-1][m-1]+1;
            }
        }
        
        // 下面这个也可以。 甚至更好！区别在于加了 while()
        // int m = 0;
        // while(dp[K][m]<N){
        //     m++;
        //     for(int i=1;i<=K;i++){
        //         // cout << "i:" << i << " ,m:" << m<<endl;
        //         dp[i][m] = dp[i][m-1]+dp[i-1][m-1]+1;
        //     }
        // }
        return m;
    }
    /**
     * @Description: 使用暴力 -> 递归+备忘录 简洁方法先打基础做出来！之后再进阶 优化复杂度。
     * @param {int} k
     * @param {int} n
     * @return {*}
     * @notes: 注意！要理解清楚题意：！最坏情况  ！至少 
     */
    int superEggDrop(int k, int n) {
        vector<vector<int>> memo(k+1, vector<int>(n+1, -1));
        // return dp(k,n , memo);
        return dp2(k,n , memo);
    }
    // 辅助函数：表示最坏情况下，至少 移动几步能找到对应的层数。
        // memo 备忘录记录以计算出的步数；避免重复计算。
    int dp(int K, int N, vector<vector<int>> &memo){
        // base
        if(K==1) return N;
        if(N==0) return 0;
        
        if(memo[K][N]!=-1){
            // 说明已经计算过
            return memo[K][N];
        }

        // dp
        int res = INT_MAX; 
        for(int i = 1;i<=N;i++){            // 穷举、递归遍历。
            res = min(res,max(
                dp(K-1, i-1, memo), // 碎了
                dp(K, N-i, memo)//没碎
                ) + 1               // 扔出去一次 别忘记+1；
            );
        }  // 0会超出范围
        memo[K][N] = res;
        return res;
    }
    // 辅助函数2：表示最坏情况下，至少 移动几步能找到对应的层数。
        // memo 备忘录记录以计算出的步数；避免重复计算。
    // 此处：使用二分查找 优化两个单调线性函数的 线性搜索时间。
        // 具体图片见 P174《AI小抄》。
    int dp2(int K, int N, vector<vector<int>> &memo){
        // base
        if(K==1) return N;
        if(N==0) return 0;
        
        if(memo[K][N]!=-1){
            // 说明已经计算过
            return memo[K][N];
        }

        // dp1
        // int res = INT_MAX; 
        // for(int i = 1;i<=N;i++){            // 穷举、递归遍历。
        //     res = min(res,max(
        //         dp(K-1, i-1, memo), // 碎了
        //         dp(K, N-i, memo)//没碎
        //         ) + 1               // 扔出去一次 别忘记+1；
        //     );
        // }  // 0会超出范围


        // dp2
        int res = INT_MAX; 
        int lo=1,hi=N;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            int broken = dp(K-1, mid-1, memo); // sui
            int not_broken = dp(K, N-mid, memo); //wei sui
            if(broken > not_broken){
                hi = mid -1; // 向下搜索
                res = min(res, broken+1);
            }else{
                lo = mid + 1;
                res = min(res, not_broken+1);
            }
        }
        memo[K][N] = res;
        return res;
    }
};
