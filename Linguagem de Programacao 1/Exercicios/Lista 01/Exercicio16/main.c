#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");

    int num, digito, soma = 0;

    printf("Digite um n�mero inteiro: ");
    scanf("%i", &num);

    if (num < 0){
        num = - num;
    }

    while (num > 0){
        digito = num % 10;
        num = num / 10;
        soma += digito;

    }

    printf("\n\nA soma dos termos do n�mero digitado � %i\n\n", soma);












    return 0;
}
