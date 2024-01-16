#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int numMin (int n1, int n2){

    int menor, maior;

    if (n1 < n2){
        menor = n1;
    } else {
        menor = n2;
    }

    return menor;
}



int main()
{
    setlocale(LC_ALL, "portuguese");


    int x, y, menor, sair;



    while (sair != -1){

        printf("Defina o 1º número: ");
        scanf("%i", &x);
        printf("Defina o 2º número: ");
        scanf("%i", &y);
        menor = numMin(x,y);

        printf("\n\n");
        printf("Menor valor é %i\n\n", menor);

        printf("Digite -1 para sair ou qualquer valor para continuar: ");
        scanf("%i", &sair);
        printf("\n\n");

    }


    return 0;
}
