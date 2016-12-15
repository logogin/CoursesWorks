
#include <iostream.h>
#include <fstream.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <assert.h>
#include <memory.h>
#include <malloc.h>

#include "Functions.h"
#include "BinaryString.h"

//#define DEBUG

ofstream out_file;

//unsigned int _sop_function[]={2,6,7,8,10};
//unsigned int _care_function[]={8,15,19,23};
unsigned int *sop_function;
unsigned int *care_function;
unsigned int var_number;

unsigned int minterm_number;
unsigned int care_function_size;
unsigned int previos_minterm_number;
unsigned int next_minterm_number;

ProductString *previos_table;
ProductString *next_table;
ProductString *main_solution;

bool *in_table;
bool *in_function;
bool care_flag;

unsigned int previos_table_size;
unsigned int next_table_size;
unsigned int main_solution_size;

unsigned char *previos_matrix;

void new_previos_table(void)
{
	previos_table=new_pointer(previos_table,previos_table_size);
}
 
void new_in_table(void)
{
	in_table=new_pointer(in_table,previos_table_size);
	memset(in_table,true,sizeof(bool)*previos_table_size);
}

bool in_array(const ProductString &element, const ProductString *pointer, const unsigned int size)
{
	bool flag=false;
	unsigned int i=0;
	while (!flag&&i<size)
		if (pointer[i]==element)
			flag=true;
		else
			i++;
	return flag;
}

int in_sop_function(const unsigned int element)
{
	bool flag=false;
	unsigned int index=0;
	for (unsigned int i=0; i<minterm_number&&!flag; i++)
	{
		if (in_function[i])
		{
			if (sop_function[i]==element)
				flag=true;
			if (!flag)
				index++;
		}
	}
	if (flag)
		return index;
	else
		return -1;
}

unsigned int find_minterm(const unsigned int element)
{
	bool flag=false;//unsigned int j=0;
	for (unsigned int i=0; i<minterm_number&&!flag; i++)
		if (sop_function[i]==element)
			flag=true;
	return i-1;
}

unsigned char read_matrix(const unsigned char *matrix,const unsigned int row_size,
						  const unsigned int i,const unsigned int j)
{
	return matrix[i*row_size+j];
}

void write_matrix(unsigned char *matrix,const unsigned int row_size,const unsigned int i,
				  const unsigned int j,const unsigned char value)
{
	matrix[i*row_size+j]=value;
}

unsigned char *or_row(const unsigned char *row1,const unsigned char *row2)
{
	unsigned char *result=NULL;
	result=new_pointer(result,previos_minterm_number);
	for (unsigned int i=0; i<previos_minterm_number; i++)
		result[i]=row1[i]|row2[i];
	return result;
}

bool and_row(unsigned char *row)
{
	bool flag=true;
	for (unsigned int i=0; i<previos_minterm_number&&flag; i++)
		if (!row[i])
			flag=false;
	return flag;
}

void previos_table2next(void)
{
	void *ptr;
	previos_table_size=next_table_size;
	delete []previos_table;
	new_previos_table();
	ptr=memcpy(reinterpret_cast<void *>(previos_table),
		reinterpret_cast<const void *>(next_table),
		sizeof(ProductString)*next_table_size);
	assert_pointer(ptr);
	free(next_table);
	next_table=NULL;
	next_table_size=0;
	delete []in_table;
	new_in_table();
}

void previos_matrix2next(void)
{
	int pos;
	previos_matrix=new_pointer(previos_matrix,previos_table_size*previos_minterm_number);
	memset(previos_matrix,0,sizeof(unsigned char)*previos_table_size*previos_minterm_number);
	for (unsigned int i=0; i<previos_table_size; i++)
		for (unsigned int j=0; j<previos_table[i].GetMintermNumber(); j++)
		{
			pos=in_sop_function(previos_table[i].GetMinterm(j));
			if (pos!=-1)
				write_matrix(previos_matrix,previos_minterm_number,i,pos,1);
		}
}

