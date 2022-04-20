#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 10
#define S (N - 1) / 2

void arr_make(int *arr, int min, int max);

void arr_inc_dec(int arr[], int l);
void arr_print(int *arr);

int main () {

int arrI[N], i,l, minimum, maximum;


printf("Enter minimum & maximum: ");
scanf("%d %d", &minimum, &maximum);
arr_make(arrI, minimum, maximum);
int* arr = &arrI[S]; //указатель на середину массива
arr_print(arr);

//scanf("%c"); // избавляемся от \n

printf("Enter чиселко: ");
scanf("%d", &l);
arr_inc_dec(arr, l);
arr_print(arr);

}

void arr_make(int *arr, int min, int max) { int i;

srand(time(NULL));

for(i=0; i<N; i++)

*arr++ = rand() % (max - min + 1) + min;

}

void arr_inc_dec(int *arr, int l)
{ int i;
arr = arr - S; //сдвигаем на начало массива
for (i=0; i<N; i++) {

arr[i]=arr[i]+l;

}

}

void arr_print(int *arr) {
int i;
arr = arr - S; //сдвигаем на начало массива
printf("The array is: ");
for (i=0; i<N; i++)
printf("%d ", *arr++);
printf("\n");

}