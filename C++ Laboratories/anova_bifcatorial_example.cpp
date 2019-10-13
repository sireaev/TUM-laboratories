using namespace std;
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <time.h>
#include <iomanip>

#define N 5.0
#define sizeN 5

int main() {
	float vector[252];
	int a = 3, b = 4;
	int A1[] = {70,77,82,85};
	int A2[] = {83,77,94,84};
	int A3[] = {81,74,72,68};

	int B1[] = {70, 83, 81};
	int B2[] = {77, 77, 74};
	int B3[] = {82, 94, 72};
	int B4[] = {85, 84, 68};
	
	int matrice[][3] = {
		{70, 83, 81},
		{77, 77, 74},
		{82, 94, 72},
		{85, 84, 68}
	};

	float B[21] = {
		70,77,82,
		85,83,77,
		94,84,81,
		74,72,68,
		70,83,81,
		77,77,74,
		85,84,68
	};

	int dfa = a - 1;
	int dfb = b - 1;
	int dfe = dfa * dfb;
	
	float sumA1 = 0, sumA2 = 0, sumA3 = 0,
	sumB1 = 0, sumB2 = 0, sumB3 = 0, sumB4 = 0;

	for(int i = 0; i < 4; i++) {
		sumA1 += A1[i];
		sumA2 += A2[i];
		sumA3 += A3[i];
	}

	for(int i = 0; i < 3; i++) {
		sumB1 += B1[i];
		sumB2 += B2[i];
		sumB3 += B3[i];
		sumB4 += B4[i];
	}

	float XBA1 = (float)sumA1/b;
	float XBA2 = (float)sumA2/b;
	float XBA3 = (float)sumA3/b;

	float XBB1 = (float)sumB1/a;
	float XBB2 = (float)sumB2/a;
	float XBB3 = (float)sumB3/a;
	float XBB4 = (float)sumB4/a;

	float XBA[] = {XBA1, XBA2, XBA3};
	float XBB[] = {XBB1, XBB2, XBB3, XBB4};

	float sumXBA = 0;
	for(int i = 0; i < 3; i++) {
		sumXBA += XBA[i];
	};
	float sumXBB = 0;
	for(int i = 0; i < 4; i++) {
		sumXBB += XBB[i];
	};

	float xDubluA = (float)sumXBA / a;
	float xDubluB = (float)sumXBB / b;

	int lengthXBA = sizeof(XBA)/sizeof(*XBA);
	float sumaXBA = 0, d = 0, f = 0;
	for(int i = 0; i < lengthXBA; i++) {
		 d = XBA[i] - xDubluA;
		 f = d * d;
		 sumaXBA += f;
	}
	int lengthXBB = sizeof(XBB)/sizeof(*XBB);
	float sumaXBB = 0;

	for(int i = 0; i < lengthXBB; i++) {
		d = XBB[i] - xDubluA;
		f = d * d;
		sumaXBB += f;
	}

	//CALCUL SSA, MSA, SSB, MSB
	float ssa = b * sumaXBA;
	float msa = ssa / (a - 1);
	float ssb = a * sumaXBB;
	float msb = ssb / (b -1);

	float prim[lengthXBA];
	for(int i = 0; i < lengthXBA; i++) {
		f = xDubluA + (XBA[i] - xDubluA) + (XBB[i] - xDubluA);
		prim[i] = f;
	}

	int lengthMatrice = sizeof(matrice) / sizeof(*matrice);
	float h = 0, sumaLista = 0;
	int k = 0, m = 0;
	float lista[lengthMatrice*3];
	for(int i = 0; i < lengthMatrice; i++) {
		for(int j = 0; j < 3; j++) {
			h = j - prim[k];
			f = h * h;
			lista[m] = f;
			sumaLista += lista[m];
			k++; m++;
			if(k == 3) {
				k = 0;
			}
		}
	}
	
	float sse = sumaLista;
	float mse = sse/((a-1) * (b-1));
	float Fa = msa/mse;
	float Fb = (float)msb/(float)mse;
	
	k = 0;
	float SS = 0;
	for(int i = 0; i < lengthMatrice; i++) {
		for(int j = 0; j < 3; j++) {
			h = j - xDubluA;
			f = h * h;
			SS += f;
			if(k == 3) {
				k = 0;
			}
		}
	}
	
	float dfTotal = a * b - 1;
	
	//CREAREA TABELULUI
	cout << "\n+----------+---------+----+-------+------+---------+" << endl;
	cout << "|" << setw(7) << " " << setw(4) << "|" << setw(6) << "SS" << setw(4) << "|" << setw(3) << "df" << setw(2) << "|"
	<< setw(5) << "MS" << setw(3) << "|" << setw(3) << "F" << setw(4) << "|" << setw(8) << "p-value" << setw(2) << "|" << endl;
	cout << "+----------+---------+----+-------+------+---------+" << endl;
	
	cout << "|" << setw(9) << "Factor A" << setw(2) << "|" << setw(8) << fixed << setprecision(2) << ssa << setw(2) << "|" 
	<< setw(3) <<  dfa << setw(2) << "|"	<< setw(4) << msa << setw(2) << "|" << setw(5) << Fa << setw(2) << "|" << setw(7)
	<< "p<0.25" << setw(3) << "|" << endl;

	cout << "|" << setw(9) << "Factor B" << setw(2) << "|" << setw(8) << fixed << setprecision(2) << ssb << setw(2) << "|" 
	<< setw(3) << dfb << setw(2) << "|"	<< setw(6) << msb << setw(2) << "|" << setw(5) << Fb << setw(2) << "|" << setw(7)
	<< "p>0.25" << setw(3) << "|" << endl;
	
	cout << "|" << setw(9) << "Residual" << setw(2) << "|" << setw(8) << fixed << setprecision(2) << sse << setw(2) << "|" 
	<< setw(3) << dfe << setw(2) << "|"	<< setw(6) << mse << "|" << setw(5) << "-" << setw(1) << "|" << setw(7)
	<< "-" << setw(3) << "|" << endl;
	
	cout << "|" << setw(9) << "Total" << setw(2) << "|" << setw(8) << fixed << setprecision(2) << SS << setw(2) << "|" 
	<< setw(3) << dfTotal << setw(2) << "|"	<< setw(6) << "-" << "|" << setw(5) << "-" << setw(1) << "|" << setw(7)
	<< "-" << setw(3) << "|" << endl;
	cout << "+----------+---------+----+-------+------+---------+" << endl;
	
	return 0;}
