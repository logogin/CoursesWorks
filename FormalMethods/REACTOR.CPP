#include <conio.h>
#include <stdio.h>
#include <dos.h>
#include <string.h>
#include <stdlib.h>
#include <bios.h>
#include "mouse.h"

#define open 1
#define close 0
#define max_personnel 255
#define switched_off 0
#define powered_up 1
#define discharge 2
#define full_activation 3

typedef unsigned char byte;
typedef unsigned int word;

char *status[4]={" Switched Off    ",
		 " Power Up        ",
		 " Discharge       ",
		 " Fully Activated "};
char *rooms[4]={" Room #1      ",
		" Room #2      ",
		" Room #3      ",
		" Control Room "};
char *doors[2]={"Locked","Open  "};
char *personnel[2]={" Add Personnel  ",
		   " Move Personnel "};

byte rooms_status[5];
char doors_status[4]={open,open,open,open};
byte _status=switched_off;

void printxy(char *st,byte x,byte y,byte color,byte background,byte blink)
 {
  byte far *con;
  byte attrib_byte=0;
  con=(byte far *)MK_FP(0xB800,0);
  if (blink)
   attrib_byte+=128;
  attrib_byte+=(background << 4);
  attrib_byte+=color;
  x%=80;
  y%=25;
  for (int i=0; i<strlen(st); i++)
   {
    con[160*y+(x+i)*2]=st[i];
    con[160*y+(x+i)*2+1]=attrib_byte;
   }
 }

void frame(byte x1,byte y1,byte x2,byte y2)
 {
  for (int i=x1+1; i<x2; i++)
   {
    printxy("Í",i,y1,7,0,0);
    printxy("Í",i,y2,7,0,0);
   }
  for (i=y1+1; i<y2; i++)
   {
    printxy("º",x1,i,7,0,0);
    printxy("º",x2,i,7,0,0);
   }
  printxy("É",x1,y1,7,0,0);
  printxy("»",x2,y1,7,0,0);
  printxy("¼",x2,y2,7,0,0);
  printxy("È",x1,y2,7,0,0);
 }

void invert_item (byte x,byte y,byte current,byte backward,char *items[])
 {
  printxy(items[backward],x+2,y+2+backward,7,0,0);
  printxy(items[current],x+2,y+2+current,0,7,0);
 }

void clear_screen(byte x1,byte y1,byte x2,byte y2)
 {
  for (int i=0; i<=x2-x1; i++)
   for (int j=0; j<=y2-y1; j++)
    printxy(" ",x1+i,y1+j,0,0,0);
 }

byte menu(byte x,byte y,char *title,byte items_number,char *items[])
 {
  int max_len=strlen(title);
  int key=0;
  for (int i=0; i<items_number; i++)
   if (strlen(items[i])>max_len)
    max_len=strlen(items[i]);
  frame(x,y,x+max_len+3,y+items_number+3);
  printxy(title,x+(max_len+2)/2-strlen(title)/2+1,y,15,0,0);
  printxy(items[0],x+2,y+2,0,7,0);
  for (i=1; i<items_number;i++)
   printxy(items[i],x+2,y+2+i,7,0,0);
  byte result=0;
  while (key!=13&&key!=27)
   {
    if (kbhit())
     {
      key=getch();
      switch (key)
       {
	case 72: if (!result)
		  {
		   result=items_number-1;
		   invert_item(x,y,items_number-1,0,items);
		  }
		 else
		  {
		   result--;
		   invert_item(x,y,result,result+1,items);
		  } break;
	case 80: if (result==items_number-1)
		  {
		   result=0;
		   invert_item(x,y,0,items_number-1,items);
		  }
		 else
		  {
		   result++;
		   invert_item(x,y,result,result-1,items);
		  } break;

       }
     }
    else
     {
      read_mouse();
      if (handle.x>x+2&&(handle.x<(x+strlen(items[0])+2))&&handle.left_button)
       {
	while (handle.left_button)
	 read_mouse();
	for (i=0; i<items_number; i++)
	 if (handle.y==(y+2+i))
	  {
	   invert_item(x,y,result,i,items);
	   result=i;
	   key=13;
	  }
       }
      if (handle.y==24&&handle.x>0&&handle.x<10&&handle.left_button)
       {
	while (handle.left_button)
	 read_mouse();
	key=27;
       }
     }
   }
  if (key==27)
   return 0;
  else return result+1;
 }

