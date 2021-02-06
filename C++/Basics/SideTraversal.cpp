/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\Basics\SideTraversal.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-02-06 11:57:33
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-02-06 15:53:31
 * @Version             : 1.0
 * @Description         : 二维数组的 倾斜遍历/ 侧遍历
 */
#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

int main()
{
    vector<vector<int>> vec = {{1, 2, 3}, {4, 5, 6}, {8, 5, 9}, {22, 7, 3}, {6, 7, 1}};
    int k, m = 5; // m行5  n列3

    //   for(int i=0;i<m;i++)
    //   {//有m行
    //     vector<int> vv;//注意定义的位置,不能在for循环外
    //     while(cin>>k)
    //     {
    //        vv.push_back(k);
    //        if(cin.get()=='\n')
    //           break;
    //     }
    //     vec.push_back(vv);
    //   }

    int n = vec[0].size(); //列
    //测试用
    // for(int ii=0;ii<m;ii++)
    // {
    //     for(int jj=0;jj<n;jj++)
    //     cout<<vec[ii][jj]<<" ";
    //     cout<<endl;
    // }

    /**
     * @Description: 左到右  上到下；左上角
     * @param {*}
     * @return {*}
     * @notes: 
     */
    int i, j;                                 //遍历时的行和列
    for (int num = 0; num < m + n - 1; num++) //num是遍历的次数
    {
        for (i = 0; i < m; i++)    // not num ,it is m
        {
            j = num - i;
            if (j >= 0 && j < n){
                cout << vec[i][j] << " ";
            }
        }
        cout << endl;
    }
     /**
     * @Description: 右下角： 下到上 右到左
     * @param {*}
     * @return {*}
     * @notes: 
     */
    cout << "****************************" << endl;
    int iii, jjj;                                 //遍历时的行和列
    for (int num = m+n-2; num >= 0; num--) //num是遍历的次数
    {
        for (iii = 0; iii < m; iii++)
        {
            jjj =num-iii;
            if (jjj >= 0 && jjj < n){
                cout << vec[iii][jjj] << " ";
            }
        }
        cout << endl;
    }

    
     /**
     * @Description: 左下角：左到右  下到上
     * @param {*}
     * @return {*}
     * @notes: 
     */
    cout << "****************************" << endl;
    int iiii, jjjj;                                 //遍历时的行和列
    for (int num = m+n-2; num >= 0; num--) //num是遍历的次数
    {
        for (iiii = 0; iiii < m; iiii++)
        {
            jjjj = n - num + iiii - 1;
            if (jjjj >= 0 && jjjj < n){
                cout << vec[iiii][jjjj] << " ";
            }
        }
        cout << endl;
    }
    /**
     * @Description: 右上角：右到左  上到下
     * @param {*}
     * @return {*}
     * @notes: 
     */
    cout << "****************************" << endl;
    int ii, jj;                                 //遍历时的行和列
    for (int num = 0; num < m + n - 1; num++) //num是遍历的次数
    {
        for (ii = 0; ii < m; ii++)
        {
            jj = n - num + ii - 1;
            if (jj >= 0 && jj < n){
                cout << vec[ii][jj] << " ";
            }
        }
        cout << endl;
    }
    
    
    system("pause");
    return 0;
}

// 输出：
// 1
// 2 4
// 3 5 8
// 6 5 22
// 9 7 6
// 3 7
// 1
// ****************************
// 3
// 2 6
// 1 5 9
// 4 5 3
// 8 7 1
// 22 7
// 6

