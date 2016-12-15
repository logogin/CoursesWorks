// 16.11.2000 Dmitry Zavyalov (c)
//
// 4.17
//	Program that simulates the rolling of two dice
// and calculate the sum of the two values.

#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>





#include <string.h>
#include <time.h>
#include <iomanip.h>

main(void)
{
	clrscr();

	const unsigned int RollNum=36000;	// number of dice rolling
	unsigned int Counter, CheckSum=0;
	int Dice_1, Dice_2, HighResult=0;
	int Sum2d[11] = {0};            	// array fo two dice sum


	randomize();				// macro that initializes
						// random number generator
	for(Counter=0; Counter<RollNum; Counter++ ){
		Dice_1=random(6)+1;		// first dice rolling
		Dice_2=random(6)+1;         	// second dice rolling
		Sum2d[(Dice_1+Dice_2)-2]++; 	// sum calculation
	}
						// finding frequently fall out dice sum
	for(Counter=0; Counter<11; Counter++ ){
		if(Sum2d[Counter]>Sum2d[HighResult]) HighResult=Counter;
	}

	for(Counter=0; Counter<11; Counter++ ){
		cout<<setw(2)
			<<Counter+2             // output result to screen
			<<". "
			<<setw(4)
			<<Sum2d[Counter]
			<<setw(16);

		if(HighResult==Counter) cout<<"reasonable !!!";
		else cout<<"not reasonable";
		cout<<endl;

		CheckSum+=Sum2d[Counter];	// CheckSum counting:
	}                               	// all dice sum = 36000
	cout<<"------------------------\n"
		<<"CheckSum = "             	// output CheckSum to screen
		<<CheckSum
		<<endl;

	cout<<endl;
	cout<<"Press any key to continue...";
	getch();
	return (0);
}