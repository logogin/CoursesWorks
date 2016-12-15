#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Queue.h"

const char *names[20]={"Anna","Bob","David","Bill","Camille",
					"Pat","Diana","Karen","Amy","Edward",
					"Mary","Jim","Max","Brain","Thomas",
					"Robert","Alex","Peter","Rose","Nik"};

const enum{male='M',female='F'};

const char gender[20]={female,male,male,male,female,
					male,female,female,female,male,
					female,male,male,male,male,
					male,male,male,female,male};
struct student
{
	char *name;
	char sex;
	int age; 
} *students;

int size;
queue queue1;
queue queue2;
queue bus;

void init()
{
	int id;
	cout <<"How many students in each queue ? : ";
	cin >>size;

	students=new student[size*2];
	assert(students!=NULL);
	
	queue_init(queue1,size,0);
	queue_init(queue2,size,0);
	srand((unsigned)time(NULL));
	cout <<"First queue : "<<endl;
	for (int i=0; i<size; i++)
	{
		if (!(i%6))
			cout<<endl;
		enqueue(queue1,i,1);
		id=rand()%20;
		students[i].name=strdup(names[id]);
		students[i].sex=gender[id];
		students[i].age=20+rand()%20;
		cout <<names[id]<<"{"<<gender[id]<<","<<students[i].age<<"} "<<flush;
	}
	cout <<endl<<"Second queue : "<<endl;
	for (i=size; i<size*2; i++)
	{
		if (!((i-size)%6))
			cout<<endl;
		enqueue(queue2,i,1);
		id=rand()%20;
		students[i].name=strdup(names[id]);
		students[i].sex=gender[id];
		students[i].age=20+rand()%20;
		cout <<names[id]<<"{"<<gender[id]<<","<<students[i].age<<"} "<<flush;
	}
	cout<<endl<<endl;
}

void ordering()
{
	int id1;
	int id2;
	queue_init(bus,size*2,0);
	for (int i=0; i<size; i++)
	{
		id1=dequeue(queue1,1);
		id2=dequeue(queue2,1);
		
		if (students[id1].age!=students[id2].age)
			if (students[id1].age>students[id2].age)
			{
				enqueue(bus,id2,1);
				enqueue(bus,id1,1);
			}
			else
			{
				enqueue(bus,id1,1);
				enqueue(bus,id2,1);
			}
		else
			if (students[id1].sex!=students[id2].sex)
				if (students[id1].sex==male)
				{
					enqueue(bus,id2,1);
					enqueue(bus,id1,1);
				}
				else
				{
					enqueue(bus,id1,1);
					enqueue(bus,id2,1);
				}
			else
				if (strcmp(students[id1].name,students[id2].name)>0)
				{
					enqueue(bus,id2,1);
					enqueue(bus,id1,1);
				}
				else
				{
					enqueue(bus,id2,1);
					enqueue(bus,id1,1);
				}
	}
}
void main()
{
	int id;
	init();
	ordering();
	for(int i=0; i<size*2; i++)
	{
		if (!(i%6))
			cout<<endl;
		id=dequeue(bus,1);
		cout<<students[id].name<<"{"<<students[id].sex<<","
			<<students[id].age<<"} "<<flush;
	}
	cout<<endl;
	queue_delete(queue1);
	queue_delete(queue2);
	queue_delete(bus);
	delete []students;
}