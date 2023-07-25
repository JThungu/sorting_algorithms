#include <stdio.h>
#include <stdlib.h>
/**
 * print_array - Prints an array of integers
 * @arr: The array to be printed
 * @size: Number of elements in @arr
 */
void print_array(const int *arr, size_t size)
{
    size_t i;

    for (i = 0; i < size; i++)
    {
        if (i > 0)
            printf(", ");
        printf("%d", arr[i]);
    }
    printf("\n");
}
