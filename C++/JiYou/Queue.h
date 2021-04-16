#ifndef QUEUE_H
#define QUEUE_H
#define maxSize 10
#include "init.h"
typedef struct
{
	int data[maxSize];
	int front;//队首指针
	int rear;//队尾指针
} SqQueue;//顺序队类型定义

Status displayQueue(SqQueue &qu);
void initQueue(SqQueue &qu);
Status EnQueue(SqQueue &qu,int x);
Status DeQueue(SqQueue &qu,int &x);
#endif

