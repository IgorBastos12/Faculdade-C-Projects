#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int fatorial (int n){

    int fat = 1;

    while (n > 0){

        fat = fat * n;
        n -= 1;
    }

    return fat;

}

int main()
{
    setlocale(LC_ALL, "portuguese");

    int resultado, n;

    printf("Programa que calcula o fatorial de um n�mero N qualquer.\n\n");

    printf("Defina um n�mero inteiro N positivo qualque para calcular seu fatorial: ");
    scanf("%i", &n);

    while ( n < 0){
        printf("\n\n");
        printf("[ERRO] N�O EXISTE FATORIAL DE N�MERO NEGATIVO.");
        printf("\n\n");
        printf("Defina um n�mero inteiro N positivo qualque para calcular seu fatorial: ");
        scanf("%i", &n);
    }

    resultado = fatorial(n);

    printf("\n\n");
    printf("%i! = %i", n, resultado);
    printf("\n\n\n");



    return 0;
}
