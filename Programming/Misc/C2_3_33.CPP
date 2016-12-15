#include <iostream.h>

int qualityPoints()
{
	int average;
	cout <<" Enter the student`s average : ";
	cin >>average;
	if (average>=90&&average<=100) return 4;
	if (average>=80&&average<=89) return 3;
	if (average>=70&&average<=79) return 2;
	if (average>=60&&average<=69) return 1;
	if (average<60) return 0;
	else return -1;
}

void main ()
{
	int n=qualityPoints();
	if (n==-1)
		cout <<"Exided averange !!! "<<endl;
	else 
		cout <<"Quality Points are : "<<n<<endl;
}