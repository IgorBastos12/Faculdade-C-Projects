#include <stdio.h>
#include <stdlib.h>

int main()
{
    float x;
    float y;
    float z;

    printf("Digite um valor para X: ");
    scanf("%f", &x);

    y = (2*x) + 5;

    if (y < 0){
        z = (2*y*y) - (3*y) + 7;
    }else{
        z = (4*y*y) + (5*y) - 3;
    }

    printf("\n%.2f\n",z);
}
