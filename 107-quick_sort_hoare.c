#include "sort.h"

void swap_int(int *m, int *j);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

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
 * hoare_partition - Order a subset of an array of integers
 * @array: integers array
 * @size: array size
 * @left: starting index of the subset
 * @right: ending index of the subset
 *
 * Return: final partition index
 *
 * Description: uses the last element of the partition as the pivot
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, up, under;

	pivot = array[right];
	for (up = left - 1, under = right + 1; up < under;)
	{
		do {
			up++;
		} while (array[up] < pivot);
		do {
			under--;
		} while (array[under] > pivot);

		if (up < under)
		{
			swap_ints(array + up, array + under);
			print_array(array, size);
		}
	}

	return (up);
}

/**
 * hoare_sort - implement the quicksort algorithm through recursion
 * @array: integers array
 * @size: array size
 * @left: starting index of the array partition
 * @right: ending index of the array partition
 *
 * Description: uses the Hoare partition scheme
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, part - 1);
		hoare_sort(array, size, part, right);
	}
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending order
 * @array: integers array
 * @size: array size
 *
 * Description: uses the Hoare partition scheme and prints
 * the array after each swap of two elements
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
