//
#include <iostream.h>
#include <conio.h>
#include <stdio.h>
//#include <iomainip.h>

void  GetResult(int, int);

int main()
{
  int Num1, Num2;
  clrscr();

  cout<<"Enter 2 Integers" <<endl;
  cin>>Num1 >>Num2;

  GetResult(Num1, Num2);

  getch();
  return 0;
}

void  GetResult(int Int1, int Int2)
  {
	int Counter1, Counter2;

	for(Counter1=1; Counter1<=Int1; Counter1++){
	  for(Counter2=1; Counter2<=Int2; Counter2++){
		cout<<Counter1*Counter2 <<"   ";
	  }
	  cout<<"\n" <<endl;
	}
	printf("OK!");
  }