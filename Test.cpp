/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\Test.cpp
 * @Author              : AClearZhang
 * @Date                : 2020-12-10 15:45:57
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-03-25 10:06:43
 * @Version             : 1.0
 * @Description         : c++语法测试
 */

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <map>

using namespace std;

//C++返回多个值
//有四种方法
//1.在函数内部用静态数组，最后返回数组地址
//2.在函数内部用指针的形式声明一个数组，最后返回一个指针首地址即可
//3.在主函数中声明指针数组，然后作为参数进行计算即可，最终会改变数值
//4.直接声明普通数组，传入数组的首地址，形参使用指针改变数值

//1.在函数内部用静态数组，最后返回数组地址
int *get_more_param_0()
{
    int len = 4;
    static int a[4];
    cout << "-----------------------------------" << endl;
    for (int i = 0; i < len; i++)
    {
        a[i] = i * 10;
        cout << "地址：" << (a + i) << "  数值" << a[i] << endl;
    }
    cout << "-----------------------------------" << endl;
    return a;
}

//2.在函数内部用指针的形式声明一个数组，最后返回一个指针首地址即可
int *get_more_param_1()
{
    int len = 4;
    int *a = new int[len];
    cout << "-----------------------------------" << endl;
    for (int i = 0; i < len; i++)
    {
        a[i] = i * 10;
        cout << "地址：" << (a + i) << "  数值：" << a[i] << endl;
    }
    cout << "-----------------------------------" << endl;
    return a;
}

//3.在主函数中声明指针数组，然后作为参数进行计算即可，最终会改变数值
void get_more_param_2(int *b, int start, int end)
{
    int len = 4;
    cout << "-----------------------------------" << endl;
    for (int i = 0; i < len; i++)
    {
        b[i] = i * 10;
        cout << "地址：" << (b + i) << "  数值：" << b[i] << endl;
    }
    cout << "-----------------------------------" << endl;
}

//4：直接声明普通数组，传入地址，形参使用指针改变数值
void get_more_param_3(int *b, int start, int end)
{
    int len = 4;
    cout << "-----------------------------------" << endl;
    for (int i = 0; i < len; i++)
    {
        b[i] = i * 10;
        cout << "地址：" << (b + i) << "  数值：" << b[i] << endl;
    }
    cout << "-----------------------------------" << endl;
}

bool comp(int a, int b)
{
    return a > b;
}
int findKthLargest1(vector<int> &nums, int k)
{
    //从大到小排序 —— 找到 k-1 个未知的数。
    int n = nums.size();
    sort(nums.begin(), nums.begin() + n, comp);
    return nums[k - 1];
}

int main()
{
    // vector<int> arr = {3,1,2,4};
    // int k = 2;
    // findKthLargest1(arr, k) ;
    // for(auto a : arr){
    //     cout << a << endl;
    // }

    /**
     * @Description: 这里进行测试 c++除法取整数和小数的问题。
     * @param {*}
     * @return {*}
     * @notes: 
     */
    int a = 4;
    int b = 3;
    float c = a / b;
    cout << "Now Test caculate Values." << endl;
    cout << "c is :" << c << endl;
    cout << "float(a) / b is:" << float(a) / b << endl;
    cout << "(float)a / b is:" << (float)a / b << endl;
    // printf("a/b:%.1f\n", a / b);
    cout << "1.0/2 = " << 1.0 / 2 << endl;
    cout << "1.0/a = " << 1.0 / a << endl;
    cout << "4/3 = " << 4/3 << endl;
    cout << "float(4)/3 = " << float(4)/3 << endl;
    cout << "ceil(float(4)/3) = " << ceil(float(4)/3) << endl;
    cout << "floor(float(4)/3) = " << floor(float(4)/3) << endl;

    for (char ch = '1'; ch <= '9'; ch++)
    {
        cout << "Now ch is:" << atoi(&ch) << endl;
    }

    cout << "测试使用 multimap:" << endl;
    multimap<int, int> m;
    m.insert(make_pair(1, 3));
    m.insert(make_pair(1, 2));
    m.insert(make_pair(1, 4));
    multimap<int, int>::iterator it;
    for (it = m.begin(); it != m.end(); it++)
    {
        cout << it->first << "--->";
        cout << it->second << endl;
    }
    //     cout << endl << endl << "Now Test return array Numbers" << endl;
    //     //内部声明普通数组
    //     cout<<"方法1：内部声明静态数组"<<endl;
    //     int * p = get_more_param_0();
    //     for(int i=0;i<4;i++){
    //         cout<<"地址："<<(p+i)<<"   数值："<<p[i]<<endl;
    //     }
    //     cout<<"-----------------------------------"<<endl;
    //     cout<<endl;

    //     //内部函数声明指针数组
    //     cout<<"方法2：内部函数声明指针数组"<<endl;
    //     int * p1 = get_more_param_1();
    //     for(int i=0;i<4;i++){
    //         cout<<"地址："<<(p1+i)<<"   数值："<<p1[i]<<endl;
    //     }
    //     cout<<"-----------------------------------"<<endl;
    //     cout<<endl;

    //     //直接声明指针数组，作为参数改变数组
    //     cout<<"方法3：直接声明指针数组，作为参数改变数组"<<endl;
    //     int * p2 = new int[4];
    //     get_more_param_2(p2,0,4);
    //     for(int i=0;i<4;i++){
    //         cout<<"地址："<<(p2+i)<<"   数值："<<p2[i]<<endl;
    //     }
    //     cout<<"-----------------------------------"<<endl;
    //     cout<<endl;

    //    //直接声明普通数组，传入地址，形参使用指针改变数值
    //     cout<<"方法4：直接声明普通数组，传入地址，形参使用指针改变数值"<<endl;
    //     int arr[4] = {0,0,0,0};
    //     get_more_param_3(arr,0,4);
    //     for(int i=0;i<4;i++){
    //         cout<<"地址："<<(arr+i)<<"   数值："<<arr[i]<<endl;
    //     }
    //     cout<<"-----------------------------------"<<endl;
    //     cout<<endl;

    system("pause");
    return 0;
}
