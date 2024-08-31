#include <iostream>
#include <vector>
#include <string>
// Función para calcular el array Z
std::vector<int> calculateZ(const std::string &s)
{
    /*

    Pequeña intermision. Mientras que conceptualmente entiendo lo de los rangos L y R
    siento que aunque sin duda es una manera de resolver el ejercicio, y asi fue como
    fue originalmente resuleto, pero hay maneras conceptualmente mas faciles, al menos
    si es como entendi el problema. Perfectamente puedo estar mal, pero cual es el beneficio
    de usar "rangos", es que de otra manera el problema deja de ser lineal y empieza a ser de rango O(n*m)?
    */

    int n = s.length();
    std::vector<int> Z(n, 0);
    int L = 0, R = 0, K;
    for (int i = 1; i < n; ++i)  
                                 
    {
        if (i > R) // Si el iterador es mayor al limite derecho
        { // recalculamos los limites
            L = R = i; // Lo minimo que se necesitan expander los limites es a lo mismo que el iterador
            while (R < n && s[R] == s[R - L]) // Mientras limite derecho es mayor a la longitud a la cadena concatenada Y la cadena concatenada en indice R es igual a la cadena concatenada en indice derecha mas izquierda 
            {
                R++; // Expandimos limite de la derecha 
            }
            Z[i] = R - L; // Asignamos la cantidad de letras que coinciden con nuesto patron
            R--;
        }
        else // Si el iterador no es mayor al limite derecho
        {
            K = i - L;
            if (Z[K] < R - i + 1)
            {
                Z[i] = Z[K];
            }
            else // mas logica
            {
                L = i;
                while (R < n && s[R] == s[R - L])
                {
                    R++;
                }
                Z[i] = R - L;
                R--;
            }
        }
    }
    return Z;
}

// Función para buscar el patrón en el texto usando el algoritmo Z
std::vector<int>
searchPattern(const std::string &text, const std::string &pattern)
{
    std::string concat = pattern + "$" + text; // Cadena final, estilo aba$abacabab
    std::vector<int> Z = calculateZ(concat); // Se calcula la matriz, caso ejemplo = {0,1,0,3,0,1,0,3,0,1,0}
    std::vector<int> result;
    int m = pattern.length(); // Longitud del patron, en este caso 3
    for (int i = 0; i < Z.size(); ++i) // Desde 0 hasta la longitud de Z, hasta 11
    {
        if (Z[i] == m) // Si el numero en el indice I es igual que la longitud de la cadena original
        // Esto implica que el codigo solo retorna donde hay coincidencias completas, no coinicdencias parciales
        {
            // std::cout << Z[i] << " " << m << std::endl;
            result.push_back(i - m - 1);
        }
    }
    return result;
}

int main()
{
    std::string text, pattern;
    // Entrada del patrón y texto
    std::cout << "Introduce el patrón: ";
    std::cin >> pattern;
    std::cout << "Introduce el texto: ";
    std::cin >> text;
    // Buscar patrón en el texto
    std::vector<int> positions = searchPattern(text, pattern);
    // Imprimir las posiciones donde se encontró el patrónif (positions.empty()) {
    std::cout << "El patrón no se encuentra en el texto." << std::endl;
    if (positions.empty())
    {
        std::cout << "El patrón no se encuentra en el texto." << std::endl;
    }
    else
    {
        std::cout << "El patrón se encuentra en las posiciones: ";
        for (int pos : positions)
        {
            std::cout << pos + 1 << " "; // +1 para ajustar a 1-based index
        }
        std::cout << std::endl;
    }
    return 0;
}