#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/*
Escreva um programa que solicite ao usu�rio tr�s n�meros inteiros a, b, c. O
programa deve somar todos os inteiros entre b e c que sejam divis�veis por
n�mero a.
*/

int main()
{

    setlocale(LC_ALL, "portuguese");

    int x, ini, fim, i;
    int soma = 0;

    printf("Programa que verifica quais n�meros dentro de um intervalo definido s�o divis�veis por X e retorna a soma dele. \n");
    printf("-----------------------------------------------------------------------------------------\n\n");

    printf("\nDefina X: ");
    scanf("%i", &x);

    printf("\nDefina o inicio do intervalo: ");
    scanf("%i", &ini);

    printf("\nDefina o fim do intervalo: ");
    scanf("%i", &fim);

    for(i = ini; i <= fim; i++){
        if (i % x == 0){
            soma += i ;
        }
    }

    printf("\n\nSoma = %i\n\n", soma);










    return 0;
}
