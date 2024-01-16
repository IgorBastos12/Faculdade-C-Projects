#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
Escreva um programa que permita armazenar dados sobre o estoque de vinhos
de uma adega que tem seguintes funcionalidades:
- Mostrar um menu para usuário:
- 1 para vinho tinto
- 2 para vinho branco
- 3 para vinho rosê
- Entrada de dados indicando a quantidade e o tipo de vinho para incluir no
estoque
- Entrada de dados indicando a quantidade e o tipo de vinho para retirar do
estoque
- Demostrar a situação no estoque especificando a quantidade de cada tipo
de vinho e a porcentagem da cada tipo sobre o total geral de vinhos.
*/

int main()
{
    setlocale(LC_ALL, "portuguese");

    int op1, op2, op3, nvt, nvb, nvr;
    int vt = 50, vb = 50, vr = 50;


    while(1){
        printf("-----------------ADEGAVINHOS---------------- \n\n");
        printf("1. PARA ADICIONAR VINHO NO ESTOQUE. \n");
        printf("2. PARA RETIRAR VINHO DO ESTOQUE. \n");
        printf("3. PARA MOSTRAR O ESTOQUE. \n");
        printf("4. PARA SAIR. \n\n");
        printf("-------------------------------------------- \n\n");

        printf("Defina a operação: ");
        scanf("%i", &op1);

        if(op1 == 4){
            break;
        } else{

            switch (op1){
            case 1:
                printf("\n\nBEM VINDO AO ESTOQUE!\n\n");

                printf("--------ESTOQUE---------\n\n");
                printf("1. Vinho Tinto \n");
                printf("2. Vinho Branco \n");
                printf("3. Vinho Rose \n");
                printf("\n------------------------\n\n");

                printf("Escolha o tipo de vinho que deseja adicionar ao estoque conforme o MENU: ");
                scanf("%i", &op2);
                if (op2 == 1){
                    printf("\n\nESTOQUE DE VINHO TINTO!\n\n");
                    printf("Digite a quantidade de garrafas a serem adicionadas ao estoque: ");
                    scanf("%i", &nvt);
                    vt += nvt;

                    printf("\n%i GARRAFAS ADICIONADAS AO ESTOQUE COM SUCESSO!\n\n", nvt);

                } else if (op2 == 2) {
                    printf("\n\nESTOQUE DE VINHO BRANCO\n\n");
                    printf("Digite a quantidade de garrafas a serem adicionadas ao estoque: ");
                    scanf("%i", &nvb);
                    vb += nvb;

                    printf("\n%i GARRAFAS ADICIONADAS AO ESTOQUE COM SUCESSO! \n\n", nvb);

                } else if (op2 == 3){
                    printf("\n\nESTOQUE DE VINHO ROSE\n\n");
                    printf("Digite a quantidade de garrafas a serem adicionadas ao estoque: ");
                    scanf("%i", &nvr);
                    vr += nvr;

                    printf("\n%i GARRAFAS ADICIONADAS AO ESTOQUE COM SUCESSO! \n\n", nvr);
                } else {
                    printf("\n\nOPÇÃO INVÁLIDA\n\n");
                }
                break;

            case 2:
                printf("\n\nBEM VINDO AO ESTOQUE!\n\n");

                printf("--------ESTOQUE---------\n\n");
                printf("1. Vinho Tinto \n");
                printf("2. Vinho Branco \n");
                printf("3. Vinho Rose \n");
                printf("\n------------------------\n\n");

                printf("Escolha o tipo de vinho que deseja RETIRAR do estoque conforme o MENU: ");
                scanf("%i", &op2);

                if (op2 == 1){
                    printf("\n\nESTOQUE DE VINHO TINTO!\n\n");
                    printf("Digite a quantidade de garrafas a serem RETIRADAS do estoque: ");
                    scanf("%i", &nvt);
                    vt -= nvt;

                    printf("\n%i GARRAFAS RETIRADAS DO ESTOQUE COM SUCESSO!\n\n", nvt);

                } else if (op2 == 2) {
                    printf("\n\nESTOQUE DE VINHO BRANCO\n\n");
                    printf("Digite a quantidade de garrafas a serem RETIRADAS do estoque: ");
                    scanf("%i", &nvb);
                    vb -= nvb;

                    printf("\n%i GARRAFAS RETIRADAS DO ESTOQUE COM SUCESSO! \n\n", nvb);

                } else if (op2 == 3){
                    printf("\n\nESTOQUE DE VINHO ROSE\n\n");
                    printf("Digite a quantidade de garrafas a serem RETIRADAS do estoque: ");
                    scanf("%i", &nvr);
                    vr -= nvr;

                    printf("\n%i GARRAFAS RETIRADAS DO ESTOQUE COM SUCESSO! \n\n", nvr);
                } else {
                    printf("\n\nOPÇÃO INVÁLIDA\n\n");
                }
                break;

            case 3:
                printf("\n\nBEM VINDO AO ESTOQUE!\n\n");

                printf("-----------ESTOQUE---------------\n\n");
                printf("1. Vinho Tinto = %i Garrafas. \n", vt);
                printf("2. Vinho Branco = %i Garrafas. \n", vb);
                printf("3. Vinho Rose = %i Garrafas.\n", vr);
                printf("\n---------------------------------\n\n");

                break;

            }


        }
    }



    return 0;
}
