#include <stdio.h>
#include <stdlib.h>

int main()
{
    float x;
    float y;

    printf("Digite um valor para X: ");
    scanf("%f", &x);

    if(x <= 0){
        y = 0;
    } else if (x > 0 && x <= 1){
        y = x + 1;
    } else {
        y = (x*x)+5;
    }
    printf("\nY = %.2f \n", y);
}
