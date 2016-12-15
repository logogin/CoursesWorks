#include <iostream.h>
#include <stdlib.h>
#include <time.h>
#include "List.h"

void main()
{
	list l1,l2;
	int num;
	int el;
	list_init(&l1);
	list_init(&l2);
	list *pos1=&l1;
	list *pos2=&l2;
	srand((unsigned)time(NULL));
	num=10+rand()%20;
	cout <<"Number of elements : "<<num<<endl;
	cout <<"First List : "<<endl;
	for (int i=0; i<num; i++)
	{
		el=rand()%100;
		cout <<" "<<el;
		list_insert(&l1,pos1,el);
		pos1=pos1->next;
	}
	pos1=l1.next;
	cout<<endl;
	for (i=0; i<num; i++)
	{
		el=list_retrive(pos1);
		pos1=pos1->next;
		if (list_find(&l2,el)==NULL)
		{
			list_insert(&l2,pos2,el);
			pos2=pos2->next;
		}
	}
	cout <<"Second List : "<<endl;
	pos2=l2.next;
	while (pos2!=NULL)
	{
		cout<<" "<<list_retrive(pos2);
		pos2=pos2->next;
	}
	cout<<endl;
}
