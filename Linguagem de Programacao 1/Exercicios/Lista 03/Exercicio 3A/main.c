#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int max_element (int *vetor, int n){      /// Verifica o maior elemento do vetor

    int i;
    int maxel = vetor[i];

    for (i = 0; i < n; i++){
        if (vetor[i] > maxel){
            maxel = vetor[i];
        }
    }
    return maxel;
}

int min_element (int *vetor, int n){    ///  Verifica o menor elemento do vetor

    int i;
    int minel = vetor[i];

    for (i = 0; i < n; i++){
        if (vetor[i] < minel){
            minel = vetor[i];
        }
    }
    return minel;
}

int msum (int *vetor, int n){

    int maxel, minel;

    maxel = max_element (vetor, n);
    minel = min_element (vetor, n);

    return maxel + minel;
 }


int main()
{

    setlocale(LC_ALL, "portuguese");

    int somamaxmin;
    int a[10] = {1,2,3,4,5,6,7,8,9,10};

    somamaxmin = msum (a, 10);

    printf("A soma entre o maior e o menor elemento do vetor é: %i \n\n\n", somamaxmin);


    return 0;
}
