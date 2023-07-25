#include "sort.h"

void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_subarr - sort a subarray of integers
 * @subarr:subarray of integers to sort
 * @buff: buffer to store sub array
 * @front: front index of array
 * @mid: middle index of array
 * @back: back index of array
 */
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t p, s, l = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (p = front, s = mid; p < mid && s < back; l++)
		buff[l] = (subarr[p] < subarr[s]) ? subarr[p++] : subarr[s++];
	for (; p < mid; p++)
		buff[l++] = subarr[p];
	for (; s < back; s++)
		buff[l++] = subarr[s];
	for (p = front, l = 0; p < back; p++)
		subarr[p] = buff[l++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merge_sort_recursive - implement the merge sort algorithm
 * @subarr:sub array of integers
 * @buff: buffer to store
 * @front: front index of sub array
 * @back: back index of sub array
 */
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_recursive(subarr, buff, front, mid);
		merge_sort_recursive(subarr, buff, mid, back);
		merge_subarr(subarr, buff, front, mid, back);
	}
}

/**
 * merge_sort - sort an array of integers in ascending order
 * @array: integers array
 * @size: array size
 *
 * Description: implements the top-down merge sort algorithm
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_sort_recursive(array, buff, 0, size);

	free(buff);
}
