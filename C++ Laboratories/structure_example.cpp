#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

typedef struct spital {
    long nrfis;
    char numele[45];
    char prenumele[45];
    int zi;
    int luna;
    int an;
    char domiciliu[45];
    long politasig;
    int izi, iluna, ian;
    int ozi, oluna, oan;
}
SP;
main() {
    int i, j, n, k, inpz, inpl, inpan;
    SP NR1[100], temp[100];
    system("cls");
    printf("Bine ai venit in SPITALUL NR.1\n");
    printf("Introdu nr de pacienti:");
    scanf("%d", & n);
    printf("Introdu datele pacientilor:\n");
    for (i = 0; i < n; i++) {
        printf("\nPacient nr.%d:", i + 1);
        printf("\nIntrodu numarul fisei:");
        scanf("%d", & NR1[i].nrfis);
        printf("Introdu numele:");
        scanf("%s", & NR1[i].numele);
        printf("Introdu prenumele:");
        scanf("%s", & NR1[i].prenumele);
        printf("Introdu ziua nasterii:");
        scanf("%d", & NR1[i].zi);
        printf("Introdu luna nasterii:");
        scanf("%d", & NR1[i].luna);
        printf("Introdu anul nasterii:");
        scanf("%d", & NR1[i].an);
        printf("Introdu domiciliul:");
        scanf("%s", & NR1[i].domiciliu);
        printf("Introdu numarul politei de asigurare:");
        scanf("%li", & NR1[i].politasig);
        printf("Introdu data de intrare:\n");
        printf("Ziua:");
        scanf("%d", & NR1[i].izi);
        printf("Luna:");
        scanf("%d", & NR1[i].iluna);
        printf("Anul:");
        scanf("%d", & NR1[i].ian);
        printf("Introdu data de iesire:\n");
        printf("Ziua:");
        scanf("%d", & NR1[i].ozi);
        printf("Luna:");
        scanf("%d", & NR1[i].oluna);
        printf("Anul:");
        scanf("%d", & NR1[i].oan);
    }
    printf("\nIntrodu datele perioadei de vizualizare:\n");
    printf("Introdu ziua:");
    scanf("%d", & inpz);
    printf("Introdu luna:");
    scanf("%d", & inpl);
    printf("Introdu anul:");
    scanf("%d", & inpan);
    //Sortarea datelor dupa nume
    for (k = 1; k < n; k++) {
        for (j = k; j > 0; j--) {
            if (NR1[j].numele > NR1[j - 1].numele) {
                temp[0] = NR1[j];
                NR1[j] = NR1[j - 1];
                NR1[j - 1] = temp[0];
            }
        }
    }
    printf("-------------------------------------------------------------------------------------------------------------------\n");
    printf("|Nr.| Fisa    | Nume      | Prenume    | D.nasterii | Domiciliul    | P.Asigurare     |   Intrat   |   Iesire    |\n");
    for (i = 0; i < n; i++)
    //Verifica daca pacientii se afla in perioada data
    {
        if ((NR1[i].izi <= inpz) && (NR1[i].iluna <= inpl) && (NR1[i].ian <= inpan) &&
            (NR1[i].ozi >= inpz) && (NR1[i].oluna >= inpl) && (NR1[i].oan >= inpan)) {
            printf("|%2d | %4d  | %8.10s  | %8.10s   | %2d.%2d.%2d |  %10.15s       |    %d      | %d.%d.%2d| %2d.%2d.%2d |\n",
                i + 1, NR1[i].nrfis, NR1[i].numele, NR1[i].prenumele, NR1[i].zi, NR1[i].luna, NR1[i].an, NR1[i].domiciliu,
                NR1[i].politasig, NR1[i].izi, NR1[i].iluna, NR1[i].ian, NR1[i].ozi, NR1[i].oluna, NR1[i].oan);
        }
    }
    printf("-------------------------------------------------------------------------------------------------------------------\n");
    getch();
}