void print_doors()
 {
  for (int i=0; i<4; i++)
   printxy(doors[doors_status[i]],70,13+i,15,0,0);
 }

void print_personnel()
 {
  char st[4];
  for (int i=0; i<4; i++)
   {
    itoa(rooms_status[i],st,10);
    printxy("   ",22,4+i,0,0,0);
    printxy(st,25-strlen(st),4+i,15,0,0);
   }
  itoa(rooms_status[4],st,10);
  printxy("   ",22,9,0,0,0);
  printxy(st,25-strlen(st),9,15,0,0);
 }

void show_status(byte backward)
 {
  printxy(status[backward],59,4+backward,7,0,0);
  printxy(status[_status],59,4+_status,0,7,0);
 }

void print_menu_bar()
 {
  for (int i=0; i<11; i++)
   printxy(" ",i,24,0,0,0);
  printxy("F1",1,24,15,0,0);
  printxy(" Help",3,24,7,0,0);
  printxy("F2",12,24,15,0,0);
  printxy(" Status",14,24,7,0,0);
  printxy("F3",25,24,15,0,0);
  printxy(" Personnel",27,24,7,0,0);
  printxy("F10",41,24,15,0,0);
  printxy(" Quit",44,24,7,0,0);
 }

void print_cancel()
 {
  for (int i=0; i<49; i++)
   printxy(" ",i,24,0,0,0);
  printxy("Esc",1,24,15,0,0);
  printxy(" Cancel",4,24,7,0,0);
 }

void init()
 {
  init_mouse();
  if (!handle.status)
   {
    printf("Cannot find mouse driver!!!");
    getch();
    exit(1);
   }
  cursor_hide();
  show_mouse();
  frame(0,0,79,23);
  frame(57,2,77,9);
  printxy(" Status ",63,2,15,0,0);
  for (int i=0; i<4; i++)
   printxy(status[i],59,4+i,7,0,0);
  show_status(0);
  frame(52,11,77,18);
  printxy(" Doors ",61,11,15,0,0);
  for (i=0; i<4; i++)
   {
    printxy(rooms[i],54,13+i,7,0,0);
    printxy(": ",68,13+i,7,0,0);
   }
  print_doors();
  frame(2,2,27,11);
  printxy(" Personnel ",10,2,15,0,0);
  for (i=0; i<4; i++)
   {
    printxy(rooms[i],4,4+i,7,0,0);
    printxy(":",18,4+i,7,0,0);
   }
  printxy("Total",5,9,7,0,0);
  printxy(":",18,9,7,0,0);
  print_personnel();
  for (i=1; i<79; i++)
   printxy("Ä",i,20,7,0,0);
  printxy("Ç",0,20,7,0,0);
  printxy("¶",79,20,7,0,0);
  printxy(" Messages ",35,20,15,0,0);
  print_menu_bar();
 }

void clear_mes_box()
 {
  for (int i=0; i<70; i++)
   printxy(" ",i+1,21,0,0,0);
 }

byte read_personnel(byte max_capacity)
 {
  int _personnel=0,i=0,flag=0;
  char ch=0;
  frame(2,13,49,17);
  clear_mes_box();
  printxy(" Add/Move Personnel ",16,13,15,0,0);
  gotoxy(5,16);
  textcolor(7);
  cprintf("Enter the number of personnel (%d max): ",max_capacity);
  while (ch!=27&&ch!=13&&!flag&&i<3)
   {
    ch=getch();
    if (ch>='0' && ch<='9')
     {
      i++;
      _personnel*=10;
      _personnel+=ch-0x30;
      putch(ch);
     }
    if (_personnel>max_capacity)
      flag=1;
   }
  cursor_hide();
  if (flag)
   {
    printxy("Add/Move Personnel: Exided number of personnel!!!",2,21,7,0,0);
    return 0;
   }
  else return _personnel;
 }
void add_personnel()
 {
  byte result;
  byte new_personnel;
  clear_mes_box();
  if (rooms_status[4]<max_personnel)
   {
    result=menu(30,2," To: ",4,rooms);
    clear_screen(30,2,47,9);
    if (result)
     {
      if (doors_status[result-1])
       {
	new_personnel=read_personnel(max_personnel-rooms_status[4]);
	clear_screen(2,13,49,17);
	rooms_status[result-1]+=new_personnel;
	rooms_status[4]+=new_personnel;
	print_personnel();
       }
      else printxy("Add Personnel: Doors to this room are locked!!!",2,21,7,0,0);
     }
   }
  else printxy("Add Personnel: Not enough free space!!!",2,21,7,0,0);
 }

