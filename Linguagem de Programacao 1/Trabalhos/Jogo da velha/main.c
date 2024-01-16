#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>


char jogo[3][3];

int i,j;


// Função que inicializa a matriz com espaço ' ' dentro de cada posição
void inicializarjogo(){
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            jogo[i][j] = ' ';
        }
    }
}


// Função que imprime o jogo
void imprimirjogo(){


     printf("\n     0   1   2 \n\n");
     for (i = 0; i < 3; i++){
        printf(" %i", i);
        for (j = 0; j < 3; j++){
            if(j == 0){
                printf("  ");
            }
            printf(" %c ", jogo[i][j]);
            if (j < 2){
                printf("|");
            }
        }
        printf("\n");
        if ( i < 2){
            printf("    -----------");
            printf("\n");
        }
    }
}


// Função que atribui o valor no jogo

void jogada(int jogador){

    int i, j;

    printf("\n\nLinha: ");
    scanf("%i", &i);
    printf("coluna: ");
    scanf("%i", &j);

    while (i > 2 || i < 0 || j > 2 || j < 0){
        printf("\n[ERRO] Valor inválido\n\n");
        printf("Linha: ");
        scanf("%i", &i);
        printf("Coluna: ");
        scanf("%i", &j);
    }

    while (jogo[i][j] != ' '){
        printf("\n[ERRO] Local já preenchido\n\n");
        printf("Linha: ");
        scanf("%i", &i);
        printf("coluna: ");
        scanf("%i", &j);
    }

    if(jogador == 1){
        jogo[i][j] = 'X';
    } else {
        jogo[i][j] = 'O';
    }


}


// Função que verifica se alguem venceu

bool verificacao(){

    bool venceu = false;

    // verificando linhas

    for (i = 0; i < 3; i++){
        if (jogo[i][0] != ' ' && jogo[i][1] != ' ' && jogo[i][2] != ' '){
            if (jogo[i][0] == jogo[i][1] && jogo[i][1] == jogo[i][2]){
                venceu = true;
            }
        }
    }

    // Verificando Colunas

    for (j = 0; j < 3; j++){
        if (jogo[0][j] != ' ' && jogo[1][j] != ' ' && jogo[2][j] != ' '){
            if (jogo[0][j] == jogo[1][j] && jogo[1][j] == jogo[2][j]){
                venceu = true;
            }
        }
    }

    // Verificando Diagonal 1

    if (jogo[0][0] != ' ' && jogo[1][1] != ' ' && jogo[2][2] != ' '){
        if (jogo[0][0] == jogo[1][1] && jogo[1][1] == jogo[2][2]){
            venceu = true;
        }
    }

    // Verificando Diagonal 2

    if (jogo[2][0] != ' ' && jogo[1][1] != ' ' && jogo[0][2] != ' '){
        if (jogo[2][0] == jogo[1][1] && jogo[1][1] == jogo[0][2]){
            venceu = true;
        }
    }

    return venceu;
}

int main()
{
    setlocale(LC_ALL, "portuguese");


    int esc = 0;


    printf("#------------- JOGO DA VELHA -------------#\n");
    printf("|                                         |\n");
    printf("|              Jogador 1 = X              |\n");
    printf("|              Jogador 2 = O              |\n");
    printf("|                                         |\n");
    printf("#-----------------------------------------#\n\n");


    printf("Pressione qualquer tecla para iniciar o jogo...\n");
    getchar();


    while (esc != 1){

        inicializarjogo();  // Função que inicializa a matriz do jogo com ' '

        int njogadas = 0;
        int jogador = 1;

        bool venceu = false;

        while (njogadas < 9){

            system("cls");

            if (jogador == 1){

                printf("\n\n--> Jogador 1 = X \n\n");
                imprimirjogo();
                jogada(jogador);
                njogadas++;
                venceu = verificacao();
                if (venceu){
                    break;
                }
                jogador = 2;


            } else {

                printf("\n\n--> Jogador 2 = O\n\n");
                imprimirjogo();
                jogada(jogador);
                njogadas++;
                venceu = verificacao();
                if (venceu){
                    break;
                }
                jogador = 1;
            }
        }

        if (venceu == false){
            system("cls");
            printf("\n\n");
            imprimirjogo();
            printf("\n\nO JOGO TERMINOU EMPATADO!\n\n");
        } else {
            system("cls");
            printf("\n\n");
            imprimirjogo();
            printf("\n\nPARABÉNS O JOGADOR %i VENCEU!\n\n", jogador);
        }

        printf("\n\nDigite:\n\n");
        printf("1 - Para sair\n");
        printf("2 - Para jogadar Novamente\n");
        scanf("%i", &esc);
    }

    printf("\n\n");

    return 0;
}
