/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\DS\146.LRUCache.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-03-24 14:47:06
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-03-24 18:12:08
 * @Version             : 1.0
 * @Description         : LRU 缓存机制
 * 146. LRU 缓存机制
运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制 。
实现 LRUCache 类：

LRUCache(int capacity) 以正整数作为容量 capacity 初始化 LRU 缓存
int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
void put(int key, int value) 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字-值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。
 

进阶：你是否可以在 O(1) 时间复杂度内完成这两种操作？

 

示例：

输入
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
输出
[null, null, null, 1, null, -1, null, -1, 3, 4]

解释
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // 缓存是 {1=1}
lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
lRUCache.get(1);    // 返回 1
lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
lRUCache.get(2);    // 返回 -1 (未找到)
lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
lRUCache.get(1);    // 返回 -1 (未找到)
lRUCache.get(3);    // 返回 3
lRUCache.get(4);    // 返回 4
 

提示：

1 <= capacity <= 3000
0 <= key <= 3000
0 <= value <= 104
最多调用 3 * 104 次 get 和 put
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
 * @notes: 关键：DoubleLinkedHashmap —— 尾入头出。
 */
class LRUCache {
public:
    LRUCache(int capacity) {
        this->_n = capacity;
    }
    
    int get(int key) {
        if(_mapHash.count(key) > 0){
            // 得到val，并转移到链表尾
            list<pair<int,int>> tmpList = _mapHash[key];
            int ans = tmpList.front().second;
            _list.splice(_list.end(), _list, tmpList.begin());  // 指向的当前查询的数值 插入到链表尾前面。
            return ans;
        }else{ // 不存在
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(_mapHash.count(key) > 0) { // 存在则变更数值，并放置到链表尾
            list<pair<int,int>> tmpList = _mapHash[key];
            tmpList.front().second = value;
            _list.splice(_list.end(), _list, tmpList.begin());  // 指向的当前查询的数值 插入到链表尾前面。
            return ;
        }
        // 不存在，两种情况 超出、未超出
        if(_list.size() != _n){ // 未超出
            // 直接插入到尾部
            _list.push_back(make_pair(key, value));
            // map新增
            _mapHash.emplace(key, _list.back());
            return ;
        }else{ // 超出
            // 删除list头， 删除map key
            _list.pop_front();
            _mapHash.erase(key);
            // 其它的和上面一样了。
            _list.push_back(make_pair(key, value));
            _mapHash.emplace(key, _list.back());
            return ;
        }
    }
private:
    unordered_map<int, list<pair<int, int>>> _mapHash;  // 为存储 iterator 这个方法夭折了。
    list<pair<int,int>> _list;
    int _n;  // 总的承受量
};


/**
 * @Description: 
 * @param {*}
 * @return {*}
 * @notes: 关键：DoubleLinkedHashmap —— 尾入头出。
 */
class LRUCache {
public:
    LRUCache(int capacity) {
        this->_n = capacity;
    }
    
    int get(int key) {
        auto it = _mapHash.find(key);
        if(it != _mapHash.end()){
            // 得到val，并转移到链表尾
            int ans = it->second->second;  // 相当于指针 已经指向了具体的位置 pair
            _list.splice(_list.end(), _list, it->second);  // 指向的当前查询的数值 插入到链表尾前面。
            return ans;
        }else{ // 不存在
            return -1;
        }
    }
    
    void put(int key, int value) {
        auto it = _mapHash.find(key);
        if(it != _mapHash.end()) { // 存在则变更数值，并放置到链表尾
            it->second->second = value;
            _list.splice(_list.end(), _list, it->second);  // 指向的当前查询的数值 插入到链表尾前面。
            return ;
        }
        // 不存在，两种情况 超出、未超出
        if(_list.size() < _n){ // 未超出
            // 直接插入到尾部
            _list.push_back(make_pair(key, value));
            // map新增
            _mapHash.emplace(key, prev(_list.end(), 1));
            return ;
        }else{ // 超出
             // 删除list头， 删除map key
            _mapHash.erase(_list.front().first);    // gai cuole1! 应该删除开头第一个！
            _list.pop_front();
            // 其它的和上面一样了。
             _list.push_back(make_pair(key, value));
            // map新增
            _mapHash.emplace(key, prev(_list.end(), 1));
            return ;
        }
    }
private:
    unordered_map<int, list<pair<int, int>>::iterator> _mapHash;  // 为存储 iterator 这个方法夭折了。
    list<pair<int,int>> _list;
    int _n;  // 总的承受量
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
