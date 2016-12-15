#include <iostream.h>
#include <stdlib.h>
#include <time.h>
#include "Male.h"
#include "Female.h"
#include "Child.h"

void main()
{
	const char *colors[7]={"White","Yellow","Red","Black","Brown","Blue","Blond"};
	const unsigned char Skin[4]={White,Yellow,Red,Black};
	const unsigned char Hair[4]={Blond,Red,Brown,Black};
	const unsigned char Eye[3]={Blue,Brown,Black};

	srand((unsigned)time(NULL));

	Child Son(Skin[rand()%4],Hair[rand()%4],Eye[rand()%3],
		140.0+(float)(rand()%7000)/100.0,45.0+(float)(rand()%8500)/100.0,
		Skin[rand()%4],Hair[rand()%4],Eye[rand()%3],
		140.0+(float)(rand()%7000)/100.0,45.0+(float)(rand()%8500)/100.0);

	Female *Mother=&Son;
	Male *Father=&Son;
	
	cout <<"Father :"<<endl;
	cout <<"Skin : "<<colors[Father->GetSkin()]<<endl;
	cout <<"Hair : "<<colors[Father->GetEye()]<<endl;
	cout <<"Eye : "<<colors[Father->GetEye()]<<endl;
	cout <<"High : "<<Father->GetHigh()<<" cm"<<endl;
	cout <<"Weight : "<<Father->GetWeight()<<" kg"<<endl;

	cout <<"Mother :"<<endl;
	cout <<"Skin : "<<colors[Mother->GetSkin()]<<endl;
	cout <<"Hair : "<<colors[Mother->GetEye()]<<endl;
	cout <<"Eye : "<<colors[Mother->GetEye()]<<endl;
	cout <<"High : "<<Mother->GetHigh()<<" cm"<<endl;
	cout <<"Weight : "<<Mother->GetWeight()<<" kg"<<endl;

	cout <<"Son :"<<endl;
	cout <<"Skin : "<<colors[Son.GetSkin()]<<endl;
	cout <<"Hair : "<<colors[Son.GetEye()]<<endl;
	cout <<"Eye : "<<colors[Son.GetEye()]<<endl;
	cout <<"High : "<<Son.GetHigh()<<" cm"<<endl;
	cout <<"Weight : "<<Son.GetWeight()<<" kg"<<endl;
}