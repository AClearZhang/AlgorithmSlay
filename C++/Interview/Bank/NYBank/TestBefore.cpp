/*
 * @FilePath            : \AlgorithmInterview\AlgorithmSlay\C++\Interview\Bank\NYBank\TestBefore.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-09-25 20:11:46
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-09-25 21:28:40
 * @Version             : 1.0
 * @Description         : 测试相关程序
 */



#include <stdio.h>
#include <windows.h>
#include <iostream>

using namespace std;

/**
 * @Description: 测试 structure
 * @param {*}
 * @return {*}
 * @notes: 
 */


struct student{
    int num;
    char name[20];
    int score;
};


struct student stud[2] = {{1 , "li",84},{2, "zhang", 98}};


void Rev(int *x, int n){
    int t, *p, *i, *j, m = (n-1)/2;
    i = x; j = x+n-1; p = x+m;
    for ( ; i<=p ;i++, j--){
        t = *i; *i = *j; *j = t;
    }

}

int main(int argc, char const *argv[])
{
    int i, a[10] = {3, 7, 9, 11, 0, 6, 7, 5, 4, 2};
    int *p;
    Rev(a, 10);
    for (p = a; p<a+10 ; p++){
        cout << *p << endl;
    }

    cout << "now jinzhi out is:" << endl;
    int a1 = 0, b = 0;
    a1 = 021;
    b = 0x10;
    printf("a+b=%d", a1+b);

    cout << "switch case:" << endl;
    int v1 = 0, v2 = 0;
    int v3 = 0, v4 = 0;
    char ch;
    while((ch=getchar())!= '#'){
        // hello world!# 
        switch(ch){
            case 'a':
            case 'h':
            case 'o': v2++;
            default: v1++;
            
        }

        switch(ch){
            case 'a':
            case 'h':
            default: v3++;
            case 'o': v4++;  // default 都满足所以执行后序的所有语句！！！  因为没有加 break！！！！
        }
    }
    cout << "v1:" << v1 << " , v2:" << v2 << endl;
    cout << "v3:" << v3 << " , v4:" << v4 << endl;
    system("pause");
    return 0;
}



// int main(int argc, char const *argv[])
// {
//     int i, sum = 0;
//     float avg = 0;
//     for(i = 0; i < 2 ;i++){
//         sum += stud[i].score;
//     }
//     avg = sum/2;
//     printf("%2f", avg);
    
//     system("pause");
//     return 0;
// }



// int main(int argc, char const *argv[])
// {
//     char ch[2][5] = {"1234", "5678"}, (*p)[5];
//     int s = 0;
//     p = ch;
//     for(int i = 0; i < 2 ; i++){
//         for( int j = 0; *(*(p+i)+j)!='\0' ;j++){
//             s += p[i][j] - '0';
//         }
//      }
//     printf("%d\n", s);

//     cout << "now the s sum is :" << s << endl;

//     system("pause");
//     return 0;
// }



