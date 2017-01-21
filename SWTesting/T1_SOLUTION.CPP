//
// Targil 1
//
#include <stdio.h>
#include <conio.h>
#include <iostream>
void main()
{
#define matrice_rows 20 ;
#define vec_rows  20 ;
int I, J, m_size=3, SUM_VECTOR=0, SUM_ROW=0;
int m_a[10][10], VECTOR_ROWSUMS[5] ;
int m_b[20][matrice_rows] ;
int vec_r[vec_rows];
float fi, fj ; char ci, cj ;
long li, lj ;
fi = 0.0 ;
fj = 0.0 ;
ci = 'c' ;
cj = 'c' ;
li = 0 ;
lj = 0 ;
//
//  (MATRICE SIZE: 5*5)
// ENTER UNTIL MATRICE VALUES, 
//
// 
for(I=0; I<m_size; I++)
 {
  for (J=0; J<m_size; J++)
   {
    printf("Enter Matrice numbers  "); 
    scanf("%d",&m_a[I][J]);
   }
 }
//
// SUM the SUM of the Rows, into VECTOR_ROWSUMS[] 
// 
 for (I=0; I< m_size; I++)				
 {
  for(J=0; J< m_size; J++)
  {
   SUM_ROW += m_a[I][J] ;
   if (J == m_size - 1 )			// if at END OF ROW, save SUM_ROW
     {						//    into VECTOR_ROWSUMS
      VECTOR_ROWSUMS[I] = SUM_ROW;
	  SUM_ROW = 0;

     }
   }  
  }
//
// sum the vector VECTOR_ROWSUMS
//
 for (I=0 ; I < m_size ; I++) SUM_VECTOR += VECTOR_ROWSUMS[I] ;
//
// Print the values of matrice m_a
//
 for(I=0; I< m_size; I++)
 {
  for (J=0; J< m_size; J++)
  { printf("m_a[%d][%d]= %d ",I,J,m_a[I][J]); if (J == m_size - 1) printf ("\n"); }
 }
//
// print the values of VECTOR_ROWSUMS and its sum SUM_VECTOR
//
 for (I=0 ; I < m_size ; I++) 
	 printf ("The VECTOR_ROWSUMS[%d] = %d \n", I,VECTOR_ROWSUMS[I]);
//
 printf ("The vector sum is %d", SUM_VECTOR);
} /* End of program */

