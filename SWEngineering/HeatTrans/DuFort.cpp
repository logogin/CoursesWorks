#include <iostream.h>
#include <fstream.h>
#include <math.h>
#include <assert.h>
#include <iomanip.h>

const double a_value=-2.0;
const double b_value=-0.5;

const double ci=133.0;
const double ro=21450.0;
const double kei=71.6;
const double alpha=kei/(ci*ro);

const double t_init=12000.0;
const double t_end=15000.0;

double f(const double x_value)
{
	return 50*x_value+3/*10*//*x_value*/;
}

double g1(const double t_value)
{
	return 20*cos(8*t_value)/*10.0*//*0.0*/;
}

double g2(const double t_value)
{
	return 20*sin(0.5*t_value)/*10.0*//*0.4*/;
}

double *matrix[3]={NULL,NULL,NULL};

void init_matrix(const int size)
{
	for (int i=0; i<3; i++)
	{
		if (matrix[i]!=NULL)
			delete []matrix[i];
		matrix[i]=new double[size];
		assert(matrix[i]!=NULL);
	}
}

void main()
{
	//ofstream file("data.txt",ios::out);
	//file<<setiosflags(ios::left)<<setw(10);
	int vector_size=8;
	int matrix_height=0;
	int matrix_size;
	int k=0;
	double dx;
	double dt;
	double lambda;
	double previous_value;
	double next_value;
	bool flag=false;
	double x=-0.6;
	double t=14500;
	double error=0.001;
	do
	{
		ofstream file("data.txt",ios::out);
		ofstream filex("datax.txt",ios::out);
		ofstream filey("datay.txt",ios::out);
		ofstream filez("dataz.txt",ios::out);
		//dx=(b_value-a_value)/vector_size;
		dx=(x-a_value)/vector_size;
		matrix_size=(b_value-a_value)/dx;
		init_matrix(matrix_size);
		dt=0.4*dx*dx/alpha;
		matrix_height=(t-t_init)/dt;
		lambda=alpha*dt/(dx*dx);

		for (int i=0; i<matrix_size; i++)
			matrix[0][i]=f(a_value+i*dx);
	
	
		for (i=0; i<3; i++)
		{
			matrix[i][0]=g1(t_init+dt*i);
			matrix[i][matrix_size-1]=g2(t_init+dt*i);
		}

		for (i=1; i<matrix_size-1; i++)
			matrix[1][i]=lambda*matrix[0][i-1]+(1-2*lambda)*matrix[0][i]+lambda*matrix[0][i+1];

		for (i=0; i<2; i++)
		{
			for(int j=0; j<matrix_size; j++)
			{
				file<<setiosflags(ios::left)<<setw(15)<<matrix[i][j]<<" "<<flush;
			//	filex<<a_value+j*dx<<endl;
			//	filey<<t_init+i*dt<<endl;
			//	filez<<matrix[i][j]<<endl;
			}
			file<<endl;
		}

		for (int j=1; (j+1)<matrix_height; j++)
		{
			for (i=1; i<matrix_size-1; i++)
				matrix[2][i]=(1-2*lambda)/(1+2*lambda)*matrix[0][i]+2*lambda/(1+2*lambda)
				*(matrix[1][i+1]+matrix[1][i-1]);
			for (i=0; i<matrix_size; i++)
			{
				matrix[0][i]=matrix[1][i];
				matrix[1][i]=matrix[2][i];
				file<<setiosflags(ios::left)<<setw(15)<<matrix[2][i]<<" "<<flush;
			//	filex<<a_value+i*dx<<endl;
			//	filey<<t_init+(j+1)*dt<<endl;
			//	filez<<matrix[2][i]<<endl;
			}
			matrix[2][0]=g1(t_init+dt*j);
			matrix[2][matrix_size-1]=g2(t_init+dt*j);
			file<<endl;
		}
		if (!flag)
		{
			next_value=matrix[1][int((x-a_value)/(b_value-a_value)*matrix_size)];
			previous_value=-next_value;
			flag=true;
		}
		else
		{
			previous_value=next_value;
			next_value=matrix[1][int((x-a_value)/(b_value-a_value)*matrix_size)];
		}
		cout<<"X= "<<x<<" T= "<<t<<" U(X,T)= "<<next_value<<" size= "<<vector_size<<endl;
		vector_size*=2;
		file.close();
		filex.close();
		filey.close();
		filez.close();
	}
	while (fabs(next_value-previous_value)>error);
	/*
	ofstream filex("datax.txt",ios::out);
	ofstream filey("datay.txt",ios::out);
	ofstream filez("dataz.txt",ios::out);
	for (i=0; i<100; i++)
		for(int j=0; j<10; j++)
		{
			filey<<t_init+i*dt<<endl;
			filex<<a_value+j*dx<<endl;
			filez<<matrix[i][j]<<endl;
		}
	filex.close();
	filey.close();
	filez.close();*/
}