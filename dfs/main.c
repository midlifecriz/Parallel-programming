#include "graph.h"


//#define START   10
//#define MAX 1000
//#define MULTIPLIER  10
#define SIZE    5


int main() {
    int v = 0;
    int* colour = NULL;
    int* visited = NULL;
    int visited_count = 0;
    int quantity = 0;
    Graph* graph = NULL;
    size_t index = 0;

    int experiments[SIZE] = {100, 250, 500, 750, 1000};

    while (index < SIZE) {
        quantity = experiments[index];
        printf("Время выполнения для %d вершин:\n", quantity);

        // создаем случайный граф на n вершин
        graph = generateRandomGraph(quantity);
        if (graph == NULL) return 1;

        colour = (int*)malloc(quantity * sizeof(int));
        for (size_t i = 0; i < quantity; i++) colour[i] = WHITE;
        visited = (int*)malloc(quantity * sizeof(int));
        visited_count = 0;

        clock_t start_time = clock();
        shellForDFS(graph, colour, visited, &visited_count);
        clock_t end_time = clock();
        double time_spent = (double)(end_time - start_time) / CLOCKS_PER_SEC;
        
        //for (size_t j = 0; j < visited_count; j++) printf("%d  ", visited[j]);
        //printf("\n");
        
        printf("Случайный граф: %lf\n", time_spent);

        destroyGraph(graph);
        free(colour);
        free(visited);
        visited_count = 0;

        //создаем разреженный граф на n вершин
        Graph* graph = generateRandomGraph(quantity);
        if (graph == NULL) return 1;
        v = rand() % quantity;
        colour = (int*)malloc(quantity * sizeof(int));
        for (size_t i = 0; i < quantity; i++) colour[i] = WHITE;
        visited = (int*)malloc(quantity * sizeof(int));
        visited_count = 0;

        start_time = clock();
        DFS(graph, v, colour, visited, &visited_count);
        end_time = clock();
        time_spent = (double)(end_time - start_time) / CLOCKS_PER_SEC;

        //for (size_t j = 0; j < visited_count; j++) printf("%d  ", visited[j]);
        //printf("\n");

        printf("Разреженный граф: %lf\n", time_spent);

        destroyGraph(graph);
        free(colour);
        free(visited);
        visited_count = 0;

        //создаем плотный шраф на n вершин
        graph = generateRandomGraph(quantity);
        if (graph == NULL) return 1;
        v = rand() % quantity;
        colour = (int*)malloc(quantity * sizeof(int));
        for (size_t i = 0; i < quantity; i++) colour[i] = WHITE;
        visited = (int*)malloc(quantity * sizeof(int));
        visited_count = 0;

        start_time = clock();
        DFS(graph, v, colour, visited, &visited_count);
        end_time = clock();
        time_spent = (double)(end_time - start_time) / CLOCKS_PER_SEC;

        //for (size_t j = 0; j < visited_count; j++) printf("%d  ", visited[j]);
        //printf("\n");

        printf("Плотный граф: %lf\n", time_spent);

        destroyGraph(graph);
        free(colour);
        free(visited);
        visited_count = 0;

        index++;
        //quantity *= MULTIPLIER;
    }

    return 0;
}

