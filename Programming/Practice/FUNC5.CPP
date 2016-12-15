#include <stdio.h>
#include <conio.h>
#include <math.h>

long factorial(int n)
 {
  long f=1;
  for (int i=2; i<=n; i++)
   f*=i;
  return f;
 }
double _pow(double x, int n)
 {
  double p=1;
  for (int i=1; i<=n; i++)
   p*=x;
  return p;
 }
void main()
 {

  double _exp=0;
  float x;
  clrscr();
  printf("Enter x : ");
  scanf("%f",&x);
  _exp=(double)1+x;
  for (int i=2; i<15; i++)
   _exp+=_pow(x,i)/factorial(i);
  printf("exp(x)=%.17f\n",_exp);
  printf("Real value is %.17f",exp(x));
  getch();
 }