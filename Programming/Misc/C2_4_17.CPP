#include <iostream.h>
#include <iomanip.h>
#include <windows.h>

void main ()
{
	int d1;
	int d2;
	int combinations[11]={0};
	int probability[11]={1,2,3,4,5,6,5,4,3,2,1};
	
	cout <<"Rolling dices ..."<<endl;
	
	for (int i=0; i<36000; i++)
	{
		d1=rand()%6+1;
		d2=rand()%6+1;
		combinations[d1+d2-2]++;
	}
	
	cout <<endl<<
		"Sum"<<setw(22)<<
		"Current Probability"<<setw(19)<<
		"Real Probability"<<setw(17)<<
		"Number of sums"<<endl; 

	for (i=0; i<11; i++)
		cout<<setw(2)<<
		i+2<<setw(22)<<
		(float)combinations[i]/36000<<setw(19)<<
		(float)probability[i]/36<<setw(17)<<
		combinations[i]<<endl;
}