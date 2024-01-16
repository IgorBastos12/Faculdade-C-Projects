#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int impar (int *vetor, int n){

    int i;
    int impares = 0;

    for (i = 0; i < n; i++){
        if (vetor[i] % 2 != 0){
            impares++;
        }
    }
    return impares;
}

 int sump (int *vetor, int n) {

    int i;
    int soma = 0;

    for (i = 0; i < n; i++){
        if (vetor[i] >= 0){
            soma += vetor[i];
        }
    }

    return soma;


 }

int main()
{
    setlocale(LC_ALL, "portuguese");

    int impares, somaPares;


    int a[10] = {2,-5,4,18,7,12,-3,9,10,-1};

    impares = impar(a, 10);

    somaPares = sump(a, 10);

    printf("Total de números impares do vetor a = %i \n", impares);
    printf("A soma dos números positivos do vetor a = %i \n\n\n", somaPares);



    return 0;
}
