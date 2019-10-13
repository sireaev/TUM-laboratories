#include <iostream>
#include <math.h>

using namespace std;

int main () {
	float x[] = {2.5, 3.9, 2.9, 2.4, 2.9, 0.8, 9.1, 0.8, 0.7, 7.9, 1.8, 1.9, 0.8, 6.5, 1.6, 5.8, 1.3};
	float y[] = {211, 167, 131, 191, 220, 297, 71, 211, 300, 107, 167, 266, 227, 86, 207, 115, 285};

	int n = sizeof(x) / sizeof(*x);
	int i;
	float sumXB = 0, sumYB = 0;
	for(i = 0; i < n; i++) {
		sumXB += x[i];
		sumYB += y[i];
	}
	
	sumXB /= n;
	sumYB /= n;
	
	float lista1[n], lista1a[n];
	float d = 0, f = 0, sumaXpatrat = 0, XY = 0;
	
	float lista2[n], lista2a[n], lista3;
	for(i = 0; i < n; i++) {
		d = x[i] - sumXB; 
		f = d * d; // X[i] - X barat la patrat
		lista1[i] = d;
		lista1a[i] = f;
		sumaXpatrat += f;
		
		d = y[i] - sumYB;
		f = d * d;
		lista2[i] = d;
		lista2a[i] = f;
		
		lista3[i] = lista1[i] * lista2[i];
		XY += lista3[i];
	}
	
	float b = XY / sumaXpatrat;
	float a = sumYB - b * sumXB;
	
	//Determinarea y potential = a + b * x	
	float lista4[n];
	for(i = 0; i < n; i++) {
		lista4[i] = a + b * x[i];
	}
	
	//Calcul y - y potential
	// lista6 - y - y potential la patrat
	float lista5[n], lista6[n], yMinPotPatrat = 0;
	for(i = 0; i < n; i++) {
		d = y[i] - lista4[i];
		lista5[i] = d;
		f = d * d;
		lista6[i] = f;
		yMinPotPatrat += lista6[i];		
	}
	
	//Calcul df
	int df = n - 2;
	//Calcul s
	float s = yMinPotPatrat / df;
	float S = sqrt(s);
	float SE = S / sumaXpatrat;
	
}
