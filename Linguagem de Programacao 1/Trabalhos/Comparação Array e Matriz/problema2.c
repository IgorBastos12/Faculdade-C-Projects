// FILE:          problema2.c
// TITLE:         Problem 2
// SUBMITTED BY:  Igor Fiedler de Bastos and Matheus Demetrio Vieira
// FOR COURSE:    Programming Language 1
// DUE DATE:      September 21, 2023
//
// PURPOSE:
// This program will compare an array with 15 elements and a matriz 3x3
// and return the numbers in common between both. It will read, from
// the user, the 15 elements of the array and 9 elements of the matriz.
// It will print the array and matriz and then compare the values of both
// and print the ones that belong to the array and the matriz.
//
// OVERALL METHOD:
// The list of general tasks is:
// 1. Input array data.
// 2. Input matriz data.
// 3. Print the array values.
// 4. Print the matriz values.
// 5. Compare and print common values
//
// FUNCTIONS:
//    none
//
// INCLUDED FILES:
//    locale.h
//    stdlib.h
//
// DATA FILES:
//    none

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{

    setlocale(LC_ALL, "portuguese");

    const int tam_vet = 15;
    int vet[tam_vet];
    const int l_mat = 3, c_mat = 3;
    int mat[l_mat][c_mat];
    int i, im, j, v_vet, v_mat;
    int ocorrencias[100] = {0};



    printf("Trabalho Avaliativo 01 \n\n");

    printf("Problema 2.2 \n\n");
    printf("Programa que recebe dados de 0 a 99 para um vetor com 15 elementos e uma matriz 3x3 e retorna os valores em comum entre eles.\n\n");
    printf("-------------------------------------------------------------------------------------------------------------------\n\n");


    //------------------------------------------------- Receber dados para o vetor ----------------------------------------------------

    printf("VETOR COM 15 ELEMENTOS.\n\n");
    for (i = 0; i < tam_vet; i++){
        printf("Digite o valor para a posição %i do vetor: ", i);
        scanf("%i", &v_vet);
        fflush(stdin);
        while (v_vet < 0 || v_vet > 99){
            printf("\n\n[ERRO] Valor invalido\n\n");
            printf("Digite o valor para a posição %i do vetor: ", i);
            scanf("%i", &v_vet);
            fflush(stdin);
        }

        vet[i] = v_vet;
    }

    printf("\n\n\n\n");

    //------------------------------------------------- Receber dados para a matriz --------------------------------------------------

    printf("MATRIZ 3X3\n\n");
    for (i = 0; i < l_mat; i++){
        for (j = 0; j < c_mat; j++){
            printf("Digite o valor para a posição %i%i da matriz 3x3: ",i,j);
            scanf("%i", &v_mat);
            fflush(stdin);
            while (v_mat < 0 || v_mat > 99){
                printf("\n\n[ERRO] Valor invalido\n\n");
                printf("Digite o valor para a posição %i%i da matriz 3x3: ",i,j);
                scanf("%i", &v_mat);
                fflush(stdin);
            }
            mat[i][j] = v_mat;

        }
    }
    printf("\n\n\n\n");

    //------------------------------------------------- Mostrar vetor ------------------------------------------------------------------

    for (i = 0; i < tam_vet; i++){
        if(i == 0){
            printf("-> Seu Vetor é:\n\n[ %i ", vet[i]);
        } else if (i == tam_vet - 1){
            printf("%i ]", vet[i]);
        } else {
            printf("%i ", vet[i]);
        }
    }

    printf("\n\n\n\n");

    //------------------------------------------------- Mostrar matriz ---------------------------------------------------------------------

    printf("-> Sua Matriz é:\n\n");
    for (i = 0; i < l_mat; i++){
        printf("{" );
        for (j = 0; j < c_mat; j++){
            if(j == 2){
                printf(" %i } ", mat[i][j]);
            } else {
                printf(" %i ", mat[i][j]);
            }
        }
    }
    printf("\n\n\n\n");

    //------------------------------------------------ Comparando vetor e matriz ---------------------------------------------------------------

    printf("-> Os valores em comum no vetor e na matriz são : \n\n");

    printf("{ ");
    for (i = 0; i < tam_vet; i++){
        for (im = 0; im < l_mat; im++){
            for(j = 0; j < c_mat; j++){
                if (vet[i] == mat[im][j] && ocorrencias[vet[i]] == 0){
                    printf("%i ", vet[i]);
                    ocorrencias[vet[i]] = 1;

                }
            }
        }
    }

    printf("}");
    printf("\n\n\n\n");

    return 0;
}
