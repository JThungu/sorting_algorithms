#include "sort.h"

int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

/**
 * get_max - maximum value in an array of integers
 * @array: integers array
 * @size: array size
 *
 * Return: maximum integer in the array
 */
int get_max(int *array, int size)
{
	int max, p;

	for (max = array[0], p = 1; p < size; p++)
	{
		if (array[p] > max)
			max = array[p];
	}

	return (max);
}

/**
 * radix_counting_sort - sort digits of an array in ascending order
 * @array: integers array
 * @size: array size
 * @sig: significant digit to sort on
 * @buff: buffer to store
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t p;

	for (p = 0; p < size; p++)
		count[(array[p] / sig) % 10] += 1;

	for (p = 0; p < 10; p++)
		count[p] += count[p - 1];

	for (p = size - 1; (int)p >= 0; p--)
	{
		buff[count[(array[p] / sig) % 10] - 1] = array[p];
		count[(array[p] / sig) % 10] -= 1;
	}

	for (p = 0; p < size; p++)
		array[p] = buff[p];
}

/**
 * radix_sort - sort an array of integers in ascending order
 * @array: integers array
 * @size: array size
 *
 * Description: implements the LSD radix sort algorithm and prints
 * the array after each digit increase
 */
void radix_sort(int *array, size_t size)
{
	int max, sig, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	max = get_max(array, size);
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		radix_counting_sort(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
