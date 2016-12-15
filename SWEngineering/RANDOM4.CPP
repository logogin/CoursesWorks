
// Problem 4.
// Write a computer program simulating the toss of a fair die with
// outcomes 1,2,3,4,5,6.
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void main ()
{
 clrscr();
 randomize();
 printf("Simulating the toss of fair... %d",random(6)+1);
 getch();
}