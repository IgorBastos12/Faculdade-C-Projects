#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");

    int vetorA[10] = {1, 6, 9, 10, 15, 26, 30, 36, 42, 50};

    int vetorB[10] = {2, 3, 8, 17, 16, 28, 29, 34, 48, 52};

    int *Ptr[10];



    for ( int i = 0; i < 10; i++){
        if (vetorA[i] > vetorB[i]){
            Ptr[i] = &vetorA[i];
        } else {
            Ptr[i] = &vetorB[i];
        }
    }


    for (int i = 0; i < 10; i++){
        printf("Endereço apontado pelo ponteiro Ptr[%i] = %p  | valor no endereço de memória apontado = %i\n",i, Ptr[i], *Ptr[i] );
    }


    return 0;
}
