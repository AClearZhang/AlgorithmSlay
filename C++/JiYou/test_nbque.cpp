#include "init.h"
#include "Queue.h"
#include <iostream>
using namespace std;
int main()
{
	//int x;
	SqQueue sq;
	initQueue(sq);
	EnQueue(sq,1);
	EnQueue(sq,2);
	EnQueue(sq,3);
	EnQueue(sq,4);
	EnQueue(sq,5);
	EnQueue(sq,6);
	//if(DeQueue(sq,x)==1)  cout<<x<<endl;//1 出队
	EnQueue(sq,7);
	EnQueue(sq,8);
	EnQueue(sq,9);
	EnQueue(sq,10);
	displayQueue(sq);
	getchar();
	return 0;
}
