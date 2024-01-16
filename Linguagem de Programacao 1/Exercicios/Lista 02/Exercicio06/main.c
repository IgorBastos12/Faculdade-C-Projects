#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>


int contador (){

    int n = 5;
    printf("Iniciando Contagem...\n");
    Sleep(1000);
    while ( n >= 0){
        printf("%i \n", n);
        n --;
        Sleep(1000);
    }
}

int main()
{

    setlocale(LC_ALL, "portuguese");

    int sair;

    printf("Contador do número 5.\n\n\n");

    printf("Digite 1 se quiser ativar o contador ou 0 para sair: ");
    scanf("%i", &sair);
    printf("\n");

    while (sair != 0){

        contador();
        printf("\n\n");
        printf("Digite 1 se quiser ativar o contador ou 0 para sair: ");
        scanf("%i", &sair);
        printf("\n\n");

    }
}
