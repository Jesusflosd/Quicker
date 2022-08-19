#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int gato();
int loop(char tabla [3][3]);
void iniciarTabla(char tabla[3][3]);
void imprimirTabla(char tabla[3][3]);
void introducirFicha(char tabla[3][3]);
void introducirIA(char tabla[3][3]);
int ganador(char tabla[3][3]);
int main (){
	gato ();
	
	
	return 0;
}
int gato (){
	char tabla[3][3];
	printf("%d",loop(tabla)); //probar salida
	sleep (2);
	system("cls");
	return 0;
}
int loop (char tabla[3][3]){
	int i=0,j;
	iniciarTabla(tabla);
	do {
		system("cls");
		imprimirTabla(tabla);
		if (i%2==0){
			
			introducirIA(tabla);
		}
		else {
			introducirFicha(tabla);
		}
		j=ganador(tabla);
		i++;
	}while(i<=8 && j==2);
	system("cls");
	imprimirTabla(tabla);
	if (j==1){
		puts("\tGanaste");
		return 1;
	}
	else {
		if (j==0) {
			puts("\tPerdiste"); 
			return 0;
		}
		else {
			puts ("\tEmpate");
			return 2;
		}
	} 
}
void iniciarTabla(char tabla[3][3]){
	int i,j;
	char aux='1';
	for (i=0;i<3;i++){
		for (j=0;j<3;j++){
			tabla[i][j]=aux++;
		}
	}
}
void imprimirTabla(char tabla[3][3]){
	int i,j;
	puts("\n");
	for (i=0;i<3;i++){
		printf("\t\t");
		for (j=0;j<3;j++){
			if (j<2){
				printf(" %c |",tabla[i][j]);
			}
			else {
				printf(" %c ",tabla[i][j]);
			}
		}
		if (i<2){
			puts("\n\t\t-----------");
		}
	}
	puts("\n\n");
}
void introducirFicha(char tabla[3][3]){
	int i,j,k;
	char ficha;
	do {
		do{
			printf("\tColoca tu ficha: ");
			fflush(stdin);
			scanf("%c", &ficha);
		} while(ficha<'1'||ficha>'9');
		k=0;
		switch (ficha){
			case '1': {
				i=0;
				j=0;
				if (tabla[i][j]=='X' || tabla[i][j]=='O'){
					k=1;
					puts("\tCasilla ocupada");
				}
				break;
			}
			case '2': {
				i=0;
				j=1;
				if (tabla[i][j]=='X' || tabla[i][j]=='O'){
					k=1;
					puts("Casilla ocupada");
				}
				break;
			}
			case '3': {
				i=0;
				j=2;
				if (tabla[i][j]=='X' || tabla[i][j]=='O'){
					k=1;
					puts("\tCasilla ocupada");
				}
				break;
			}
			case '4': {
				i=1;
				j=0;
				if (tabla[i][j]=='X' || tabla[i][j]=='O'){
					k=1;
					puts("\tCasilla ocupada");
				}
				break;
			}
			case '5': {
				i=1;
				j=1;
				if (tabla[i][j]=='X' || tabla[i][j]=='O'){
					k=1;
					puts("\tCasilla ocupada");
				}
				break;
			}
			case '6': {
				i=1;
				j=2;
				if (tabla[i][j]=='X' || tabla[i][j]=='O'){
					k=1;
					puts("\tCasilla ocupada");
				}
				break;
			}
			case '7': {
				i=2;
				j=0;
				if (tabla[i][j]=='X' || tabla[i][j]=='O'){
					k=1;
					puts("\tCasilla ocupada");
				}
				break;
			}
			case '8': {
				i=2;
				j=1;
				if (tabla[i][j]=='X' || tabla[i][j]=='O'){
					k=1;
					puts("\tCasilla ocupada");
				}
				break;
			}
			case '9': {
				i=2;
				j=2;
				if (tabla[i][j]=='X' || tabla[i][j]=='O'){
					k=1;
					puts("\tCasilla ocupada");
				}
				break;
			}
		}
	}while(k==1);
	tabla[i][j]='X';
}
void introducirIA(char tabla[3][3]){
	char aux;
	int i,j,k;
	srand(time(NULL));
	do {
		i=rand()%3;
		j=rand()%3;
		k=0;
		if (tabla[i][j]=='X' || tabla[i][j]=='O'){
			k=1;
		}
	}while (k==1);
	tabla[i][j]='O';
}
int ganador (char tabla[3][3]){
	if (tabla[0][0]=='X' || tabla[0][0]=='O'){
		if (tabla[0][0]==tabla[0][1]&& tabla[0][0]==tabla[0][2]){
			if (tabla[0][0]=='X'){
				return 1; //ganar
			}
			else {
				return 0;
			}
		}
		if (tabla[0][0]==tabla[1][0]&& tabla[0][0]==tabla[2][0]){
			if (tabla[0][0]=='X'){
				return 1; //ganar
			}
			else {
				return 0;
			}
		}
	}
	if (tabla[1][1]=='X' || tabla[1][1]=='O' ) {
		if (tabla[1][1]==tabla[0][0]&& tabla[1][1]==tabla[2][2]){
			if (tabla[1][1]=='X'){
				return 1; 
			}
			else {
				return 0;
			}
		}
		if (tabla[1][1]==tabla[1][0]&& tabla[1][1]==tabla[1][2]){
			if (tabla[1][1]=='X'){
				return 1; 
			}
			else {
				return 0;
			}
		}
		if (tabla[1][1]==tabla[2][0]&& tabla[1][1]==tabla[0][2]){
			if (tabla[1][1]=='X'){
				return 1; 
			}
			else {
				return 0;
			}
		}
		if (tabla[1][1]==tabla[0][1]&& tabla[1][1]==tabla[2][1]){
			if (tabla[1][1]=='X'){
				return 1; 
			}
			else {
				return 0;
			}
		}
	}
	if (tabla[2][2]=='X' || tabla[2][2]=='O'){
		if (tabla[2][2]==tabla[2][0]&& tabla[2][2]==tabla[2][1]){
			if (tabla[2][2]=='X'){
				return 1; 
			}
			else {
				return 0;
			}
		}
		if (tabla[2][2]==tabla[0][2]&& tabla[2][2]==tabla[1][2]){
			if (tabla[2][2]=='X'){
				return 1; 
			}
			else {
				return 0;
			}
		}
	}
	return 2; 
}
