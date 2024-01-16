#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
Escreva um programa para calcular a média aritmética de um conjunto de
números pares positivos fornecidos pelo usuário.
- Observe que nada impede que o usuário forneça números ímpares ou
negativos, com a ressalva de que eles não poderão ser usados no cálculo
da média aritmética.
-O programa deve realizar a contagem de tentativas de entrada de dados
inválidos.
*/

int main()
{
    setlocale(LC_ALL, "portuguese");

    int num;
    int soma = 0, impar = 0, invalidos = 0, negativos = 0, pares = 0, total = 0;
    float media;

    printf("Programa que Calcula a média dos números pares positivos.\n");
    printf("---------------------------------------------------------\n\n");

    while(1){

        printf("Digite um número ou -1 para finalizar o programa: ");
        scanf("%i", &num);

        if (num > 0 && num % 2 != 0){
            impar ++;
            invalidos ++;
        } else if (num < -1){
            negativos ++;
            invalidos ++;
        } else if (num == -1){
            break;
        } else {
            soma += num;
            pares ++;
        }
    }

    if (soma == 0){
        media = 0;
    } else {
        media = soma / pares;
    }

    total = invalidos + pares;

    printf("\n\n---> Foram recebidos um total de %i dados com os seguintes resultados: \n\n", total);
    printf("---> Ímpares = %i --- Negativos = %i --- Total de dados inválidos = %i \n\n", impar, negativos, invalidos);
    printf("---> Dos dados válidos foram recebidos um total de %i dados com os seguintes resultados:\n\n", pares);
    printf("---> Soma = %i --- Média = %.2f \n\n ", soma, media);

    return 0;
}
