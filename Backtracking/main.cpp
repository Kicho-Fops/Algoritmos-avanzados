#include <iostream>

const int FILAS = 4;
const int COLUMNAS = 4;

// const int FILA = 10;
// const int COLUMNA = 10;

const int FILAS2 = FILAS;
const int COLUMNAS2 = COLUMNAS;

const int FILAS3 = FILAS;
const int COLUMNAS3 = COLUMNAS;

// Mapa base
char mapaBase[FILAS][COLUMNAS] = {
    {'S', '.', '*', 'F'},
    {'.', '.', '.', '.'},
    {'.', '.', '.', '.'},
    {'.', '.', '.', '.'}
    
    };

// char mapaBase[FILAS][COLUMNAS] = {
//     {'I', '.', '.', '*', '.', '.', '.', '.', '.', '.'},
//     {'.', '*', '.', '*', '.', '*', '*', '*', '*', '.'},
//     {'.', '*', '.', '.', '.', '.', '.', '.', '*', '.'},
//     {'.', '.', '*', '*', '*', '.', '*', '.', '*', '.'},
//     {'*', '.', '.', '.', '.', '*', '.', '.', '.', '.'},
//     {'.', '*', '*', '*', '.', '.', '.', '*', '*', '.'},
//     {'.', '.', '.', '*', '*', '*', '.', '.', '.', '.'},
//     {'.', '*', '.', '.', '.', '.', '.', '*', '.', '.'},
//     {'.', '.', '.', '*', '*', '.', '*', '.', '*', '.'},
//     {'.', '*', '.', '.', '.', '.', '.', '.', '.', 'F'}
//     };


// Variables globales
int numPasos = 0;    // Número de pasos a dar
int numLlamadas = 0; // Número de llamadas recursivas hechas
int mejorLongitud = -1; // Inicializar a -1 para indicar que no se ha encontrado una solución aún
char solucion[FILAS][COLUMNAS] = {};
char mejorSolucion[FILAS2][COLUMNAS2] = {};
char prueba[FILAS3][COLUMNAS3] = {};

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
    mejorLongitud = -1; // Resetear a -1 al inicio
}

// Función de backtracking
void backtrackingEncontrarCamino(char mapa[FILAS][COLUMNAS], int fila, int columna, int nPasos)
{
    // Pase el codigo por ChatGPT para que le diera formato y me ayudo un poco al final a resolverlo
    // Sigo sin entender porque se ejecuta casi 1800 veces pero logre que encontrar la solucion mas corta que eso me importa mas

    numLlamadas++;

    // Caso base exitoso: encontramos la salida
    if (mapa[fila][columna] == 'F')
    {
        clonar(mapa, solucion); // Actualizamos la solución temporal
        if (mejorLongitud == -1 || nPasos < mejorLongitud)
        {
            mejorLongitud = nPasos; // Guardamos la longitud del mejor camino
            std::cout << "Mejor longitud: " << mejorLongitud << '\n';
            clonar(solucion, mejorSolucion); // Guardamos la mejor solución encontrada
        }
        numPasos = mejorLongitud;
        return;
    }

    // Seguimos explorando si no chocamos con pared o si no hemos visitado la casilla
    if (mapa[fila][columna] != '*' && mapa[fila][columna] != 'x')
    {
        mapa[fila][columna] = 'x'; // Marca la posición actual como visitada

        // Intentar moverse en las 4 direcciones
        if (fila > 0)
        {
            backtrackingEncontrarCamino(mapa, fila - 1, columna, nPasos + 1);
        }
        if (fila < FILAS - 1)
        {
            backtrackingEncontrarCamino(mapa, fila + 1, columna, nPasos + 1);
        }
        if (columna > 0)
        {
            backtrackingEncontrarCamino(mapa, fila, columna - 1, nPasos + 1);
        }
        if (columna < COLUMNAS - 1)
        {
            backtrackingEncontrarCamino(mapa, fila, columna + 1, nPasos + 1);
        }

        //clonar(solucion, prueba);
        //imprimirMapa(prueba);

        mapa[fila][columna] = '.'; // Desmarcar la posición actual para explorar otros caminos
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
    backtrackingEncontrarCamino(mapa, filaInicio, columnaInicio, 0);

    if (mejorLongitud != -1)
    {
        std::cout << "Encontrada solución con " << mejorLongitud << " pasos\n";
        imprimirMapa(mejorSolucion);
    }
    else
    {
        std::cout << "No se ha encontrado salida\n";
    }

    std::cout << "Llamadas recursivas realizadas: " << numLlamadas << '\n';
    return 0;
}
