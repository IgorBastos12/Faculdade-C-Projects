#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


/*
Escreva um programa que recebe uma quantidade arbitrária de números reais
(float) e mostra qual foi o maior número negativo.

*/

int main()
{

    setlocale(LC_ALL, "portuguese");

    float num;
    float maior = 0;
    int total = 0;
    int leituraincial = 1;

    printf("Programa que recebe uma quantidade de números reais e retorna o maior número negativo.\n");
    printf("------------------------------------------------------------------------------- \n\n");

    while(1){
        printf("Digite um número ou 12345 para finalizar: ");
        scanf("%f", &num);

        if(num == 12345){
            break;
        } else if ( leituraincial == 1 && num < 0){
            maior = num;
            total ++;
            leituraincial = 0;
        } else if ( num < 0 && num > maior ) {
            maior = num;
            total ++;
        } else{
            total ++;
        }
    }

    printf("\n\nForam recebidos um total de %i números onde o maior dos negativos foi %f \n\n", total, maior);







    return 0;
}
