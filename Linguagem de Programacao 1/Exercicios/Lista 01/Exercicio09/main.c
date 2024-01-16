#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
Escreva um programa que recebe uma quantidade arbitr�ria de n�meros
inteiros positivos e calcula a soma dos n�meros pares.
*/

int main()
{

    setlocale(LC_ALL, "portuguese");

    int n;
    int soma = 0;
    int pares = 0;

    printf("Programa que recebe n�meros e calcula a soma dos n�meros pares.\n");
    printf("---------------------------------------------------------------\n\n");

    while(1){

        printf("Digite um n�mero Positivo ou -1 para continuar: ");
        scanf("%i", &n);

        if (n < -1){
            printf("[ERRO] N�mero inv�lido\n\n");
        } else if (n == -1){
            break;
        } else if(n % 2 == 0){
            soma += n;
            pares ++;
        }

    }

    printf("\n\nAo todo foram recebidos %i n�meros pares e a soma deles foi de %i!\n\n", pares, soma);

    return 0;
}
