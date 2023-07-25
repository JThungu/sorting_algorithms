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
 * shell_sort - sort an array of integers in ascending order
 * @array: integers array
 * @size: array size
 *
 * Description: Uses the Knuth interval sequence
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, q;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			q = i;
			while (q >= gap && array[q - gap] > array[q])
			{
				swap_ints(array + q, array + (q - gap));
				q -= gap;
			}
		}
		print_array(array, size);
	}
}
