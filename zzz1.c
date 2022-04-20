#include <stdlib.h> 
#include <stdint.h> 
#include <stdio.h>
#include <time.h> 

#define N 10 

void arr_make(float arr[], float min, float max); 
void arr_inc_dec(float arr[], char sign, float x); 
void arr_print(float *arr); 

int main() 
{ 
float arrI[N], i, minimum, maximum, x; char ch; 
		
printf("Enter minimum & maximum: "); 
scanf("%f %f", &minimum, &maximum); 
arr_make(arrI, minimum, maximum); 
arr_print(arrI); 
scanf("%*c"); //избавл. от \n 
printf("Enter sign (+,-): "); 
scanf("%c", &ch);
printf ("Enter number: ");
scanf("%f", &x); 
arr_inc_dec(arrI, ch, x); 
arr_print(arrI);
}

void arr_make(float *arr, float min, float max)
{
int i;  
srand(time(NULL)); 
for(i=0; i<N; i++) 
*arr++ = rand()/(max - min + 1) + min;
}

void arr_inc_dec(float *arr, char sign, float x)
{
int i; 
for(i=0; i<N; i++) 
	{ 
	if (sign == '+') arr[i]=arr[i]+x; 
	if (sign == '-') arr[i]=arr[i]-x; 
	} 
}

void arr_print(float *arr)
{ 
int i; 
printf("The array is: "); 
for (i=0; i<N; i++)  
	printf("%f ", *arr++); 
printf("\n"); 
} 














































