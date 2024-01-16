#include <stdio.h>
#include <stdlib.h>

int reverse(int n) {
    int reversed = 0;

    while (n != 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }

    return reversed;
}

int main()
{
    int number = 97631;
    int reversedNumber = reverse(number);

    printf("N�mero original: %d\n", number);
    printf("N�mero invertido: %d\n", reversedNumber);
    return 0;
}
