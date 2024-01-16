#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int count (int *vetor, int n, int k){

    int i;
    int contador = 0;

    for (i = 0; i < n; i++){
        if (vetor[i] == k){
            contador++;
        }
    }
    return contador;
}


int main()
{

    setlocale(LC_ALL ,"portuguese");


    int i, k, resultado;
    int a[10] = {1,2,3,4,5,3,7,8,9,10};

    printf("Escolha um número inteiro e positivo para K: ");
    scanf("%i", &k);

    resultado = count(a, 10, k);

    printf("\n\nO vetor (a) tem os seguintes elementos: \n\n");
    for(i = 0; i < 10; i++){
        printf("%i  ", a[i]);
    }

    if (resultado > 1) {
        printf("\n\n\n\nO valor que você escolheu para K aparece %i vezes.\n\n", resultado);
    } else {
        printf("\n\n\n\nO valor que você escolheu para K aparece %i vez.\n\n", resultado);
    }





    return 0;
}
