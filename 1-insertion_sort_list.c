#include "sort.h"

/**
  * insertion_sort_list -
  * @list: an unsorted doubly linked list
  *
  * Return: no return
  */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL;

	if (*list == NULL)
	{
		return;
	}

	current = *list;
	while (current->next != NULL)
	{
		listint_t *inverser = NULL;

		inverser = current->prev;
		while (inverser != NULL)
		{
			if (inverser->n > current->n)
			{
				current->prev->next = current->next;
				current->next->prev = current->prev;

				current->next = inverser;
				if (inverser->prev == NULL)
				{
					inverser->prev = current;
					current->prev = NULL;
					*list = current;
					print_list(*list);
					continue;
				}
				current->prev = inverser->prev;
				inverser->prev->next = current;
				inverser->prev->next = current;
				print_list(*list);
			}
			inverser = inverser->prev;
		}
		current = current->next;
	}
}
