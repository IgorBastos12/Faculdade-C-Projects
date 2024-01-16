#include <stdio.h>
#include <stdlib.h>

int verificaRep (int *vetor, int x){

    int i;
    int contador = 0;

    for (i = 0; i < 10; i++){
        if(x == vetor[i]){
            contador++;
        }
    }
    return contador;
}


int main()
{
    int vetor[10] = {7,8,1,0,8,0,7,5,6,7};
    int vetrep[10];
    int i, nrepitidos, adicionado, j;
    int k = 0;

    for (i = 0; i < 10; i++){
      nrepitidos = verificaRep(vetor, vetor[i]);
      if (nrepitidos > 1){

        adicionado = 0;

        for(j = 0; j < k; j++){
            if (vetrep[j] == vetor[i]){
                adicionado = 1;
            }
        }


        if (adicionado == 0){
            vetrep[k] = vetor[i];
            k++;
        }
      }
    }


    for (i = 0; i < k; i++){
        printf("%i  ", vetrep[i]);
    }


    return 0;
}
