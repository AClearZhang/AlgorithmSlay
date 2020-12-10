/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\Test.cpp
 * @Author              : AClearZhang
 * @Date                : 2020-12-10 15:45:57
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2020-12-10 20:11:57
 * @Version             : 1.0
 * @Description         : c++语法测试
 */


#include <iostream>
#include <windows.h>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;



//C++返回多个值
//有四种方法
//1.在函数内部用静态数组，最后返回数组地址
//2.在函数内部用指针的形式声明一个数组，最后返回一个指针首地址即可
//3.在主函数中声明指针数组，然后作为参数进行计算即可，最终会改变数值
//4.直接声明普通数组，传入数组的首地址，形参使用指针改变数值

//1.在函数内部用静态数组，最后返回数组地址
int * get_more_param_0(){
    int len = 4;
    static int a[4];
    cout<<"-----------------------------------"<<endl;
    for(int i=0;i<len;i++){
        a[i] = i*10;
        cout<<"地址："<<(a+i)<<"  数值"<<a[i]<<endl;
    }
    cout<<"-----------------------------------"<<endl;
    return a;
}

//2.在函数内部用指针的形式声明一个数组，最后返回一个指针首地址即可
int * get_more_param_1(){
    int len = 4;
    int * a = new int[len];
    cout<<"-----------------------------------"<<endl;
    for(int i=0;i<len;i++){
        a[i] = i*10;
        cout<<"地址："<<(a+i)<<"  数值："<<a[i]<<endl;
    }
    cout<<"-----------------------------------"<<endl;
    return a;
}

//3.在主函数中声明指针数组，然后作为参数进行计算即可，最终会改变数值
void get_more_param_2(int * b, int start,int end){
    int len = 4;
    cout<<"-----------------------------------"<<endl;
    for(int i=0;i<len;i++){
        b[i] = i*10;
        cout<<"地址："<<(b+i)<<"  数值："<<b[i]<<endl;
    }
    cout<<"-----------------------------------"<<endl;
}

//4：直接声明普通数组，传入地址，形参使用指针改变数值
void get_more_param_3(int * b, int start,int end){
    int len = 4;
    cout<<"-----------------------------------"<<endl;
    for(int i=0;i<len;i++){
        b[i] = i*10;
        cout<<"地址："<<(b+i)<<"  数值："<<b[i]<<endl;
    }
    cout<<"-----------------------------------"<<endl;
}

int main(){
    int a = 4;
    int b = 3;
    float c = a / b ;
    cout << "Now Test caculate Values." << endl;
    cout << "c is :" << c << endl;
    cout << "float(a) / b is:" << float(a)/b << endl; 
    cout << "(float)a / b is:" << (float)a/b << endl; 
    printf("a/b:%.1f", a/b);
    
    cout << endl << endl << "Now Test return array Numbers" << endl;
    //内部声明普通数组
    cout<<"方法1：内部声明静态数组"<<endl;
    int * p = get_more_param_0();
    for(int i=0;i<4;i++){
        cout<<"地址："<<(p+i)<<"   数值："<<p[i]<<endl;
    }
    cout<<"-----------------------------------"<<endl;
    cout<<endl;

    //内部函数声明指针数组
    cout<<"方法2：内部函数声明指针数组"<<endl;
    int * p1 = get_more_param_1();    
    for(int i=0;i<4;i++){
        cout<<"地址："<<(p1+i)<<"   数值："<<p1[i]<<endl;
    }
    cout<<"-----------------------------------"<<endl;
    cout<<endl;

    //直接声明指针数组，作为参数改变数组
    cout<<"方法3：直接声明指针数组，作为参数改变数组"<<endl;
    int * p2 = new int[4];
    get_more_param_2(p2,0,4);    
    for(int i=0;i<4;i++){
        cout<<"地址："<<(p2+i)<<"   数值："<<p2[i]<<endl;
    }
    cout<<"-----------------------------------"<<endl;
    cout<<endl;

   //直接声明普通数组，传入地址，形参使用指针改变数值
    cout<<"方法4：直接声明普通数组，传入地址，形参使用指针改变数值"<<endl;
    int arr[4] = {0,0,0,0};
    get_more_param_3(arr,0,4);    
    for(int i=0;i<4;i++){
        cout<<"地址："<<(arr+i)<<"   数值："<<arr[i]<<endl;
    }
    cout<<"-----------------------------------"<<endl;
    cout<<endl;



    system("pause");
    return 0;
}

