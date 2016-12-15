#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
struct stack
 {
  int sp;
  int *items;
  int size;
 };

typedef struct stack STACK;

void init_stack(STACK *st,const int ssize)
 {
  st->items=(int *)malloc(ssize*sizeof(int));
  if (st->items==NULL)
   {
    printf("Cannot alocate memory (items) !!! \n");
    getch();
    exit(1);
   }

  st->size=ssize;
  st->sp=0;
 }

void pop_stack(STACK *const st, int *to)
 {
   *to=st->items[st->sp-1];
   st->items[st->sp-1]=0;
   st->sp--;
 }

void push_stack(STACK *const st,const int element)
 {
   st->items[st->sp]=element;
   st->sp++;
 }

void delete_stack(STACK *st)
 {
  free(st->items);
 }

void test_stack(STACK *st, int *element)
 {
  *element=st->items[st->sp-1];
 }