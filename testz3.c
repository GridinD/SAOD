#include <stdio.h> 

#define N 10 

void arr_change(const int a[], int b[]); 

int main() 
{ 
int arr[N] = {2,3,4,5,12,13,14,15,22,23}; 
int arr1[N], i; 
arr_change(arr, arr1); 

for(i=0; i<N; i++)  
	printf("%d ", arr1[i]); 
printf("\n"); 
} 

void arr_change(const int m1[], int m2[]) 
{ 
int i; 
for(i=0; i<N; i++) 
	m2[i] = -m1[N-i-1]; 
} 
