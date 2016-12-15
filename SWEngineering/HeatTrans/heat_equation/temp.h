#include<iostream.h>
#include<stdlib.h>
#include<stdio.h>

void vfTemperatureInPointXT(double, double, double, double, double, int);
void vfTemperatureInTimeT(char *, double, double, double, double, double, int);
void vfTemperatureInPointX(char *, double, double, double, double, double, int);

// ---------- T(x,t) -----------------
void vfTemperatureInPointXT(double dA, double dB, double dTinit, double dTend, double dDT, int iN){
	int it, ix;
	double x, t, dx;
	double *pPVector = new double[iN];
	bool test = true;

	while(test){
		cout<<"Enter X = ";
		cin>>x;
		cout<<"Enter T = ";
		cin>>t;
		if(x<dA || x>dB) cout<<"Rod between coordinats "<<dA<<" and "<<dB<<endl;
		else if(t<dTinit || t>dTend) cout<<"Time between coordinats "<<dTinit<<" and "<<dTend<<endl;
		else test = false;
	}
	
	ix = (int)((x - dA)/((dB-dA)/(iN-1)));
	it = (int)((t-dTinit)/dDT);
	
	dx = (dB-dA)/iN;
	if(t<dTend) vNextIteration(pPVector, dTinit, t, iN - 1, dx, dDT, dA, dB);
	else vNextIteration(pPVector, dTinit, dTend, iN - 1, dx, dDT, dA, dB);

	if(x == dB) cout<<"T(x,t) = T("<<x<<"; "<<t<<") = "<<pPVector[ix];
	else{
		double l = (x - dA - ix * dx) / dx;
		double r = (dA + (ix + 1) * dx - x) / dx;
		cout<<"T(x,t) = T("<<x<<"; "<<t<<") = "<<l * pPVector[ix+1] + r	* pPVector[ix]<<endl;
	}
	delete(pPVector);
}

// ------------ Temperarure in each point of rod at time T ------------------
void vfTemperatureInTimeT(char *pcFileName, double dA, double dB, double dDT, double dTinit,
						  double dTend, int iN){
	FILE *fptr;
	bool test;
	double t, dx;
	double *pPVector = new double[iN]; 
	int it;
	test = true;
	while(test){
		cout<<"\nWhat time you interest? T = ";
		cin>>t;
		if(t<dTinit || t>dTend) cout<<"Input error!\nTime mast be between "<<dTinit<<" and "<<dTend<<endl;
		else test = false;
	}
	
	it = (int)((t-dTinit)/dDT);
	dx = (dB-dA)/(iN-1);

	if(t<dTend) vNextIteration(pPVector, dTinit, t, iN - 1, dx, dDT, dA, dB);
	else vNextIteration(pPVector, dTinit, dTend, iN - 1, dx, dDT, dA, dB);	
	
	fptr = fopen(pcFileName, "w");
		for(int i=0; i<iN; i++) fprintf(fptr, "%f\t%f\n", dA + i*dx, pPVector[i]);
	fclose(fptr);
	delete(pPVector);
}


















// --------- Temperature in point X at each time of process ------------------
void vfTemperatureInPointX(char *pcFileName, double dA, double dB, double dDT, double dTinit,
						   double dTend, int iN){
	FILE *fptr;
	bool test;
	double x, dx;
	int it, ix, i = 0;
	double *pPVector = new double[iN];

	test = true;
	while(test){
		cout<<"\nWhat point you interest? X = ";
		cin>>x;
		if(x<dA || x>dB) cout<<"Input error!\nCoordinate mast be between "<<dA<<" and "<<dB<<endl;
		else test = false;
	}

	it = (int)((dTend-dTinit)/dDT);
	ix = (int)((x - dA)/((dB-dA)/(iN-1)));
	dx = (dB-dA)/(iN-1);

	fptr = fopen(pcFileName, "w");
	pPVector[i] = (leftBoundaryCondition(dTinit) + initialCondition(dA))/2;
	for(i++; i < iN - 1; i++) pPVector[i] = initialCondition(dA + i*dx);
	pPVector[i] = (rightBoundaryCondition(dTinit)+initialCondition(dB))/2;
	
	double l = (x - dA - ix * dx) / dx;
	double r = (dA + (ix + 1) * dx - x) / dx;

	if(x == dB) fprintf(fptr, "%f\t%f\n", dTinit, pPVector[ix]);
	else fprintf(fptr, "%f\t%f\n", dTinit, r*pPVector[ix] + l*pPVector[ix+1]);
	
	for(i=1; i<=it; i++){
		vNextVector(pPVector, iN, i*dDT);
		if(x == dB) fprintf(fptr, "%f\t%f\n", dTinit + i*dDT, pPVector[ix]);
		else fprintf(fptr, "%f\t%f\n", dTinit + i*dDT, r*pPVector[ix] + l*pPVector[ix+1]);
	}

	if(dTinit + (i-1)*dDT < dTend) vNextVector(pPVector, iN, dTend);
	if(x == dB) fprintf(fptr, "%f\t%f\n", dTend, pPVector[ix]);
	else fprintf(fptr, "%f\t%f\n", dTend, r*pPVector[ix] + l*pPVector[ix+1]);


	fclose(fptr);
	delete(pPVector);
}
