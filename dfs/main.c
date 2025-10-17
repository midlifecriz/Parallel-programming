#include "graph.h"


#define START   5
#define MAX 5000
#define MULTIPLIER  10


int main() {
    int v = 0;
    int* colour = NULL;
    int* visited = NULL;
    int visited_count = 0;
    int quantity = START;

    while (quantity <= MAX) {    
        // создаем случайный граф на n вершин
        Graph* graph = generateRandomGraph(quantity);
        v = rand() % quantity;
        colour = (int*)malloc(quantity * sizeof(int));
        for (size_t i = 0; i < quantity; i++) colour[i] = WHITE;
        visited = (int*)malloc(quantity * sizeof(int));
        visited_count = 0;

        clock_t start_time = clock();
        DFS(graph, v, colour, visited, &visited_count);
        clock_t end_time = clock();
        double time_spent = (double)(end_time - start_time) / CLOCKS_PER_SEC;
        //for (size_t j = 0; j < visited_count; j++) printf("%d  ", visited[j]);
        printf("Время выполнения DFS для %d элементов: %lf\n", quantity, time_spent);

        destroyGraph(graph);
        free(colour);
        free(visited);
        visited_count = 0;

        quantity *= MULTIPLIER;
    }

    return 0;
}

