
#include<stdio.h>
#include<string.h>
    // Una función máxima para encontrar el máximo de dos números enteros
int max(int x, int y)
{
    return(x > y) ? x : y;
}
// Devuelve la longitud de la subsecuencia palindrómica más larga en la secuencia
int longest_palindrome(char a[], int i, int j)
{
    // Caso base 1: Si solo hay 1 carácter
    if(i == j)
        return 1;
    // *Caso base 2: Si solo hay 2
    // caracteres y ambos son iguales*
    if(a[i] == a[j] && i + 1 == j)
        return 2;
    // Si el primer y el último carácter coinciden
    if(a[i] == a[j])
            return longest_palindrome(a, i + 1, j - 1) + 2;
    // Si el primer y el último carácter no coinciden
    return max(longest_palindrome(a, i, j - 1), longest_palindrome(a, i + 1, j));
}

/* Programa controlador para probar las funciones anteriores
 */
int main()
{
    char seq[] = "ABBDCACB";
    int n = strlen(seq);
printf("La longitud de la subsecuencia de palíndromo más    larga es: %d", longest_palindrome(seq, 0, n-1));
return 0;
}