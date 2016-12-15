#include <conio.h>
#include <fstream.h>
#include <stdlib.h>
#include <mem.h>
#include <dir.h>
#include <string.h>

#define true 1
#define false 0

ifstream file_a,file_b;
ofstream m_file;

int *a_set,*b_set,*matrix,*head_line,*partition;
int size_a,size_b,matrix_size,sqr;
struct peculiarity
 {
  int set;
  int sub_set;
  int b_set;
  int reflexive;
  int irreflexive;
  int symetric;
  int anti_symetric;
  int assymetric;
  int transitive;
  int equivalence;
 } flags;


int in_set(int set[],int element,int set_size)
 {
  int i=0,flag=false;
  while ((!flag)&&(i<set_size))
   {
    if (set[i]==element) flag=true;
    i++;
   }
  if (flag) return i;
  else return 0;
 }

void read_fnames()
 {
  char filea_name[MAXPATH]/*="a_set.dat"*/,fileb_name[MAXPATH]/*="b_set1.dat"*/;
  cout << "Enter file name with set A : ";
  cin >> filea_name;
  cout << "Enter file name with set B : ";
  cin >> fileb_name;
  file_a.open(filea_name/*"D:/Work/a_set.dat"*/);
   if (!file_a)
    {
     cerr << "Error when opening file \""<<filea_name<<"\""<<endl;
     getch();
     exit(1);
    }
  file_b.open(fileb_name/*"D:/Work/b_set.dat"*/);
   if (!file_b)
    {
     cerr << "Error when opening file \""<<fileb_name<<"\""<<endl;
     getch();
     exit(1);
    }
 }

void read_a_set()
 {
  int number,end,size=0;
  a_set=(int *)malloc(sizeof(int));
  if (a_set==NULL)
   {
    cerr << "a_set : Cannot allocate memory!!!";
    getch();
    exit(1);
   }
  do
   {
    file_a >> number;
    end=file_a.peek();
//    if (end!=EOF)
//     {
      size++;
      a_set=(int *)realloc(a_set,sizeof(int)*size);
      if (a_set==NULL)
       {
	cerr << "a_set : Cannot allocate memory!!!";
	getch();
	exit(1);
       }
      a_set[size-1]=number;
//     }
   }

  while (end!=EOF);
  size_a=size;
  file_a.close();
 }

void check_a()
 {
  int i=0;
  flags.set=true;
  while (flags.set&&i<size_a-1)
   {
    if (in_set(a_set+i+1,a_set[i],size_a-i-1))
     flags.set=false;
    i++;
   }
 }
void read_b_set()
 {
  int num1,num2,end,size=0;
  flags.sub_set=true;
  flags.b_set=true;
  b_set=(int *)malloc(sizeof(int)*2);
  if (b_set==NULL)
   {
    cerr << "b_set : Cannot allocate memory!!!";
    getch();
    exit(1);
   }
  do
   {
    file_b >> num1 >> num2;
    end=file_b.peek();
    if (!in_set(a_set,num1,size_a)&&!in_set(a_set,num2,size_a))
     flags.sub_set=false;
  //  if (end!=EOF&&flags.sub_set)
  //   {
      size+=2;
      b_set=(int *)realloc(b_set,size*sizeof(int));
      if (b_set==NULL)
       {
	cerr << "b_set : Cannot allocate memory!!!";
	getch();
	exit(1);
       }
      b_set[size-2]=num1;
      b_set[size-1]=num2;
//    }
   }
  while (end!=EOF&&flags.sub_set);
  size_b=size;
  file_b.close();
  if (flags.sub_set)
   {
    int i=0;
    while (flags.b_set&&i<size_b)
     {
      int j=i+2;
      while (flags.b_set&&j<size_b)
       {
	if (b_set[i]==b_set[j]&&b_set[i+1]==b_set[j+1])
	 flags.b_set=false;
	j+=2;
       }
      i+=2;
     }
   }
 }

void rput(int a,int b)
 {
  matrix[matrix_size*b+a]=1;
 }

int rget(int a,int b)
 {
  return matrix[matrix_size*b+a];
 }

