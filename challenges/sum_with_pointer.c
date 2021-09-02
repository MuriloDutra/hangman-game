#include <stdio.h>

int sum(int* num, int a, int b)
{
    printf("sum() - memory address: %d\n", num);
    printf("sum() - content: %d\n", (*num));
    (*num) = a + b;
}

int main()
{
    int result = 0;
    sum(&result, 2, 40);
    printf("sum() - content: %d\n", (result));
}