void sort_function(void)
{
	unsigned int temp;
	for (unsigned int i=0; i<minterm_number-1; i++)
		for (unsigned int j=i+1; j<minterm_number; j++)
			if (sop_function[i]>sop_function[j])
			{
				temp=sop_function[i];
				sop_function[i]=sop_function[j];
				sop_function[j]=temp;
			}
}

void init_start_table(void)
{
	if (care_flag)
	{
		void *ptr;
		sop_function=realloc_pointer(sop_function,minterm_number+care_function_size);
		ptr=memcpy(sop_function+minterm_number,care_function,
			sizeof(unsigned int)*care_function_size);
		assert_pointer(ptr);
		minterm_number+=care_function_size;
	}
	sort_function();
	previos_table_size=minterm_number;
	new_previos_table();
	out_file<<"Step 1"<<endl;
	for(unsigned int i=0; i<minterm_number; i++)
	{
		ProductString Temp(sop_function[i],var_number);
		previos_table[i]=Temp;

/**/	out_file<<Temp<<"   ";
		Temp.PrintMinterms(out_file);
		out_file<<endl;
	}
	new_in_table();
}

void create_table(void)
{
	int steps=1;
	bool flag=true;
	while (flag)
	{
		out_file<<endl;
		steps++;
		out_file<<"Step "<<steps<<endl;
		flag=false;
		for (unsigned int i=0; i<previos_table_size-1; i++)
			for (unsigned int j=i+1; j<previos_table_size; j++)
				if ((previos_table[i]^previos_table[j])&&
					(previos_table[j].Get1sNumber()-previos_table[i].Get1sNumber())==1)
				{
					flag=true;
					in_table[i]=false;
					in_table[j]=false;
					if (in_vector(previos_table[i]+previos_table[j],
						next_table,next_table_size)==-1)
					{
						next_table_size++;
						next_table=realloc_pointer(next_table,next_table_size);
						next_table[next_table_size-1]=(previos_table[i]+previos_table[j]);

/**/					out_file<<next_table[next_table_size-1]<<"   ";
						next_table[next_table_size-1].PrintMinterms(out_file);
						out_file<<endl;
					}
				}
		if (flag)
		{
			for (i=0; i<previos_table_size; i++)
				if (in_table[i]&&in_vector(previos_table[i],next_table,next_table_size)==-1)
				{
					next_table_size++;
					next_table=realloc_pointer(next_table,next_table_size);
					next_table[next_table_size-1]=previos_table[i];

/**/				out_file<<next_table[next_table_size-1]<<"   ";
					next_table[next_table_size-1].PrintMinterms(out_file);
					out_file<<endl;
				}
			previos_table2next();
		}
	}
}

bool find_essential_implicant(const unsigned int row)
{
	bool stop_flag=false;
	bool found_flag;
	for (unsigned int i=0; i<previos_minterm_number&&!stop_flag; i++)
		if (read_matrix(previos_matrix,previos_minterm_number,row,i))
		{
			found_flag=false;
			for (unsigned int j=0; j<previos_table_size&&!stop_flag; j++)
				if (j!=row&&read_matrix(previos_matrix,previos_minterm_number,j,i))
					found_flag=true;
			if (!found_flag)
				stop_flag=true;
		}
	return !found_flag;
}

void remove_essential_implicants(void)
{
	for (unsigned int i=0; i<previos_table_size; i++)
		if (find_essential_implicant(i))
		{
			main_solution_size++;
			main_solution=realloc_pointer(main_solution,main_solution_size);
			main_solution[main_solution_size-1]=previos_table[i];
			in_table[i]=false;
			for (unsigned int j=0; j<previos_minterm_number; j++)
				if (read_matrix(previos_matrix,previos_minterm_number,i,j))
				{
					next_minterm_number--;
					for (unsigned int k=0; k<previos_table_size; k++)
						write_matrix(previos_matrix,previos_minterm_number,k,j,0);
				}
			for (j=0; j<previos_table[i].GetMintermNumber(); j++)
				in_function[find_minterm(previos_table[i].GetMinterm(j))]=false;
		}
	for (i=0; i<previos_table_size; i++)
		if (in_table[i])
		{
			next_table_size++;
			next_table=realloc_pointer(next_table,next_table_size);
			next_table[next_table_size-1]=previos_table[i];
		}
	previos_table2next();
	previos_minterm_number=next_minterm_number;
	delete []previos_matrix;
	previos_matrix2next();
}

