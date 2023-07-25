#include "sort.h"

void swap_int(int *m, int *j);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_int - swap two integers
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
 * lomuto_partition - order a subset of an array of integers
 * @array: integers array
 * @size: array size
 * @left: starting index
 * @right: ending index
 *
 * Return: final partition index
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - implement quicksort algorithm through recursion
 * @array: integers array
 * @size: array size
 * @left: starting index
 * @right: ending index
 *
 * Description: Uses the Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - sort array of integers in ascending order
 * @array: integer array
 * @size: array size
 *
 * Description: Uses the Lomuto partition scheme and prints
 *              array after each swap of two elements
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
