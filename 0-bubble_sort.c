#include "sort.h"

/**
 * swap_int - swaps two integers
 * @m: first integer
 * @j: second integer
 */
void swap_int(int *m, int *j)
{
	int tmp;

	tmp = *m;
	*m = *j;
	*j = tmp;
}

/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: array of to sort
 * @size:  array size
 *
 * Description: array printed after each swap
 */
void bubble_sort(int *array, size_t size)
{
	size_t b, len = size;
	bool bubbles = false;

	if (array == NULL || size < 2)
		return;

	while (bubbles == false)
	{
		bubbles = true;
		for (b = 0; b < len - 1; b++)
		{
			if (array[i] > array[b + 1])
			{
				swap_int(array + b, array + b + 1);
				print_array(array, size);
				bubbles = false;
			}
		}
		len--;
	}
}
