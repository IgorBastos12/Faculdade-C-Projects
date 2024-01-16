#include <stdio.h>
#include <stdlib.h>

int MatPares (int **matriz, int n, int m){   // Função que retorna a quantidade de elementos Pares de uma matriz
    int i, j;
    int Npares = 0;

    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            if (matriz[i][j] % 2 == 0){
                Npares++;
            }
        }
    }
    return Npares;
}


int main()
{

    int **matPtrA;

    int *vetPtrPares;

    int i, j, m, n, k, Npares;

    printf("Definir a quantidade de linhas n da matriz: ");
    scanf("%i", &n);

    printf("Definir a quantidade de colunas m da matriz: ");
    scanf("%i", &m);

    matPtrA = (int* *) malloc(n * sizeof(int *)); //Alocando dinamicâmente o vetor de ponteiros

    printf("\n");
    for (i = 0; i < n; i++){
        matPtrA[i] = (int *)malloc(m * sizeof(int));  // Alocando dinamicâmente o vetor das linhas da matriz
        for(j = 0; j < m; j++){
            printf("Defina o valor para Matriz[%i][%i] = ", i, j);
            scanf("%i", &matPtrA[i][j]);
        }
    }

    // Pegando a quantidade de elementos pares na matriz;

    Npares = MatPares(matPtrA, n, m);

    vetPtrPares = (int *) malloc(Npares * sizeof(int)); // Alocando dinâmicamente o vetor dos pares da matriz

    k = 0;

    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            if (matPtrA[i][j] % 2 == 0){
                vetPtrPares[k] = matPtrA[i][j];
                k++;
            }
        }
    }

    // Mostando a matriz na tela

     printf("\n\nMatriz:\n\n");
     for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            printf("%i  ", matPtrA[i][j]);
        }
        printf("\n");
    }

    printf("\n\nElementos pares da matriz: \n\n");

    for (k = 0; k < Npares; k++){
        printf("%i  ", vetPtrPares[k]);
    }

    free(matPtrA);
    free(vetPtrPares);

    printf("\n\n");

    return 0;
}
