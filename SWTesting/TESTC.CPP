/**************************************************************************/
/* write program that build "test cases" by using test tehnicue           */
/* that called "Equivalense partition " .                                 */
/* program need receive from user names of variables,type of variables    */
/* area of using .                                                        */
/**************************************************************************/

#include <stdio.h>
#include <conio.h>
#include <string.h>
/*=============================New Types==================================*/
  union Up_Boundary
 {
  int    i_x2;                         /* upper boundary for int      */
  char   ch_x2;                        /* upper boundary for char     */
  float  f_x2;                        /* upper boundary for float     */
  double d_x2;                        /* upper boundary for double    */
  long   l_x2;                        /* upper boundary for long      */

 };
 union Down_Boundary
 {
  int    i_x1;                         /* down boundary for int        */
  char   ch_x1;                        /* down boundary for char       */
  float  f_x1;                         /* down boundary for float      */
  double d_x1;                         /* down boundary for double     */
  long   l_x1;                         /* down boundary for long       */

 };

typedef struct Var{
	int    STATUS;                       /* variable of using           */
	int    FLAG;                         /* type of parametr            */
	char   Name[255];                    /* Name of variable            */
	char   Type[20];                     /* Type of variable            */
	Up_Boundary   up;
	Down_Boundary down;
  };


enum Logic { FALSE,TRUE };

/*============================Function's Prototypes======================*/
 Var  InsertData(int *k);
 int  Find_Type(Var T);
 void PrintTestCases(Var T,int p,int x);
 void DrawTable();

/*================================Main body==============================*/
 main()
 {
   int stat = FALSE,i = FALSE,p = 0;
   Var VarIableS[20]={{0}};
 for(i=0;;i++)
  {
	VarIableS[i]=InsertData(&i);
	if((stat==TRUE)||(i==19))
	break;
  }
 for(stat=0; stat < i ; ++stat) {
   PrintTestCases(VarIableS[stat],p,stat);
   p = 1;
 }


  getch();
   return 0;

 }
/*===========================Bodyes of functions=========================*/
Var InsertData(int *k)
{
   Var T={0};
   char ch='j';
   int flag;
   T.STATUS = TRUE;
   clrscr();
   printf("\nWhoud you like insert new (%d) variable (y/n) ",*k);
   flushall();
   scanf("%c",&ch);
	if(ch == 'n'){
	 *k = 19;
	 T.STATUS = FALSE;
	 return T;
   }
   printf("Please insert :\n");
   printf("Name            :>");
   scanf("%s",&T.Name);
   printf("Type            :>");
   scanf("%s",T.Type);
   flag = Find_Type(T);
   T.FLAG = flag;

	printf("Area of using ? X1:>");
	switch(flag){
	 case 0:scanf("%s",&T.down.ch_x1);break;
	 case 1:scanf("%d",&T.down.i_x1);break;
	 case 2:scanf("%f",&T.down.f_x1);break;
	 case 3:scanf("%lf",&T.down.d_x1);break;
	 case 4:scanf("%ld",&T.down.l_x1);break;
	 default:
	  printf("Please insert right type ! \n You can insert only "
			 "char,int,float,double,long types !\a ");
	 break;
	}
	printf("Area of using ? X2:>");
	switch(flag){
	 case 0:scanf("%s",&T.up.ch_x2);break;
	 case 1:scanf("%d",&T.up.i_x2);break;
	 case 2:scanf("%f",&T.up.f_x2);break;
	 case 3:scanf("%lf",&T.up.d_x2);break;
	 case 4:scanf("%ld",&T.up.l_x2);break;
	 default:
	  printf("Please insert right type ! \n You can insert only"
			 "char,int,float,double,long types !\a ");
	 break;
	}
 return T;
}
/*.........................................................................*/
 int Find_Type(Var T)
 {
   int i,k=TRUE;
   char *TP[]={"char","int","float","double","long"};

   for(i=0;i<=4;i++){
	k=strcmp(TP[i],T.Type);
	if(k==FALSE)
	 return i;
  }
  return 5;
 }

