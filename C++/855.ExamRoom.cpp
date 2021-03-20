/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\855.ExamRoom.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-03-20 15:11:58
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-03-20 17:28:51
 * @Version             : 1.0
 * @Description         : 考场就座  二叉平衡树
 * 855. 考场就座
在考场里，一排有 N 个座位，分别编号为 0, 1, 2, ..., N-1 。

当学生进入考场后，他必须坐在能够使他与离他最近的人之间的距离达到最大化的座位上。如果有多个这样的座位，他会坐在编号最小的座位上。(另外，如果考场里没有人，那么学生就坐在 0 号座位上。)

返回 ExamRoom(int N) 类，它有两个公开的函数：其中，函数 ExamRoom.seat() 会返回一个 int （整型数据），代表学生坐的位置；函数 ExamRoom.leave(int p) 代表坐在座位 p 上的学生现在离开了考场。每次调用 ExamRoom.leave(p) 时都保证有学生坐在座位 p 上。

 

示例：

输入：["ExamRoom","seat","seat","seat","seat","leave","seat"], [[10],[],[],[],[],[4],[]]
输出：[null,0,9,4,2,null,5]
解释：
ExamRoom(10) -> null
seat() -> 0，没有人在考场里，那么学生坐在 0 号座位上。
seat() -> 9，学生最后坐在 9 号座位上。
seat() -> 4，学生最后坐在 4 号座位上。
seat() -> 2，学生最后坐在 2 号座位上。
leave(4) -> null
seat() -> 5，学生最后坐在 5 号座位上。
 

提示：

1 <= N <= 10^9
在所有的测试样例中 ExamRoom.seat() 和 ExamRoom.leave() 最多被调用 10^4 次。
保证在调用 ExamRoom.leave(p) 时有学生正坐在座位 p 上。
 */
#include <algorithm>
#include <cmath>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

class ExamRoom {
public:
    /**
     * @Description: 初始化座位个数
     * @param {int} N
     * @return {*}
     * @notes: 就近且 与最近人距离最远的方式安排座位。
     */
    vector<int> seatInt;  // 0表示没有人座。
    vector<pair<int, int>> space; // 表示线段中点以及 间隔大小；注意按照 value降序，key的升序进行。
    ExamRoom(int N) {
        vector<int> temp(N,0);
        this->seatInt.insert(seatInt.begin(), temp.begin(), temp.begin()+N);
    }
    /**
     * @Description: 分配座位
     * @param {*}
     * @return {*}
     * @notes: 
     */
    int seat() {
        int n = seatInt.size();
        // 当space为空 ; 只有1个或0个。
        if(space.empty()){
            int find = -1;
            for(int i = 0;i < n;i++){
                if(seatInt[i] == 1){
                    find = i;
                }
            }
            if( find == -1){
                // 两种情况 空或者1个数值
                seatInt[0] = 1;
                return 0;
            }else{
                // 有一个数值，再插入一个新的。
                int insertPos = ((n-1)-find) > (find-0) ? n-1 : 0;
                
                // 插入
                int seatNext = ceil( abs(insertPos - find)/2) + findFirst;
                pair<int, int> spaceTmp = make_pair(seatNext, (ceil((i - findFirst)/2) - 1)); // 间隔赋值.
                tmpSapce.push_back(spaceTmp);
                

            seatInt[n-1] = 1;
            return n-1;       
            }
        }
        
        
        // 下面是需要加入 中间线段
            // 使用间隔排序找到 当前需要落座位置。
        pair<int,int> nowSpace = *space.begin();
        int nowSeat = nowSpace.first;
        seatInt[nowSeat] = 1;

          
        this->space = this->generateNewSpaceInternal();
        return nowSeat;
    }
    /**
     * @Description: 移除——注意间隔个数。
     * @param {int} p
     * @return {*}
     * @notes: 
     */
    void leave(int p) {
        seatInt[p] = 0;
        // 注意如果只剩下一个数了就不行了
        if(space.size() <= 1){
            this->space.clear();
            return ;
        }
        this->space = generateNewSpaceInternal();
        return ;
    }

    // helper 生成新的间隔map
    vector<pair<int, int>> generateNewSpaceInternal(){
        int n = this->seatInt.size();
          // 设置新的间隔 并 排序
        vector<pair<int, int>> tmpSapce;
        int findFirst = -1; // 未发现
        for(int i = 0; i<n ; i++){
            if(seatInt[i] == 0) continue;
            if(findFirst == -1) {
                findFirst = i; // 找到第一个点
                continue;
            }
            // 第一个和第二个点都找到了. 开始计算新的space 最终排序
                // 计算间隔
            int seatNext = ceil((i - findFirst)/2) + findFirst;
            pair<int, int> spaceTmp = make_pair(seatNext, (ceil((i - findFirst)/2) - 1)); // 间隔赋值.
            tmpSapce.push_back(spaceTmp);

            findFirst = i; // 更新方便下一个间隔进行计算
        }
        // 排序tmpSpace
        sort(tmpSapce.begin(), tmpSapce.end() ,cmp);
        return tmpSapce;
    }
    // 排序新的 space map的方法。
    static bool cmp(const pair<int, int>& a, const pair<int,int>& b){
        return (a.second>b.second) || (a.second==b.second && a.first < b.first);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */

