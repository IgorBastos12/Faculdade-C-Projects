#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 0;
    int y = 0;

    printf("Digite um valor para X: ");
    scanf("%i", &x);

    if ( x <= 2 && x >= -2  ){
        y = x * x;
    } else{
        y = 4;
    }

    printf("\n%i\n", y);

}

