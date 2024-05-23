#include <stdio.h>
#include "sort.h"
#include <stdlib.h>

/**
 * insertion_sort_list - Sorts a doubly linked list of
 *                       integers in ascending
 *                       order using the insertion sort algorithm
 * @list: Pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next_node, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}

	current = (*list)->next;

	while (current != NULL)
	{
		next_node = current->next;

		while (current->prev != NULL && current->prev->n > current->n)
		{
			temp = current->prev;

			/* Swap the nodes */
			temp->next = current->next;
			if (current->next != NULL)
			{
				current->next->prev = temp;
			}

			current->next = temp;
			current->prev = temp->prev;
			temp->prev = current;

			if (current->prev != NULL)
			{
				current->prev->next = current;
			}
			else
			{
				*list = current;
			}
			print_list(*list);
		}
		current = next_node;
	}
}