void make_matrix()
 {
  int r;
  head_line=(int *)malloc(sizeof(int));
  if (head_line==NULL)
   {
    cerr << "head_line : Cannot allocate memory!!!";
    getch();
    exit(1);
   }
  for (int i=0; i<size_b; i++)
   if (!in_set(head_line,b_set[i],matrix_size))
    {
     head_line[matrix_size]=b_set[i];
     matrix_size++;
     head_line=(int *)realloc(head_line,sizeof(int)*(matrix_size+1));
     if (head_line==NULL)
      {
       cerr << "head_line : Cannot allocate memory!!!";
       getch();
       exit(1);
      }
    }

  for (i=0; i<matrix_size-1; i++)
   for (int j=i+1; j<matrix_size; j++)
    if (head_line[i]>head_line[j])
     {
      r=head_line[i];
      head_line[i]=head_line[j];
      head_line[j]=r;
     }

  sqr=matrix_size*matrix_size;
  matrix=(int *)malloc(sizeof(int)*sqr);
  if (matrix==NULL)
   {
    cerr << "matrix : Cannot allocate memory!!!";
    getch();
    exit(1);
   }
  for (i=0; i<sqr; i++)
   matrix[i]=0;
  for (i=0; i<size_b; i+=2)
   rput(in_set(head_line,b_set[i],matrix_size)-1,
	in_set(head_line,b_set[i+1],matrix_size)-1);
 }

void make_partitions()
 {
  ofstream file_p;
  int flag=true,new_partition=true;
  int r1,r2,k=0;
  char num[10],file_name[MAXPATH];
  partition=(int *)malloc(sizeof(int)*matrix_size);
  if (partition==NULL)
   {
    cerr << "partition : Cannot allocate memory!!!";
    getch();
    exit(1);
   }
  for (int i=0; i<matrix_size; i++)
   partition[i]=0;
  while (new_partition)
   {
    new_partition=false;
    i=0;
    while (!new_partition&&i<matrix_size)
     {
      if (!partition[i])
       {
	k++;
	partition[i]=k;
	new_partition=true;
	flag=true;
       }
      i++;
     }
      while (flag)
       {
	flag=false;
	for (int j=0; j<matrix_size; j++)
	 if (partition[j]==k)
	  {
	   flag=true;
	   partition[j]=-k;
	   for (int j1=0; j1<size_b/2; j1++)
	    {
	     r1=in_set(head_line,b_set[j1*2],matrix_size);
	     r2=in_set(head_line,b_set[j1*2+1],matrix_size);
	     if (b_set[j1*2]==head_line[j]&&!partition[r2-1])
	      partition[r2-1]=k;
	     if(b_set[j1*2+1]==head_line[j]&&!partition[r1-1])
	      partition[r1-1]=k;
	    }
	  }
	}
   }
  cout<<endl<<"Found "<<k<<" block(s)."<<endl;
  cout <<endl<<"Making files : ";
  for (i=0; i<k; i++)
   {
    strcpy(file_name,"part");
    cout<<".";
    itoa(i+1,num,10);

    strcat(file_name,num);
    strcat(file_name,".dat");
    file_p.open(file_name);
    if (!file_p)
    {
     cerr << "Error when opening file \""<<file_name<<"\""<<endl;
     getch();
     exit(1);
    }
    for (int j=0; j<matrix_size; j++)
     if (partition[j]==-(i+1))
      file_p <<head_line[j]<<endl;
    file_p.close();
   }
  cout <<" Done"<<endl;
 }

void print_matrix()
 {
  m_file.open(/*"D:/Work\\*/"matrix.dat");
  if (!m_file)
   {
    cerr << "Error when opening file \"matrix.dat\""<<endl;
    getch();
    exit(1);
   }
  m_file << "  ";
  for (int i=0; i<matrix_size; i++)
   m_file <<" "<< head_line[i];
  m_file <<endl;
  for (i=0; i<matrix_size; i++)
   {
    m_file <<endl<<head_line[i]<<" ";
    for (int j=0; j<matrix_size; j++)
     m_file <<" "<<rget(j,i);
   }
  m_file.close();
 }

