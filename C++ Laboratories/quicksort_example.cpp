#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#define dim 12

void quicksort(float tab[], int inf, int sup) {
    int i, j;
    float t, x;
    x = tab[inf];
    i = inf;
    j = sup;
    while (i < j) {
        while (tab[i] <= x && i < sup) i++;
        while (tab[j] > x) j--;
        if (i < j) {
            t = tab[i];
            tab[i] = tab[j];
            tab[j] = t;
        }
    }
    if (j > inf) {
        tab[inf] = tab[j];
        tab[j] = x;
    }
    if (inf < j - 1) quicksort(tab, inf, j - 1);
    if (j + 1 < sup) quicksort(tab, j + 1, sup);
}

void main() {
    float a[dim];
    int i;
    clrscr();
    for (i = 0; i < dim; i++)
        a[i] = rand() % 100;
    printf("\n Tabelul initial: \n");
    for (i = 0; i < dim; i++)
        printf(" %3.1f ", a[i]);
    quicksort(a, 0, dim - 1);
    printf("\n Tabelul sortat: \n");
    for (i = 0; i < dim; i++)
        printf(" %3.1f ", a[i]);
    printf("\n");
}
