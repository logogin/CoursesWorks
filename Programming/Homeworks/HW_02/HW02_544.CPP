// 20.11.2000 Dmitry Zavyalov (c)
//
// 5.44 - Write program that reads a date in the first format
// ( 11/21/99 ) and prints that date in the second format.
// ( November 21, 1999 )

#include <iostream.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>

main(void)
{
	clrscr();

	int DaysInM[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31	};

	char Mon[][9] = {"January",  "February", "March",    "April",
			 "May",       "June",    "July",     "August",
			 "September", "October", "November", "December"	};

	int ErrorFlag;
	int Month, Day,  Year;
	char DateInput[9]=" ";

	do{
		ErrorFlag=0;

		cout<<"Date Eample: 04/26/75\n"
			<<"Please, Enter our date: ";
		cin>>DateInput;                         // Date Input

		Month= atoi( strtok(DateInput,"/") );	// converting data
		Day  = atoi( strtok(NULL,"/") );	// from char to int
		Year = atoi( strtok(NULL,"/") );

		if( Month>12 || Month<1 ) {             // Month input check
			ErrorFlag=1;                    // for errors
			cout<<"Error in MONTH"
				<<endl;
		}

		if( Day>DaysInM[Month-1] || Day<1 ) {   // Day input check
			ErrorFlag=1;                    // for errors
			cout<<"Error in DAY"
				<<endl;
		}

		if( Year < 1 ) {                        // Year input check
			ErrorFlag=1;			// for errors
			cout<<"Error in YEAR"
				<<endl;
		}
		cout<<endl;			// If ErrorsFlag=1 then
	} while(ErrorFlag!=0);			// go to Data Input

	cout<<Mon[Month-1] <<" "		// Output to Screen Month
		<<Day <<", ";     		// -- --  //  -- -- Day

	if(Year<10)cout<<"190";			// -- --  //  -- -- Year
	else cout<<"19";

	cout<<Year
		<<endl;

	cout<<endl;
	cout<<"Press any key to continue...";
	getch();
	return (0);
}