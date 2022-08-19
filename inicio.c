#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void titulo ();
int opcionesMenu(int i);
int main (){
	char tecla;
	int seleccion, i=0;
	while (tecla!=10){
		system("color 02");
		titulo ();
		seleccion=opcionesMenu(i);
		tecla=getch();
		if (tecla=='s'||tecla=='S') {
			i++;
		}
		if (tecla=='w'||tecla=='W'){
			i--;
		}
		if(tecla==13){
			if (seleccion==0){
				puts("comenzar");//colocar funcion
				system ("pause");
			}
			else {
				if (seleccion==1){
					puts("puntuaciones");
					system ("pause");
				}
				else {
					tecla=10;
				}
			}
		}
		if (i<0){
			i=0;
		}
		if (i>2){
			i=2;
		}
		system("cls");
	}
	return 0;
}
	
void titulo (){
	puts("\n");
	puts("\t===================================================\n");
	puts("\t   #####            ##         ##  ##");
	puts("\t ##     ##                     ## ##    ##");
	puts("\t ##     ##  ##  ##  ##  #####  ####    #  #  # ###");
	puts("\t ##     ##  ##  ##  ##  ##     ####    ####  ##"); 
	puts("\t ##   # ##  ##  ##  ##  ##     ## ##   #     ##");
	puts("\t   #####    ######  ##  #####  ##  ##  ####  ##");
	puts("\t        #   ");
	puts("\t===================================================\n");
}
int opcionesMenu(int i){
	switch (i){
		case 0: puts("\t\t\tSelecciona:");
				puts("\t\t\t-> Empezar"); 
				puts("\t\t\t   Puntuaciones"); 
				puts("\t\t\t   Salir"); 
				puts("\n\t\t\t\t\t\tWCORP. 2020."); return 0;
		case 1: puts("\t\t\tSelecciona:");
				puts("\t\t\t   Empezar"); 
				puts("\t\t\t-> Puntuaciones"); 
				puts("\t\t\t   Salir"); 
				puts("\n\t\t\t\t\t\tWCORP. 2020."); return 1;
		case 2: puts("\t\t\tSelecciona:");
				puts("\t\t\t   Empezar"); 
				puts("\t\t\t   Puntuaciones"); 
				puts("\t\t\t-> Salir"); 
				puts("\n\t\t\t\t\t\tWCORP. 2020."); return 2;
	}
	return 0;
}
