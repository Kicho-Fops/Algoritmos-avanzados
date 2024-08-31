#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
// Número de ciudades
#define N 4
// Función para encontrar la longitud de la ruta más corta utilizando Ramificación y Poda
    int
    tsp(int graph[N][N], int pos, int visited, vector<vector<int>> &memo)
{

    if (visited == (1 << N) - 1)
    {
        return graph[pos][0]; // Regresar al punto de partida
    }
    if (memo[pos][visited] != -1)
    {
        return memo[pos][visited];
    }
    int min_cost = INT_MAX;
    // Considerar todos los vértices no visitados y calcular el costo mínimo
        for (int city = 0; city < N; city++)
    {

        if (!(visited & (1 << city)))
        {
            int new_visited = visited | (1 << city);
            int curr_cost = graph[pos][city] + tsp(graph, city, new_visited, memo);
            min_cost = min(min_cost, curr_cost);
        }
    }
    memo[pos][visited] = min_cost;
    return min_cost;
}

int main() {
    // Matriz de distancias entre ciudades (grafo)
    int graph[N][N] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    // Memoización para guardar subproblemas ya resueltos
    vector<vector<int>> memo(N, vector<int>(1 << N, -1));

    // Comenzar desde la ciudad 0
    int result = tsp(graph, 0, 1, memo);

    cout << "La ruta más corta tiene una longitud de: " << result << endl;

    return 0;
}

