#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{

    setlocale(LC_ALL, "portuguese");

    int **matPtrA;

    int i, j, m, n, maior, maiorI, maiorJ;


    printf("Definir a quantidade de linhas n da matriz: ");
    scanf("%i", &n);

    printf("Definir a quantidade de colunas m da matriz: ");
    scanf("%i", &m);


    matPtrA = (int **) malloc(n * sizeof(int*));  // Alocando memória para o vetor de ponteiros


    // Adicionando os valores a matriz
    printf("\n");
    for (i = 0; i < n; i++){
        matPtrA[i] = (int *) malloc(m * sizeof(int)); // Alocando memória para o cada linha da da matriz
        for(j = 0; j < m; j++){
            printf("Defina o valor para Matriz[%i][%i] = ", i, j);
            scanf("%i", &matPtrA[i][j]);
        }
    }


    // Analisando o maior valor da matriz

    maior = matPtrA[0][0];
    maiorI = 1;
    maiorJ = 1;

    for (i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            if(matPtrA[i][j] > maior){
                maior = matPtrA[i][j];
                maiorI = i + 1;
                maiorJ = j + 1;
            }
        }
    }


    // Mostrando a mtriz o maior valor da matriz a sua linha e sua coluna

    printf("\n\nMatriz \n\n");
    for(i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            printf("%i  ", matPtrA[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    printf("O maior valor da matriz é %i que está na linha %i e na coluna %i\n\n", maior, maiorI, maiorJ);

    free(matPtrA);


    return 0;
}
