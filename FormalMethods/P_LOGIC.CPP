#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream.h>
#include <alloc.h>

typedef unsigned char byte;
const char *operators[5]={"~","|","&","->","<->"};
char *operands;
byte *truth_table;
int pow,operands_number,file_flag;
ofstream file;
//----------Operations---------------------------------
byte not(byte st)
 {
  return !st;
 }

byte or(byte st1,byte st2)
 {
  if (st1||st2) return 1;
  else return 0;
 }
byte and(byte st1,byte st2)
 {
  if (st1&&st2) return 1;
  else return 0;
 }
byte implies(byte st1,byte st2)
 {
  if (st1&&(!st2)) return 0;
  else return 1;
 }

byte equivalence(byte st1,byte st2)
 {
  if (st1!=st2) return 0;
  else return 1;
 }

//------------------------------------------------------
int binary_pow(int n)
 {
  int result=1;
  for (int i=0; i<n; i++)
   result*=2;
  return result;
 }

//------------Starting Truth Table----------------------------------------
void start_table()
 {
  int res;
  for (int i=0; i<pow; i++)
   {
    res=i;
    for (int j=operands_number; j>0; j--)
     {
      truth_table[i+pow*(j-1)]=res%2;
      res/=2;
     }
   }
 }

//----------Replacing chars to codes of operators---------------
void replace_operator(char *st,char *pos,int op_number)
 {
  char *new_st;
  new_st=(char *)malloc(strlen(pos));
  if (op_number>2)
     strcpy(new_st,pos+op_number-1);
  else strcpy(new_st,pos+1);

  *pos=0x30+op_number;
  *(pos+1)='\x0';
  strcat(st,new_st);
  free(new_st);
 }

//----------Defining operators in the string-----------------------------
void define_operators(char *st)
 {
  char *position;
  int flag=1;
  position=(char *)malloc(strlen(st));
  while (flag)
   {
    flag=0;
    for (int i=0; i<5; i++)
     {
      position=strstr(st,operators[i]);
      if (position!=NULL)
       {
	flag=1;
	if ((i==3)&&(*(position-1)=='<'))
	     replace_operator(st,position-1,i+1);
	else replace_operator(st,position,i);
       }
     }
   }
  free(position);
 }

//---------Defining operands in the string----------------------------
void define_operands(char *st)
 {
  char *op_pos;
  op_pos=(char *)malloc(strlen(st));
  define_operators(st);
  operands=(char *)malloc(1);
  for (char i='a'; i<'z'; i++)
   {
    op_pos=strchr(st,i);
    if (op_pos!=NULL)
     {
      operands[operands_number]=i;
      operands_number++;
      operands=(char *)realloc(operands,operands_number);
     }
   }
  operands[operands_number]='\x0';
  free(op_pos);
 }

//---------Checking for Errors--------------------------------
int error_check(char *st)
 {
  int _error=0;
  for (int i=0; i<strlen(st)-1; i++)
   {
    if (st[i]<'0' || st[i]>'z')
     _error=1;
    if ((st[i]>='a' && st[i]<='z') && (st[i+1]>='a' && st[i+1]<='z'))
     _error=1;
    if ((st[i]>='1' && st[i]<='4') && (st[i+1]>='1' && st[i+1]<='4'))
     _error=1;
    if (st[i]=='0' && st[i+1]<='4' && st[i+1]!='0')
     _error=1;
    if (st[i+1]=='0' && st[i]>='a')
     _error=1;
   }
  return _error;
 }


//-------Calculates operations----------------------------------------
byte execution(byte operand1,byte operand2,int operator_number)
 {
  switch (operator_number)
  {
   case 1: return or(operand1,operand2);
   case 2: return and(operand1,operand2);
   case 3: return implies(operand1,operand2);
   case 4: return equivalence(operand1,operand2);
  }
 }

//----------Returns number of operand in truth table-----------------------
int get_operand(char operand)
 {
  for (int i=0; i<operands_number; i++)
   if (operands[i]==operand) return i;
 }

//---------Printing begin of truth table----------------------------------
void print_begin_of_table(int line)
 {
  for (int i=0; i<operands_number; i++)
   {

    if (file_flag)
      file <<"  "<<char('F'+14*truth_table[pow*i+line]);
    else cout <<"  " <<char('F'+14*truth_table[pow*i+line]);
   }
 }
//----------Printing blanks-----------------------------------------------
void blanks(int n)
 {
  for (int i=0; i<n; i++)
   if (file_flag) file <<" ";
     else cout<<" ";
 }

