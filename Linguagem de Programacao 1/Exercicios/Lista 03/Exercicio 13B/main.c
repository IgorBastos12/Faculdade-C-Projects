#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **matPtrA; // Vetor de ponteiros

    int **matPtrB;

    int n, m, i, j;


    printf("Defina a quantidade de linhas n da matriz: ");
    scanf("%i", &n);

    printf("Defina a quantidade de colunas m da matriz: ");
    scanf("%i", &m);


    matPtrA = (int **)malloc(n*sizeof(int*)); // Alocando memória para o meu vetor de ponteiros para inteiros que terá tamanho n, ou seja, igual o número
                                            // de linhas da minha matriz

    printf("\n\n");

    for (i = 0; i < n; i++){
        matPtrA[i] = (int *)malloc(m*sizeof(int));  // Cada linha do meu vetor de ponteiros vai apontar para uma linha da minha matriz;
        for (j = 0; j < m; j++){
            printf("Defina o valor para Matriz[%i][%i] = ", i, j);
            scanf("%i", &matPtrA[i][j]);
        }
    }


    matPtrB = (int**)malloc(m*sizeof(int*));   // Alocando memória para o vetor de ponteiros para inteiros B

    for (j = 0; j < m; j++){
         matPtrB[j] = (int*)malloc(n*sizeof(int)); // Apontando cada linha do vetor de ponteiros B para uma linha da matriz B
         for (i = 0; i < n; i++){
            matPtrB[j][i] = matPtrA[i][j];
         }
    }


    printf("\n\nImprimindo dados \n\n");


    printf("Matriz A\n");
    for (i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            printf("%i  ", matPtrA[i][j]);
        }
        printf("\n");
    }

    printf("\n\nMatriz B = Matriz A transposta\n");
    for (j = 0; j < m; j++){
        for(i = 0; i < n; i++){
            printf("%i  ", matPtrB[j][i]);
        }
        printf("\n");
    }




    free(matPtrA);
    free(matPtrB);



    return 0;
}
