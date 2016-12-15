#include <iostream.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "List.h"

list summation(list &l1,list &l2)
{
	list sum;
	list *pos1,*pos2;
	list_init(&sum);
	
	int el1,el2,remainder=0;
	
	if (l1.elements_num>l2.elements_num)
	{
		sum=list_copy(&l1);
		pos1=sum.next;
		pos2=l2.next;
	}
	else
	{
		sum=list_copy(&l2);
		pos1=sum.next;
		pos2=l1.next;
	}
	while (pos1!=NULL)
	{
		el2=0;
		pos1->element+=remainder;
		el1=pos1->element;
		if (pos2!=NULL)
			el2=pos2->element;
		pos1->element=(el1+el2)%10;
		remainder=(el1+el2)/10;
		if ((pos1->next==NULL)&&remainder)
			pos1->next=new list;
		pos1=pos1->next;
		if (pos2!=NULL)
			pos2=pos2->next;
	}
	return sum;
}

list multi(list &l1,list &l2)
{
	list mul;
	list *pos1,*pos2;
	list digit;
	list *digit_pos;
	list temp;
	list *temp_pos;
	int num1,num2,remainder=0;

	list_init(&digit);
	list_init(&mul);
	list_init(&temp);
	digit_pos=&digit;
	
	pos2=l2.next;

	while (pos2!=NULL)
	{
		temp.elements_num=0;
		temp_pos=&temp;
		bool flag=true;
		num2=list_retrive(pos2);
		pos1=l1.next;
		while (flag)
		{
			num1=0;
			if (pos1!=NULL)
			{
				num1=list_retrive(pos1);
				pos1=pos1->next;
			}
			list_insert(&temp,temp_pos,(num1*num2+remainder)%10);
			temp_pos=temp_pos->next;
			temp_pos->next=NULL;
			remainder=(remainder+num1*num2)/10;
			if (!remainder&&pos1==NULL)
				flag=false;
		}
		digit_pos->next=temp.next;
		digit.elements_num+=temp.elements_num;
		mul=summation(mul,digit);
		list_insert(&digit,digit_pos,0);
		digit.elements_num-=temp.elements_num;
		digit_pos=digit_pos->next;
		pos2=pos2->next;
	}
	return mul;
}

void print_number(const list *l)
{
	if (l->next!=NULL)
		print_number(l->next);
	cout<<(int)l->element<<flush;
}

void main()
{
	list a,b,sum,mul;
	list *pos1,*pos2;
	char num1[80];
	char num2[80];

	list_init(&a);
	list_init(&b);
	pos1=&a;
	pos2=&b;
	cout<<"Enter first number : ";
	cin>>num1;
	cout<<"Enter second number : ";
	cin>>num2;
	for (int i=strlen(num1)-1; i>=0; i--)
		if (isdigit(num1[i]))
		{
			list_insert(&a,pos1,(int)(num1[i]-0x30));
			pos1=pos1->next;
		}
		else
		{
			cerr<<"Error in number!!!"<<endl;
			exit(0);
		}
	
	for (i=strlen(num2)-1; i>=0; i--)
		if (isdigit(num2[i]))
		{
			list_insert(&b,pos2,(int)(num2[i]-0x30));
			pos2=pos2->next;
		}
		else
		{
			cerr<<"Error in number!!!"<<endl;
			exit(0);
		}

	sum=summation(a,b);
	cout <<"The sum is : ";
	print_number(sum.next);
	cout<<endl;
	mul=multi(a,b);
	cout<<"Multiplication is : ";
	print_number(mul.next);
	cout<<endl;
}
