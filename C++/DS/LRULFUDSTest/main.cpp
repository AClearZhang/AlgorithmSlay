/*
 * @FilePath            : \AlgorithmInterview\AlgorithmSlay\C++\DS\146.LRUCache.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-03-24 14:47:06
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-10-20 15:48:13
 * @Version             : 1.0
 * @Description         : LRU �������
 * 146. LRU �������
�����������յ����ݽṹ����ƺ�ʵ��һ��  LRU (�������ʹ��) ������� ��
ʵ�� LRUCache �ࣺ

LRUCache(int capacity) ����������Ϊ���� capacity ��ʼ�� LRU ����
int get(int key) ����ؼ��� key �����ڻ����У��򷵻عؼ��ֵ�ֵ�����򷵻� -1 ��
void put(int key, int value) ����ؼ����Ѿ����ڣ�����������ֵ������ؼ��ֲ����ڣ��������顸�ؼ���-ֵ���������������ﵽ����ʱ����Ӧ����д��������֮ǰɾ�����δʹ�õ�����ֵ���Ӷ�Ϊ�µ�����ֵ�����ռ䡣


���ף����Ƿ������ O(1) ʱ�临�Ӷ�����������ֲ�����



ʾ����

����
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
���
[null, null, null, 1, null, -1, null, -1, 3, 4]

����
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // ������ {1=1}
lRUCache.put(2, 2); // ������ {1=1, 2=2}
lRUCache.get(1);    // ���� 1
lRUCache.put(3, 3); // �ò�����ʹ�ùؼ��� 2 ���ϣ������� {1=1, 3=3}
lRUCache.get(2);    // ���� -1 (δ�ҵ�)
lRUCache.put(4, 4); // �ò�����ʹ�ùؼ��� 1 ���ϣ������� {4=4, 3=3}
lRUCache.get(1);    // ���� -1 (δ�ҵ�)
lRUCache.get(3);    // ���� 3
lRUCache.get(4);    // ���� 4


��ʾ��

1 <= capacity <= 3000
0 <= key <= 3000
0 <= value <= 104
������ 3 * 104 �� get �� put
 */
#include <algorithm>
#include <cmath>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <set>
#include <deque>  // ʧ�� ���뵽����˫���������ʵ�deque--�ܶ�ȱ�㡪��û�뵽�Լ��õײ�� ���ݽṹȥ�ϳɣ�
#include <list>

using namespace std;

/**
 * @Description:
 * @param {*}
 * @return {*}
 * @notes: �ؼ���DoubleLinkedHashmap ���� β��ͷ����
 */
class LRUCache2 {
public:
    LRUCache2(int capacity) {
        this->_n = capacity;
    }

    int get(int key) {
        auto it = _mapHash.find(key);
        if(it != _mapHash.end()){
            // �õ�val����ת�Ƶ�����β
            int ans = it->second->second;  // �൱��ָ�� �Ѿ�ָ���˾����λ�� pair
            _list.splice(_list.end(), _list, it->second);  // ָ��ĵ�ǰ��ѯ����ֵ ���뵽����βǰ�档
            return ans;
        }else{ // ������
            return -1;
        }
    }

    void put(int key, int value) {
        auto it = _mapHash.find(key);
        if(it != _mapHash.end()) { // ����������ֵ�������õ�����β
            it->second->second = value;
            _list.splice(_list.end(), _list, it->second);  // ָ��ĵ�ǰ��ѯ����ֵ ���뵽����βǰ�档
            return ;
        }
        // �����ڣ�������� ������δ����
        if(_list.size() < _n){ // δ����
            // ֱ�Ӳ��뵽β��
            _list.push_back(make_pair(key, value));
            // map����
            _mapHash.emplace(key, prev(_list.end(), 1));
            return ;
        }else{ // ����
             // ɾ��listͷ�� ɾ��map key
            _mapHash.erase(_list.front().first);    // gai cuole1! Ӧ��ɾ����ͷ��һ����
            _list.pop_front();
            // �����ĺ�����һ���ˡ�
             _list.push_back(make_pair(key, value));
            // map����
            _mapHash.emplace(key, prev(_list.end(), 1));
            return ;
        }
    }
private:
    unordered_map<int, list<pair<int, int>>::iterator> _mapHash;  // Ϊ�洢 iterator �������ز���ˡ�
    list<pair<int,int>> _list;
    int _n;  // �ܵĳ�����
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(int argc, char const *argv[])
{
    LRUCache2 lRUCache(2);
    lRUCache.put(1, 1); // ������ {1=1}
    lRUCache.put(2, 2); // ������ {1=1, 2=2}
    cout << lRUCache.get(1) << endl;    // ���� 1
    lRUCache.put(3, 3); // �ò�����ʹ�ùؼ��� 2 ���ϣ������� {1=1, 3=3}
    cout << lRUCache.get(2) << endl;    // ���� -1 (δ�ҵ�)
    lRUCache.put(4, 4); // �ò�����ʹ�ùؼ��� 1 ���ϣ������� {4=4, 3=3}
    cout << lRUCache.get(1) << endl;    // ���� -1 (δ�ҵ�)
    cout << lRUCache.get(3) << endl;    // ���� 3
    cout << lRUCache.get(4) << endl;


    return 0;
}

