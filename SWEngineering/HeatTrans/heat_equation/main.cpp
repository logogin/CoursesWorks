#include "function.h"
#include "temp.h"
//#include "temperature.h"

int main(int argc, char *argv[]){
	double *pdPresentStateVector;
	double *pdNextIterationVector;
	double dC;			// Specific heat
	double dR;			// Consistence of stuff
	double dK;			// Thermal conductivity
	double dALFA;		// T(x,t)t = alfa * T(x,t)xx
	double dDT, dDX;
	double power;
	double dA, dB;		// bounds of rod (left, right)
	double dTinit, dTend;	// bounds of time
	double dTOL;
	bool test;
	double dFreeMemory;

	dA = 5.0;
	dB = 5.4;
	dR = 7.133;
	dC = 0.3831;
	dK = 1.13;
	dTinit = 12000;
	dTend = 15000;
	dFreeMemory = 1.0;
	power = 1;
	dTOL = 0.001;
/*
	cout<<"Enter left bound of rod, [m]: ";
	cin>>dA;
	cout<<"Enter right bound of rod, [m]: ";
	cin>>dB;
	assert(dA<dB);
	cout<<"Enter tolerance of culculation, [Cel]: ";
	cin>>dTOL;
	cout<<"Enter cpecific heat, [Joul/kg-kelvin]: ";
	cin>>dC;
	cout<<"\nEnter thermal conductivity, [Joul/cm-kelvin-sec]: ";
	cin>>dK;
	cout<<"\nEnter consistence of stuff, [gr/cm^3]: ";
	cin>>dR;
	assert(dC>0 && dK>0 && dR>0);
	cout<<"What are free memory space : ";
	cin>>dFreeMemory;
*/

	dALFA = 0.0001 * dK / (dC*dR);
cout<<dALFA<<endl;
// ------------ building present iteration -----------
	dDX = (dB-dA)/pow(2.0, power);
	dDT = pow (dDX, 2)/dALFA;
	pdPresentStateVector = new double[(int)pow(2.0, power)+1];
	vNextIteration(pdPresentStateVector, dTinit, dTend, (int)pow(2.0, power), dDX, dDT, dA, dB);

// ------------ building next iteration -----------
	test = true;
	do{
		power++;
		dDX = (dB-dA)/pow(2.0, power);
		dDT = pow(dDX, 2)/dALFA;
		pdNextIterationVector = new double[(int)pow(2.0, power)+1];
		vNextIteration(pdNextIterationVector, dTinit, dTend, (int)pow(2.0, power), dDX, dDT, dA, dB);
		if(bCheckTolerance(pdPresentStateVector, pdNextIterationVector, dTOL, dA, dB, power)){
			test = false;
			delete(pdNextIterationVector);
			delete(pdPresentStateVector);		
		}
		else{
			delete(pdPresentStateVector);
			pdPresentStateVector = pdNextIterationVector;
		}
	}while(test);
// ========================================================================

	cout<<"dx = "<<dDX<<endl;
	cout<<"dt = "<<dDT<<endl;
	cout<<"iN = "<<pow(2.0, power)<<endl;
	cout<<"power = "<<power<<endl;


	if(((dTend - dTinit)/dDT * pow(2.0, power) + 1024) / pow(1024.0, 3.0)> dFreeMemory)
		cout<<"\nIsn't enough free memory for calculation with this accuracy!"<<endl;
  	else vfInsertIntoFile(argv[argc-2], dTinit, dTend, dDX, dDT, (int)pow(2.0, power), dA, dB);	

	test = true;
	while(test){
		switch(cfMenu()){
		case '1': vfTemperatureInPointXT(dA, dB, dTinit, dTend, dDT, (int)pow(2.0, power) + 1);
			break;
		case '2': vfTemperatureInTimeT(argv[argc-1], dA, dB, dDT, dTinit, dTend, (int)pow(2.0, power) + 1);
			break;
		case '3': vfTemperatureInPointX(argv[argc-1], dA, dB, dDT, dTinit, dTend, (int)pow(2.0, power) + 1);
			break;
		case 'q':test = false;
			break;
		default:cout<<"\nDecide between the four variants : 1, 2, 3, q"<<endl;
			break;
		}
	}



/*	
	if(((dTend - dTinit)/dDT * pow(2.0, power) + 1024) / pow(1024.0, 3.0)> dFreeMemory)
		cout<<"\nIsn't enough free memory for calculation with this accuracy!"<<endl;
	else{
		vfInserIntoBinaryFile(argv[argc-1], dTinit, dTend, dDX, dDT, (int)pow(2.0, power) + 1, dA, dB);
		test = true;
		while(test){
			switch(cfMenu()){
			case '1': vfTemperatureInPointXT(dA, dB, dTinit, dTend, dDT, (int)pow(2.0, power) + 1, argv[argc-1]);
				break;
			case '2': vfTemperatureInTimeT(argv[argc-1], argv[argc-2], dA, dB, dDT, dTinit, dTend,
										   (int)pow(2.0, power) + 1);
				break;
			case '3': vfTemperatureInPointX(argv[argc-1], argv[argc-2], dA, dB, dDT, dTinit, dTend,
												(int)pow(2.0, power) + 1);
				break;
			case 'q':test = false;
				break;
			default:cout<<"\nDecide between the four variants : 1, 2, 3, q"<<endl;
				break;
			}
		}
	}
*/

	return 0;
}
