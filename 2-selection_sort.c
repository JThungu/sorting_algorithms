#include "sort.h"

/**
 * swap_int - swap two integers in an array
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
 * selection_sort - sort an array of integers in ascending order
 * @array: array of integers
 * @size: size of the array
 *
 * Description: array printed after each swap
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t i, q;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (q = i + 1; q < size; q++)
			min = (array[q] < *min) ? (array + q) : min;

		if ((array + i) != min)
		{
			swap_ints(array + i, min);
			print_array(array, size);
		}
	}
}
