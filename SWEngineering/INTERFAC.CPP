
// Homework 3.7. December 10,2000.
//
// Design a sample introductory screen page for the Square Root Finder
// and implement it in C.
#include <stdio.h>
#include <conio.h>
void main()
{
 clrscr();
 textattr(BLUE);
 cprintf("�");
 for (int i=2; i<80;i++)
  {
   gotoxy(i,1); cprintf("�");
   gotoxy(i,24); cprintf("�");
  }
 for (i=2;i<80; i++)
  {
   gotoxy(i,15);cprintf("�");
  }
 for (i=2; i<24;i++)
  {
   gotoxy(1,i); cprintf("�");
   gotoxy(80,i); cprintf("�");
  }
 cprintf("�");
 gotoxy(1,15); cprintf("�");
 gotoxy(80,15); cprintf("�");
 gotoxy(80,1); cprintf("�");
 gotoxy(80,24); cprintf("�");
 gotoxy(1,8); cprintf("�");
 gotoxy(80,8); cprintf("�");
 for (i=2; i<80; i++)
  {
   gotoxy(i,8); cprintf("�");
  }
 textattr(WHITE);
 gotoxy(31,1);cprintf(" Entering numbers ");
 gotoxy(36,8);cprintf(" Result ");
 gotoxy(35,15);cprintf(" Messages ");
 window(2,16,79,23);
 clrscr();
 textattr(GREEN);
 cprintf("  Hello! Nice day to find the square roots.");
 cprintf(" Press any key to continue ... ");
 getch();
}