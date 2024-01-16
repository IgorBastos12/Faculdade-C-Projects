#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/*
Escreva um programa que recebe uma quantidade arbitr�ria de n�meros
inteiros e mostra qual foi o menor n�mero �mpar.
*/


int main()
{
    setlocale(LC_ALL, "portuguese");

    int num, menor;
    int leiturainicial = 1;
    int total = 0;

    printf("Programa que recebe uma quantidade finita de n�meros e retorna o menor n�mero impar. \n");
    printf("------------------------------------------------------------------------------------\n\n");

    while(1){
        printf("Digite um n�mero ou -1 para finalizar: ");
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
        printf("\n\nN�o foi passado nenhum n�mero impar antes da finaliza��o do programa");
    } else{
        printf("\n\nForam passados %i n�meros e o menor n�mero impar foi %i \n\n", total, menor);
    }




    return 0;
}
