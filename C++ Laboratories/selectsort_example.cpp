#include<stdio.h>
#include<stdlib.h>
#define dim 10
int tab[dim];

void main() {
    int selectsort(int[], int);
    int i;
    for (i = 0; i < dim; i++)
        tab[i] = random(103);
    printf("\n Tabelul initial: \n");
    for (i = 0; i < dim; i++)
        printf(" %3d ", tab[i]);

    selectsort(tab, dim);

    printf("\n Tabelul sortat: \n");
    for (i = 0; i < dim; i++)
        printf(" %3d ", tab[i]);
    printf("\n");
}

int selectsort(int a[], int m) {
    int i, k, locmin;
    float min;
    for (k = 0; k < m - 1; k++) {
        min = a[k];
        locmin = k;
        for (i = k + 1; i < m; i++)
            if (a[i] < min) {
                min = a[i];
                locmin = i;
            }
        a[locmin] = a[k];
        a[k] = min;
    }
    return a[m];
}
