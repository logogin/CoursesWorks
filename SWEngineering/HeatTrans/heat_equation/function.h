#include<iostream.h>
#include<math.h>
#include<assert.h>
#include<stdlib.h>
#include<stdio.h>

double leftBoundaryCondition(double);
double rightBoundaryCondition(double);
double initialCondition(double);
void vNextVector(double *, int, double);
void vNextIteration(double *, double, double, int, double, double, double, double);
bool bCheckTolerance(double *, double *, double , double , double , double);
double dTemperatureInX(double *, double, double, double, double);
double dMAX(double *, int);
void vfInsertIntoFile(char *, double, double, double, double, int, double, double);
char cfMenu();


//-------------- FUNCTION ----------------------------------------

// ----------- Building temperatur's vector in next level --------------------
void vNextVector(double *ptr, int iSIZE, double dTNext){
	double *pdVectorA = new double[iSIZE];
	double *pdVectorS = new double[iSIZE];
	int i = 1;
	pdVectorA[i] = 4;
	pdVectorS[i] = ptr[i-1] + ptr[i+1] + leftBoundaryCondition(dTNext);
	for(i++; i<iSIZE-1; i++){
		pdVectorA[i] = 4 - (1 / pdVectorA[i-1]);
		pdVectorS[i] = (ptr[i-1]+ptr[i+1])+pdVectorS[i-1]/pdVectorA[i-1];
	}
	pdVectorS[--i] += rightBoundaryCondition(dTNext);
	ptr[iSIZE-2] = pdVectorS[i] / pdVectorA[i];
	for(i--; i>0; i--) ptr[i] = (pdVectorS[i] + ptr[i+1]) / pdVectorA[i];
	ptr[0] = leftBoundaryCondition(dTNext);
	ptr[iSIZE-1] = rightBoundaryCondition(dTNext);
	delete(pdVectorA);
	delete(pdVectorS);
}

// ----------- Building of iteration ----------------------------
void vNextIteration(double *pVector, double dTinit, double dTend, int iN, double dDX, double dDT,
					double dA, double dB){
	double dTcurrent;
	bool test;
	int i = 0;
	pVector[i] = (leftBoundaryCondition(dTinit) + initialCondition(dA))/2;
	for(i++; i < iN; i++) pVector[i] = initialCondition(dA + i*dDX);
	pVector[i] = (rightBoundaryCondition(dTinit)+initialCondition(dB))/2;
	dTcurrent = dTinit;
	test = true;
	while(test){
		if(dTcurrent + dDT < dTend) dTcurrent += dDT;
		else{
			dTcurrent = dTend;
			test = false;
		}
		vNextVector(pVector, iN + 1, dTcurrent);		
	}
}

// -------- Checking of too last iterations by 10 points --------------------------
bool bCheckTolerance(double *pdPresentStateVector, double *pdNextIterationVector, double dTOL,
					 double dA, double dB, double power){
	double dSUMMA[20];
	double *dArrayX	= new double[20];
	for(int i=0; i<20; i++){
		dSUMMA[i] = 0;
		dArrayX[i] = dA + ((double)rand()/RAND_MAX) * (dB - dA);
	}
	for(i=0;i<20;i++){
		dSUMMA[i] = fabs(dTemperatureInX(pdPresentStateVector, dA, dB, (dB - dA)/pow(2.0, power-1),
									 dArrayX[i]) - dTemperatureInX(pdNextIterationVector,
									 dA, dB, (dB - dA)/pow(2.0, power), dArrayX[i]));
	}
	delete(dArrayX);
	if(dMAX(dSUMMA, 20)>dTOL) return false;	
	else return true;
}

// ---------- Finding to temperature in point (X, Tend) ----------------------
double dTemperatureInX(double *pdTemperatureVector, double dA, double dB, double dDX, double dX){
	double dTemperature;
	int iN;
	iN = (int)((dX - dA)/dDX);
	if(dX = dB) dTemperature = pdTemperatureVector[iN];
	else dTemperature = pdTemperatureVector[iN]*((dDX * (iN+1) - dX)/dDX) +
					    pdTemperatureVector[iN+1]*((dX - (dDX * iN))/dDX);
	return dTemperature;
}

