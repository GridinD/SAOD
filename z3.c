#include <stdlib.h>
#include <stdio.h>
#include <time.h> 
#define N 10 

void arr_replacement(const int mas1[], int mas2[]);
void arr_creator(int arr1[]);
void arr_print(int *arr1); 
void arr_print2(int *arr2); 

int main ()
{ 
int arr1[N]; 
int arr2[N], i;
arr_creator(arr1);
arr_print(arr1);  
arr_replacement(arr1, arr2);
arr_print2(arr2); 
} 

void arr_replacement(const int m1[], int m2[]) 
{ 
int i; 
for (i=0; i<N; i++)
{ 
	m2[i] = -m1[N-i-1];
}
}

void arr_creator(int *arr1) 
{ 
int i;
srand(time(NULL)); 
for(i=0; i<N; i++) 
{ 
	arr1[i]=rand()%10;
} 
}

void arr_print(int *arr1)
{ 
int i; 
printf("First array is: "); 
for (i=0; i<N; i++) 
	printf("%d ", *arr1); 
printf("\n"); 
} 

void arr_print2(int *arr2) 
{ 
int i; 
printf("Modified array is: ");
for (i=0; i<N; i++) 
	printf("%d ", *arr2); 
printf("\n");
}























