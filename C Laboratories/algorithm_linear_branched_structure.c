#include <stdio.h>
#include <conio.h>
#include <math.h>

void main(void) {
    float a = -0.8, b = 1.9, d, x, n = 150606, f;
    clrscr();
    d = 1 + 1.E-6 * n;
    printf("\nIntrodu data initiala x:");
    scanf("%f", & x);
    if (x < b / 2) {
        f = sqrt(fabs(a) + x * x) + b / d * x * log10(b - x);
    } else {
        f = exp(x / d) + (a / d) * (sin(pow(x, 0.25))) + x / (pow(x, 0.33) + sqrt(sqrt(sqrt(x))) + pow(x, 0.11));
    }
    printf("\na)x=%f \nb)Afiseaza rezultatul functiei=%f \nc)Parametrul d=%f", x, f, d);
    getch();
}