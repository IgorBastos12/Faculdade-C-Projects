#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float minv (float *vetor , int n){   ///  Função que retorna o menor valor do array

    int i;
    float menor = *vetor;

    for (i = 0; i < n; i++){
        if (vetor[i] < menor){
            menor = vetor[i];
        }
    }

    return menor;
}

float sumv (float *vetor, int n) {   ///  Função que retorna a soma dos elementos do array

    int i;
    float soma = 0;

    for (i = 0; i < n; i++){
        soma += vetor[i];
    }

    return soma;
}

float meanv (float *vetor, int n){   /// Função que retorna a media dos valores de um array

    int i;
    float soma = 0, media;

    for (i = 0; i < n; i++){
        soma += vetor[i];
    }

    media = soma / n;

    return media;
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    float menorA, menorB, somaA, somaB, mediaA, mediaB;



    float a[10] = {10,12,30,41,51,61,71,81,91,99};
    float b[15] = {15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};

    menorA = minv(a, 10);
    menorB = minv(b, 15);

    somaA = sumv(a, 10);
    somaB = sumv(b, 15);

    mediaA = meanv(a ,10);
    mediaB = meanv(b, 15);

    printf("Menor valor do vetor a = %.2f \n", menorA);
    printf("Menor valor do vetor b = %.2f \n\n\n", menorB);

    printf("Soma dos valores do vetor a = %.2f \n", somaA);
    printf("Soma dos valores do vetor a = %.2f \n\n\n", somaB);

    printf("Media dos valores do vetor a = %.2f \n", mediaA);
    printf("Media dos valores do vetor a = %.2f \n\n\n", mediaB);


    return 0;
}
