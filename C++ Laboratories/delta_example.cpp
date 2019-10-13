/**************************
 * This program is created*
 *  by Sireaev Vladislav  *
 **************************/
#include <stdio.h>
#include <math.h>
#include <conio.h>

void main(void)
//Declararea variabilelor
{
    float a1, a2, a3, b1, b2, b3, c1, c2, c3, d1, d2, d3, delta, x, y, z, deltaX, deltaY, deltaZ;

    clrscr();
    //Citirea datelor
    printf("\nIntrodu a1:");
    scanf("%f", & a1);
    printf("\nIntrodu a2:");
    scanf("%f", & a2);
    printf("\nIntrodu a3:");
    scanf("%f", & a3);
    printf("\nIntrodu b1:");
    scanf("%f", & b1);
    printf("\nIntrodu b2:");
    scanf("%f", & b2);
    printf("\nIntrodu b3:");
    scanf("%f", & b3);
    printf("\nIntrodu c1:");
    scanf("%f", & c1);
    printf("\nIntrodu c2:");
    scanf("%f", & c2);
    printf("\nIntrodu c3:");
    scanf("%f", & c3);
    printf("\nIntrodu d1:");
    scanf("%f", & d1);
    printf("\nIntrodu d2:");
    scanf("%f", & d2);
    printf("\nIntrodu d3:");
    scanf("%f", & d3);

    //Calcularea delta

    delta = (a1 * b2 * c3) + (b1 * c2 * a3) + (a2 * b3 * c1) - (c1 * b2 * a3) - (b1 * a2 * c3) - (c2 * b3 * a1);
    printf("\n Delta este egala cu=%f \t", delta);

    //Calcularea deltaX, deltaY, deltaZ

    if (delta != 0) {
        deltaX = (d1 * b2 * c3) + (b1 * c2 * d3) + (d2 * b3 * c1) - (c1 * b2 * d3) - (b1 * d2 * c3) - (c2 * b3 * d1);
        printf("\n DeltaX este egala cu=%f \t", deltaX);

        deltaY = (a1 * d2 * c3) + (d1 * c2 * a3) + (a2 * d3 * c1) - (c1 * d2 * a3) - (d1 * a2 * c3) - (c2 * d3 * a1);
        printf("\n DeltaY este egala cu=%f \t", deltaY);

        deltaZ = (a1 * b2 * d3) + (b1 * d2 * a3) + (a2 * b3 * d1) - (d1 * b2 * a3) - (b1 * a2 * d3) - (d2 * b3 * a1);
        printf("\n DeltaY este egala cu=%f \t", deltaZ);

        //Calcularea x, y, z
        x = deltaX / delta;
        printf("\n X este egal cu=%f \t", x);

        y = deltaY / delta;
        printf("\n Y este egal cu=%f \t", y);

        z = deltaZ / delta;
        printf("\n Z este egal cu=%f \t", z);
    } else {
        printf("Determinantul este 0");
        goto L;
    }

    L: getch();
}