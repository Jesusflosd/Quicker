#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct  {
	char *nombre;
	int puntos;
}guardaPuntaje;
guardaPuntaje *punt;
void posicionesPuntaje (int acierto);
void vaciar(char temp[]);
void copiar(char temp[], int i);
void cambio(char aux[]);
int main () {
	int acierto=10;//lo que recibe la funcion  del programa madre
	posicionPuntaje (acierto);
	
	
	return 0;
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
		printf("Nombre: %s    Puntos: %i \n",punt[i].nombre,punt[i].puntos);
	}
	if (acierto<punt[2].puntos){
		return 0;
	}
	puts("Escribe tu nombre: ");
	fflush(stdin);
	gets(nombres);
	copiar(nombres,3);
	punt[3].puntos=acierto;
	printf("Nombre: %s    Puntos: %i \n",punt[3].nombre,punt[3].puntos);
	fclose(f);
	//ordenar
	int aux2, vector[4];
	char *aux3[20]; //
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
