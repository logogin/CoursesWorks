#include <time.h>
#include <stdlib.h>
#include "Queue.h"
void main()
{
	queue q;
	int size;
	int num;
	cout<<"Enter size of Queue : ";
	cin>>size;
	queue_init(q,size,size);
	srand((unsigned)time(NULL));
	for (int i=0; i<size; i++)
	{
		num=rand()%101;
		if (num<=50)
			enqueue(q,num,1);
		else
			enqueue(q,num,2);
	}
	cout<<"First Queue : "<<endl;
	queue_print(q,1);
	cout<<endl;
	cout<<"Second Queue : "<<endl;
	queue_print(q,2);
	cout<<endl;
	queue_delete(q);
}