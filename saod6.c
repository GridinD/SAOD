#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int graph[999][2];
int count;

int CreateGaphPoints()
{
    for (int i = 0; i != count; i++)
    {
        graph[i][0] = rand() % 10;
        graph[i][1] = rand() % 10;
    }
}

int PrintGraphPoints()
{
    for (int i = 0; i != count; i++)
    {
        printf("%d %d \n", graph[i][0], graph[i][1]);
    }
}

int CheckPath(int start, int finish)
{
    int b = 0;
    for (int i = 0; i != count; i++)
    {
        if ((start == finish) && (graph[i][0] == graph[i][1]))
        {
            b = 1;
        }

        if (graph[i][0] == graph[i][1])
        {
            continue;
        }

        if ((graph[i][0] == start) && (graph[i][1] == finish))
        {
            b = 1;
        }

        if (b)
        {
            break;
        }

        if (graph[i][0] == start)
        {
            b = CheckPath(graph[i][1], finish);
        }
    }

    return b;
}

int main()
{
    srand(time(NULL));
    printf("%s", "Введите кол.во векторов направления: ");
    scanf("%d", &count);
    CreateGaphPoints();
    PrintGraphPoints();
    int start;
    int finish;
    printf("%s", "Введите начальную точку и конечную для проверки есть ли между ними маршрут: ");
    scanf("%d %d", &start, &finish);

    if (CheckPath(start, finish))
        printf("%s", "Путь есть");
    else
        printf("%s", "Пути нет");

    printf("%s", "\n");
}