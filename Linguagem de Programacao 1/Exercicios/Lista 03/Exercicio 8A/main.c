#include <stdio.h>
#include <stdlib.h>

int fatorial(int n) {
    // Caso base: fatorial de 0 é 1
    if (n == 0) {
        return 1;
    }
    // Caso recursivo: fatorial de n é n multiplicado pelo fatorial de (n - 1)
    else {
        return n * fatorial(n - 1);
    }
}

int main()
{


    int res = fatorial(5);

    printf("%i", res);
    return 0;
}
