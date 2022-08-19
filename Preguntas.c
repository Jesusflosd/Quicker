#include<stdio.h>
#include<stdlib.h>
#include<time.h>
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
int main () {
	
	int acierto=0; //para probar aumento de velocidad
	printf("%d", preguntas(acierto));
	return 0;
}
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
	opcion=5;//prueba
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
					return 1;
				}
				else {
					puts("Incorrecto");
					Sleep(1000);
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
	} puts ("Se acabo el tiempo"); 
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
		case 1: puts("\n\tEl resultado de 4*3-2/1 es:");
				puts("\t\t  -150"); 
				puts("\t\t->-250"); 
				puts("\t\t  -300"); break;
		case 2: puts("\n\tEl resultado de 4*3-2/1 es:");
				puts("\t\t  -150"); 
				puts("\t\t  -250"); 
				puts("\t\t->-300"); break;
	}
	return 0;
}
