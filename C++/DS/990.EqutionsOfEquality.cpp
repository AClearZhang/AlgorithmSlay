/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\DS\990.EqutionsOfEquality.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-03-26 22:38:12
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-03-26 23:21:49
 * @Version             : 1.0
 * @Description         : 等式方程的可满足性
 *990. 等式方程的可满足性
给定一个由表示变量之间关系的字符串方程组成的数组，每个字符串方程 equations[i] 的长度为 4，并采用两种不同的形式之一："a==b" 或 "a!=b"。在这里，a 和 b 是小写字母（不一定不同），表示单字母变量名。

只有当可以将整数分配给变量名，以便满足所有给定的方程时才返回 true，否则返回 false。 

 

示例 1：

输入：["a==b","b!=a"]
输出：false
解释：如果我们指定，a = 1 且 b = 1，那么可以满足第一个方程，但无法满足第二个方程。没有办法分配变量同时满足这两个方程。
示例 2：

输入：["b==a","a==b"]
输出：true
解释：我们可以指定 a = 1 且 b = 1 以满足满足这两个方程。
示例 3：

输入：["a==b","b==c","a==c"]
输出：true
示例 4：

输入：["a==b","b!=c","c==a"]
输出：false
示例 5：

输入：["c==c","b==d","x!=z"]
输出：true 
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

/**
 * @Description: 【关键】 注意每次 重量都要去改变。
 * @param {*}
 * @return {*}
 * @notes: 
 */
class UnionFind
{
public:
    UnionFind(int n)
    {
        this->n = n;

        // 动态数组内存分配
        this->parent = new int[n];
        this->size = new int[n];
        // this->parent = (int*)malloc(n*sizeof(int));
        // this->size = (int*)malloc(n*sizeof(int));
        // this->parent.resize(n); 也可以 积累！！！
        // this->size.resize(n);
        

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
    // ~UnionFind()
    // {
    //     this->parent.clear();
    //     this->size.clear();
    // }
    /* 判断 p 和 q 是否连通 */
    bool connected(int p, int q)
    {
        int rootP = find(p);
        int rootQ = find(q);
        // cout << rootP << "rootq:" << rootQ << endl;
        return rootP == rootQ;
    }
    /* 返回图中有多少个连通分量 */
    int count()
    {
        return this->n;
    }
    // 发现 父节点， 返回父节点
    int find(int x)
    {
        // 经过三次修正 降低路径搜索难度
        while (parent[x] != x)
        {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
    // 将p和q连通
    void unionRoot(int p, int q)
    {
        // 比较size，将轻的放在重的上面
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ)
            return; // cuo

        if (size[rootP] > size[rootQ])
        {
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ]; // cuo
        }
        else
        {
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP]; //cuo
        }
        n--; // cuo
    }

private:
    int n;       // 连通分量
    int *parent; // 节点父节点索引 —— 方便并查集合并与使用
    int *size;   // 每个节点的重量是多少，方便 减少查找次数
};
class Solution
{
public:
    /**
     * @Description: 使用 并查集。因为分为两类、 中间动态链接。最后检查 联不联通即可。
     * @param {*}
     * @return {*}
     * @notes: 
     */
    bool equationsPossible(vector<string> &equations)
    {
        UnionFind *equaEquality = new UnionFind(26); //26 个英文字母 来对应0--25  'a'-'a';
        // 先联通分类
        for (string e : equations)
        {
            if (e[1] == '=')
            {
                // 联通 0 3
                int p = int(e[0] - 'a'), q = int(e[3] - 'a');
                // cout << p << ',' << q << endl;
                equaEquality->unionRoot(p, q);
            }
        }

        // 然后检查
        for (string e : equations)
        {
            if (e[1] == '!')
            {
                // p q是否联通
                int p = int(e[0] - 'a'), q = int(e[3] - 'a');
                // cout << p << '-' << q << endl;
                if (equaEquality->connected(p, q))
                {
                    // 连通
                    // cout << "连通" << endl;
                    return false;
                }
            }
        }
        return true;
    }
};
