#include <stdio.h>
#include "sort.h"

/**
 * print_list - prints a linked list of integers
 *
 * @head: head of the linked list to be printed
 */
void print_list(const listint_t *list)
{
	int count = 0;

	while (list)
	{
	if (count > 0)
	    printf(", ");
	printf("%d", list->n);
	++count;
	list = list->next;
	}
	printf("\n");
}
