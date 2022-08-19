//puntaje
#include<stdio.h>
#include<stdlib.h>
void resultado (int valor, int *acierto, int *vida);
void puntaje(int puntos, int vidas);
void tresCorazones ();
void dosCorazones();
void unCorazon();
int preguntas();
int main (){
	int acierto=0, vida=3,opcion=0, juego;
	while (vida!=0) {
		puntaje(acierto,vida);
		sleep(2);
		system("cls");
		/*srand(time(NULL));
		juego = rand()%3;
		switch (juego) {
			case 0: resultado(preguntas(),&acierto,&vida); break;
			case 1: break;
			case 2: break;
		}
		*/
		
		
		vida=0; //prueba
	}
	return 0;
}
void puntaje (int puntos, int vidas){
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
	else {
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
