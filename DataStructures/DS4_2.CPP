#include <iostream.h>
#include <stdlib.h>
#include <time.h>
#include "List.h"

void main()
{
	unsigned char n;
	bool flag;
	list children;
	list *pos=&children;
	int children_num;
	srand((unsigned)time(NULL));
	cout <<"Enter number of children : ";
	cin >>children_num;
	list_init(&children);
	cout<<"Children Indeces : "<<endl;
	for (int i=0; i<children_num; i++)
	{
		flag=false;
		while (!flag)
		{
			n=rand()%40;
			if (list_find(&children,n)==NULL)
				flag=true;
		}
		cout<<" "<<(int)n;
		list_insert(&children,pos,n);
		pos=pos->next;
	}
	cout<<endl;
	pos=&children;
	while (children.elements_num!=1)
	{
		for (i=0; i<6; i++)
		{
			if (pos->next!=NULL)
				pos=pos->next;
			else
				pos=children.next;
		}
		if (pos->next==NULL)
			pos->next=children.next;
		list *temp=pos->next->next;
		if (temp==NULL)
			temp=children.next;
		pos->next=temp;
		children.elements_num--;
	}
	cout<<"Last Child : "<<pos->next->element<<endl;
}