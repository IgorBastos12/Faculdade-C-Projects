#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/*
Escreva um programa que recebe uma quantidade arbitrária de números
inteiros e mostra qual foi o menor número ímpar.
*/


int main()
{
    setlocale(LC_ALL, "portuguese");

    int num, menor;
    int leiturainicial = 1;
    int total = 0;

    printf("Programa que recebe uma quantidade finita de números e retorna o menor número impar. \n");
    printf("------------------------------------------------------------------------------------\n\n");

    while(1){
        printf("Digite um número ou -1 para finalizar: ");
        scanf("%i", &num);

        if (num == -1){
            break;

        } else if (num %2 != 0 && leiturainicial == 1){
            menor = num;
            total ++;
            leiturainicial = 0;

        } else if (num % 2 != 0 && num < menor){
            menor = num;
            total++;

        } else {
            total++;

        }

    }

    if (leiturainicial == 1){
        printf("\n\nNão foi passado nenhum número impar antes da finalização do programa");
    } else{
        printf("\n\nForam passados %i números e o menor número impar foi %i \n\n", total, menor);
    }




    return 0;
}
