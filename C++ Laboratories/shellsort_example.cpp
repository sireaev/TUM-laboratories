#include<stdio.h>
#include<stdlib.h>
#define dim 10

void main(void) {
    float a[dim];
    int i, j, inc, n;
    float temp;
    for (i = 0; i < dim; i++)
        a[i] = rand() % 100;
    printf("\n Tabelul initial:\n");
    for (i = 0; i < dim; i++)
        printf(" %3.1f ", a[i]);
    for (inc = n / 2; inc > 0; inc /= 2)
        for (i = inc; i < n; i++)
            for (j = i - inc; j >= 0 && a[j] > a[j + inc]; j -= inc) {
                temp = a[j];
                a[j] = a[j + inc];
                a[j + inc] = temp;
            }
    printf("\n Tabelul sortat:\n");
    for (i = 0; i < dim; i++)
        printf(" %3.1f ", a[i]);
    printf("\n");
}
