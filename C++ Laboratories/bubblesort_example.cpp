#include<stdio.h>
#include<stdlib.h>
#define dim 10
float tab[dim];

main() {
    extern void bubblesort(float x[], int m);
    int i;
    for (i = 0; i < dim; i++)
        tab[i] = rand() % 100;
    printf("\n Tabelul initial:\n");
    for (i = 0; i < dim; i++)
        printf(" %3.1f ", tab[i]);

    bubblesort(tab, dim);

    printf("\n Tabelul sortat:\n");
    for (i = 0; i < dim; i++)
        printf(" %3.1f ", tab[i]);
    printf("\n");
}

void bubblesort(float a[], int m) {
    int i, j;
    float temp;

    for (i = 0; i < m; i++)
        for (j = i; j > 0; j--)
            if (a[j] < a[j - 1]) {
                temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
            }
}
