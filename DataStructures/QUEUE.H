
#ifndef Queue_H
#define Queue_H
#include <assert.h>
#include <iostream.h>

struct queue
{
	int *items;
	int head[2];
	int tail[2];
	int size[2];
	bool empty[2];
	bool full[2];
};

void queue_init(queue &q,int size1,int size2)
{
	q.items=new int[size1+size2];
	assert(q.items!=NULL);
	q.size[0]=size1;
	q.head[0]=0;
	q.tail[0]=0;
	q.full[0]=false;
	q.empty[0]=true;

	q.size[1]=size2+size1;
	q.head[1]=size1;
	q.tail[1]=size1;
	q.full[1]=false;
	q.empty[1]=true;
}

void enqueue(queue &q,int item,int to)
{
	q.items[q.tail[to-1]]=item;
	q.tail[to-1]++;
	q.tail[to-1]%=q.size[to-1];
	if (!q.tail[to-1])
		q.tail[to-1]+=(q.size[to-1]-q.size[0]);
	q.empty[to-1]=false;
	if (q.head[to-1]==q.tail[to-1])
		q.full[to-1]=true;
	else
		q.full[to-1]=false;
}

int dequeue(queue &q,int from)
{
	int el=q.items[q.head[from-1]];
	q.head[from-1]++;
	q.head[from-1]%=q.size[from-1];
	if (!q.head[from-1])
		q.head[from-1]+=(q.size[from-1]-q.size[0]);
	q.full[from-1]=false;
	if (q.head[from-1]==q.tail[from-1])
		q.empty[from-1]=true;
	else 
		q.empty[from-1]=false;
	return el;
}

int queue_test(queue &q,int from)
{
	return q.items[q.head[from-1]];
}

void queue_print(queue &q,int from)
{
	int i=q.head[from-1];
	do
	{
		cout<<q.items[i]<<" "<<flush;
		i++;
		i%=q.size[from-1];
		q.head[from-1]+=(q.size[from-1]-q.size[0]);
	}
	while (i!=q.tail[from-1]);
}

void queue_delete(queue &q)
{
	delete []q.items;
}

#endif Queue_H