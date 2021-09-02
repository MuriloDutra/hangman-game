#include <stdio.h>

int main()
{
    int numbers[3] = {12, 14, 16};
    char letters[3] = {'A', 'B', 'C'};

    printf("CHAR: 1 byte | INT: 4 bytes\n\n");
    for(int i = 0; i <= 2; i++)
    {
        printf("%d     %d\n", &letters[i], &numbers[i]);
    }
}
