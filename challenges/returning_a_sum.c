#include <stdio.h>

int sum(int nums[3], int array_size)
{
    int result = 0;
    for(int i = 0; i < array_size; i++)
        result += nums[i];
    return result;
}

int main()
{
    int numbers[3];
    numbers[0] = 30;
    numbers[1] = 30;
    numbers[2] = 30;

    int result = sum(numbers, 3);
    printf("RESULT: %d\n", result);
}
