#include <stdio.h>
#include <stdlib.h>

int Pares (int *vetor, int sizevetor){    // Função que retorna a quantidade de valores pares de um vetor

    int npares = 0;

    for (int i = 0; i < sizevetor; i++){
        if (vetor[i] % 2 == 0){
            npares++;
        }
    }
    return npares;
}

int main()
{

    int sizevetorA, sizevetorB, sizevetorC, i;

    int *vetorC; // Declaração do ponteiro vetorC



    printf("Defina um tamanho para o seu vetorA: ");  // Tamanho do vetorA
    scanf("%i", &sizevetorA);


    int vetorA[sizevetorA];   // Declaração o vetorA

    printf("\n\nDefina os valores pare seu vetorA: \n");  // Input dos valores para o vetorA
    for (i = 0; i < sizevetorA; i++){
        printf("vetor[%i] = ", i);
        scanf("%i", &vetorA[i]);
    }


    printf("\n\nDefina um tamanho para o seu vetorB: "); // Tamanho do vetorB
    scanf("%i", &sizevetorB);


    int vetorB[sizevetorB];   // Declaração do vetorB

    printf("\n\nDefina os valores pare seu vetorB: \n");  // Input dos valores para o vetorB
    for (i = 0; i < sizevetorB; i++){
        printf("vetor[%i] = ", i);
        scanf("%i", &vetorB[i]);
    }



    sizevetorC = Pares(vetorA, sizevetorA) + Pares(vetorB, sizevetorB); // Descobrindo o tamanho do vetorC que será os valores pares do vetorA e os valores pares do vetorB

    vetorC = (int *)malloc(sizevetorC*sizeof(int));


    if (vetorC == NULL){

        printf("\n\nERRO na alocação de memória!\n\n");

    } else {

        int k = 0;

        for (i = 0; i < sizevetorA; i++){     // Adicionando os valores pares do vetorA no vetorC
            if (vetorA[i] % 2 == 0){
                vetorC[k] = vetorA[i];
                k++;
            }
        }


        for (i = 0; i < sizevetorB; i++){     // Adicionando os valores pares do vetorB no vetorC
            if (vetorB[i] % 2 == 0){
                vetorC[k] = vetorB[i];
                k++;
            }
        }


        printf("\n\nImprimindo dados: \n\n");

        printf("Vetor A = ");
        for (i = 0; i < sizevetorA; i++){
            printf("  %i", vetorA[i]);
        }

        printf("\n\n");

        printf("Vetor B = ");
        for (i = 0; i < sizevetorB; i++){
            printf("  %i", vetorB[i]);
        }


        printf("\n\n");

        printf("Vetor A = ");
        for (i = 0; i < sizevetorC; i++){
            printf("  %i", vetorC[i]);
        }

    }



    free(vetorC);

    printf("\n\n");

    return 0;
}
