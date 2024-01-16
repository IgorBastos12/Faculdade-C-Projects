#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
Escreva um programa para calcular a m�dia aritm�tica de um conjunto de
n�meros pares positivos fornecidos pelo usu�rio.
- Observe que nada impede que o usu�rio forne�a n�meros �mpares ou
negativos, com a ressalva de que eles n�o poder�o ser usados no c�lculo
da m�dia aritm�tica.
-O programa deve realizar a contagem de tentativas de entrada de dados
inv�lidos.
*/

int main()
{
    setlocale(LC_ALL, "portuguese");

    int num;
    int soma = 0, impar = 0, invalidos = 0, negativos = 0, pares = 0, total = 0;
    float media;

    printf("Programa que Calcula a m�dia dos n�meros pares positivos.\n");
    printf("---------------------------------------------------------\n\n");

    while(1){

        printf("Digite um n�mero ou -1 para finalizar o programa: ");
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
    printf("---> �mpares = %i --- Negativos = %i --- Total de dados inv�lidos = %i \n\n", impar, negativos, invalidos);
    printf("---> Dos dados v�lidos foram recebidos um total de %i dados com os seguintes resultados:\n\n", pares);
    printf("---> Soma = %i --- M�dia = %.2f \n\n ", soma, media);

    return 0;
}
