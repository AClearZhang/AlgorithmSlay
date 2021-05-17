/*
 * @FilePath            : \AlgorithmInterview\AlgorithmSlay\C++\DynamicProgram\ZijieDP.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-05-17 16:16:34
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-05-17 16:35:41
 * @Version             : 1.0
 * @Description         : 字节跳动高频 动规题目.  https://blog.csdn.net/weixin_45918732/article/details/116562822
 * 4.1 环路0点出发，k步回原点有几种方法
4.1.1 题目描述
一个环上有10个点,编号为0-9,从0点出发,每步可以顺时针到下一个点,也可以逆时针到上一个点,求:经过n步又回到0点有多少种不同的走法？

举例
如果n=1，则从0出发只能到1或者9，不可能回到0，共0种走法
如果n=2，则从0出发有4条路径:0->1->2, 0->1->0, 0->9->8, 0->9->0,其中有两条回到了0点，故一共有2种走法

4.1.2 解析
动态规划：
状态： 步数变化、当前点变化。
目标： dp[n,0]
dp数组 dp二维数组——从0出发，k步到达j点的方法有多少种。
j步达到i点的问题，转化为j-1步从相邻的两个节点到达目标节点的方法数之和。

状态方程 d(k, j) = d(k-1, j-1) + d(k-1, j+1);
由于可能发生越界，故转换为
d(k, j) = d(k-1, (j-1+n)%n) + d(k-1, (j+1)%n);
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


class Solution{
public:
    /**
     * @Description: 有n个节点，问：需要从0出发走 k步  有多少种方案。
     * @param {int} n
     * @param {int} k
     * @return {*}
     * @notes: 关键动规——思考清楚 状态/目标（  ）=》dp =》 状态转移关系
     * 状态： 当前点变化/或者说0点出发到目标点的方案几种、 步数变化。目标： dp[n,0]
dp数组 dp二维数组——从0出发，k步到达j点的方法有多少种。
j步达到i点的问题，转化为j-1步从相邻的两个节点到达目标节点的方法数之和。

状态方程 d(k, j) = d(k-1, j-1) + d(k-1, j+1);
由于可能发生越界，故转换为
d(k, j) = d(k-1, (j-1+n)%n) + d(k-1, (j+1)%n);
     */
    int GetSteps(int n,int k){
        if(n==0) return 1;
        //如果只有2个结点，则偶数有1个方法，奇数不能到达
        if(n==2){
            if(k%2==0) return 1;
            else return 0;
        }
        vector<vector<int>> dp(k+1, vector<int>(n, 0));
        //0步到达0点有1种方法
            // 此为关键 —— 标志从0 开始出发

        // base —— 第一行，因为都要用上一行
        dp[0][0]=1;
        //0步到达任意点有0种方法,上面已赋值
        //for(int i=0;i<n;i++){
        //    dp[0][i]=0
        //}
        for(int i=1;i<=k;i++){
            for(int j=0;j<n;j++){
                //i步达到i点的问题，转化为i-1步从相邻的两个节点到达目标节点的方法数之和。
                //需要保证在0~n-1范围，故需要防止越界进行处理
                dp[i][j]=dp[i-1][(j-1+n)%n]+dp[i-1][(j+1)%n];
            }
        }
        //这里的0对应的是回到0点，达到任意点可以通过将0改为目标点即可
        return dp[k][0];
    }
    
};

int main(){
    Solution s1;
    cout << s1.GetSteps(10, 1) << endl;
    cout << s1.GetSteps(10, 2) << endl;
    cout << s1.GetSteps(10, 3) << endl;
    cout << s1.GetSteps(10, 4) << endl;
    cout << s1.GetSteps(10, 5) << endl;
    cout << s1.GetSteps(10, 6) << endl;

    system("pause");
    return 0;
}

