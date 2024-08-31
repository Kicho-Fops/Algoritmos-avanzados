#include <iostream>
const int FILAS = 4;
const int COLUMNAS = 4;
// Mapa base
char mapaBase[FILAS][COLUMNAS] = {
    {'S', '.', '*', 'F'},
    {'.', '.', '.', '.'},
    {'.', '.', '.', '.'},
    {'.', '.', '.', '.'}};

    
// Variables globales
int numPasos = 0;    // Número de pasos a dar
int numLlamadas = 0; // Número de llamadas recursivas hechas
char solucion[FILAS][COLUMNAS] = {};
// Función para clonar el mapa
void clonar(const char origen[FILAS][COLUMNAS], char destino[FILAS][COLUMNAS])
{
    for (int i = 0; i < FILAS; ++i)
    {
        for (int j = 0; j < COLUMNAS; ++j)
        {
            destino[i][j] = origen[i][j];
        }
    }
}
// Función para imprimir el mapa
void imprimirMapa(const char mapa[FILAS][COLUMNAS])
{
    for (int i = 0; i < FILAS; ++i)
    {
        for (int j = 0; j < COLUMNAS; ++j)
        {
            std::cout << mapa[i][j] << ' ';
        }
        std::cout << '\n';
    }
}
// Función para resetear variables globales
void resetearVariables()
{
    numPasos = 0;
    numLlamadas = 0;
}
// Función de backtracking
void backtrackingBasico(char mapa[FILAS][COLUMNAS], int fila, int columna, int nPasos)
{
    numLlamadas++;
    // Caso base exitoso: encontramos la salida
    if (mapa[fila][columna] == 'F')
    {
        mapa[fila][columna] = 'x'; // Marcar la solución
        clonar(mapa, solucion);    // Actualizamos la solución global
        numPasos = nPasos;
        return;
    }
    // Seguimos explorando si no chocamos con pared o con pasos previos
    // y aún no hemos encontrado solución (numPasos == 0)
    if (mapa[fila][columna] != '*' && mapa[fila][columna] != 'x')
    {
        mapa[fila][columna] = 'x'; // Marca la posición actual
        // Intentar moverse en las 4 direcciones
        if (fila > 0 && numPasos == 0)
        {
            backtrackingBasico(mapa, fila - 1, columna, nPasos + 1);
        }
        if (fila < FILAS - 1 && numPasos == 0)
        {
            backtrackingBasico(mapa, fila + 1, columna, nPasos + 1);
        }
        if (columna > 0 && numPasos == 0)
        {
            backtrackingBasico(mapa, fila, columna - 1, nPasos + 1);
        }
        if (columna < COLUMNAS - 1 && numPasos == 0)
        {
            backtrackingBasico(mapa, fila, columna + 1, nPasos + 1);
        }
        // Desmarca la posición si no se encontró solución
        std::cout << numPasos <<  "\n";
        if (numPasos == 0) // Esto permite que las posiciones sean desmarcadas si no son parte de la solución
        {
            mapa[fila][columna] = '.'; // Desmarcar
        }
    }
}
// Función principal
int main()
{
    // Establecemos el punto de partida en las coordenadas donde esté la 'S'
    int filaInicio = 0, columnaInicio = 0;
    char mapa[FILAS][COLUMNAS];
    // Clonar el mapa base
    clonar(mapaBase, mapa);
    // Primera solución; backtracking básico para encontrar un camino
    std::cout << "*****Versión básica para encontrar una salida : ***\n";
    resetearVariables();
    backtrackingBasico(mapa, filaInicio, columnaInicio, 0);
    if (numPasos > 0)
    {
        std::cout << "Encontrada solución con " << numPasos << " pasos\n";
        imprimirMapa(solucion);
    }
    else
    {
        std::cout << "No se ha encontrado salida\n";
    }
    std::cout << "Llamadas recursivas realizadas: " << numLlamadas << '\n';
    return 0;
}