/***********************
 * Welcome to my second*
 * CPP program.        *
 * Sireaev Vladislav   *
 ***********************/

//Declararea librariilor
#include <stdio.h>
#include <math.h>
#include <conio.h>
#define pi 3.14159

void main(void) {
    //Declaram variabilele
    int raza, l_tr, l_pat, s_pat;
    float s_cerc, s_tr;

    /*Citirea datelor de la tastatura*/
    printf("\n Introdu raza cercului");
    scanf("%d", & raza);
    printf("\n Introdu latura patratului");
    scanf("%d", & l_pat);
    printf("\n Introdu latura triunghiului");
    scanf("%d", & l_tr);
    getch();

    /* Calculam aria patratului */
    s_pat = l_pat * l_pat;
    /* Calculam aria cercului */
    s_cerc = pi * raza * raza;
    /* Calculam aria triunghiului lateral */
    s_tr = (l_tr * l_tr * sqrt(3)) / 4;
    clrscr();

    printf("\n Aria cercului=%12.6f \n Aria patratului=%10d \n Aria triunghiului=%12.1f", s_cerc, s_pat, s_tr);

}