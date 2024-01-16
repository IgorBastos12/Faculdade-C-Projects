#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    int op;
    float n1;
    float n2;
    float resultado;

    printf("------------------------CALCULADORA-------------------------------- \n\n");
    printf("1 - Soma      ");
    printf("2 - Subtra��o      ");
    printf("3 - Divis�o     ");
    printf("4 - Multiplica��o     \n");
    printf("\n\n------------------------------------------------------------------- \n\n");

    printf("Digite o valor correspondente a ope��o que se deseja realizar na calculadora: ");
    scanf("%i", &op);

    while (op > 4 || op < 1){
            printf("\n\n[ERRO] Valor escolhido inv�lido.\n\n");
            printf("Digite o valor correspondente a ope��o que se deseja realizar na calculadora: ");
            scanf("%i", &op);
    }

    printf("\nDigite o 1� valor: ");
    scanf("%f", &n1);
    printf("\nDigite o 2� valor: ");
    scanf("%f", &n2);

   switch(op){
   case 1:
    op = "Soma";
    resultado = n1 + n2;
    break;
   case 2:
    op = "Subtra��o";
    resultado = n1 - n2;
    break;
   case 3:
    op = "Divis�o";
    resultado = n1 / n2;
    break;
   case 4:
    op = "Multiplica��o";
    resultado = n1 * n2;
    break;
   }

   printf("\nO valor da %s de %.2f com %.2f � igual a %.2f \n\n",op, n1, n2, resultado);
}