void init_matrix(void)
{
	in_function=new_pointer(in_function,minterm_number);
	memset(in_function,true,sizeof(bool)*minterm_number);
	if (care_flag)
	{
		for (unsigned int i=0; i<care_function_size; i++)
			in_function[in_vector(care_function[i],sop_function,minterm_number)]=false;

		for (i=0; i<previos_table_size; i++)
		{
			bool flag=false;
			for (unsigned int j=0; j<previos_table[i].GetMintermNumber()&&!flag; j++)
				if (in_vector(previos_table[i].GetMinterm(j),sop_function,
					minterm_number)!=-1)
					flag=true;
			if (!flag)
				in_table[i]=false;
		}
		for (i=0; i<previos_table_size; i++)
			if (in_table[i])
			{
				next_table_size++;
				next_table=realloc_pointer(next_table,next_table_size);
				next_table[next_table_size-1]=previos_table[i];
			}
		previos_table2next();
	}

	previos_minterm_number=minterm_number-care_function_size;
	next_minterm_number=previos_minterm_number;
	previos_matrix2next();
}

void remove_cyclic_implicants(void)
{
	unsigned max_iter=1<<previos_table_size;
	unsigned int *sums=NULL;
	int pos;
	unsigned int sums_size=0;
	unsigned int min;
	unsigned char *previos_row=NULL;
	previos_row=new_pointer(previos_row,previos_minterm_number);
	for (unsigned int i=1; i<max_iter; i++)
	{
		BinaryString st(i,previos_table_size);
		char *temp=st.GetString();
		memset(previos_row,0,sizeof(unsigned char)*previos_minterm_number);
		for (unsigned int j=0; j<st.GetSize(); j++)
			if (temp[j])
				previos_row=or_row(previos_row,previos_matrix+j*previos_minterm_number);
		if (and_row(previos_row))
		{
			sums_size++;
			sums=realloc_pointer(sums,sums_size);
			sums[sums_size-1]=i;
		}
	}
	
	BinaryString st(sums[0],previos_table_size);
	min=st.Get1sNumber();
	for (i=0; i<sums_size; i++)
	{
		st.SetNewString(sums[i]);
		if (st.Get1sNumber()<min)
			min=st.Get1sNumber();
	}

	out_file<<endl<<"Additional solution variants (secondary essential implicants): "<<endl;
	for (i=0; i<sums_size; i++)
	{
		BinaryString st(sums[i],previos_table_size);
		if (st.Get1sNumber()==min)
		{
			char *temp=st.GetString();
			for (unsigned int j=0; j<min; j++)
			{
				pos=in_vector((char)1,temp,st.GetSize());
				if (pos!=-1)
				{
					temp[pos]=0;
					out_file<<previos_table[pos]<<(j!=(min-1) ? " + " : "");
				}
				else
				{
					cerr<<"Error in data"<<endl;
					exit(1);
				}
			}
			out_file<<endl;
		}
	}
}

void print_matrix(void)
{
	for (unsigned int i=0; i<previos_table_size; i++)
	{
		out_file<<previos_table[i]<<"   "<<flush;
		for (unsigned int j=0; j<previos_minterm_number; j++)
			out_file<<(read_matrix(previos_matrix,previos_minterm_number,i,j) ? 'x' : '.')<<" ";
		out_file<<endl;
	}
}

void print_main_solution(void)
{
	out_file<<endl<<"Main Solution (essential implicants):"<<endl;
	for (unsigned int i=0; i<main_solution_size; i++)
		out_file<<main_solution[i]<<(i!=(main_solution_size-1) ? " + " : "");
	out_file<<endl;
}

