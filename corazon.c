#include <stdio.h>
#include <stdlib.h>
void tresCorazones ();
void dosCorazones();
void unCorazon();
int main() {
   tresCorazones();
   dosCorazones();
   unCorazon();
   return 0;
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
