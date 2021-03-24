/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\DS\460.LFUCache.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-03-24 20:29:39
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-03-24 22:55:22
 * @Version             : 1.0
 * @Description         : LFU 缓存算法
 * 460. LFU 缓存
请你为 最不经常使用（LFU）缓存算法设计并实现数据结构。

实现 LFUCache 类：

LFUCache(int capacity) - 用数据结构的容量 capacity 初始化对象
int get(int key) - 如果键存在于缓存中，则获取键的值，否则返回 -1。
void put(int key, int value) - 如果键已存在，则变更其值；如果键不存在，请插入键值对。当缓存达到其容量时，则应该在插入新项之前，使最不经常使用的项无效。在此问题中，当存在平局（即两个或更多个键具有相同使用频率）时，应该去除 最久未使用 的键。
注意「项的使用次数」就是自插入该项以来对其调用 get 和 put 函数的次数之和。使用次数会在对应项被移除后置为 0 。

为了确定最不常使用的键，可以为缓存中的每个键维护一个 使用计数器 。使用计数最小的键是最久未使用的键。

当一个键首次插入到缓存中时，它的使用计数器被设置为 1 (由于 put 操作)。对缓存中的键执行 get 或 put 操作，使用计数器的值将会递增。

 

示例：

输入：
["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
输出：
[null, null, null, 1, null, -1, 3, null, -1, 3, 4]

解释：
// cnt(x) = 键 x 的使用计数
// cache=[] 将显示最后一次使用的顺序（最左边的元素是最近的）
LFUCache lFUCache = new LFUCache(2);
lFUCache.put(1, 1);   // cache=[1,_], cnt(1)=1
lFUCache.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
lFUCache.get(1);      // 返回 1
                      // cache=[1,2], cnt(2)=1, cnt(1)=2
lFUCache.put(3, 3);   // 去除键 2 ，因为 cnt(2)=1 ，使用计数最小
                      // cache=[3,1], cnt(3)=1, cnt(1)=2
lFUCache.get(2);      // 返回 -1（未找到）
lFUCache.get(3);      // 返回 3
                      // cache=[3,1], cnt(3)=2, cnt(1)=2
lFUCache.put(4, 4);   // 去除键 1 ，1 和 3 的 cnt 相同，但 1 最久未使用
                      // cache=[4,3], cnt(4)=1, cnt(3)=2
lFUCache.get(1);      // 返回 -1（未找到）
lFUCache.get(3);      // 返回 3
                      // cache=[3,4], cnt(4)=1, cnt(3)=3
lFUCache.get(4);      // 返回 4
                      // cache=[3,4], cnt(4)=2, cnt(3)=3
 */
#include <algorithm>
#include <cmath>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <set>
#include <deque>  // 失策 是想到了有双向链表性质的deque--很多缺点——没想到自己用底层的 数据结构去合成！
#include <list>

using namespace std;

/**
 * @Description: 
 * @param {*}
 * @return {*}
 * @notes: 头出尾入 ； 但是还是要看  当前fre和新旧。关键：新旧通过 get() put() 进行比较选择排序。比较慢。
 *          所以有了方法二，主要瓶颈在于  fre大小的查找，所以通过 使用另一个HashMap来存放  多个双向链表（每个fre下有一个链接）。O(1)即可找到。
 */
class LFUCache {
public:
    LFUCache(int capacity) {
        _n = capacity;
    }
    
    int get(int key) {
        auto it = _mapHash.find(key);
        if(it != _mapHash.end()){
            // 得到val，并添加1个fre  寻找插入位置。
            int ans = it->second->value;  // 相当于指针 已经指向了具体的位置 pair
            it->second->fre++;

            // 开始更换位置
            list<Node>::iterator it_node = it->second;
            auto it_next_node = next(it_node, 1);
            while(it_next_node != _list.end() && *it_node >= *it_next_node){
                // 频率大的时候
                it_next_node++;
            }
                // 当前频率下  插入到next前面
            _list.splice(it_next_node, _list, it_node); 
            // 结束更换位置
            return ans;
        }else{ // 不存在
            return -1;
        }
    }
    
    void put(int key, int value) {
        auto it = _mapHash.find(key);
        if(it != _mapHash.end()) { // 存在则变更数值，fre++ 更换位置
            it->second->value = value;
            it->second->fre++;

            // 开始更换位置
            list<Node>::iterator it_node = it->second;
            auto it_next_node = next(it_node, 1);
            while(it_next_node != _list.end() && *it_node >= *it_next_node){
                // 频率大的时候
                it_next_node++;
            }
                // 当前频率下  插入到next前面
            _list.splice(it_next_node, _list, it_node); 
            // 结束更换位置
            return ;
        }
        
        // 不存在，两种情况 未超出和超出
        if(_list.size() < _n){ // 未超出
            // 直接插入到头部或再往前！因为自己为新的
            Node *tmp_node = new Node(key, value, 1);  // 新的 所以>=

            // 开始更换位置
            list<Node>::iterator it_next_node = _list.begin();
            while(it_next_node != _list.end() && *tmp_node >= *it_next_node){
                // 频率大的时候
                it_next_node++;
            }
                // 当前频率下  插入到next前面
            auto it_now = _list.insert(it_next_node, *tmp_node); 
            // 结束更换位置

            // map新增
            _mapHash.emplace(key, it_now);
            return ;
        }else{ // 超出
        
            // 0 超出,不存在可以插入的
            if(this->_n == 0)
                return ;
                
            // 删除list的头部fre低、不新的； 接着erase map中的key
            _mapHash.erase(_list.front().key);
            _list.pop_front();


            // 直接插入到头部或再往前！因为自己为新的
            Node *tmp_node = new Node(key, value, 1);  // 新的 所以>=

            // 开始更换位置
            list<Node>::iterator it_next_node = _list.begin();
            while(it_next_node != _list.end() && *tmp_node >= *it_next_node){
                // 频率大的时候
                it_next_node++;
            }
                // 当前频率下  插入到next前面
            auto it_now = _list.insert(it_next_node, *tmp_node); 
            // 结束更换位置

            // map新增
            _mapHash.emplace(key, it_now);
            return ;
        }
    }

private:
    struct Node{
        int key, value, fre;
        Node(int _key, int _value, int _fre) : key(_key), value(_value), fre(_fre) {

        }  // 自动构造函数

        bool operator>(const Node& bnt){
            return this->fre > bnt.fre;
        }
        bool operator>=(const Node& bnt){
            return this->fre >= bnt.fre;
        }
    };
    unordered_map<int, list<Node>::iterator> _mapHash;  // 存储list的地址，方便进行移动
    list<Node> _list; // 维持一个从尾到头 有序的双向链表
    int _n;  // 总的承受量
};