void resolve(void)
{
	print_matrix();
	out_file<<endl;
	remove_essential_implicants();
	print_matrix();
	print_main_solution();
	if (previos_table_size&&previos_minterm_number)
		remove_cyclic_implicants();
	out_file<<endl<<"Finished"<<endl;
}

void init_data(void)
{
	bool flag=false;
	char ch=0;
	unsigned int max_minterm;
	long number;
	unsigned int minterm;
	cout<<"Enter number of variables : "<<flush;
	cin>>number;
	if (number<=0)
	{
		cerr<<"Error input data!!!"<<endl;
		exit(0);
	}
	var_number=number;
	max_minterm=1<<var_number;
	while (ch!='Y'&&ch!='y'&&ch!='N'&&ch!='n')
	{
		cout<<"Do you want to use 'Don`t care conditions' ? (Y/N) : "<<flush;
		cin>>ch;
	}
	if (ch=='Y'||ch=='y')
		care_flag=true;
	else
		care_flag=false;
	cout<<"Enter main SOP function (0~"<<(max_minterm-1)<<") (-1 for end)"<<endl;
	do
	{
		cin>>minterm;
		if (minterm!=-1&&minterm<max_minterm)
		{
			if (in_vector(minterm,sop_function,minterm_number)==-1)
			{
				minterm_number++;
				sop_function=realloc_pointer(sop_function,minterm_number);
				sop_function[minterm_number-1]=minterm;
			}
			else 
				flag=true;
		}
		else 
			if (minterm!=-1)
				flag=true;

	}
	while (minterm!=-1&&!flag);
	if (flag)
	{
		cerr<<"Error input data!!!"<<endl;
		exit(0);
	}
	if (care_flag)
	{
		cout<<"Enter 'Dont Care' SOP function (0~"<<(max_minterm-1)<<") (-1 for end)"<<endl;
		flag=false;
		do
		{
			cin>>minterm;
			if (minterm!=-1&&minterm<max_minterm)
			{
				if (in_vector(minterm,sop_function,minterm_number)==-1&&
					in_vector(minterm,care_function,care_function_size)==-1)
				{
					care_function_size++;
					care_function=realloc_pointer(care_function,care_function_size);
					care_function[care_function_size-1]=minterm;
				}
				else 
					flag=true;
			}
			else
				if (minterm!=-1)
					flag=true;
		}
		while (minterm!=-1&&!flag);
		if (flag)
		{
			cerr<<"Error input data!!!"<<endl;
			exit(0);
		}
	}
}

void deleting_pointers(void)
{
	delete []previos_table;
	free(next_table);
	delete []in_table;
	delete []in_function;
//	delete []previos_matrix;
//	free(main_solution);
}

void main()
{
#ifndef DEBUG
	init_data();
#endif DEBUG

#ifdef DEBUG
	{
		sop_function=new unsigned[minterm_number];
		memcpy(sop_function,_sop_function,sizeof(_sop_function));

		care_function=new unsigned[care_function_size];
		memcpy(care_function,_care_function,sizeof(_care_function));
	}
#endif DEBUG
	cout<<endl<<"Processing : "<<endl;
	cout<<"Opening file 'output.txt' ... "<<flush;
	out_file.open("output.txt",ios::out);
	if (!out_file)
	{
		cerr<<endl<<"Cannot open file!!!"<<endl;
		exit(1);
	}
	out_file.clear();
	cout<<"Done"<<endl;
	cout<<"Initialisation ... "<<flush;
	init_start_table();
	cout<<"Done"<<endl;
	cout<<"Creation of tables ... "<<flush;
	create_table();
	cout<<"Done"<<endl;
	cout<<"Initialisation of matrices ... "<<flush;
	init_matrix();
	cout<<"Done"<<endl;
	cout<<"Resolving function ... "<<flush;
	resolve();
	cout<<"Done"<<endl;
	cout<<"Deleting global pointers ... "<<flush;
	deleting_pointers();
	cout<<"Done"<<endl;
	out_file.close();
	cout<<endl<<"Output in the file 'output.txt' in current working directory"<<endl;
	getch();
}