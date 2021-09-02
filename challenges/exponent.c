#include <stdio.h>

void exponent(int a, int b)
{
    int result = 1;
    for(int i = 1; i <= b; i++)
    {
        result *= a;
    }
    printf("%dˆ%d = %d\n", a, b, result);
}

int main()
{
    exponent(2, 5);
}
