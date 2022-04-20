#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define N 10

void arr_change(const int a[], int b[]);

int main() {

    srand(time(NULL));

    int A[N];
    int B[N], i, j = 0;

    printf("Full array is: ");
    for (j; j < N; j++) {
        A[j] = rand() % 100;
        printf("%4d", A[j]);
    }
    printf("\n\n");

    


    arr_change(A, B);

    printf("Full (empty) array:");
    for (i = 0; i < N; i++)
        printf(" %d ", B[i]);

    printf("\n");
}

void arr_change(const int m1[], int m2[]) {
    int i;

    for (i = 0; i < N; i++)
        m2[i] = -m1[N - i - 1];
}
