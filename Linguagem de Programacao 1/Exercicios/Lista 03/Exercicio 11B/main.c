#include <stdio.h>
#include <stdlib.h>

int pares (int *vetor , int size){    // Função que retorna quantos valores pares tem no vetor

    int npares = 0;

    for (int i = 0; i < size; i++){
        if (vetor[i] % 2 == 0){
            npares++;
        }
    }
    return npares;
}

int positivos (int *vetor, int size){    // Função que retorna quantos valores positivos tem no vetor

    int npositivos = 0;

    for (int i = 0; i < size; i++){
        if (vetor[i] >= 0){
            npositivos++;
        }
    }
    return npositivos;
}

int main()
{

    int sizevetorA, sizevetorB, sizevetorC, i;

    int *vetorB, *vetorC;


    printf("Defina um tamanho para o seu vetorA: ");
    scanf("%i", &sizevetorA);


    int vetorA[sizevetorA];

    printf("\n\nDefina os valores pare seu vetorA: \n");  // Input dos valores para o vetor
    for (i = 0; i < sizevetorA; i++){
        printf("vetor[%i] = ", i);
        scanf("%i", &vetorA[i]);
    }

    sizevetorB = pares(vetorA, sizevetorA);  //Chamado a função que vai retornar a quantidade de vetores pares do vetorA

    sizevetorC = positivos(vetorA, sizevetorA); // Chamando a função que vai retornar a quantidade de vetores positivos do vetorB


    vetorB = (int *)malloc(sizevetorB*sizeof(int)); // Alocação dinâmica de memória para o vetorB;

    vetorC = (int *)malloc(sizevetorC*sizeof(int)); // Alocalção dinâmica de memória para o vetorC;


    if ( vetorB == NULL || vetorC == NULL){

        printf("\n\nErro na alocação de memória!\n\n");

    } else {
        int k = 0;

        for (i = 0; i < sizevetorA; i++){      // Atribui todos os valores pares do vetorA para o vetorB
            if (vetorA[i] % 2 == 0){
                vetorB[k] = vetorA[i];
                k++;
            }
        }

        k = 0;

        for (i = 0; i < sizevetorA; i++){     // Atribui todos os valores positivos do vetorA para o vetorC
            if (vetorA[i] >= 0){
                vetorC[k] = vetorA[i];
                k++;
            }
        }



        printf("\n\nImprimindo os dados:\n\n");

        printf("VetorA = ");
        for (i = 0; i < sizevetorA; i++){
            printf("  %i", vetorA[i]);
        }

        printf("\n\n");

        printf("VetorB = ");
        for (i = 0; i < sizevetorB; i++){
            printf("  %i", vetorB[i]);
        }

        printf("\n\n");

        printf("VetorC = ");
        for (i = 0; i < sizevetorC; i++){
            printf("  %i", vetorC[i]);
        }
    }


    free(vetorB);
    free(vetorC);

    printf("\n\n");

    return 0;
}
