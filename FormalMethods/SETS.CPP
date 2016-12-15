#include <stdio.h>
#include <conio.h>
int in_set(int element,int set[],int size)
 {
  int flag=0,i=0;
  while (!(flag)&&(i<size))
   {
	if (set[i]==element) flag=1;
	i++;
   }
  return flag;
 }

int union_set(int set1[],int set2[],int size1,int size2,int result[])
 {
  int size=size1;
  for (int i=0; i<size1; i++)
   result[i]=set1[i];
  for (i=0; i<size2; i++)
	if (!in_set(set2[i],set1,size1))
	 {
	  result[size]=set2[i];
	  size++;
	 }
  return size;
 }
int intersection(int set1[],int set2[],int size1, int size2, int result[])
 {
  int size=0;
  for (int i=0; i<size1; i++)
   if (in_set(set1[i],set2,size2))
	{
	 result[size]=set1[i];
	 size++;
	}
  return size;
 }

int diff_set(int set1[],int set2[],int size1,int size2,int result[])
 {
  int size=0;
  for (int i=0; i<size1; i++)
   if (!in_set(set1[i],set2,size2))
	{
	 result[size]=set1[i];
	 size++;
	}
  return size;
 }
int sym_diff(int set1[],int set2[],int size1,int size2,int result[])
 {
  int size=0;
  size=diff_set(set1,set2,size1,size2,result);
  for (int i=0; i<size2; i++)
   if (!in_set(set2[i],set1,size1))
	{
	 result[size]=set2[i];
	 size++;
	}
   return size;
 }
void order_set(int set[],int size)
 {
  int p;
  for (int i=0; i<size-1; i++)
   for (int j=i+1; j<size; j++)
	if (set[i]>set[j])
	 {
	  p=set[i];
	  set[i]=set[j];
	  set[j]=p;
	 }
 }

void print_set(int set[],int size)
 {
  if (!size)
   printf("Empty Set \n");
  else
   {
	printf("{%d",set[0]);
	for (int i=1; i<size; i++)
	 printf(",%d",set[i]);
	printf("}\n");
   }
 }
void main()
{
 int result[20];
 int size;
 int a[]={1,2,3,5,7,12,17,4};
 int b[]={2,7,5,6,9,10};
 int c[]={6,8,9};
 clrscr();
 order_set(a,8);
 order_set(b,6);
 printf("A=");
 print_set(a,8);
 printf("B=");
 print_set(b,6);
 printf("C=");
 print_set(c,3);

 printf("Union(A,B)=");
 size=union_set(a,b,8,6,result);
 order_set(result,size);
 print_set(result,size);

 printf("Intersection(A,C)=");
 size=intersection(a,c,8,3,result);
 order_set(result,size);
 print_set(result,size);

 printf("Intersection(A,B)=");
 size=intersection(a,b,8,6,result);
 order_set(result,size);
 print_set(result,size);

 printf("Difference(A,B)=");
 size=diff_set(a,b,8,6,result);
 order_set(result,size);
 print_set(result,size);

 printf("Symetric Difference(A,B)=");
 size=sym_diff(a,b,8,6,result);
 order_set(result,size);
 print_set(result,size);
 getch();
}