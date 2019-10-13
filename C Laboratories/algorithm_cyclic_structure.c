#include <stdio.h>
#include <conio.h>
#include <math.h>

void main(void) {
    double a = -0.8, b = 1.9, d, x, h, f;
    float A[12], B[12];
    int i, n = 12;
    clrscr();
    d = 1 + 1.E-06 * n;
    printf("\nDatele sunt implicit introduse in program!\n");
    h = (b - a) / n;
    x = a;
    printf(" _________________________");
    printf("\t\n|      X     |     F      |");
    printf("\t\n|____________|____________|");
    n = 0;
    while (x <= b && n < 12) {
        if (x < b / 2) {
            f = sqrt(fabs(a) + x * x) + b / d * x * log10(b - x);
        }
        else {
            f = exp(x / d) + (a / d) * (sin(pow(x, 0.25))) + x / (pow(x, 0.33) +
                sqrt(sqrt(sqrt(x))) + pow(x, 0.11));
        }
        printf("\t\n|  %7.3f   |   %7.3f  |", x, f);
        A[n] = x;
        B[n] = f;
        x += h;
        n++;
    }
    printf("\n|____________|____________|");
    printf("\n-------------------------------------------------");
    printf("\n __________________________________________________");
    printf("\n|X |");
    for (i = 0; i < n; i += 2) printf("%7.3f|", A[i]);
    printf("\n|Y |");
    for (i = 0; i < n; i += 2) printf("%7.3f|", B[i]);
    printf("\n --------------------------------------------------");
    getch();
}