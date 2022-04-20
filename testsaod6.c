#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct graph
{
    int g;
    int count;
} Graph;

int CreateGraphPoint()
{
    int count;
    scanf("%d", &count);
    Graph *mas;
    mas = (Graph *)malloc(count * sizeof(Graph));
    for (int i = 0; i < count; i++)
    {
        *mas.g = rand() % 10;
    }
}