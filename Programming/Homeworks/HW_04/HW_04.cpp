// 14.12.2000 Dmitry Zavyalov (c)
//
// Home Work No4 (class Passport)

#include <iostream.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "sex.h"
#include "date.h"
#include "name.h"
#include "passport.h"

#define Max 5

int CheckPeople( Passport* );
int Exit(void);

void main()
{
	Passport aPeople_pas[Max];
	int Flag=-1;

	while( Exit() ) {
		Flag = CheckPeople( aPeople_pas );

		switch( Flag ) {
			case  1: cout<<"\nTrue" <<endl	; break;
			case  0: cout<<"\nFalse" <<endl	; break;
			default:						  break;
		}
	}
}

int Exit(void)
{
	int Ret=-1;
	char Input;

	do {
		cout<<"Do You want to End Program ? (Y/N) : ";
		cin>>Input;
		if( Input=='Y' || Input=='y' ) Ret=0;
		if( Input=='N' || Input=='n' ) Ret=1;
	} while( Ret==-1 );

	return( Ret );
}

int CheckPeople( Passport *P_Pas )
{
	int Ret=-1, Counter;
	int C_Name=0, C_Date=0, C_Sex=0;	// Counters for Name, Date & Sex

	Name MyName;
	char name[256]=" ";
	char surname[256]=" ";
	MyName.GetFullName( name, surname );

	char nameP[256]=" ";
	char surnameP[256]=" ";

	for( Counter=0; Counter<Max; Counter++ ){
		P_Pas[Counter].GetFullName( nameP, surnameP );

		if( strcmp(name, nameP)==0 && strcmp( surname, surnameP)==0 ) C_Name=1;

		if( C_Name==1 ) {
			Date MyDate;
			if( MyDate.GetDay() == P_Pas[Counter].GetDay() &&
				MyDate.GetMonth() == P_Pas[Counter].GetMonth() &&
				MyDate.GetYear() == P_Pas[Counter].GetYear() ) C_Date=1;
		}

		if( C_Name==1 && C_Date==1 ) {
			Sex MySex;
			if( MySex.GetPSex() == P_Pas[Counter].GetPSex() ) C_Sex=1;
		}
	}

	if( C_Name==1 && C_Date==1 && C_Sex==1 ) Ret=1;

	return( Ret );
}
