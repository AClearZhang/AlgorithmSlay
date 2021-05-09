/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\Interview\ByteDance\No.3.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-05-09 21:49:15
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-05-09 22:00:52
 * @Version             : 1.0
 * @Description         : 第三题  —— 吃鸡跟随
 * 
 */

#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

#define For(x, y, z) for (ll x = y; x < z; ++x)
typedef long long ll;

/**
 * @Description: [用法]分类 、 建立动态联通关系。 
 * @param {*}
 * @return {*}
 * @notes: 
 */
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
        this->cnt = n;
        this->n1 = n;
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
        return this->cnt;
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
        this->cnt--; // cuo
    }
    int maxCircle()
    { // 返回最大的连通分量
        int max = 1;
        for (int i = 0; i < n1; i++)
        {
            max = size[i] > max ? size[i] : max;
        }
        return max;
    }

private:
    int cnt;     // 连通分量
    int *parent; // 节点父节点索引 —— 方便并查集合并与使用
    int *size;   // 每个节点的重量是多少，方便 减少查找次数; 对应当前节点 所有的节点个数。
    int n1;
};

int main()
{
    int N, K;
    cin >> N >> K;
    UnionFind *unionChick = new UnionFind(N);
    while (K--)
    {
        int p1, p2;
        cin >> p1 >> p2;
        unionChick->unionRoot(p1-1, p2-1);   // 注意这里！！！
    }

    cout << "最大的团队数量为： " << unionChick->maxCircle() << endl;  // 对了。
    system("pause");
    return 0;
}