void check_peculiarities()
 {
  int diagonal=0,n1,n2,mul,counter=0;
  flags.symetric=true;
  flags.anti_symetric=true;
  flags.transitive=true;
  flags.assymetric=true;
  flags.reflexive=true;
  flags.irreflexive=true;
  for (int i=0; i<matrix_size; i++)
   for (int j=0; j<matrix_size; j++)
    {
     mul=0;
     n1=rget(i,j);
     n2=rget(j,i);
     if (flags.transitive)
      {
       int k=0;
       while (!mul&&k<matrix_size)
	{
	 mul+=rget(i,k)*rget(k,j);
	 k++;
	}
       if (!mul) counter++;
       if (mul&&!n1)
	{
	 flags.transitive=false;
	 cout <<"Transitive - FALSE : {"
	 <<head_line[i]<<","
	 <<head_line[k-1]<<"}-found, {"
	 <<head_line[k-1]<<","
	 <<head_line[j]<<"}-found, {"
	 <<head_line[i]<<","
	 <<head_line[j]<<"}-not found."<<endl;
	}
      }
     if ((i==j)&&!rget(i,i)&&flags.reflexive)
      {
       flags.reflexive=false;
       cout <<"Reflexive - FALSE : {"
       <<head_line[i]<<","<<head_line[i]<<"}-not found."<<endl;
      }
     if ((i==j)&&rget(i,i))
      {
       diagonal++;
       if (flags.irreflexive)
	{
	 flags.irreflexive=false;
	 cout <<"Irreflexive - FALSE : {"
	 <<head_line[i]<<","<<head_line[i]<<"}-found."<<endl;
	}
       if (flags.assymetric)
	{
	 flags.assymetric=false;
	 cout <<"Assimetric - FALSE : {"
	 <<head_line[i]<<","<<head_line[i]<<"}-found."<<endl;
	}

      }
     if (n1&&n2&&i!=j&&flags.anti_symetric)
      {
       flags.anti_symetric=false;
       cout << "Anti Symetric - FAlSE : {"
       <<head_line[i]<<","<<head_line[j]<<"}-found, {"
       <<head_line[j]<<","<<head_line[i]<<"}-found."<<endl;
       if (flags.assymetric)
	{
	 flags.assymetric=false;
	 cout <<"Assimetric - FALSE : {"
	 <<head_line[i]<<","<<head_line[j]<<"}-found, {"
	 <<head_line[j]<<","<<head_line[i]<<"}-found."<<endl;
	}
      }
     if ((((n1&&!n2)||(!n1&&n2))&&(i!=j))&&flags.symetric)
      {
       flags.symetric=false;
       cout << "Symetric -FALSE : {"
       <<head_line[i*n1+j*n2]<<","
       <<head_line[j*n1+i*n2]<<"}-found, {"
       <<head_line[i*n2+j*n1]<<","
       <<head_line[j*n2+i*n1]<<"}-not found."<<endl;
      }
    }
  if (flags.transitive)
   cout <<"Transitive - TRUE"<<endl;
  if (counter==sqr)
   {
    flags.transitive=false;
    cout <<"Transitive - FALSE"<<endl;
   }
  if (flags.symetric)
   cout <<"Symetric - TRUE"<<endl;
  if (flags.anti_symetric)
   cout <<"Anti Symetric - TRUE"<<endl;
  if (diagonal==matrix_size)
   {
    flags.reflexive=true;
    cout <<"Reflexive - TRUE"<<endl;
   }

  if (!diagonal)
   {
    flags.irreflexive=true;
    cout <<"Irreflexive - TRUE"<<endl;
   }
  if (!diagonal&&flags.anti_symetric)
   {
    flags.assymetric=true;
    cout <<"Assymetric - TRUE"<<endl;
   }
  if (flags.reflexive&&flags.symetric&&flags.transitive)
   {
    flags.equivalence=true;
    cout <<"Equivalence - TRUE"<<endl;
   }
  else
   cout <<"Equivalence - FALSE"<<endl;
 }

void main()
 {
  ifstream file_p;
  char ch=0;
  int part_num,el,end;
  char num[10],part_name[MAXPATH]="part";
  clrscr();
  read_fnames();
  read_a_set();
  check_a();
  if (flags.set)
   {
    read_b_set();
    if (flags.sub_set)
     {
      if (!flags.b_set)
       {
	cout <<"B set contains some same relations!"<<endl;
	cout <<"Do you want to continue? (Y/N) : ";
	while (ch!='Y'&&ch!='N'&&ch!='y'&&ch!='n')
	 ch=getch();
	cout <<ch<<endl;
       }
      if (ch!='N'&&ch!='n')
       {
	ch=0;
	make_matrix();
	print_matrix();
	cout <<endl;
	check_peculiarities();
	if (flags.equivalence)
	 {
	  make_partitions();
	  while (ch!='N'&&ch!='n')
	   {
	    cout <<"Do you want to view blocks? (Y/N) : ";
	    while (ch!='Y'&&ch!='N'&&ch!='y'&&ch!='n')
	     ch=getch();
	    cout <<ch<<endl;
	    if (ch=='y'||ch=='Y')
	     {
	      ch=0;
	      cout <<"Enter the number of block : ";
	      cin >> part_num;
	      itoa(part_num,num,10);
	      strcat(part_name,num);
	      strcat(part_name,".dat");
	      file_p.open(part_name);
	      if (!file_p)
	       {
		cerr << "Error when opening file \""<<part_name<<"\""<<endl;
		getch();
		exit(1);
	       }
	      file_p >> el;
	      cout <<"{"<<el;
	      do
	       {
		file_p >> el;
		end=file_p.peek();
		if (end!=EOF)
		 cout <<","<<el;
		}
	       while (end!=EOF);
	       cout <<"}"<<endl;
	       file_p.close();
	       strcpy(part_name,"part");
	     }
	   }
	 }
       }
     }
    else cout << "B is not sub-set of AxA !!!";
   }
  else cout <<"A is not a set !!!";
  getch();
 }
