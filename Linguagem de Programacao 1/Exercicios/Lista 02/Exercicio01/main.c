#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


float soma (float x, float y){

    float r_soma;

    r_soma = x + y;

    return r_soma;

}

float subtracao( float x, float y){

    float r_subt = x - y;

    return r_subt;

}

float multiplicacao (float x, float y){

    float r_multi = x * y;

    return r_multi;
}

float divisao (float x, float y){

    float r_div = x / y;

    return r_div;
}

int main()
{


    setlocale(LC_ALL, "portuguese");

    int op;
    float resultado, x, y;


    printf("-----------------CALCULADORA-----------------");
    printf("\n\n");
    printf("1 - SOMA");
    printf("\n");
    printf("2 - SUBTRA��O");
    printf("\n");
    printf("3 - SUBTRA��O");
    printf("\n");
    printf("4 - DIVIS�O");
    printf("\n\n");
    printf("---------------------------------------------");

    printf("\n\n");
    printf("Defina a opera��o que deseja realizar conforme o MENU acima: ");
    scanf("%i", &op);

    while(op < 1 || op > 4){
        printf("\n\n");
        printf("[ERRO] Digite um valor de opera��o v�lido.");
        printf("\n\n");
        printf("Defina a opera��o que deseja realizar conforme o MENU acima: ");
        scanf("%i", &op);

    }

    printf("\n");
    printf("Defina o primeiro n�mero: ");
    scanf("%f", &x);


    printf("Defina o segundo n�mero: ");
    scanf("%f", &y);
    printf("\n\n");



    switch (op){

    case 1:

        resultado = soma(x, y);
        printf("O resultado da soma de %.2f + %.2f � igual %.2f", x, y, resultado);
        break;

    case 2:

        resultado = subtracao(x, y);
        printf("O resultado da subtra��o de %.2f - %.2f � igual %.2f", x, y, resultado);
        break;

    case 3:


        resultado = multiplicacao(x, y);
        printf("O resultado da multiplica��o de %.2f x %.2f � igual %.2f", x, y, resultado);
        break;

    case 4:

        resultado = divisao(x, y);
        printf("O resultado da divis�o de %.2f / %.2f � igual %.2f", x, y, resultado);
        break;

    }

    printf("\n\n\n");

    return 0;
}
