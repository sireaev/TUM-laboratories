#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * transformare(char text[]) {
    int c = 0, d = 0;
    char txt2[1000];
    while (text[c] != '\0') {
        if (text[c] == ' ') {
            int temp = c + 1;
            if (text[temp] != '\0') {
                while (text[temp] == ' ' && text[temp] != '\0') {
                    if (text[temp] == ' ') {
                        c++;
                    }
                    temp++;
                }
            }
        }
        txt2[d] = text[c];
        c++;
        d++;
    }
    txt2[d] = '\0';
    return txt2;
}

int main() {
    char txt1[1000], txt2[1000];
    system("cls");
    printf("Introdu secventa de text:\n");
    gets(txt1);
    printf("Secventa de text dupa procesare:\n");
    printf("%s", transformare(txt1));
    return 0;
}
