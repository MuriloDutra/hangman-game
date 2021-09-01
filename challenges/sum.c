#include <stdio.h>

void sum(int numbers[10])
{
    int result = 0;
    for(int i = 0; i <= 9; i++)
    {
        result = result + numbers[i];
    }
    printf("RESULT: %d\n", result);
}

void write_array_elements(int array[10])
{
    for(int i = 0; i <= 9; i++)
    {
        printf("Element: %d\n", array[i] = i);
        if(i == 9){
            printf("\n");
        }
    }
}

int main()
{
    int array_of_numbers[10];
    for(int i = 0; i <= 9; i++)
    {
        array_of_numbers[i] = i;
    }

    write_array_elements(array_of_numbers);
    sum(array_of_numbers);
}
