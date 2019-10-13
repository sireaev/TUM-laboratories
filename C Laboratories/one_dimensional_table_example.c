#include <stdio.h>
#include <conio.h>
#include <math.h>

void main(void) {
    int A[28], P[28], I[28], S[28], D[28], i;
    clrscr();
    printf("Introdu 28 de elemente:\n");
    for (i = 0; i < 28; i++) scanf("%d", & A[i]);
    clrscr();
    for (i = 0; i < 28; i++) printf("%3d", A[i]);
    printf("\n\n");
    printf("\n{");
    for (i = 0; i < 28; i += 2) {
        P[i] = A[i];
        printf("%3d", P[i]);
    }
    printf("\t}");
    printf("\n{");
    for (i = 1; i < 28; i += 2) {
        I[i] = A[i];
        printf("%3d", I[i]);
    }
    printf("\t}");
    printf("\n{");
    for (i = 0; i < 28; i += 2) {
        S[i] = P[i] + I[i + 1];
        printf("%3d", S[i]);
    }
    printf("\t}");
    printf("\n{");
    for (i = 0; i < 28; i += 2) {
        D[i] = P[i] - I[i + 1];
        printf("%3d", D[i]);
    }
    printf("\t}");
    getch();
}