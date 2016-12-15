#include "stack.h"
void main()
 {
  int size1;
  int size2;
  int element1;
  int element2;
  int p;
  int index;
  STACK array1;
  STACK array2;

  clrscr();
  printf("Enter size of the first array : ");
  scanf("%d",&size1);
  puts("");
  printf("Enter size of the second array : ");
  scanf("%d",&size2);
  init_stack(&array1,size1+size2);
  init_stack(&array2,size2+size1);
  puts("");
  for (int i=0; i<size1;  i++)
   {
    printf("Enter the %d element : ",i+1);
    scanf("%d",&element2);

    if (array1.sp)
     test_stack(&array1,&element1);
    index=0;
    while (array1.sp&&element2>element1)
     {
      pop_stack(&array1,&element1);
      push_stack(&array2,element1);
      if (array1.sp)
       test_stack(&array1,&element1);
      index++;
     }
     push_stack(&array1,element2);
     for (int j=0; j<index; j++)
      {
       pop_stack(&array2,&element1);
       push_stack(&array1,element1);
      }
   }
  for (i=0; i<size1; i++)
   {
    pop_stack(&array1,&p);
    push_stack(&array2,p);
    printf("%d ",p);
   }

  for (i=0; i<size1; i++)
   {
    pop_stack(&array2,&p);
    push_stack(&array1,p);
   }
  puts("");
  for (i=0; i<size2; i++)
   {
    printf("Enter the %d element : ",i+1);
    scanf("%d",&element2);
    if (array2.sp)
     test_stack(&array2,&element1);
    index=0;
    while (array2.sp&&element2>element1)
     {
      pop_stack(&array2,&element1);
      push_stack(&array1,element1);
      if (array2.sp)
       test_stack(&array2,&element1);
      index++;
     }
     push_stack(&array2,element2);
     for (int j=0; j<index; j++)
      {
       pop_stack(&array1,&element1);
       push_stack(&array2,element1);
      }
   }
  for (i=0; i<size2; i++)
   {
    pop_stack(&array2,&p);
    push_stack(&array1,p);
    printf("%d ",p);
   }

  for (i=0; i<size2; i++)
   {
    pop_stack(&array1,&p);
    push_stack(&array2,p);
   }
  puts("");
  for (i=0; i<size2; i++)
   {
    pop_stack(&array2,&element2);
    test_stack(&array1,&element1);
    index=0;
    while (array1.sp&&element2>element1)
     {
      pop_stack(&array1,&element1);
      push_stack(&array2,element1);
      if (array1.sp)
       test_stack(&array1,&element1);
      index++;
     }

     push_stack(&array1,element2);

     for (int j=0; j<index; j++)
      {
       pop_stack(&array2,&element1);
       push_stack(&array1,element1);
      }
   }
  puts("");
  for (i=0; i<size1+size2; i++)
   {
    pop_stack(&array1,&p);
    printf("%d ",p);
   }
  delete_stack(&array1);
  delete_stack(&array2);
  getch();
 }