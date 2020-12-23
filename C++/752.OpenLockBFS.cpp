/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\752.OpenLockBFS.cpp
 * @Author              : AClearZhang
 * @Date                : 2020-12-22 21:11:35
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2020-12-23 10:31:59
 * @Version             : 1.0
 * @Description         : 打开密码锁？寻找最小的步数？——使用 BFS寻找 最小路径？
 * 752. 打开转盘锁
你有一个带有四个圆形拨轮的转盘锁。每个拨轮都有10个数字： '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' 。每个拨轮可以自由旋转：例如把 '9' 变为  '0'，'0' 变为 '9' 。每次旋转都只能旋转一个拨轮的一位数字。

锁的初始数字为 '0000' ，一个代表四个拨轮的数字的字符串。

列表 deadends 包含了一组死亡数字，一旦拨轮的数字和列表里的任何一个元素相同，这个锁将会被永久锁定，无法再被旋转。

字符串 target 代表可以解锁的数字，你需要给出最小的旋转次数，如果无论如何不能解锁，返回 -1。

 

示例 1:

输入：deadends = ["0201","0101","0102","1212","2002"], target = "0202"
输出：6
解释：
可能的移动序列为 "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202"。
注意 "0000" -> "0001" -> "0002" -> "0102" -> "0202" 这样的序列是不能解锁的，
因为当拨动到 "0102" 时这个锁就会被锁定。
示例 2:

输入: deadends = ["8888"], target = "0009"
输出：1
解释：
把最后一位反向旋转一次即可 "0000" -> "0009"。
示例 3:

输入: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
输出：-1
解释：
无法旋转到目标数字且不被锁定。
示例 4:

输入: deadends = ["0000"], target = "8888"
输出：-1
 

提示：

死亡列表 deadends 的长度范围为 [1, 500]。
目标数字 target 不会在 deadends 之中。
每个 deadends 和 target 中的字符串的数字会在 10,000 个可能的情况 '0000' 到 '9999' 中产生。
 */
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>


using namespace std;


class Solution {
public:
    /**
     * @Description: 对应 labuladong c++实现方法
     * @Param: 
     * @Return: 
     * @Notes: 
     */
    int openLock(vector<string>& deadends, string target) {
        if(target == "") return 0;
        unordered_set<string> stopEnds(deadends.begin(), deadends.end());
        unordered_set<string> visited;
        queue<string> q;

        int dis = 0;
        if(stopEnds.count("0000")) return -1;
        q.push("0000");
        visited.insert("0000");   // 访问过 并 添加进来了。
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz ;++i){
                // 每个当前这一层高度进行pop 和  访问处理。
                string cur = q.front();
                q.pop();
                if(cur == target){ // do
                    return dis;
                }
                
                // 邻域添加到 queue中去
                for(int j = 0; j < 4 ; ++j){
                    string plus = plusOne(cur, j);
                    string minus = minusOne(cur, j);
                    // if(!visited.count(plus) && stopEnds.find(plus) == stopEnds.end()){
                    if(!visited.count(plus) && !stopEnds.count(plus)){
                        // 不是永久暂停
                        q.push(plus);
                        visited.insert(plus);
                    }
                    // if(!visited.count(minus) &&stopEnds.find(minus) == stopEnds.end()){
                    if(!visited.count(minus) && !stopEnds.count(plus)){
                        // 不是永久暂停
                        q.push(minus);
                        visited.insert(minus);    // 【没加这个。cpu爆炸了！】
                    }
                }

            }
            dis++;
        }

        return -1;


    }
    /**
     * @Description: 以下 两个辅助函数， 方便查找邻域的节点； —— 对应注意 防止死循环；visited[]
     * @Param: 
     * @Return: 
     * @Notes: 
     */
    // 辅助函数，向上拨动一次
    string plusOne(string cur, int j){
        cur[j] = cur[j] == '9' ? '0' : (cur[j]+1);
        return cur;
    }
    // 辅助函数，向下拨动一次
    string minusOne(string cur, int j){
        cur[j] = cur[j]=='0'?'9':cur[j]-1;
        return cur;
    }

};
class Solution1 {
public:

    string plusOne(string str,int i)//数字+1
    {
        str[i] = str[i]=='9'?'0':str[i]+1;
        return str;
    }

    string downOne(string str,int i)//数字-1
    {
        str[i] = str[i]=='0'?'9':str[i]-1;
        return str;
    }


    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>deadset(deadends.begin(),deadends.end());//死亡密码

        unordered_set<string>visited;//走过的密码
        visited.insert("0000");

        queue<string>q;//当前的密码
        q.push("0000");

        int step=0;

        while(!q.empty())
        {
            int size = q.size();//当前这一批次，广度优先遍历，一批(一层)一批的走
            for(int i=0;i<size;i++)
            {
                string cur = q.front();//这一批次，当前密码
                q.pop();

                if(deadset.count(cur)) continue; //在死亡密码中，换下一个
                if(cur==target) return step;    //到达目标，结束

                for(int i=0;i<4;i++)    //每次转动，有(上、下)*4 种可能
                {
                    string up = plusOne(cur,i);  //向上
                    if(!visited.count(up))       //没有走过
                    {
                        q.push(up);              //放入当前密码(下一批次计算)
                        visited.insert(up);      //放入走过密码
                    }
                    string down = downOne(cur,i); //向下
                    if(!visited.count(down))      //没有走过
                    {
                        q.push(down);
                        visited.insert(down);
                    }
                }
            }
            step++;
        }
        return -1;
    }
};


int main(){
    // vector<string> deadends = {"0201","0101","0102","1212","2002"}; string target = "0202";
    vector<string> deadends = {"8887","8889","8878","8898","8788","8988","7888","9888"}; string target = "8888";
    Solution so;
    auto distance = so.openLock(deadends, target);
    cout << "揭开当前密码锁需要的最小步数为:" << distance << endl;
    
    system("pause");
    return 0;
}