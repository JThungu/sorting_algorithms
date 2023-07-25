#include "sort.h"

void swap_int(int *m, int *j);
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow);
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_sort(int *array, size_t size);

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
 * bitonic_merge - sort a bitonic sequence inside an array of integers
 * @array: integers array
 * @size: array size
 * @start: starting index of the sequence in array to sort
 * @seq: size of the sequence to sort
 * @flow: direction to sort in
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t p, jump = seq / 2;

	if (seq > 1)
	{
		for (p = start; p < start + jump; p++)
		{
			if ((flow == UP && array[p] > array[p + jump]) ||
			    (flow == DOWN && array[p] < array[p + jump]))
				swap_ints(array + p, array + p + jump);
		}
		bitonic_merge(array, size, start, jump, flow);
		bitonic_merge(array, size, start + jump, jump, flow);
	}
}

/**
 * bitonic_seq - convert array of integers to bitonic sequence
 * @array: integers array
 * @size: array size
 * @start: starting index of block of the building
 * @seq: size of a block of the building
 * @flow: direction to sort
 */
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t cut = seq / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		bitonic_seq(array, size, start, cut, UP);
		bitonic_seq(array, size, start + cut, cut, DOWN);
		bitonic_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - sort an array of integers in ascending order
 * @array: integers array
 * @size: array size
 *
 * Description: Prints the array after each swap
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, UP);
}
