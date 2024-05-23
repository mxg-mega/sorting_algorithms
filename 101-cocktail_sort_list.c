#include "sort.h"
#include <stdio.h>

/**
 * swap_nodes - Swaps two adjacent nodes in a doubly linked list.
 * @list: Pointer to the head of the list.
 * @left: Pointer to the left node to be swapped.
 * @right: Pointer to the right node to be swapped.
 */
void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
	if (left->prev)
		left->prev->next = right;
	else
		*list = right;

	if (right->next)
		right->next->prev = left;

	left->next = right->next;
	right->prev = left->prev;
	left->prev = right;
	right->next = left;

	print_list(*list);
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm.
 * @list: Pointer to the head of the doubly linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current;
	int swapped = 1;

	if (list == NULL || *list == NULL)
		return;

	while (swapped)
	{
		swapped = 0;
		current = *list;

		/* Forward pass */
		while (current->next)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				swapped = 1;
			}
			else
			{
				current = current->next;
			}
		}

		/* If no swaps occurred in the forward pass, the list is sorted */
		if (!swapped)
			break;

		swapped = 0;

		/* Backward pass */
		while (current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, current->prev, current);
				swapped = 1;
			}
			else
			{
				current = current->prev;
			}
		}
	}
}
