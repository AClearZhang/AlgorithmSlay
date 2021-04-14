/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\797.AllPathsInGraph.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-04-14 20:22:25
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-04-14 21:06:51
 * @Version             : 1.0
 * @Description         : 图中所有可能的路径
 * 797. 所有可能的路径
给一个有 n 个结点的有向无环图，找到所有从 0 到 n-1 的路径并输出（不要求按顺序）

二维数组的第 i 个数组中的单元都表示有向图中 i 号结点所能到达的下一些结点（译者注：有向图是有方向的，即规定了 a→b 你就不能从 b→a ）空就是没有下一个结点了。

 

示例 1：



输入：graph = [[1,2],[3],[3],[]]
输出：[[0,1,3],[0,2,3]]
解释：有两条路径 0 -> 1 -> 3 和 0 -> 2 -> 3
示例 2：



输入：graph = [[4,3,1],[3,2,4],[3],[4],[]]
输出：[[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]
示例 3：

输入：graph = [[1],[]]
输出：[[0,1]]
示例 4：

输入：graph = [[1,2,3],[2],[3],[]]
输出：[[0,1,2,3],[0,2,3],[0,3]]
示例 5：

输入：graph = [[1,3],[2],[3],[]]
输出：[[0,1,2,3],[0,3]]
 

提示：

结点的数量会在范围 [2, 15] 内。
你可以把路径以任意顺序输出，但在路径内的结点的顺序必须保证。
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


class Solution {
public:
    /**
     * @Description: 使用深度优先搜索  查找所能到达的节点。
     * @param {*}
     * @return {*}
     * @notes: 
     */
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<bool> visited(graph.size(), false);
        vector<int> tmp;
        dfs(graph, visited, res, tmp, 0);
        return res;
    }

    void dfs(vector<vector<int>>& graph, vector<bool> &visited, vector<vector<int>>& res, vector<int> &tmp, int s){
        visited[s] = true;
        tmp.push_back(s);
        if( s== (graph.size()-1)){
            res.push_back(tmp);
            return ;            
        }

        // neighbors visited
        for(int vertex: graph[s]){
            if(!visited[vertex] ){
                dfs(graph, visited, res, tmp, vertex);
                visited[vertex] = false;// 返回
                tmp.pop_back();
            }
        }
    }
};