//----------------Main operations----------------------------------------
void calculation(char *st)
 {
  int first_not=0,not_flag=0;
  pow=binary_pow(operands_number);
  int position;
  int shift=pow*operands_number;
  int result=0;

  truth_table=(byte *)malloc((operands_number+1)*pow);
  start_table();

  if (file_flag) file <<"The truth table is :"<<endl;
  else cout <<"The truth table is :"<<endl;

  for (int i=0; i<operands_number; i++)
  if (file_flag) file <<"  " <<operands[i];
  else cout << "  " <<operands[i];

  i=0;
  if (st[0]=='0')
    {
     int _not=0;
     while (st[i++]=='0')
      _not++;
     first_not=_not;
     if (_not%2)
      {
       if (file_flag) file <<"  ~"<<st[i-1];
       else cout <<"  ~"<<st[i-1];
       position=get_operand(st[i-1])*pow;
       not_flag=1;
      }
     else position=get_operand(st[_not])*pow;
    }
  else position=get_operand(st[0])*pow;
  for (i; i<strlen(st); i++)
   {
    if (st[i]<'a' && st[i+1]!='0')
     {
      blanks(2);
      for (int j=0; j<=(i+1); j++)
	if (st[j]>='0' && st[j]<='4')
	  if (file_flag) file <<operators[st[j]-0x30];
	    else cout << operators[st[j]-0x30];
	else
	 if (file_flag) file <<st[j];
	  else cout << st[j];
     }
    if (st[i+1]=='0')
     {
      int _not=0;
      i++;
      while (st[i++]=='0')
	_not++;
      if (_not%2)
       {
	if (file_flag) file <<"  ~"<<st[i-1];
	  else cout<<"  ~"<<st[i-1];
       }
	blanks(2);

      for (int j=0; j<i; j++)
       if (st[j]>='0' && st[j]<='4')
	if (file_flag) file << operators[st[j]-0x30];
	 else cout<<operators[st[j]-0x30];
       else
	if (file_flag) file << st[j];
	 else cout <<st[j];
      i--;
     }
   }
  if (file_flag) file <<endl;
   else cout <<endl;

  if (not_flag)
    for (int i=0; i<pow; i++)
      truth_table[shift+i]=not(truth_table[position+i]);
  else
    for (int i=0; i<pow; i++)
      truth_table[shift+i]=truth_table[position+i];

  for (i=0; i<pow; i++)
   {
    int j=first_not;
    print_begin_of_table(i);
    int blank=first_not;
    if (not_flag)
       {
	blanks(2);
	if (file_flag) file <<" " <<char('F'+14*truth_table[shift+i]);
	 else cout<<" "<<char('F'+14*truth_table[shift+i]);
       }
    blanks(2);
    while (st[j]!='\x0')
     {
      if (st[j]>='a') blank++;

      if (st[j]<'a' && st[j+1]!='0')
       {
	truth_table[shift+i]=
	 execution(truth_table[shift+i],
	  truth_table[get_operand(st[j+1])*pow+i],st[j]-0x30);
	blanks(blank);
	blank+=strlen(operators[st[j]-0x30]);
	if (file_flag) file <<char('F'+14*truth_table[shift+i]);
	 else cout<<char('F'+14*truth_table[shift+i]);
	blanks(strlen(operators[st[j]-0x30])+2);
       }
      if (st[j+1]=='0')
       {
	int _not=0;
	if (!j) _not=1;
	int pred=j;
	while (st[++j]=='0')
	  _not++;
	if (_not%2)
	 {
	  truth_table[shift+i]=
	  execution(truth_table[shift+i],
	  not(truth_table[get_operand(st[j])*pow+i]),st[pred]-0x30);
	  blanks(1);
	  if (file_flag) file <<char('F'+14*not(truth_table[get_operand(st[j])*pow+i]))<<"  ";
	   else cout<<char('F'+14*not(truth_table[get_operand(st[j])*pow+i]))<<"  ";
	  blanks(blank);
	  blank+=strlen(operators[st[pred]-0x30])+_not+1;
	  if (file_flag) file <<char('F'+14*truth_table[shift+i]);
	   else cout <<char('F'+14*truth_table[shift+i]);
	  blanks(strlen(operators[st[pred]-0x30])+_not+2);
	 }
	else
	 {
	  truth_table[shift+i]=
	  execution(truth_table[shift+i],
	   truth_table[get_operand(st[j])*pow+i],st[pred]-0x30);
	  blanks(blank);
	  blank+=_not+strlen(operators[st[pred]-0x30])+1;
	  if (file_flag) file <<char('F'+14*truth_table[shift+i]);
	   else cout<<char('F'+14*truth_table[shift+i]);
	  blanks(_not+strlen(operators[st[pred]-0x30])+2);

	 }

       }
      j++;
     }
    if (file_flag) file <<endl;
     else cout <<endl;
    result+=truth_table[shift+i];
   }
  if (result==pow)
   if (file_flag) file << "This statement is tautology."<<endl;
    else cout <<"This statement is tautology."<<endl;
  else
   if (file_flag) file << "This statement is not tautology."<<endl;
    else cout << "This statement is not tautology."<<endl;
 }

void main ()
{
 char *statement,*reserved;
 clrscr();
 cout << "Enter the statement : " <<endl;
 cin >> statement;
// statement="~a->~b|a&~~a|~b->~b|~a&b|~~~~a->b";
// statement="a|~~b&~~~a";
// statement="~~~a|~~b->~~~a|~~~~b";
// statement="~~~~p->q&~q->~p";
// statement="a->b|~~a&b<->b|a";
// statement="a->b|~~a&c<->b|a->a";
 reserved=(char *)malloc(strlen(statement));
 strcpy(reserved,statement);
 define_operands(statement);
 if (error_check(statement))
  cout << "Error in the statement!!! "<<endl;
 else
  {
   if (operands_number>4 || strlen(reserved)>16)
    {
     file_flag=1;
     file.open("p_logic.dat");
     cout << "Output in the file \"P_LOGIC.DAT\" "<<endl;
     if (!file)
      {
       cerr <<"Error with opening file \"P_LOGIC.DAT\" "<<endl;
       exit(1);
      }
     file << reserved <<endl;
    }
   calculation(statement);
  }
 if (file_flag) file.close();
 free(statement);
 free(reserved);
// free(operands);
// free(truth_table);
 getch();
}