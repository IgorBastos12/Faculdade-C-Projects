#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int min_element(int *vetor, int n){

    int mine, i;

    mine = *vetor;

    for (i = 0; i < n; i++){
        if (vetor[i] < mine){
            mine = vetor[i];
        }
    }
    return mine;
}

void sub_impares ( int *vetorA, int n, int *vetorB, int m ){

    int i, min_ele_b;

    min_ele_b = min_element(vetorB, m);

    for (i = 0; i < n; i++){
        if (vetorA[i] % 2 != 0){
            vetorA[i] = min_ele_b;
        }
    }

}

int main()
{
    setlocale(LC_ALL, "portuguese");


    int i;

    int a[10] = {1,2,3,4,5,6,7,8,9,10};

    int b[5] = {10,20,3,40,50};

    printf("Vetor a antes de chamar a função: \n\n");

    for (i = 0; i < 10; i++){
        printf("%i  ", a[i]);
    }

    sub_impares(a, 10, b, 5);

    printf("\n\nVetor a depois de chamar a função: \n\n");

    for (i = 0; i < 10; i++){
        printf("%i  ", a[i]);
    }
    printf("\n\n");




    return 0;
}
