
#ifndef List_H
#define List_H

#include <assert.h>

typedef struct list
{
	int element;
	unsigned char elements_num;
	struct list *next;
} list;

void list_init(list *l)
{
	l->next=NULL;
	l->element=0;
	l->elements_num=0;
}

void list_insert(list *l,list *pos,const int el)
{
	list *temp;
	temp=new list;
	assert(temp!=NULL);
	temp->element=el;
	temp->next=pos->next;
	pos->next=temp;
	l->elements_num++;
}

unsigned int list_retrive(const list *pos)
{
	return pos->element;
}

list *list_find(const list *l,const int el)
{
	list *pos=l->next;
	bool flag=false;
	while ((pos!=NULL)&&!flag)
	{
		if (pos->element!=el)
			pos=pos->next;
		else
			flag=true;
	}
	return pos;
}

list list_copy(list *l)
{
	list copy;
	list *copy_pos,*list_pos;
	list_pos=l;
	copy_pos=&copy;
	while (list_pos!=NULL)
	{
		copy_pos->element=list_pos->element;
		copy_pos->elements_num=list_pos->elements_num;
		copy_pos->next=NULL;
		if (list_pos->next!=NULL)
			copy_pos->next=new list;
		list_pos=list_pos->next;
		copy_pos=copy_pos->next;
	}
	return copy;
}

#endif List_H