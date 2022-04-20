#include <stdlib.h> 
#include <time.h> 
#include <stdio.h>

#define N 10 
#define M N / 2

void arr_creator(int *arr, int min, int max); 
void arr_inc_dec(int arr[], int f); 
void arr_print(int *arr); 

int main() {

int arrI[N], i, f, minimum, maximum; 

printf("Enter minimum & maximum: "); 
scanf("%d %d", &minimum, &maximum); 
arr_creator(arrI, minimum, maximum); 
int* arr = &arrI[M]; //указатель на середину массива 
arr_print(arr);  
printf("Enter number: "); 
scanf("%d", &f); 
arr_inc_dec(arr, f); 
arr_print(arr); 
} 

void arr_creator(int *arr, int min, int max) { int i;
srand(time(NULL));
for(i=0; i<N; i++)
*arr++ = rand() % (max - min + 1) + min;
}

void arr_inc_dec(int *arr, int f)
{ int i;
arr = arr - M; //сдвиг на начало массива
for (i=0; i<N; i++) {
arr[i]=arr[i]+f;
}
}

void arr_print(int *arr) {
int i;
arr = arr - M; //сдвиг на начало массива
printf("The array is: ");
for (i=0; i<N; i++)
printf("%d ", *arr++);
printf("\n");

}
