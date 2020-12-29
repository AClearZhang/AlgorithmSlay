/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\126.WordLadderII.cpp
 * @Author              : AClearZhang
 * @Date                : 2020-12-23 21:35:30
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2020-12-29 09:02:36
 * @Version             : 1.0
 * @Description         : 单词接龙II
 * 126. 单词接龙 II
给定两个单词（beginWord 和 endWord）和一个字典 wordList，找出所有从 beginWord 到 endWord 的最短转换序列。转换需遵循如下规则：

每次转换只能改变一个字母。
转换后得到的单词必须是字典中的单词。
说明:

如果不存在这样的转换序列，返回一个空列表。
所有单词具有相同的长度。
所有单词只由小写字母组成。
字典中不存在重复的单词。
你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
示例 1:

输入:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

输出:
[
  ["hit","hot","dot","dog","cog"],
  ["hit","hot","lot","log","cog"]
]
示例 2:

输入:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

输出: []

解释: endWord "cog" 不在字典中，所以不存在符合要求的转换序列。
 */

#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <windows.h>

using namespace std;

class Solution
{
public:
    /** 每次变一个， 且邻域在 wordlist中。
     * @Description: 单词接龙解题思路：①首先，BFS寻找最短路径的层数 和 构建搜索树的邻接表。②使用回溯思想，深搜并记录track 返回最短路径的 单词接龙多种解决方案。
     * @Param: 结构需要：见下方
     * @Return: 
     * @Notes: 注意：①subVisited ②不要 同一层相连，去除这样构建的搜索树——使不相连。   【注意：已经不相连了，因为 visit 已经去除了同层连接】
     */
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        vector<vector<string>> ans;
        unordered_set<string> wordList1(wordList.begin(), wordList.end());
        if(wordList1.count(endWord) == 0) { return ans; } // 上来就没有end，返回空列表。

        queue<string> q; // 记录bfs的层
        unordered_set<string> visited;
        unordered_map<string, vector<string>> souTree;

        // 开始BFS
        q.push(beginWord);
        visited.insert(beginWord);
        bool isFound = false;

        int level = 0;
        while(!q.empty()){
            unordered_set<string> subVisited; // 方便在最外层添加进入visited
            int sz = q.size();
            
            // vector<string> successor; // 错了位置
            vector<string> preSuccessor;
            while(sz--){

                string cur = q.front();
                q.pop();
                // 结束条件,但是仍要在当前层结束后， 结束所有的bfs
                // 但是再者说，我们在 下面直接 visit了。所以不需要等到当前层提取结束，我们在访问上次一层的时候 就添加到邻域中了。
                if(cur == endWord && !isFound){
                    isFound = true;
                    break;
                }

                // 寻找邻域 并 添加到搜索树
                vector<string> neiborWord;
                vector<string> successor; // 【错了位置】
                findCurNeibor(cur, neiborWord, wordList1);
                for( string nei : neiborWord ){
                    if(!visited.count(nei)){

                        // [丢失 去除同一层的重复单词]
                        subVisited.insert(nei);
                        successor.push_back(nei);
                        q.push(nei);
                    }

                }
                souTree.emplace(cur, successor);

            }
            // 一层结束
            if( isFound ) { break; } // 如果找到了 break;
            visited.insert(subVisited.begin(), subVisited.end());
            level++;
            cout << "调试当前的层次为：" << level << endl;
        }// BFS结束