// ---------- Finding of MAXIMUM in array ---------------
double dMAX(double *pdPoints, int size){
	double dMax = pdPoints[0];
	for(int i = 1; i < 10; i++) if(dMax < pdPoints[i]) dMax = pdPoints[i];
	return dMax;
}


// ---------- Making output binary file --------------
void vfInserIntoBinaryFile(char *pFileName, double dTinit, double dTend, double dDX, double dDT, int iN,
						   double dA, double dB){
	FILE *pFile;
	double *pVector = new double[iN];
	double dTcurrent;
	bool test;
	int i = 0;

	pVector[i] = (leftBoundaryCondition(dTinit) + initialCondition(dA))/2;
	for(i++; i < iN - 1; i++) pVector[i] = initialCondition(dA + i*dDX);
	pVector[i] = (rightBoundaryCondition(dTinit) + initialCondition(dB))/2;
	
	pFile = fopen(pFileName, "w");
	fwrite(pVector, sizeof(double), iN, pFile);
	dTcurrent = dTinit;
	test = true;
	while(test){
		if(dTcurrent + dDT < dTend) dTcurrent += dDT;
		else{
			dTcurrent = dTend;
			test = false;
		}
		vNextVector(pVector, iN, dTcurrent);		
	    fwrite(pVector, sizeof(double), iN, pFile);
	}
	delete(pVector);
	fclose(pFile);
}

// --------- Making output-file (table of data) ------------------------
void vfInsertIntoFile(char *pFileName, double dTinit, double dTend, double dDX, double dDT, int iN, double dA,
					  double dB){
	FILE *pFile;
	double *pVector = new double[iN+1];
	double dTcurrent;
	bool test;
	int i = 0;

	pVector[i] = (leftBoundaryCondition(dTinit) + initialCondition(dA))/2;
	for(i++; i < iN; i++) pVector[i] = initialCondition(dA + i*dDX);
	pVector[i] = (rightBoundaryCondition(dTinit) + initialCondition(dB))/2;
	
	pFile = fopen(pFileName, "w");
	fprintf(pFile, "time[s]/distance[m]\t|\t");
	for(i=0; i<=iN; i++) fprintf(pFile, "%f\t", i*dDX);
	fprintf(pFile, "\n");
	fprintf(pFile, "\n%f\t\t|\t", dTinit);
	for(i=0; i<=iN; i++) fprintf(pFile, "%f\t", pVector[i]);
	dTcurrent = dTinit;
	test = true;
	while(test){
		if(dTcurrent + dDT < dTend) dTcurrent += dDT;
		else{
			dTcurrent = dTend;
			test = false;
		}
		vNextVector(pVector, iN+1, dTcurrent);		
		fprintf(pFile, "\n%f\t\t|\t", dTcurrent);
		for(i=0; i<=iN; i++) fprintf(pFile, "%f\t", pVector[i]);
	}
	fclose(pFile);
}

// ------------- Menu -----------------
char cfMenu(){
	char ch[2];
	cout<<"\n\t========================================================"<<endl;
	cout<<"\t= Temperature of rod in time T in point X            1 ="<<endl;
	cout<<"\t= Temperature throughout the entire rod in time T    2 ="<<endl;
	cout<<"\t= Temperature in point X all time long               3 ="<<endl;
	cout<<"\t=------------------------------------------------------="<<endl;
	cout<<"\t= Exit                                               q ="<<endl;
	cout<<"\t========================================================"<<endl;
	ch[0] = cin.get();
	ch[1] = cin.get();
	return ch[0];
}




double leftBoundaryCondition(double dT){
	double test = 10;//1;
	if(test < -276.0) return -276.0;
	else return test;
}

double rightBoundaryCondition(double dT){
	double test = 10;//20 * sin(5*dT);
	if(test < -276.0) return -276.0;
	else return test;
}

double initialCondition(double dX){
	double test = 0;//40 * tan(0.01*dX);
	if(test < -276.0) return -276.0;
	else return test;
}

