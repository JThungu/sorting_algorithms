#include "sort.h"

/**
 * swap_node - swap two nodes in a doubly-linked list
 * @h: head of the doubly-linked list
 * @n1: first node to swap
 * @n2: second node to swap
 */
void swap_node(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * @list: head of a doubly-linked list of integers
 *
 * Description: prints the list after each swap
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *circular, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (circular = (*list)->next; circular != NULL; circular = tmp)
	{
		tmp = circular->next;
		insert = circular->prev;
		while (insert != NULL && circular->n < insert->n)
		{
			swap_node(list, &insert, circular);
			print_list((const listint_t *)*list);
		}
	}
}
