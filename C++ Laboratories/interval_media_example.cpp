#include <iostream>
#include <math.h>
#include <cstdlib>
#include <algorithm>
#include <time.h>

#define N 10
#define N2 5
#define T 2.262
#define T1 2.101
#define T2 2.776

using namespace std;

int main() {
    srand(time(NULL)); //initialize the random seed
    float vector[252];
    int j, n = 10;
    for (int i = 0; i < 252; i++) {
        j = i + 1;
        vector[i] = j;
    }
    int length = sizeof(vector) / sizeof(vector[0]);
    random_shuffle( & vector[0], & vector[length]);
    cout << vector[0] << endl;
    int first_length = length / 2;
    float v11[first_length];
    float v12[first_length];
    for (int i = 0; i < first_length; i++) {
        v11[i] = vector[i];
        v12[i] = vector[first_length + i];
    }
    random_shuffle( & v11[0], & v11[first_length]);
    random_shuffle( & v12[0], & v12[first_length]);
    cout << "\nVector v11\n" << endl;
    for (int i = 0; i < first_length; i++) {
        cout << v11[i] << " ";
    }
    cout << "\n" << endl;
    cout << "\nVector v12\n" << endl;
    for (int i = 0; i < first_length; i++) {
        cout << v12[i] << " ";
    }
    float x1[N], x2[N];
    for (int i = 0; i < N; i++) {
        x1[i] = v11[i];
        x2[i] = v12[i];
    }
    cout << "\n\nx1 = ";
    for (int i = 0; i < N; i++) {
        cout << x1[i] << " ";
    }
    cout << "\n\nx2 = ";
    for (int i = 0; i < N; i++) {
        cout << x2[i] << " ";
    }
    //CALCULUL X BARAT PENTRU X1 si X2
    float sum1 = 0;
    float sum2 = 0;
    for (int i = 0; i < N; i++) {
        sum1 += x1[i];
        sum2 += x2[i];
    }
    float X1B = sum1 / N;
    float X2B = sum2 / N;
    //CALCULUL S PENTRU VECTORUL X1
    float rList1[N] = {};
    float d = 0, f = 0;
    float secondarySum1 = 0;
    for (int i = 0; i < 10; i++) {
        d = x1[i] - X1B;
        f = d * d;
        rList1[i] = f;
        secondarySum1 += rList1[i];
    }
    sum1 = sqrt(secondarySum1 / N - 1);
    //CALCULUL S PENTRU VECTORUL X2
    float rList2[N] = {};
    float secondarySum2 = 0;
    for (int i = 0; i < 10; i++) {
        d = x2[i] - X2B;
        f = d * d;
        rList2[i] = f;
        secondarySum2 += rList2[i];
    }
    sum2 = sqrt(secondarySum2 / N - 1);

    //CALCULUL MIU PENTRU AMBELE INTERVALE
    float miu1Substraction = 0, miu2Substraction = 0,
        miu1Addition = 0, miu2Addition = 0;

    miu1Substraction = X1B - T * (sum1 / sqrt(N));
    miu1Addition = X1B + T * (sum1 / sqrt(N));
    miu2Substraction = X2B - T * (sum2 / sqrt(N));
    miu2Addition = X2B + T * (sum2 / sqrt(N));
    cout << "\n" << endl;
    cout << "\nIntervalul de incredere pentru x1 este: " <<
        "[" << miu1Substraction << ", " << miu1Addition << "]" << endl;

    cout << "\nIntervalul de incredere pentru x2 este: " <<
        "[" << miu2Substraction << ", " << miu2Addition << "]" << endl;

    //CALCULUL sp
    float sp = sqrt((secondarySum1 + secondarySum2) / ((N - 1) + (N - 1)));

    //CALCULUL INTERVALULUI DELTA1/DELTA2
    double delta1 = (X1B - X2B) - T1 * sp * sqrt((0.1) * 2);
    double delta2 = (X1B - X2B) + T1 * sp * sqrt((0.1) * 2);
    cout << "\nDelta1 este " << "[" << delta1 << ", " << delta2 << "]" << endl;

    //CALCULUL VECTORULUI Y0
    random_shuffle( & v12[0], & v12[first_length]);
    float y0[N], y1[N2], y2[N2];
    cout << "\ny0 = [";
    for (int i = 0; i < N; i++) {
        y0[i] = v12[i];
        cout << " " << y0[i];
    }
    cout << "]";
    //CALCULUL VECTORULUI Y1 si Y2
    random_shuffle( & y0[0], & y0[N]);
    float sum3 = 0, sum4 = 0;
    cout << "\ny1 = [";
    for (int i = 0; i < N2; i++) {
        y1[i] = y0[i];
        sum3 += y1[i];
        cout << " " << y1[i];
    }
    cout << "]";
    cout << "\ny2 = [";
    for (int i = 0; i < N2; i++) {
        y2[i] = y0[i + N2];
        sum4 += y2[i];
        cout << " " << y2[i];
    }
    cout << "]" << endl;
    //CALCULUL Y BARAT PENTRU Y1 si Y2
    float Y1B = sum3 / N2;
    float Y2B = sum4 / N2;
    //CALCULUL S PENTRU VECTORUL Y1
    float secondarySum3 = 0, secondarySum4 = 0;
    sum3 = 0;
    sum4 = 0;
    float rList3[N2];
    for (int i = 0; i < N2; i++) {
        d = y1[i] - Y1B;
        f = d * d;
        rList3[i] = f;
        secondarySum3 += f;
    }
    sum3 = sqrt(secondarySum3 / n - 1);
    //CALCULUL S PENTRU VECTORUL Y2
    float rList4[N2];
    for (int i = 0; i < N2; i++) {
        d = y2[i] - Y2B;
        f = d * d;
        rList4[i] = f;
        secondarySum4 += f;
    }
    sum4 = sqrt(secondarySum4 / n - 1);
    //CALCULUL MIU PENTRU AMBELE INTERVALE MIU11 - Y1; MIU22 - Y2
    float miu11Substraction = Y1B - T * (sum1 / sqrt(N2));
    float miu11Addition = Y1B + T * (sum1 / sqrt(N2));
    float miu22Substraction = Y2B - T * (sum2 / sqrt(N2));
    float miu22Addition = Y2B + T * (sum2 / sqrt(N2));
    cout << "\nIntervalul y1= [" << miu11Substraction << ", " << miu11Addition << "]" << endl;
    cout << "Intervalul y2= [" << miu22Substraction << ", " << miu22Addition << "]" << endl;
    cout << "\n";
    //CALCULUL D = Y1 - Y2
    float D[N2];
    cout << "D = ";
    sum1 = 0;
    for (int i = 0; i < N2; i++) {
        D[i] = y1[i] - y2[i];
        sum1 += D[i];
        cout << " " << D[i];
    }
    cout << "\n";
    //CALCULUL D barat
    float DB = sum1 / N2;
    sum1 = 0;
    //CALCULUL D-D barat la patrat
    for (int i = 0; i < N2; i++) {
        d = D[i] - DB;
        sum1 += d * d;
    }
    float secondarySum5 = 0;
    //CALCULUL S de D
    secondarySum5 = sqrt(sum1 / (N2 - 1));
    //CALCULUL DELTA
    float delta3 = DB - T2 * secondarySum5 / (sqrt(N2));
    float delta4 = DB + T2 * secondarySum5 / (sqrt(N2));
    cout << "\nDelta2 este [" << delta3 << ", " << delta4 << "]" << endl;
    //CALCULUL T-TEST
    //delta = (X1B - X2B) +- T * sp * sqrt(1/N1+1/N2)
    float sp1x = sqrt((secondarySum1 + secondarySum2) / (N - 1) + (N - 1));
    float delta1x = (X1B - X2B) - T * sp1x * sqrt(0.2);
    float delta2x = (X1B - X2B) + T * sp1x * sqrt(0.2);
    cout << "\nIntervalul in t-test pentru delta1 este [" << delta1x << ", " << delta2x << "]" << endl;
    float sp1y = sqrt((secondarySum3 + secondarySum4) / (N - 1) + (N - 1));
    float delta1y = (Y1B - Y2B) - T * sp1y * sqrt(0.4);
    float delta2y = (Y1B - Y2B) + T * sp1y * sqrt(0.4);
    cout << "\nIntervalul in t-test pentru delta2 este [" << delta1y << ", " << delta2y << "]" << endl;
    int randIndex = rand() % length;
    int randValue = vector[randIndex];
    if (randValue > delta1 && randValue < delta2) {
        cout << "\nValoarea: " << randValue << " se include in intervalul delta1 - [" << delta1 << ", " << delta2 << "]" << endl;
    } else {
        cout << "\nValoarea: " << randValue << " nu se include in intervalul delta1 - [" << delta1 << ", " << delta2 << "]" << endl;
    }
    if (randValue > delta3 && randValue < delta4) {
        cout << "\nValoarea: " << randValue << " se include in intervalul delta2 - [" << delta3 << ", " << delta4 << "]" << endl;
    } else {
        cout << "\nValoarea: " << randValue << " nu se include in intervalul delta2 - [" << delta3 << ", " << delta4 << "]" << endl;
    }
    cout << "\n" << endl;
    return 0;
}