/*.........................................................................*/
 void PrintTestCases(Var T,int p,int x)
 {
   int xcur,ycur = 4;

   if(x==0)	xcur=25;
   if(x==1)	xcur=45;
   if(x==2)	xcur=65;

  if(T.STATUS == FALSE)
   return;
  DrawTable();
  textcolor(WHITE);
  gotoxy(xcur,ycur++);
  cprintf("%s",T.Name);
  gotoxy(xcur,ycur++);
  cprintf("%s",T.Type);
   switch(T.FLAG){
	 case 1:{
	  gotoxy(xcur,ycur++);
	  cprintf("[%d,%d]",T.down.i_x1,T.up.i_x2);
	  gotoxy(xcur,ycur++);
	  cprintf("%d",(T.down.i_x1+T.up.i_x2)/2);
	  gotoxy(xcur,ycur++);
	  textcolor(RED);
	  cprintf("%d",T.down.i_x1-10);
	  gotoxy(xcur,ycur++);
	  cprintf("%d",T.up.i_x2+5);
	  textcolor(WHITE);
	  gotoxy(xcur,ycur++);
	  cprintf("%d",T.down.i_x1+1);
	  gotoxy(xcur,ycur++);
	  cprintf("%d",T.up.i_x2-1);
	 break;
	 }
	 case 0:{
	  gotoxy(xcur,ycur++);
	  cprintf("[%c,%c]",T.down.ch_x1,T.up.ch_x2);
	  gotoxy(xcur,ycur++);
	  cprintf("%c",(T.down.ch_x1+T.up.ch_x2)/2);
	  gotoxy(xcur,ycur++);
	  textcolor(RED);
	  cprintf("%c",T.down.ch_x1-1);
	  gotoxy(xcur,ycur++);
	  for(int h=T.up.ch_x2+1;h<=T.up.ch_x2+4;h++)
	  cprintf("%c",h);
	  textcolor(WHITE);
	  gotoxy(xcur,ycur++);
	  for(h=T.down.ch_x1+1;h<=T.down.ch_x1+4;h++)
	  cprintf("%c",h);
	  gotoxy(xcur,ycur++);
	  cprintf("%c",T.up.ch_x2-1);
	 break;
	 }
	 case 2:
	 {
	  gotoxy(xcur,ycur++);
	  cprintf("[%.2f,%.2f]",T.down.f_x1,T.up.f_x2);
	  gotoxy(xcur,ycur++);
	  cprintf("%.2f  ",(T.down.f_x1+T.up.f_x2)/2);
	  gotoxy(xcur,ycur++);
	  textcolor(RED);
	  cprintf("%.2f",T.down.f_x1-10);
	  gotoxy(xcur,ycur++);
	  cprintf("%.2f",T.up.f_x2+5);
	  textcolor(WHITE);
	  gotoxy(xcur,ycur++);
	  cprintf("%.2f",T.down.f_x1+1);
	  gotoxy(xcur,ycur++);
	  cprintf("%.2f",T.up.f_x2-1);
	 break;

	 }
	 case 3:
	  {
	  gotoxy(xcur,ycur++);
	  cprintf("[%.2lf,%.2lf]",T.down.d_x1,T.up.d_x2);
	  gotoxy(xcur,ycur++);
	  cprintf("%.2lf  ",(T.down.d_x1+T.up.d_x2)/2);
	  gotoxy(xcur,ycur++);
	  textcolor(RED);
	  cprintf("%.2lf",T.down.d_x1-10);
	  gotoxy(xcur,ycur++);
	  cprintf("%.2lf",T.up.d_x2+5);
	  gotoxy(xcur,ycur++);
	  textcolor(WHITE);
	  cprintf("%.2lf",T.down.d_x1+1);
	  gotoxy(xcur,ycur++);
	  cprintf("%.2lf",T.up.d_x2-1);
	  break;
	  }
	 case 4:
	  {
	  gotoxy(xcur,ycur++);
	  cprintf("[%ld,%ld]",T.down.l_x1,T.up.l_x2);
	  gotoxy(xcur,ycur++);
	  cprintf("%ld  ",(T.down.l_x1+T.up.l_x2)/2);
	  gotoxy(xcur,ycur++);
	  textcolor(RED);
	  cprintf("%ld",T.down.l_x1-10);
	  gotoxy(xcur,ycur++);
	  cprintf("%ld",T.up.l_x2+5);
	  gotoxy(xcur,ycur++);
	  textcolor(WHITE);
	  cprintf("%ld",T.down.l_x1+1);
	  gotoxy(xcur,ycur++);
	  cprintf("%ld",T.up.l_x2-1);
	   break;

	   }
	 default:
	 cprintf("Please insert right type ! \n You can insert only"
			 "char,int,float,double,long types !\a ");
	 break;
	}
 }
/*.........................................................................*/
 void DrawTable()
 {
   char *str[]={"Name","Type","Using Area","Value ?",
				"Value < X1","Value > X2","Value->X1",
				"Value->X2"};

  gotoxy(5,1); textcolor(WHITE);
  cprintf("                        Test cases of defined variables.");
  textcolor(BLUE); gotoxy(2,2);
  cprintf("               ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄" );
	for(int i = 0; i <= 7 ; i++){
	gotoxy(2,i+4);textcolor(YELLOW);
	cprintf("%s",str[i]);
	textcolor(BLUE);gotoxy(20,i+4);
	cprintf("▄");
	}
   gotoxy(2,i+5);
   cprintf("              ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄" );

  }
/*.........................................................................*/