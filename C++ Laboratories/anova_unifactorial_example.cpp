using namespace std;

#include <iostream>
#include <math.h>
#include <cstdlib>
#include <algorithm>
#include <time.h>
#include <iomanip>

#define N 5.0
#define sizeN 5

int main() {
    srand(time(NULL));
    float vector[252];
    int j;
    //VECTORUL INITIAL FAT[][1], CARE E DE LA 1 LA 252 (CASE)
    for (int i = 0; i < 252; i++) {
        j = i + 1;
        vector[i] = j;
    }
    int length = sizeof(vector) / sizeof(vector[0]);
    random_shuffle( & vector[0], & vector[length]);
    float vector1[sizeN], vector2[sizeN], vector3[sizeN], vector4[sizeN], vector5[sizeN];
    int numar1 = 0, numar2 = 0, numar3 = 0, numar4 = 0;
    for (int i = 0; i < 25; i++) {
        if (i < N) vector1[i] = vector[i];
        if (i > 4 && i < 10) vector2[numar1++] = vector[i];
        if (i > 9 && i < 15) vector3[numar2++] = vector[i];
        if (i > 14 && i < 20) vector4[numar3++] = vector[i];
        if (i > 19 && i < 25) vector5[numar4++] = vector[i];
    }

    float sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0;
    for (int i = 0; i < N; i++) {
        //Se calculeaza suma elementelor a 5 tablouri
        sum1 += vector1[i];
        sum2 += vector2[i];
        sum3 += vector3[i];
        sum4 += vector4[i];
        sum5 += vector5[i];
    }
    cout << "vector1  [";
    for (int i = 0; i < N; i++) {
        cout << " " << vector1[i];
    }
    cout << "]" << endl;

    cout << "vector2  [";
    for (int i = 0; i < N; i++) {
        cout << " " << vector2[i];
    }
    cout << "]" << endl;
    cout << "vector3  [";
    for (int i = 0; i < N; i++) {
        cout << " " << vector3[i];
    }
    cout << "]" << endl;
    cout << "vector4  [";
    for (int i = 0; i < N; i++) {
        cout << " " << vector4[i];
    }
    cout << "]" << endl;
    cout << "vector5  [";
    for (int i = 0; i < N; i++) {
        cout << " " << vector5[i];
    }
    cout << "]" << endl;
    //CALCUL X1B (X1 barat) pentru fiecare tablou
    float listXbarat[5];
    listXbarat[0] = sum1 / N;
    listXbarat[1] = sum2 / N;
    listXbarat[2] = sum3 / N;
    listXbarat[3] = sum4 / N;
    listXbarat[4] = sum1 / N;

    //CALCUL SUMA LISTEI X barat
    float sumListBarat = 0;
    for (int i = 0; i < N; i++) {
        sumListBarat += listXbarat[i];
    }

    //CALCUL X DUBLU BARAT
    float xDubluBarat = sumListBarat / N;

    //CALCUL SUMA PRODUSULUI DIFERENTEI DINTRE X DUBLU BARAT SI X BARAT A FIECARUI X BARAT
    float rList[sizeN], d = 0, f = 0, sumXbarat = 0;
    for (int i = 0; i < N; i++) {
        d = listXbarat[i] - xDubluBarat;
        f = d * d;
        rList[i] = f;
        //Suma X barat
        sumXbarat += rList[i];
    }
    //Calculul SSA
    float ssa = N * sumXbarat;
    cout << "\nSSA = " << ssa << endl;
    //CALCUL DIFERENTA DINTRE ELEMENTELE FIECARUI VECTOR SI X BARAT
    //DIFERENTA CARUIA SE REDICA LA PATRAT SI SE STOCHEAZA INTR-UN VECTOR
    float rList1[sizeN], rList2[sizeN], rList3[sizeN], rList4[sizeN], rList5[sizeN];
    for (int i = 0; i < N; i++) {
        d = vector1[i] - listXbarat[0]; //X1B
        d = d * d;
        rList1[i] = d;

        d = vector2[i] - listXbarat[1]; //X2B
        d = d * d;
        rList2[i] = d;

        d = vector3[i] - listXbarat[2]; //X3B
        d = d * d;
        rList3[i] = d;

        d = vector4[i] - listXbarat[3]; //X4B
        d = d * d;
        rList4[i] = d;

        d = vector5[i] - listXbarat[4]; //X5B
        d = d * d;
        rList5[i] = d;
    }
    //CALCUL SSE
    float sse = 0;
    for (int i = 0; i < sizeN; i++) {
        sse += rList1[i] + rList2[i] + rList3[i] + rList4[i] + rList5[i];
    }
    cout << "SSE = " << sse << endl;
    //CALCUL MSA
    float msa = ssa / N - 1; //n-1
    cout << "MSA = " << msa << endl;
    //CALCUL MSE
    float mse = sse / N * (N - 1);
    cout << "MSE = " << mse << endl;
    //CALCUL F-TEST
    f = msa / mse;
    cout << "F = " << f << endl;
    //GRADUL DE LIBERTATE
    int df1 = N - 1;
    int df2 = N * (N - 1);
    cout << "df = " << df1 << " si " << df2 << endl;

    //CREAREA TABELULUI
    cout << "\n+----------+---------+----+-------+------+" << endl;
    cout << "|" << setw(7) << "Sursa" << setw(4) << "|" << setw(6) << "SS" << setw(4) << "|" << setw(3) << "df" << setw(2) << "|" <<
        setw(5) << "MS" << setw(3) << "|" << setw(3) << "F" << setw(4) << "|";
    cout << "\n+----------+---------+----+-------+------+" << endl;
    cout << "|" << setw(7) << "Datele" << setw(4) << "|" << setw(8) << fixed << setprecision(2) << ssa << setw(2) << "|" <<
        setw(3) << df1 << setw(2) << "|" << setw(4) << msa << "|" << setw(5) << f << setw(2) << "|";
    cout << "\n|" << setw(7) << "Residual" << setw(3) << "|" << setw(9) << fixed << setprecision(2) << sse << "|" <<
        setw(4) << df2 << setw(1) << "|" << setw(7) << mse << "|" << setw(4) << "-" << "|";
    cout << "\n|" << setw(7) << "Total" << setw(4) << "|" << setw(9) << fixed << setprecision(2) << ssa + sse << "|" <<
        setw(4) << df1 + df2 << setw(1) << "|" << setw(7) << msa + mse << "|" << setw(4) << f << "|";
    cout << "\n+----------+---------+----+-------+------+" << endl;
    return 0;
}