#include <iostream.h>
#include <stdlib.h>
#include "List.h"

int minpos(list *pos)
{
	int min,el;
	list *zero_pos;
	list *el_pos;
	zero_pos=list_find(pos,0);
	min=list_retrive(pos);
	el_pos=pos->next;
	while (el_pos!=zero_pos)
	{
		el=list_retrive(el_pos);
		if (el<min)
			min=el;
		el_pos=el_pos->next;
	}
	return min;
}

int seq_num(list *l)
{
	int i=0;
	list *pos=l;
	while ((pos=list_find(pos,0))!=NULL)
		i++;
	return i;
}

list *next_seq(list *l)
{
	return (list_find(l,0))->next;
}

void main()
{
	list seq;
	list *pos;
	int num,min,el,size;
	list_init(&seq);
	pos=&seq;
	cout<<"Enter size of sequance : ";
	cin>>size;
	cout<<"Enter Sequance : "<<flush;
	for (int i=0; i<size; i++)
	{
		cin>>num;
		list_insert(&seq,pos,num);
		pos=pos->next;
	}
	if (num!=0)
		list_insert(&seq,pos,num);

	num=seq_num(&seq);
	pos=seq.next;
	min=minpos(pos);

	for (i=0; i<num-1; i++)
	{
		pos=next_seq(pos);
		el=minpos(pos);
		if (el<min)
			min=el;
	}
	pos=seq.next;
	cout<<"New Sequance : "<<endl;
	while (pos!=NULL)
	{
		if (pos->element!=min)
			cout<<" "<<pos->element;
		pos=pos->next;
	}
	cout<<endl;
} 