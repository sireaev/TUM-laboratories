#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
#define pi 3.14159

float factorial(int fac) {
    int i;
    float factor = 1;
    if (fac == 0) return 1;
    else
        for (i = 1; i <= fac; i++)
            factor *= i;
    return factor;
}

double putere(float x, int n) {
    int i, m;
    float p = 1;
    m = fabs(n);
    if (m == 0) return 1;
    else
        for (i = 1; i <= m; i++)
            p *= x;
    if (n > 0) return p;
    else return 1 / p;
}

int main() {
    system("cls");
    int n, k;
    float a, b, h, suma, eps, term, xtab[15], x;
    a = pi / 12;
    b = (11 * pi) / 12;
    eps = putere(10, -5);
    h = (b - a) / 10;
    x = 0;
    printf("\t\t\t|---------------------------------|\n");
    printf("\t\t\t|     X     |  Suma    |   Sin(x) |\n");
    printf("\t\t\t|---------------------------------|\n");

    for (n = 0; n < 10; n++) {
        x = a + (n * h);
        suma = 0;
        k = 1;
        term = 1;
        while (fabs(term) > eps) {
            term = putere(x, 2 * k - 1) / factorial(2 * k - 1);
            if (k % 2 == 0)
                suma -= term;
            else
                suma += term;
            xtab[n] = suma;
            k++;
        }
        printf("\t\t\t|x=%3.6f | %7.6f | %7.6f |\n", x, xtab[n], sin(x));
    }
    printf("\t\t\t|---------------------------------|\n");
    getch();
}
