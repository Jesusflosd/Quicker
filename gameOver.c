#include<stdio.h>
void gameOver(int puntos);
int main (){
	int acierto=10;
	gameOver(acierto);
	
	
	return 0;
}
void gameOver (int puntos){
	puts("\n\n\t #####");
	puts("\t##       ######  ### ### #####    ##### #  # #####  ####");
	puts("\t## #### ##   ##  ## # ## #####    #   #  # # ##### ##");
	puts("\t##   ## ##   ##  ##   ## ##       #   #   ## ##    ##");
	puts("\t #####   ####### ##   ## #####    #####    # ##### ##");
	printf("\n\t\t\t   PUNTAJE:   %d\n\n\n\t",puntos);
	system("pause");
	system("cls");
}
