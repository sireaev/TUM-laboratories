#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <ctype.h>

char *identificator(char *context) {
	if(isdigit(context[0])) printf("asd");
	if(strlen(context) <= 6) printf("\n<instructiune> -> <identificator>");
}

char *prog(char *context) {
	char *found = NULL;
	found = strstr(context, "program");
	if(found) printf("\n<program> -> <lista de instructiuni>");
}

char *expresie(char *context) {
	char *found = NULL;
	int delay = 0;
	while(!found) {
		delay++;
		found = strstr(context, "+");
		if(found) break;
		found = strstr(context, "-");
		if(found) break;
		found = strstr(context, "*");
		if(found) break;
		found = strstr(context, "/");
		if(found) break;
		found = strstr(context, "**");
		if(found) break;
		if(delay == 2) break;
	}

	if(found) {
		if(found[1] == '*') goto exponent;
		switch(found[0]) {
			case '+' : printf("\n<expresie> -> <expresie><operatie><expresie>\n<operatie> -> +"); break;
			case '-' : printf("\n<expresie> -> <expresie><operatie><expresie>\n<operatie> -> -"); break;
			case '*' : printf("\n<expresie> -> <expresie><operatie><expresie>\n<operatie> -> *"); break;
			case '/' : printf("\n<expresie> -> <expresie><operatie><expresie>\n<operatie> -> /"); break;
		}
		exponent: 
		switch(found[1]) {
			case '*' : printf("\n<expresie> -> <expresie><operatie><expresie>\n<operatie> -> **"); break;
		}
	}
}

main() {
	char program[255];
	
	printf("FORTRAN INTERPRETATION");
	printf("\nFORTRAN: ");gets(program);
	
	prog(program);
	identificator(program);
	expresie(program);
	
	getch();
}
