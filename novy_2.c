#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int points[999][2];
int count;

int randomVectorPoints() {
	for (int i = 0; i != count; i++) {
		points[i][0] = rand() % 20; 
		points[i][1] = rand() % 20; 
	}
}

int printVectorPoints() {
	for (int i = 0; i != count; i++) {
		printf("%d %d \n", points[i][0], points[i][1]);
	}
}

int pathExist(int start, int end) {
	int b = 0;
	for (int i = 0; i != count; i++) {
		// printf("%d %d\n", points[i][0], points[i][1]);
		
		if ((start == end) && (points[i][0] == points[i][1]))
			b = 1;
		
		if (points[i][0] == points[i][1])
			continue;
		

		if ((points[i][0] == start) && (points[i][1] == end))
			b = 1;
			
		if (b)
			break;
		
		if (points[i][0] == start)
			b = pathExist(points[i][1], end);
	}
	
	return b;
}

int main() {
	srand(time(NULL));
	printf("%s", "Введите кол.во векторов направления: ");
	scanf("%d", &count);
	randomVectorPoints();
	int start;
	int end;
	printf("%s", "Введите начальную точку и конечную для проверки есть ли между ними маршрут: ");
	scanf("%d %d", &start, &end);

	if (pathExist(start, end))
		printf("%s", "Да, путь есть!");
	else
		printf("%s", "Не, пути нету :(");

	printf("%s", "\n");
}