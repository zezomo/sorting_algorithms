#include "sort.h"

/**
 * insertion_sort_list - Sorts list of integers in ascending order
 *                       using Insertion sort algorithm
 * @list: Pointer to a pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		temp = current->prev;
		while (temp != NULL && temp->n > current->n)
		{
			if (temp->prev != NULL)
				temp->prev->next = current;
			else
				*list = current;

			if (current->next != NULL)
				current->next->prev = temp;
			temp->next = current->next;
			current->prev = temp->prev;
			current->next = temp;
			temp->prev = current;
			print_list(*list);
		}
		current = current->next;
	}
}

