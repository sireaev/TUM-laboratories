#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>

void main(void) {
    char t[6][10], m[10][10], d[100], c[100] = "nume numele numelelor pamint paminteni pamintesc\0";
    int i, j, l, k, aux;
    printf("%s\n", c);
    l = -1;
    for (i = 0; i < 6; i++)
        t[i][1] = '\0';
    for (i = 0; i < 6; i++)
        for (j = 0; j < 10; j++) {
            l++;
            if (c[l] == ' ') {
                t[i][j] = '\0';
                break;
            }
            t[i][j] = c[l];
        }
    for (i = 0; i < 6; i++) {
        printf("\n");
        for (j = 0; j < 9; j++) {
            if (t[i][j] == '\0') break;
            printf("%c", t[i][j]);
        }
    }
    printf("\n\n\n");
    aux = 0;
    for (i = 0; i < 6; i++) {
        aux = 0;
        for (j = 0; j < strlen(t[i]); j++)
            if (t[i][j] == t[i + 1][j]) {
                aux++;
            } //compara linia 1 cu a doau 

        if (aux == strlen(t[i]))
            for (j = 0; j < strlen(t[i]); j++) {
                printf("%c", t[i][j]);
            }
        printf("\n");
    }
    k = 0;
    for (i = 47; i >= 0; i--) {
        d[k] = c[i];
        k++;
    }

    printf("\n\n%s", d);
    getch();
}