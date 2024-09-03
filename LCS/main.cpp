#include <iostream>
#include <cstring> // Use this instead of <string.h> for C++ style
using namespace std;

void print_lstring(char *X, char *Y, int m, int n)
{
    int longest[m + 1][n + 1];
    int len = 0;
    int row = 0, col = 0;

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                longest[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
            {
                longest[i][j] = longest[i - 1][j - 1] + 1;
                if (len < longest[i][j])
                {
                    len = longest[i][j];
                    row = i;
                    col = j;
                }
            }
            else
                longest[i][j] = 0; // Move this inside the else block
        }
    }

    if (len == 0)
    {
        cout << "There exists no common substring";
        return;
    }

    char *final_str = (char *)malloc((len + 1) * sizeof(char));
    final_str[len] = '\0'; // Null-terminate the string

    while (longest[row][col] != 0)
    {
        final_str[--len] = X[row - 1];
        row--;
        col--;
    }

    cout << final_str;
    free(final_str); // Free the allocated memory
}

int main()
{
    char X[] = "helloworld";
    char Y[] = "worldbook";
    int m = strlen(X);
    int n = strlen(Y);
    print_lstring(X, Y, m, n);
    return 0;
}