        // 深搜 搜索树，构建answer
        vector<string> track;
        track.push_back(beginWord);
        dfs( souTree, track, beginWord, endWord, ans);
        return ans;
    }
    // 辅助函数 —— 回溯搜索树 并 返回从begin 到 end的所有路径解
    void dfs( unordered_map<string, vector<string>> &souTree, vector<string> &track, string curWord, string endWord,  vector<vector<string>> &ans){

        // 结束条件
        if(curWord == endWord) {
            ans.push_back(track);
            return ;
        }
        if(!souTree.count(curWord)) return;

        for(string s: souTree[curWord]){
            // 剪枝
            track.push_back(s);
            // 深搜
            dfs(souTree, track, s, endWord, ans);
            // 状态重置
            track.pop_back();
        }
        

    }
    // 辅助函数--寻找当前string的所有邻域单词
    /**
     * @Description: 
     * @Param: 
     * @Return: 注意：①返回当前string的所有邻域单词 ②在里面 传入？去除同一层的单词 不要连接起来树。
     * @Notes: 
     */
    void findCurNeibor(string cur, vector<string> &neiborWord, unordered_set<string> &wordList){
        
        //26 字母只要有一个相等 且 在wordlist中就算是邻域单词
        for( char ch = 'a'; ch <= 'z' ; ch++ ){
            for(int i = 0; i<cur.size() ;++i){
                string temp = cur;
                if(ch != cur[i]){
                    cur[i] = ch;
                    if(wordList.count(cur)) { neiborWord.push_back(cur); } //存在 
                    cur = temp;//还原
                }
            }
        }

    }

};

/**
 * @Description: 双向BFS + 回溯解题思路.
 * @Param: 
 * @Return: 
 * @Notes: 
 */ 
class Solution1 {
public:

    /**
     * @Description: 
     * @Param: 
     * @Return: 
     * @Notes: 
     */
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        //开始  双向BFS + 回溯法
        vector<vector<string>> ans;
        unordered_set<string> dict(wordList.begin(), wordList.end());

        if(!dict.count(endWord)){
            return ans;
        }

        dict.erase(beginWord);
        dict.erase(endWord);
        unordered_set<string> q1{beginWord}, q2{endWord};
        unordered_map<string, vector<string>> next;
        bool reversed = false, found = false;
        while(!q1.empty()){
            unordered_set<string> q; //当前值 下一个邻域需要广搜的。
            for(const auto &w:q1){
                string s = w;
                for(size_t i = 0; i<s.size() ; i++){
                    char ch = s[i];
                    for(int j = 0;j<26;j++){ // 当前位置寻找邻域
                        s[i] = j + 'a';
                        if(q2.count(s)){  // 相交了 —— 返回！  【这里是关键 —— 蕴含着 相交 + 如何加入到next中去】
                            reversed? next[s].push_back(w) : next[w].push_back(s);
                            found = true;
                        }
                        if(dict.count(s)){// 找到邻域
                            reversed ? next[s].push_back(w) : next[w].push_back(s);
                            q.insert(s);
                        }
                    }
                    //还原回去
                    s[i] = ch;
                }
            }
            if(found){
                break;
            }
            for(const auto &w : q){
                dict.erase(w);  //【新颖——防止重复访问。】
            }
            // 接来来下一层遍历， 取最小的一边双向BFS搜索
            if(q.size() <= q2.size()){
                q1 = q; // 照常
            }else{
                // 互换
                reversed = !reversed;
                q1 = q2;
                q2 = q;
            }
        }
        if(found) {
            vector<string> track = {beginWord};
            backtracking(beginWord, endWord, next, track, ans);
        }
        return ans;
    }


    // 辅助函数 —— 回溯搜索树 并 返回从begin 到 end的所有路径解
    void backtracking( string curWord, string endWord, unordered_map<string, vector<string>> &souTree, vector<string> &track,  vector<vector<string>> &ans){

        // 结束条件
        if(curWord == endWord) {
            ans.push_back(track);
            return ;
        }
        if(!souTree.count(curWord)) return;

        for(string s: souTree[curWord]){
            // 剪枝
            track.push_back(s);
            // 深搜
            backtracking(s, endWord, souTree, track, ans);
            // 状态重置
            track.pop_back();
        }
        

    }
    
};

int main()
{
    string beginWord = "hit";
    // string beginWord = "sand";
    string endWord = "cog";
    // string endWord = "acne";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    Solution so;
    Solution1 so1;
    // auto ans = so.findLadders(beginWord, endWord, wordList);
    auto ans = so1.findLadders(beginWord, endWord, wordList);
    for(auto ans0 : ans){
        cout << "[" << endl << "[";
        for(auto ans1 :ans0){
            cout << ans1 << " ," ;
        }
        cout <<"]," << endl;
    }
    cout << "]" << endl;
    system("pause");
    return 0;
}