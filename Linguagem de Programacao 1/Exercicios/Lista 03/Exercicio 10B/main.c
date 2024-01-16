#include <stdio.h>
#include <stdlib.h>

int main()
{

    int vetorA[15] = {1, -2, -3, 4, -5, 6, -7, 8, -9, 10, -11, 12, -13, 14, -15};

    int *vetorB;   //Declarado meu ponteiro

    // Primeiro preciso saber quantos elementos positivos terei no meu vetorA;

    int positivos = 0;

    for (int i = 0; i < 15; i++){
        if (vetorA[i] >= 0){
            positivos++;
        }
    }

    int sizevetorB = positivos;

    vetorB = (int*)malloc(sizevetorB*sizeof(int));

    if (vetorB == NULL){
        printf("\n\nErro ao alocar memória dinâmicamente\n\n");  //Verificação se a memória foi alocada
    } else{


        int k = 0;
        for (int i = 0; i < 15; i++){
            if (vetorA[i] >= 0){
                vetorB[k] = vetorA[i];
                k++;
            }
        }

        for (int i = 0; i < sizevetorB; i++){
            printf("%i  ", vetorB[i]);
        }
    }

    free(vetorB);

    return 0;
}
