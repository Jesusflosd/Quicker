/*
Autor: Gener Echeverria, William Cetina, Jesus Estrella
Version 0.4
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<windows.h>
#define Vertical 21
#define Horizontal 75
#include<string.h>

void titulo ();
int opcionesMenu(int i);
//selec
void selec();
//Pantalla puntaje
void resultado (int valor, int *acierto, int *vida);
void puntaje(int puntos, int vidas);
void tresCorazones ();
void dosCorazones();
void unCorazon();
//preguntas
int preguntas(int acierto);
int preguntabloqueada1=12;
int preguntabloqueada2=12;
int controlpreguntas;
int intervaloreiniciopreguntas;
int pregunta0(int i);
int pregunta1(int i);
int pregunta2(int i);
int pregunta3(int i);
int pregunta4(int i);
int pregunta5(int i);
int pregunta6(int i);
int pregunta7(int i);
int pregunta8(int i);
int pregunta9(int i);
//gato
int gato();
int loop(char tabla [3][3]);
void iniciarTabla(char tabla[3][3]);
void imprimirTabla(char tabla[3][3]);
void introducirFicha(char tabla[3][3]);
void introducirIA(char tabla[3][3]);
int ganador(char tabla[3][3]);
//asteroid
int asteroid ();
int lineaentremeteoritos;
void borde (char campo[25][60]);
int bajar (char campo[25][60]);
void nave(char campo[25][60],int navex, int navey);
void meteorito(char campo[25][60]);
void imprimir(char campo[25][60]);
void draw(char campo[25][60]);
int gameloop(char campo[25][60],int navex, int navey);
void input(char campo[25][60],int *navex, int *navey);
//pong
void inicio(char campo[Vertical][Horizontal], int pelX, int pelY, int inijug, int finjug, int iniia, int finia);
void bordePong (char campo[Vertical][Horizontal]);
void raqjug(char campo[Vertical][Horizontal], int inijug, int finjug);
void raqia(char campo[Vertical][Horizontal], int iniia, int finia);
void pel( char campo[Vertical][Horizontal], int pelX, int pelY );
void leercamp(char campo[Vertical][Horizontal]);
int gameloopPong(char campo[Vertical][Horizontal], int pelX, int pelY, int inijug, int finjug, int iniia, int finia, int modX, int modY, int modia);
void drawPong(char campo[Vertical][Horizontal]);
void inputPong(char campo[Vertical][Horizontal], int*pelX,int *pelY, int *inijug,int *finjug, int *iniia, int *finia, int *modX, int *modY, int *modia, int *gol);
void update(char campo[Vertical][Horizontal], int pelX, int pelY, int inijug, int finjug, int iniia, int finia);
int pong(int acierto);
//Guardar puntuaciones
typedef struct  {
	char *nombre;
	int puntos;
}guardaPuntaje;
guardaPuntaje *punt;
void imprimirPuntuaciones();
int posicionPuntaje (int acierto);
void vaciar(char temp[]);
void copiar(char temp[], int i);
void cambio(char aux[]);
//gameover
void gameOver(int puntos);


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
				system("cls");
				selec();
			}
			else {
				if (seleccion==1){
					system("cls");
					imprimirPuntuaciones();
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
void selec (){
	int acierto=0, vida=3,opciona=0, opcionb=0,juego=0,recarga=1;
	while (vida!=0) {
		puntaje(acierto,vida);
		Sleep(2000);
		system("cls");
		srand(time(NULL));
		if(recarga==4){
			opciona=0;
			opcionb=0;
			juego=0;
			recarga=1;	
		}
		while (juego==opciona||juego==opcionb){
			juego = rand()%4;//cambiar dependiendo del numero de juegos
		}
		opcionb=opciona;
		opciona=juego;
		recarga++;
		switch (juego) {
			case 0: resultado(preguntas(acierto),&acierto,&vida); break;
			case 1: resultado(gato(),&acierto,&vida); break;
			case 2: resultado(asteroid(),&acierto,&vida);break;
			case 3: resultado(pong(acierto),&acierto,&vida);break;
		}
	}
	system("color 07");
	gameOver(acierto);
	posicionPuntaje (acierto);
}
//puntaje
void puntaje (int puntos, int vidas){
	if (puntos<11){
		lineaentremeteoritos=6-trunc(puntos/2);
	}else{
			lineaentremeteoritos=1;
	}
	switch (vidas){
		case 1:
			system("color 04");
			puts("\n\n\t\t     VIDAS\n");
			unCorazon();
			printf("\n\t\t  PUNTAJE: %d",puntos); break;
		case 2:
			system("color 06");
			puts("\n\n\t\t     VIDAS\n");
			dosCorazones();
			printf("\n\t\t  PUNTAJE: %d",puntos); break;
		case 3:
			system("color 02");
			puts("\n\n\t\t     VIDAS\n");
			tresCorazones();
			printf("\n\t\t  PUNTAJE: %d",puntos); break;
	}
}
void resultado (int valor, int *acierto, int *vida){
	if (valor==1){
		*acierto+=1;
	}
	
	if (valor==0){
		*vida-=1;
	}
	
}
void tresCorazones(){
	int a, b, line = 4;
   for (a = line/2; a <= line; a = a+2) { 
     	printf("\t");
      for (b = 1; b < line-a; b = b+2) 
         printf(" ");
      for (b = 1; b <= a; b++) 
         printf("*");
      for (b = 1; b <= line-a; b++)
         printf(" ");
      for (b = 1; b <= a-1; b++) 
         printf("*");
         printf("\t    ");
      for (b = 1; b < line-a; b = b+2) 
         printf(" ");
      for (b = 1; b <= a; b++)
         printf("*");
      for (b = 1; b <= line-a; b++) 
         printf(" ");
      for (b = 1; b <= a-1; b++) 
         printf("*");
         printf("\t");
      for (b = 1; b < line-a; b = b+2) 
         printf(" ");
      for (b = 1; b <= a; b++)
         printf("*");
      for (b = 1; b <= line-a; b++) 
         printf(" ");
      for (b = 1; b <= a-1; b++) 
         printf("*");
         printf("\n");
   }
   for (a = line; a >= 0; a--) { 
   	  printf("\t");
      for (b = a; b < line; b++) 
         printf(" ");
      for (b = 1; b <= ((a * 2) - 1); b++) 
         printf("*");
      printf("\t    ");
         for (b = a; b < line; b++) 
         printf(" ");
      for (b = 1; b <= ((a * 2) - 1); b++) 
         printf("*");
         printf("\t");
         for (b = a; b < line; b++) 
         printf(" ");
      for (b = 1; b <= ((a * 2) - 1); b++) 
         printf("*");
         printf("\n");
        
   }
}
void dosCorazones(){
	int a, b, line = 4;
   for (a = line/2; a <= line; a = a+2) { 
     	printf("\t");
      for (b = 1; b < line-a; b = b+2) 
         printf(" ");
      for (b = 1; b <= a; b++) 
         printf("*");
      for (b = 1; b <= line-a; b++)
         printf(" ");
      for (b = 1; b <= a-1; b++) 
         printf("*");
         printf("\t    ");
      for (b = 1; b < line-a; b = b+2) 
         printf(" ");
      for (b = 1; b <= a; b++)
         printf("*");
      for (b = 1; b <= line-a; b++) 
         printf(" ");
      for (b = 1; b <= a-1; b++) 
         printf("*");
         printf("\n");
   }
   for (a = line; a >= 0; a--) { 
   	  printf("\t");
      for (b = a; b < line; b++) 
         printf(" ");
      for (b = 1; b <= ((a * 2) - 1); b++) 
         printf("*");
      printf("\t    ");
         for (b = a; b < line; b++) 
         printf(" ");
      for (b = 1; b <= ((a * 2) - 1); b++) 
         printf("*");
         printf("\n");
   }
}
void unCorazon(){
	int a, b, line = 4;
   for (a = line/2; a <= line; a = a+2) { 
     	printf("\t");
      for (b = 1; b < line-a; b = b+2) 
         printf(" ");
      for (b = 1; b <= a; b++) 
         printf("*");
      for (b = 1; b <= line-a; b++)
         printf(" ");
      for (b = 1; b <= a-1; b++) 
         printf("*");
         printf("\n");
   }
    for (a = line; a >= 0; a--) { 
   	  printf("\t");
      for (b = a; b < line; b++) 
         printf(" ");
      for (b = 1; b <= ((a * 2) - 1); b++) 
         printf("*");
         printf("\t    ");
         printf("\n");
   }
}
//preguntas
int preguntas(int acierto) {
	int punto=0, opcion=preguntabloqueada1, respuesta, i=0, correcto;
	char tecla=1;
	time_t tiempoInicial=time(NULL);
	float tiempoLimite; 
	srand(time(NULL)); 
	while (opcion==preguntabloqueada1||opcion==preguntabloqueada2){
		opcion=rand()%10;//cambiar dependiendo del numero de preguntas
	}
	preguntabloqueada2=preguntabloqueada1;
	preguntabloqueada1=opcion;
	if (acierto<=4) {
		tiempoLimite=10.0;
	}
	else {
		if (acierto<=7) {
			tiempoLimite = 8;
		}
		else {
			tiempoLimite=6;
		}
	}
	fflush(stdin);
	while ((time(NULL)-tiempoInicial)<tiempoLimite){
		system("cls");
		puts("=============================================\n");
		printf("Tiempo: %.0f\n",tiempoLimite-(time(NULL)-tiempoInicial));
		switch (opcion){
			case 0: correcto=pregunta0(i); break;
			case 1: correcto=pregunta1(i); break;
			case 2: correcto=pregunta2(i); break;
			case 3: correcto=pregunta3(i); break;
			case 4: correcto=pregunta4(i); break;
			case 5: correcto=pregunta5(i); break;
			case 6: correcto=pregunta6(i); break;
			case 7: correcto=pregunta7(i); break;
			case 8: correcto=pregunta8(i); break;
			case 9: correcto=pregunta9(i); break;
		}
		puts("\n=============================================");
		if (kbhit()){
			tecla=getch();
			if (tecla=='s') {
				i++;
			}
			if (tecla=='w'){
				i--;
			}
			if(tecla==13){
				if (correcto==1){
					puts("Correcto");
					Sleep(1000);
					system("cls");
					return 1;
				}
				else {
					puts("Incorrecto");
					Sleep(1000);
					system("cls");
					return 0;
				}
			}
		}
		if (i<0){
			i=0;
		}
		if (i>2){
			i=2;
		}
	} puts ("Se acabo el tiempo"); Sleep(1000);
	system("cls");
	return 0;
}
int pregunta0(int i){
	switch (i){
		case 0: puts("\n\tEl resultado de 7 x 8 es:");
				puts("\t\t->56"); 
				puts("\t\t  57"); 
				puts("\t\t  58"); return 1;
		case 1: puts("\n\tEl resultado de 7 x 8 es:");
				puts("\t\t  56"); 
				puts("\t\t->57"); 
				puts("\t\t  58"); break;
		case 2: puts("\n\tEl resultado de 7 x 8 es:");
				puts("\t\t  56"); 
				puts("\t\t  57"); 
				puts("\t\t->58"); break;
	}
	return 0;
}
int pregunta1(int i){
	switch (i){
		case 0: puts("\n\tEl resultado de (5x2)+(6/3) es:");
				puts("\t\t->11"); 
				puts("\t\t  12"); 
				puts("\t\t  13"); break;
		case 1: puts("\n\tEl resultado de (5x2)+(6/3) es:");
				puts("\t\t  11"); 
				puts("\t\t->12"); 
				puts("\t\t  13"); return 1;
		case 2: puts("\n\tEl resultado de (5x2)+(6/3) es:");
				puts("\t\t  11"); 
				puts("\t\t  12"); 
				puts("\t\t->13"); break;
	}
	return 0;
}
int pregunta2(int i){
	switch (i){
		case 0: puts("\n\tEl resultado de 325+78 es:");
				puts("\t\t->401"); 
				puts("\t\t  402"); 
				puts("\t\t  403"); break;
		case 1: puts("\n\tEl resultado de 325+78 es:");
				puts("\t\t  401"); 
				puts("\t\t->402"); 
				puts("\t\t  403"); break;
		case 2: puts("\n\tEl resultado de 325+78 es:");
				puts("\t\t  401"); 
				puts("\t\t  402"); 
				puts("\t\t->403"); return 1;
	}
	return 0;
}
int pregunta3(int i){
	switch (i){
		case 0: puts("\n\tLa raiz cuadrada de 121 es:");
				puts("\t\t->11"); 
				puts("\t\t  12"); 
				puts("\t\t  13"); return 1;
		case 1: puts("\n\tLa raiz cuadrada de 121 es:");
				puts("\t\t  11"); 
				puts("\t\t->12"); 
				puts("\t\t  13"); break;
		case 2: puts("\n\tLa raiz cuadrada de 121 es:");
				puts("\t\t  11"); 
				puts("\t\t  12"); 
				puts("\t\t->13"); break;
	}
	return 0;
}
int pregunta4(int i){
	switch (i){
		case 0: puts("\n\tLa raiz cuadrada de 144 es:");
				puts("\t\t->11"); 
				puts("\t\t  12"); 
				puts("\t\t  13"); break;
		case 1: puts("\n\tLa raiz cuadrada de 144 es:");
				puts("\t\t  11"); 
				puts("\t\t->12"); 
				puts("\t\t  13"); return 1;
		case 2: puts("\n\tLa raiz cuadrada de 144 es:");
				puts("\t\t  11"); 
				puts("\t\t  12"); 
				puts("\t\t->13"); break;
	}
	return 0;
}
int pregunta5(int i){
	switch (i){
		case 0: puts("\n\tEl resultado de 7+25x4-12 es: ");
				puts("\t\t->93"); 
				puts("\t\t  94"); 
				puts("\t\t  95"); break;
		case 1: puts("\n\tEl resultado de 7+25x4-12 es: ");
				puts("\t\t  93"); 
				puts("\t\t->94"); 
				puts("\t\t  95"); break;
		case 2: puts("\n\tEl resultado de 7+25x4-12 es: ");
				puts("\t\t  93"); 
				puts("\t\t  94"); 
				puts("\t\t->95"); return 1;
	}
	return 0;
}
int pregunta6(int i){
	switch (i){
		case 0: puts("\n\tEl resultado de (-50)x(-50) es: ");
				puts("\t\t-> 2500"); 
				puts("\t\t  -2500"); 
				puts("\t\t   5000"); return 1;
		case 1: puts("\n\tEl resultado de (-50)x(-50) es: ");
				puts("\t\t   2500"); 
				puts("\t\t->-2500"); 
				puts("\t\t   5000"); break;
		case 2: puts("\n\tEl resultado de (-50)x(-50) es: ");
				puts("\t\t   2500"); 
				puts("\t\t  -2500"); 
				puts("\t\t-> 500"); break;
	}
	return 0;
}
int pregunta7(int i){
	switch (i){
		case 0: puts("\n\tEl resultado de (3)x(-3)x(3)x(-3) es: ");
				puts("\t\t->-81"); 
				puts("\t\t   81"); 
				puts("\t\t   27"); break;
		case 1: puts("\n\tEl resultado de (3)x(-3)x(3)x(-3) es:");
				puts("\t\t  -81"); 
				puts("\t\t-> 81"); 
				puts("\t\t   27"); return 1;
		case 2: puts("\n\tEl resultado de (3)x(-3)x(3)x(-3) es:");
				puts("\t\t  -81"); 
				puts("\t\t   81"); 
				puts("\t\t-> 27"); break;
	}
	return 0;
}
int pregunta8(int i){
	switch (i){
		case 0: puts("\n\tEl resultado de 4*3-2/1 es: ");
				puts("\t\t->12"); 
				puts("\t\t  11"); 
				puts("\t\t  10"); break;
		case 1: puts("\n\tEl resultado de 4*3-2/1 es:");
				puts("\t\t  12"); 
				puts("\t\t->11"); 
				puts("\t\t  10"); break;
		case 2: puts("\n\tEl resultado de 4*3-2/1 es:");
				puts("\t\t  12"); 
				puts("\t\t  11"); 
				puts("\t\t->10"); return 1;
	}
	return 0;
}
int pregunta9(int i){
	switch (i){
		case 0: puts("\n\tEl resultado de -1*200+50 es: ");
				puts("\t\t->-150"); 
				puts("\t\t  -250"); 
				puts("\t\t  -300"); return 1;
		case 1: puts("\n\tEl resultado de -1*200+50 es:");
				puts("\t\t  -150"); 
				puts("\t\t->-250"); 
				puts("\t\t  -300"); break;
		case 2: puts("\n\tEl resultado de -1*200+50 es:");
				puts("\t\t  -150"); 
				puts("\t\t  -250"); 
				puts("\t\t->-300"); break;
	}
	return 0;
}
//gato
int gato (){
	char tabla[3][3];
	int resu;
	resu=loop(tabla);
	system("cls");
	return resu;
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
		Sleep(2000);
		return 1;
	}
	else {
		if (j==0) {
			puts("\tPerdiste"); 
			Sleep(2000);
			return 0;
		}
		else {
			puts ("\tEmpate");
			Sleep(2000);
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
				return 1; 
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
//asteroid
int asteroid(){
	char campo[25][60];
	int navex=22,navey=30, resultado;
	borde(campo);
	nave(campo,navex,navey);
	imprimir(campo);
	resultado=gameloop(campo,navex,navey);
	return resultado;
}
void borde (char campo[25][60]){
	int i,j,V=25,H=60;
	for(i=0;i<V;i++){
		for (j=0;j!=H;j++){
			if(i==0||i==V-1){
				campo[i][j]='_';
			}else if(j==0||j==H-1){
				campo[i][j]='|';
			}else{
				campo[i][j]=' ';
			}
		}
	}
	return;
}
void nave (char campo[25][60],int navex, int navey){
	campo[navex][navey]='X';
	campo[navex+1][navey-1]='X';
	campo[navex+1][navey]='X';
	campo[navex+1][navey+1]='X';
	return;
}
void imprimir(char campo[25][60]){
		int i,j,V=25,H=60;
		for(i=0;i<V;i++){
		for (j=0;j!=H;j++){
		printf("%c",campo[i][j]);
		}
		printf("\n");
	}
	return;
}
int gameloop(char campo[25][60],int navex, int navey){
	int lose=0, d=1;
	int resu=0;
	time_t tiempoInicial=time(NULL);
	float tiempoLimite=10;
	do{
		printf("Tiempo: %.0f",tiempoLimite-(time(NULL)-tiempoInicial));// prueba
		draw(campo);
		if(d==lineaentremeteoritos){
			meteorito(campo);
			d=0;
		}
		lose=bajar(campo);
		d++;
		input(campo,&navex,&navey);
		input(campo,&navex,&navey);
		input(campo,&navex,&navey);
		input(campo,&navex,&navey);
		input(campo,&navex,&navey);
		input(campo,&navex,&navey);
		input(campo,&navex,&navey);
		input(campo,&navex,&navey);
		input(campo,&navex,&navey);
	//update();
	}while(lose==0&&(time(NULL)-tiempoInicial)<tiempoLimite);
	if (lose==0) {
		resu=1;
	}
	Sleep(1000);
	system ("cls");
	return resu;
}
void draw(char campo[25][60]){
	system("cls");
	imprimir(campo);
}
void meteorito(char campo[25][60]){
	int num,a;
	num=2+rand()%(57-2);
	campo[2][num]='@';
	campo[2][num+1]='@';
	campo[2][num-1]='@';
	campo[1][num]='@';
	campo[3][num]='@';

return;
}
int bajar (char campo[25][60]){
	int i,j,V=25,H=60,w=0;
	for(i=23;i>1;i--){
		for(j=H-1;j>1;j--){
			if(campo[i][j]!='X'){
			if(campo[i-1][j]!='X'){
			campo[i][j]=campo[i-1][j];
			campo[i-1][j]=' ';
		}
		}else{
			if(campo[i-1][j]=='@'){
				w=1;
			}
		}
		}
	}
return w;
}
void input(char campo[25][60],int *navex, int *navey){
	char key;
	if (kbhit()==1){
		key=getch();
		if(key=='a'||key=='A'){
			if((*navey-1)!=1){
				campo[*navex][*navey-1]='X';
				campo[*navex][*navey]=' ';
				campo[*navex+1][*navey-2]='X';
	            campo[*navex+1][*navey-1]='X';
	            campo[*navex+1][*navey]='X';
	            campo[*navex+1][*navey+1]=' ';
				*navey=*navey-1;	
			}
		}
		if(key=='d'||key=='D'){
			if((*navey+1)!=59){
				campo[*navex][*navey+1]='X';
				campo[*navex][*navey]=' ';
				campo[*navex+1][*navey+2]='X';
	            campo[*navex+1][*navey+1]='X';
	            campo[*navex+1][*navey]='X';
	            campo[*navex+1][*navey-1]=' ';
				*navey=*navey+1;	
			}
		}
			if(key=='s'||key=='S'){
			if((*navex+1)!=24){
				campo[*navex+2][*navey]='X';
				campo[*navex+1][*navey]='X';
				campo[*navex+2][*navey+1]='X';
				campo[*navex+2][*navey-1]='X';
	            campo[*navex][*navey]=' ';
	            campo[*navex+1][*navey-1]=' ';
	            campo[*navex+1][*navey+1]=' ';
				*navex=*navex+1;	
			}
		}
		    if(key=='W'||key=='w'){
			if((*navex-1)!=7){
				campo[*navex-1][*navey]='X';
				campo[*navex][*navey]='X';
				campo[*navex][*navey+1]='X';
				campo[*navex][*navey-1]='X';
	            campo[*navex+1][*navey]=' ';
	            campo[*navex+1][*navey-1]=' ';
	            campo[*navex+1][*navey+1]=' ';
				*navex=*navex-1;	
			}
		}
	}
return;	
}
//pong
int pong (int acierto) {
	int pelX,pelY=0,inijug,finjug,iniia,finia;//posicion
	int modX, modY, modia;//modificacion
	char campo[Vertical][Horizontal];
	int final = 0;
	//posicion
	pelX = 37; 
	srand(time(NULL));
	do {
		pelY=rand()%14;
		
	}while (pelY<3);	
	switch (acierto){
		case 0:
		case 1:
		case 2: inijug=5;;
				finjug=15; 
				break;
		case 3: 
		case 4:
		case 5: inijug=6;;
				finjug=14; 
				break;
		case 6: 
		case 7:
		case 8: inijug=7;;
				finjug=13; 
				break;
		case 9:
		case 10:	
		case 11: inijug=8;;
				finjug=12; 
				break;
		case 12:
		case 13:
		case 14: inijug=9;;
				 finjug=11; 
				 break;
	}
	if (acierto>14){
		inijug=9;;
		finjug=11; 
	}
	iniia = 5;
	finia = 18;
	//modificacion
	modX = -1;
	modY = -1;
	modia = -1;
	inicio (campo,pelX,pelY,inijug,finjug,iniia,finia);
	final = gameloopPong (campo, pelX,pelY,inijug,finjug,iniia,finia,modX,modY,modia);
	system("cls");
	if (final==1){
		return 0;
	}
	if (final==2){
		return 1;
	}
}

void inicio(char campo[Vertical][Horizontal], int pelX, int pelY, int inijug, int finjug, int iniia, int finia){
	bordePong(campo);
	raqjug(campo, inijug, finjug);
	raqia(campo, iniia, finia); 
	pel(campo, pelX, pelY);
}

void bordePong (char campo[Vertical][Horizontal]){
	int i,j;
	for(i = 0; i < Vertical; i++){
		for(j = 0; j < Horizontal; j++){
			if(i == 0 || i==Vertical-1){
				campo[i][j] = '-';
			}
			else {
				if (j == 0 || j == Horizontal-1){
					campo[i][j] = '|';
				}
				else {
					
					campo[i][j] = ' ';
					
				}	
			} 
		}
	}
}

void raqjug(char campo[Vertical][Horizontal], int inijug, int finjug){
	int i, j;
	for(i = inijug; i <= finjug; i++){
		for(j = 2; j <= 3; j++){
			campo[i][j] = 'X';
		}
	}
}
void raqia(char campo[Vertical][Horizontal], int iniia, int finia){
	int i,j;
	for(i = iniia; i < finia; i++){
		for(j = Horizontal-4; j <= Horizontal - 3; j++){
			campo[i][j] = 'X';	
		}
	}
}
void pel ( char campo[Vertical][Horizontal], int pelX, int pelY ){
	campo[pelY][pelX] = 'O';
}
void leercamp(char  campo[Vertical][Horizontal]){
	int i,j;
	for(i = 0;i<Vertical;i++){
		for(j= 0; j<Horizontal;j++){
			printf ("%c", campo[i][j]);
		}
		printf("\n");
	}
}

int gameloopPong(char campo[Vertical][Horizontal], int pelX, int pelY, int inijug, int finjug, int iniia, int finia, int modX, int modY, int modia){
	time_t tiempoInicial=time(NULL);
	float tiempoLimite=30; 
	int gol;
	gol = 0;
	int res = 0;
	while ((time(NULL)-tiempoInicial)<tiempoLimite) {
		drawPong (campo);//dibujar en pantalla
		inputPong (campo,&pelX,&pelY,&inijug,&finjug,&iniia,&finia,&modX,&modY,&modia, &gol);//verificar y modificar posiciones
		update (campo,pelX,pelY,inijug,finjug,iniia,finia);	//actualizar matriz de campo
		printf("Tiempo: %.0f\n",tiempoLimite-(time(NULL)-tiempoInicial));
		if (gol!=0) {
			break;
		}
	}	
	if(pelX==1){
			res = 1;
	}
		else{
			res = 2;
		}
	return res;
	
}		
void drawPong(char campo[Vertical][Horizontal]){
	system("cls");
	leercamp(campo);
}

void inputPong(char campo[Vertical][Horizontal], int*pelX,int *pelY, int *inijug,int *finjug, int *iniia, int *finia, int *modX, int *modY, int *modia, int *gol){
	int i;
	char key;
	//verificacion
	if (*pelY == 1|| *pelY== Vertical-2){
		*modY *=-1;
	}
	if (*pelX == 1|| *pelX == Horizontal - 2){
		*gol = 1;
	}
	if (*pelX == 4){
		for(i= (*inijug); i <= (*finjug); i++){
			if(i==(*pelY)){
				*modX *= -1;
			}
		}
	}
	if (*pelX == Horizontal - 5){
		for( i = (*iniia); i <= (*finia); i++){
			if (i==(*pelY)){
				*modX *=-1;
			}
		}
	}
	
	if(*iniia==1 || *finia ==Vertical-1){
		*modia *=-1;
	}
	//Modificacion
	if (*gol == 0){
		//Pelota:
		*pelX += (*modX);
		*pelY += (*modY);
		//Raqueta ia:
		*iniia += (*modia);
		*finia += (*modia);
		//Raqueta jug:
		if(kbhit()){
			key = getch();
			if(key == 'w'){
				if(*inijug != 1){
					*inijug -= 1;
					*finjug -=1;
				}
			}
			if(key == 's'){
				if(*finjug != Vertical-2){
					*inijug +=1;
					*finjug += 1;
				}
			}
		}
	}
}

void update(char campo[Vertical][Horizontal], int pelX, int pelY, int inijug, int finjug, int iniia, int finia){
	bordePong(campo);
	raqjug(campo, inijug, finjug);
	raqia(campo, iniia, finia); 
	pel(campo, pelX, pelY);
}
//guardar puntuacion
void imprimirPuntuaciones(){
	char nombres[20];
	char temp[50],aux;
	int cont=1,i,j;
	FILE *f;
	f = fopen("Puntuaciones.txt","r");
	
	while(!feof(f)){
		fgets(temp,50,f);
		cont++;
	}
	rewind(f);
	punt=(guardaPuntaje*)malloc(cont*sizeof(guardaPuntaje));
	printf("\n\n\t\t\t  PUNTUACIONES");
	 puts("\n\n\t\t  NOMBRE\t\tPUNTAJE");
	for (i=0;!feof(f);i++){
		vaciar(temp);
		aux='0';
		for(j=0;aux!='-';j++){
			aux=fgetc(f);
			if (aux!='-'){
				temp[j]=aux;
			}
		}
		copiar(temp,i);
		fgets(temp,4,f);
		punt[i].puntos = atoi(temp); //convierte numeros de string a entero
		printf("\t\t%s\t\t\t   %d\n", punt[i].nombre, punt[i].puntos);
	}
	puts("\n\nPresiona una tecla para continuar.");
	getch();
}
int posicionPuntaje (int acierto){
	char nombres[20];
	char temp[50],aux;
	int cont=1,i,j;
	FILE *f;
	f = fopen("Puntuaciones.txt","r");
	
	while(!feof(f)){
		fgets(temp,50,f);
		cont++;
	}
	rewind(f);
	punt=(guardaPuntaje*)malloc(cont*sizeof(guardaPuntaje));
	for (i=0;!feof(f);i++){
		vaciar(temp);
		aux='0';
		for(j=0;aux!='-';j++){
			aux=fgetc(f);
			if (aux!='-'){
				temp[j]=aux;
			}
		}
		copiar(temp,i);
		fgets(temp,4,f);
		punt[i].puntos = atoi(temp); //convierte numeros de string a entero
		//printf("Nombre: %s    Puntos: %i \n",punt[i].nombre,punt[i].puntos); comprobar cambios
	}
	if (acierto<punt[2].puntos){
		return 0;
	}
	puts("Escribe tu nombre: ");
	fflush(stdin);
	gets(nombres);
	copiar(nombres,3);
	punt[3].puntos=acierto;
	fclose(f);
	//ordenar
	int aux2, vector[4];
	char *aux3[20]; 
    for(i=0;i<4;i++){
          vector[i]=punt[i].puntos;
	}
	for(i=0;i<4;i++){
        for(j=0;j<4-(i+1);j++){
        	
            if(vector[j]<vector[j+1]){
                aux2=vector[j];
                *aux3=punt[j].nombre;
                vector[j]=vector[j+1];
                punt[j].nombre=punt[j+1].nombre;
                vector[j+1]=aux2;
                punt[j+1].nombre=*aux3;
            }
        }
    }
    puts("\n\n\t\t  NOMBRE\t\tPUNTAJE");
    for(i=0;i<3;i++){
    	punt[i].puntos=vector[i];
    	printf("\t\t%s\t\t\t   %d\n", punt[i].nombre, punt[i].puntos);
    }
    Sleep(4000);
	//remplazar lista con mejores 3
	f = fopen("Puntuaciones.txt","w");
	rewind(f);
	for (i=0;i<3;i++){
		//cambio(punt[0].nombre);
		fprintf(f,"%s",punt[i].nombre);
		fprintf(f,"%c",'-');
		fprintf(f,"%i",punt[i].puntos);
		if (i<2){
			fprintf(f,"\n");
		}
	}
	fclose(f);
	return 0;
}
void vaciar(char temp[]){
	int i;
	for(i=0;i<50;i++){
		temp[i]='\0';
	}
}
void copiar(char temp[], int i){
	int N = strlen(temp)+1;//strlen cuenta los caracteres de temp sin \0
	punt[i].nombre=(char*)malloc(N*sizeof(char));
	strcpy(punt[i].nombre,temp);
}
void cambio(char aux[]){
	int i;
	for (i=0;i<50;i++){
		if (aux[i]=='\n'){
			aux[i]='\0';
		}
	}
}
//gameover
void gameOver (int puntos){
	puts("\n\n\t #####");
	puts("\t##       ######  ### ### #####    ##### #  # #####  ####");
	puts("\t## #### ##   ##  ## # ## #####    #   #  # # ##### ##");
	puts("\t##   ## ##   ##  ##   ## ##       #   #   ## ##    ##");
	puts("\t #####   ####### ##   ## #####    #####    # ##### ##");
	printf("\n\t\t\t   PUNTAJE:   %d\n\n\n\t",puntos);
	Sleep(4000);
	system("cls");
}
