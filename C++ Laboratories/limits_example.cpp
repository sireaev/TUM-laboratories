#include <stdio.h>
#include <conio.h>
#include <limits.h>
#include <float.h>

void main(void) {
    clrscr();
    printf("\n Numarul de octeti pentru char=", CHAR_BIT);
    printf("\n INTmax=%d \t INTmin=%d", INT_MAX, INT_MIN);
    printf("\n FLOATmax=%e \t FLOATmin=%e", FLT_MAX, FLT_MIN);
    printf("\n DOUBLEmax=%e \t DOUBLEmin=%e \n", DBL_MAX, DBL_MIN);
}
