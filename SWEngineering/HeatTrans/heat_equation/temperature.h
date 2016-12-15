#include<iostream.h>
#include<stdlib.h>
#include<stdio.h>

void vfTemperatureInPointXT(double, double, double, double, double, int, char *);
void vfTemperatureInTimeT(char *, char *, double, double, double, double, double, int);
void vfTemperatureInPointX(char *, char *, double, double, double, double, double, int);

// ---------- T(x,t) -----------------
void vfTemperatureInPointXT(double dA, double dB, double dTinit, double dTend, double dDT, int iN, char *pFileName){
	FILE *pFile;
	int it, ix;
	double dTooPresentPoints[3], dTooNextPoints[3];
	double x, t;
	double dt, dx;
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
	if(t == dTend){
		pFile = fopen(pFileName, "r");			
		fseek(pFile, (long)((iN*it + ix) * sizeof(double)), SEEK_SET);
		fread(dTooPresentPoints, sizeof(double), 2, pFile);
		dx = (dB-dA)/(iN-1);
		double l = (x - dA - ix * dx) / dx;
		double r = (dA + (ix + 1) * dx - x) / dx;
		cout<<"T(x,t) = T("<<x<<"; "<<t<<") = "<<l * dTooPresentPoints[1] + r	* dTooPresentPoints[0]<<endl;
		fclose(pFile);
	}
	else{
		pFile = fopen(pFileName, "r");
		fseek(pFile, (long)((iN*it + ix) * sizeof(double)), SEEK_SET);
		fread(dTooPresentPoints, sizeof(double), 2, pFile);

		fseek(pFile, (long)((iN-2) * sizeof(double)), SEEK_CUR);
		fread(dTooNextPoints, sizeof(double), 2, pFile);	
		
		dx = (dB-dA)/(iN-1);
		double l = (x - dA - ix * dx) / dx;
		double r = (dA + (ix + 1) * dx - x) / dx;

		dTooPresentPoints[2] = l * dTooPresentPoints[1] + r	* dTooPresentPoints[0];
		dTooNextPoints[2] = l * dTooNextPoints[1] + r * dTooNextPoints[0];
	
		if(it == (int)((dTend-dTinit)/dDT)) dt = dTend - it*dDT-dTinit;
		else dt = dDT;
		cout<<"T(x,t) = T("<<x<<"; "<<t<<") = "<<((t-it*dDT-dTinit)/dt)*dTooNextPoints[2] +
											  ((dt-(t-it*dDT-dTinit))/dt)*dTooPresentPoints[2]<<endl;
		fclose(pFile);
	}
}

// ------------ Temperarure in each point of rod at time T ------------------
void vfTemperatureInTimeT(char *pcBinaryFileName, char *pcTextFileName, double dA, double dB, double dDT,
						  double dTinit, double dTend, int iN){
	FILE *pbf, *ptf;
	bool test;
	double t, dt;
	double *pdPresentVector, *pdNextVector;
	int it;
	test = true;
	while(test){
		cout<<"\nWhat time you interest? T = ";
		cin>>t;
		if(t<dTinit || t>dTend) cout<<"Input error!\nTime mast be between "<<dTinit<<" and "<<dTend<<endl;
		else test = false;
	}
	it = (int)((t-dTinit)/dDT);
	if(t == dTend){		
		pbf = fopen(pcBinaryFileName, "r");
		ptf = fopen(pcTextFileName, "w");
		fseek(pbf, sizeof(double), it * iN);
		double dTemp;
		for(int i=0; i<iN; i++){
			fread(&dTemp, sizeof(double), 1, pbf);
			fprintf(ptf, "%f\t%f\n", dA+i*((dB-dA)/(iN-1)), dTemp);
		}
		fclose(ptf);
		fclose(pbf);	
	}
	else{
		pdPresentVector = new double[iN];
		pdNextVector = new double[iN];
		pbf = fopen(pcBinaryFileName, "r");
		fseek(pbf, sizeof(double) * iN * it, SEEK_SET);
		fread(pdPresentVector, sizeof(double), iN, pbf);
		fread(pdNextVector, sizeof(double), iN, pbf);
		fclose(pbf);
		if(it == (int)((dTend-dTinit)/dDT)) dt = dTend - it*dDT-dTinit;
		else dt = dDT;
		ptf = fopen(pcTextFileName, "w");
		for(int i=0; i<iN; i++) fprintf(ptf, "%f\t%f\n", dA+i*((dB-dA)/(iN-1)),
				((dt-(t-dTinit-dDT*it))/dt)*pdPresentVector[i] + (t-dTinit-dDT*it)/dt*pdNextVector[i]);
		fclose(ptf);
		delete(pdNextVector);
		delete(pdPresentVector);
	}
}

// --------- Temperature in point X at each time of process ------------------
void vfTemperatureInPointX(char *pcBinaryFileName, char *pcTextFileName, double dA, double dB, double dDT,
						  double dTinit, double dTend, int iN){
	FILE *pbf, *ptf;
	bool test;
	double x;
	int it, ix, i;
	double dPresentX, dNextX;
	test = true;
	while(test){
		cout<<"\nWhat point you interest? X = ";
		cin>>x;
		if(x<dA || x>dB) cout<<"Input error!\nCoordinate mast be between "<<dA<<" and "<<dB<<endl;
		else test = false;
	}
	it = (int)((dTend-dTinit)/dDT);
	if(x == dB){
		pbf = fopen(pcBinaryFileName, "r");
		ptf = fopen(pcTextFileName, "w");
		fseek(pbf, sizeof(double)*(iN-1), SEEK_SET);
		for(i=0; i<=it; i++){
			fread(&dPresentX, sizeof(double), 1, pbf);
			fprintf(ptf, "%f\t%f\n", dTinit + i * dDT, dPresentX);
			fseek(pbf, sizeof(double)*(iN-1), SEEK_CUR);
		}
		fread(&dPresentX, sizeof(double), 1, pbf);
		fprintf(ptf, "%f\t%f\n", dTend, dPresentX);
		fclose(ptf);
		fclose(pbf);	
	}
	else{
		ix = (int)((x-dA)/((dB-dA)/(iN-1)));
		pbf = fopen(pcBinaryFileName, "r");
		ptf = fopen(pcTextFileName, "w");
		fseek(pbf, sizeof(double)*ix, SEEK_SET);
		double l = (x - (dA + (ix*((dB-dA)/(iN-1)))))/((dB-dA)/(iN-1));
		double r = ((dA + (ix+1)*((dB-dA)/(iN-1))) - x)/((dB-dA)/(iN-1));
		for(i=0; i<=it; i++){
			fread(&dPresentX, sizeof(double), 1, pbf);
			fread(&dNextX, sizeof(double), 1, pbf);
			fprintf(ptf, "%f\t%f\n", dTinit + i * dDT, r*dPresentX + l*dNextX);
			fseek(pbf, sizeof(double)*(iN-2), SEEK_CUR);
		}
		fread(&dPresentX, sizeof(double), 1, pbf);
		fread(&dNextX, sizeof(double), 1, pbf);
		fprintf(ptf, "%f\t%f\n", dTend, r*dPresentX + l*dNextX);
		fclose(ptf);
		fclose(pbf);
	}
}