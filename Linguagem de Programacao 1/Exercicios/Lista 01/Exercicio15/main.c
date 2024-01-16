#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{

    setlocale(LC_ALL, "portuguese");

    int n, i;
    float resultado = 0;


    printf("Digite um número inteiro: ");
    scanf("%i", &n);
    printf("\n\nA soma de: \n\n");


    for (i = 1; i < n; i++){
        if (i != n){
            printf("(1/%i) + ", i);
            resultado += ( 1.0 / i ) ;
        }
    }

    resultado += ( 1.0 / i ) ;
    printf("(1/%i) = %f\n\n", i, resultado);

    return 0;
}