void move_personnel()
 {
  byte from,to,_personnel;
  from=menu(30,2," From: ",4,rooms);
  clear_screen(30,2,47,9);
  clear_mes_box();
  if (from)
   {
    if (rooms_status[from-1])
     {
      _personnel=read_personnel(rooms_status[from-1]);
      clear_screen(2,13,49,17);
      if (_personnel)
       {
	to=menu(30,2," To: ",4,rooms);
	clear_screen(30,2,47,9);
	if (to)
	 {
	  if (doors_status[to-1])
	   {
	    rooms_status[from-1]-=_personnel;
	    rooms_status[to-1]+=_personnel;
	    print_personnel();
	   }
	  else printxy("Move Personnel: Doors are locked!!!",2,21,7,0,0);
	 }
       }
     }
    else printxy("Move Personnel: There is no personnel in the room!!!",2,21,7,0,0);
   }
 }

void help()
 {
  char ch=0,flag=0;
  frame(2,12,49,19);
  printxy(" Help ",23,12,7,0,0);
  print_cancel();
  printxy(" F1",3,14,15,0,0);
  printxy("  : This window.",6,14,7,0,0);
  printxy(" F2",3,15,15,0,0);
  printxy("  : Changing status of the reactor.",6,15,7,0,0);
  printxy(" F3",3,16,15,0,0);
  printxy("  : Add/Move personnel.",6,16,7,0,0);
  printxy(" Esc",3,17,15,0,0);
  printxy(" : Cancel from any window.",7,17,7,0,0);
  while (ch!=27)
   {
    while (!kbhit()&&!flag)
     {
      read_mouse();
      if (handle.y==24&&handle.x>0&&handle.x<10&&handle.left_button)
       {
	while (handle.left_button)
	 read_mouse();
	flag=1;
       }
     }
    if (!flag) ch=getch();
    else ch=27;
   }
  print_menu_bar();
  clear_screen(2,12,49,19);
 }

void change_status()
 {
  clear_mes_box();
  if (_status==full_activation)
   {
    _status=switched_off;
    show_status(full_activation);
    for (int i=0; i<3; i++)
     doors_status[i]=open;
    print_doors();
   }
  else
    if (!rooms_status[_status])
     {
      _status++;
      show_status(_status-1);
      doors_status[_status-1]=close;
      print_doors();
     }
    else printxy("Changing Status: You must remove personnel firstly!!!",2,21,7,0,0);
 }

void main ()
 {
  clrscr();
  init();
  cursor_hide();
  byte result;
  int key=0,flag=0;

  do
   {
    while ((bioskey(1)==0)&&!flag)
     {
      read_mouse();
      if (handle.y==24&&handle.x>0&&handle.x<8&&handle.left_button)
       {
	while (handle.left_button)
	 read_mouse();
	help();
       }
      if (handle.y==24&&handle.x>11&&handle.x<21&&handle.left_button)
       {
	while (handle.left_button)
	 read_mouse();
	change_status();
       }
      if (handle.y==24&&handle.x>40&&handle.x<49&&handle.left_button)
       {
	while (handle.left_button)
	 read_mouse();
	flag=1;
       }
      if (handle.y==24&&handle.x>24&&handle.x<37&&handle.left_button)
       {
	while (handle.left_button)
	 read_mouse();
	print_cancel();
	result=menu(30,2," Personnel ",2,personnel);
	clear_screen(30,2,49,7);
	switch (result)
	 {
	  case 1: add_personnel(); break;
	  case 2: move_personnel(); break;
	 }
	print_menu_bar();
       }
     }
    if (!flag)
     key=bioskey(0)>>8;
    else key=68;
    switch (key)
     {
      case 59: help(); break;
      case 60: change_status(); break;
      case 61:
       print_cancel();
       result=menu(30,2," Personnel ",2,personnel);
       clear_screen(30,2,49,7);
       switch (result)
	{
	 case 1: add_personnel(); break;
	 case 2: move_personnel(); break;
	}
       print_menu_bar();
      break;
     }
   }
  while (key!=68);
  hide_mouse();
 }