#include <stdio.h>

void exponent(int* result, int a, int b)
{
    for(int i = 1; i <= b; i++)
    {
        (*result) *= a;
    }
}

int main()
{
    int result = 1;
    int number01 = 2;
    int number02 = 5;

    exponent(&result, number01, number02);
    printf("%dˆ%d = %d\n", number01, number02, result);
}
