#include <iostream>
#include <time.h> 
#include <locale.h>
 
using namespace std; 

void MergeSort(int *a, int n) 
{
  int mid = n / 2; // находим середину сортируемой последовательности
  if (n % 2 == 1)
    mid++;
  int h = 1; // шаг
  // выделяем память под формируемую последовательность
  int *c = (int*)malloc(n * sizeof(int));
  int step;
  while (h < n) 
  {
    step = h;
    int i = 0;   // индекс первого пути
    int j = mid; // индекс второго пути
    int k = 0;   // индекс элемента в результирующей последовательности
    while (step <= mid) 
    {
      while ((i < step) && (j < n) && (j < (mid + step))) 
      { // пока не дошли до конца пути
        // заполняем следующий элемент формируемой последовательности
        // меньшим из двух просматриваемых
        if (a[i] < a[j])  
        {
          c[k] = a[i];
          i++; k++;
        }
        else {
          c[k] = a[j];
          j++; k++;
        }
      }
      while (i < step) 
      { // переписываем оставшиеся элементы первого пути (если второй кончился раньше)
        c[k] = a[i];
        i++; k++;
      }
      while ((j < (mid + step)) && (j<n)) 
      {  // переписываем оставшиеся элементы второго пути (если первый кончился раньше)
        c[k] = a[j];
        j++; k++;
      }
      step = step + h; // переходим к следующему этапу
    }
    h = h * 2;
    // Переносим упорядоченную последовательность (промежуточный вариант) в исходный массив
    for (i = 0; i<n; i++)
      a[i] = c[i];
  }
} 

void CreateArray(int* num, int size) {
    for (int i = 0; i != size; i++)
        num[i] = rand() % 100 - 20;
}
 
 
void PrintArray(int* num, int size) {
    for (int i = 0; i != size; i++)
        printf("%d ", num[i]);
} 

void OffsetArray(int* num, int numSize,  int offset) {
    for (int i = numSize; i >= offset; i--) {
        num[i + 1] = num[i];
    }
}

void MergeArrays(int* A, int* B, int Asize, int Bsize) {
    bool flag;
    int c = Asize - Bsize;
    for (int i = 0; i != Bsize; i++) {
        flag = true;
        for (int j = 0; j != Asize; j++) {
            if (B[i] < A[j]) {
                OffsetArray(A, Asize, j);
                Asize++;
                c++;
                A[j] = B[i];
                flag = false;
                break;
            }
        }
 
        if (flag) 
            A[c++] = B[i];
 
    }
} 

int main() {
    setlocale(LC_ALL,"Russian");
    int A[20];
    int B[15];
    srand(time(NULL));
 
    CreateArray(A, 5);
    printf("Выводим массив A:\n");
    PrintArray(A, 5);
    printf("\n\n");
 
    
    CreateArray(B, 15);
    printf("Выводим массив B:\n");
    PrintArray(B, 15);
    printf("\n");
    
    cout << endl;
    MergeSort(A, 5);
    MergeSort(B, 15);
    
    int Asize = sizeof(A) / sizeof(int);
    int Bsize = sizeof(B) / sizeof(int);
    MergeArrays(A, B, Asize, Bsize);
    
    printf("Выводим массив два отсортированных массива А и В, которые сохраняют сортировку:\n");
    PrintArray(A, 20);
    printf("\n");
    
}