/* C/C++ programa para resolver el problema de Rat in a Maze usando backtracking */
#include <stdio.h>

// Tamaño del laberinto
#define N 4

bool solveMazeUtil(int laberinto[N][N], int x, int y, int sol[N][N]);

/* Una función de utilidad para imprimir la matriz de solución sol[N][N] */
void printSolution(int sol[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf(" %d ", sol[i][j]);
        printf("\n");
    }
}

/* Una función de utilidad para verificar si x, y es un índice válido para el laberinto N*N */
bool isSafe(int laberinto[N][N], int x, int y)
{
    // if (x, y outside maze) return false
    if (x >= 0 && x < N && y >= 0 && y < N && laberinto[x][y] == 1)
        return true;

    return false;
}

/* Función principal para resolver el laberinto */
bool resolverLaberinto(int laberinto[N][N])
{
    int sol[N][N] = {{0, 0, 0, 0},
                     {0, 0, 0, 0},
                     {0, 0, 0, 0},
                     {0, 0, 0, 0}};

    if (solveMazeUtil(laberinto, 0, 0, sol) == false)
    {
        printf("La solución no existe");
        return false;
    }

    printSolution(sol);
    return true;
}

/* Una función de utilidad recursiva para resolver el problema del laberinto */
bool solveMazeUtil(int laberinto[N][N], int x, int y, int sol[N][N])
{
    // if (x, y is goal) return true
    if (x == N - 1 && y == N - 1)
    {
        sol[x][y] = 1;
        return true;
    }
    // Comprobar si laberinto[x][y] es válido
    if (isSafe(laberinto, x, y) == true)
    {
        // mark x, y as part of solution path
        sol[x][y] = 1;

        /* Avanzar en la dirección x */
        if (solveMazeUtil(laberinto, x + 1, y, sol) == true)
            return true;

        /* Si moverse en la dirección x no da solución entonces Mover hacia abajo en la dirección y */
        if (solveMazeUtil(laberinto, x, y + 1, sol) == true)
            return true;

        /* Si ninguno de los movimientos anteriores funciona, entonces BACKTRACK: desmarque x, y como parte de la ruta de la solución */
        sol[x][y] = 0;
        return false;
    }

    return false;
}

int main()
{
    int laberinto[N][N] = {{1, 0, 0, 0},
                           {1, 1, 0, 1},
                           {0, 1, 0, 0},
                           {1, 1, 1, 1}};

    resolverLaberinto(laberinto);
    return 0;
}
