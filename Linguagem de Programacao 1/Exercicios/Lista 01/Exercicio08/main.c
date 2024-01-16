#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");

    int go = 1;
    int value;
    int maior = 0;
    int menor = 0;
    int inicioleitura = 1;



    while ( go != 0){
        printf("---------------MENU-------------\n");
        printf("1. DIGITAR UM VALOR\n");
        printf("0. FINALIZAR O PROGRAMA\n");
        printf("--------------------------------\n");
        printf("Escolha uma Opção: ");
        scanf("%i", &go);
        if (go != 1 && go != 0){
            printf("\n\n[ERRO] Opção Inaválida\n\n");
        }

        if(go == 0){
            break;
        } else if (go == 1){
            printf("\nDigite um valor: ");
            scanf("%i", &value);
            if(inicioleitura == 1){
                maior = value;
                menor = value;
                inicioleitura = 0;
            }
            if(value > maior){
                maior = value;
            }
            if(value < menor){
                menor = value;
            }
        }


    }
    if (maior == 0 && menor == 0){
        printf("\n\nO programa foi Finalizado sem ter recebido nenhum valor.\n\n");
    } else{
        printf("\n\nO maior número recebido foi %i e o menor número recebido foi %i\n\n", maior, menor);
    }
}
