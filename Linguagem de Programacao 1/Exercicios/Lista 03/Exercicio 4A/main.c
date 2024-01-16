#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int max_element(int *vetor, int n){

    int maxe, i;

    maxe = *vetor;

    for (i = 0; i < n; i++){
        if (vetor[i] > maxe){
            maxe = vetor[i];
        }
    }
    return maxe;
}

void sub_negativos ( int *vetorA, int n, int *vetorB, int m ){

    int i, max_ele_b;

    max_ele_b = max_element(vetorB, m);

    for (i = 0; i < n; i++){
        if (vetorA[i] < 0){
            vetorA[i] = max_ele_b;
        }
    }

}

int main()
{
    setlocale(LC_ALL, "portuguese");


    int result_vetor, i;

    int a[10] = {-1,2,-3,4,-5,6,-7,8,-9,10};

    int b[5] = {10,20,30,40,50};

    printf("Vetor a antes de chamar a função: \n\n");

    for (i = 0; i < 10; i++){
        printf("%i  ", a[i]);
    }

    sub_negativos(a, 10, b, 5);

    printf("\n\nVetor a depois de chamar a função: \n\n");

    for (i = 0; i < 10; i++){
        printf("%i  ", a[i]);
    }
    printf("\n\n");




    return 0;
}
