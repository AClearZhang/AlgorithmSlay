#include "init.h"
#include <iostream>
#include "Queue.h"
using namespace std;
void initQueue(SqQueue &qu)
{
	qu.front=qu.rear=0;//队首指针与队尾指针重合，并且指向0
}
Status EnQueue(SqQueue &qu,int x)
{
	if ((qu.rear+1)%maxSize==qu.front) return 0;//判断队满，队满不能入队
	qu.rear=(qu.rear+1)%maxSize;//若队未满，移动指针
	qu.data[qu.rear]=x;//插入元素
	return 1;
}
Status DeQueue(SqQueue &qu,int &x)
{
	if (qu.rear==qu.front) return 0;//判断队空
	qu.front=(qu.front+1)%maxSize;
	x=qu.data[qu.front];
	return 1;
}
 Status displayQueue(SqQueue &qu)
{
		int i,j;
		i=qu.rear;
		j=qu.front;
		cout<<"打印队列：";
		while(i!=j)
		{
			j=(j+1)%maxSize;
			cout<<qu.data[j]<<"  ";        
		}
		cout<<endl;
		return 0;

}
