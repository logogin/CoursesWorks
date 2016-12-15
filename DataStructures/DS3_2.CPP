#include <stdlib.h>
#include <time.h>
#include "Queue.h"

void main()
{
	queue q;
	int num;
	int n=0;
	int item;
	int chief=0;
	bool flag=true;
	bool flag1=true,flag2=true;

	srand((unsigned)time(NULL));
	queue_init(q,20,0);
	cout<<"Current Queue : "<<endl;
	for (int i=0; i<20; i++)
	{
		num=1+rand()%20;
		cout<<num<<" ";
		if (num%2)
		{
			n++;
			if (!chief)
			{
				chief=-num;
				num=-num;
			}
		}
		enqueue(q,num,1);
	}
	cout<<endl<<endl<<"Ordered Queue : "<<endl;
	while (flag)
	{
		item=dequeue(q,1);
		if (item==chief)
			enqueue(q,item,1);
		if ((item%2)&&(item!=chief))
		{
			while (queue_test(q,1)!=chief)
			{
				num=dequeue(q,1);
				enqueue(q,num,1);
			}
			enqueue(q,item,1);
		}
		if (!(item%2))
		{
			int count=1;
			enqueue(q,item,1);
			while (!(queue_test(q,1)%2))
			{
				num=dequeue(q,1);
				enqueue(q,num,1);
				count++;
			}
			if ((count+n)==20)
				flag=false;
		}
	}
	for (i=0; i<20; i++)
	{
		num=dequeue(q,1);
		if (num<0)
			num=-num;
		enqueue(q,num,1);
	}
	queue_print(q,1);
	cout<<endl;
	flag=true;
	while (flag1||flag2)
	{
		item=dequeue(q,1);
		if (item%2)
		{
			while ((queue_test(q,1)%2)&&queue_test(q,1)<item)
			{
				num=dequeue(q,1);
				enqueue(q,num,1);
			}
			enqueue(q,item,1);
		}
		else
		{
			while (!(queue_test(q,1)%2)&&queue_test(q,1)<item)
			{
				num=dequeue(q,1);
				enqueue(q,num,1);
			}
			enqueue(q,item,1);
		}
		flag1=false;
		flag2=false;
		for (i=0; i<n-1; i++)
		{
			num=dequeue(q,1);
			if (num>queue_test(q,1))
				flag1=true;
			enqueue(q,num,1);
		}
		num=dequeue(q,1);
		enqueue(q,num,1);
		for (i=0; i<20-n-1; i++)
		{
			num=dequeue(q,1);
			if ((num>queue_test(q,1)))
				flag2=true;
			enqueue(q,num,1);
		}
		num=dequeue(q,1);
		enqueue(q,num,1);
	}
	cout<<endl;
	queue_print(q,1);
	cout<<endl;
	queue_delete(q);
} 