/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\DS\460.LFUCache.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-03-24 20:29:39
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-03-24 22:55:39
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

/**
 * @Description: 方法二： 双哈希表，一个key_table 用来存放key和对应的node迭代器；另一个 fre_table 用来存放fre键和 对应的真实 双向链表list。
 *              所以有了方法二，主要瓶颈在于  fre大小的查找，所以通过 使用另一个HashMap来存放  多个双向链表（每个fre下有一个链接）。O(1)即可找到。
 * @param {*}
 * @return {*}
 * @notes: 
 */
// 缓存的节点信息
struct Node {
    int key, val, freq;
    Node(int _key,int _val,int _freq): key(_key), val(_val), freq(_freq){}
};
class LFUCache {
    int minfreq, capacity;
    unordered_map<int, list<Node>::iterator> key_table;
    unordered_map<int, list<Node>> freq_table;
public:
    LFUCache(int _capacity) {
        minfreq = 0;
        capacity = _capacity;
        key_table.clear();
        freq_table.clear();
    }
    
    int get(int key) {
        if (capacity == 0) return -1;
        auto it = key_table.find(key);
        if (it == key_table.end()) return -1;

        // 存在
        list<Node>::iterator node = it -> second;
        int val = node -> val, freq = node -> freq;
        freq_table[freq].erase(node);
        // 如果当前链表为空，我们需要在哈希表中删除，且更新minFreq
        if (freq_table[freq].size() == 0) {
            freq_table.erase(freq);
            if (minfreq == freq) minfreq += 1;
        }
        // 插入到 freq + 1 中
        freq_table[freq + 1].push_front(Node(key, val, freq + 1));
        key_table[key] = freq_table[freq + 1].begin();  // 注意这里！
        return val;
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;
        auto it = key_table.find(key);
        if (it == key_table.end()) { // 不存在这个key
            // 缓存已满，需要进行删除操作
            if (key_table.size() == capacity) {
                // 通过 minFreq 拿到 freq_table[minFreq] 链表的末尾节点
                auto it2 = freq_table[minfreq].back();
                key_table.erase(it2.key);  // 删除1
                freq_table[minfreq].pop_back();  // 删除2
                if (freq_table[minfreq].size() == 0) {  // 删除3
                    freq_table.erase(minfreq);
                }
            } 
            freq_table[1].push_front(Node(key, value, 1));
            key_table[key] = freq_table[1].begin();
            minfreq = 1;
        } else { //存在这个key
            // 与 get 操作基本一致，除了需要更新缓存的值
            list<Node>::iterator node = it -> second;
            int freq = node -> freq;
            freq_table[freq].erase(node);       // 破坏了当前iterator，下面 新建了。
            if (freq_table[freq].size() == 0) {
                freq_table.erase(freq);
                if (minfreq == freq) minfreq += 1;
            }
            freq_table[freq + 1].push_front(Node(key, value, freq + 1));
            key_table[key] = freq_table[freq + 1].begin();
        }
    }
};
/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
