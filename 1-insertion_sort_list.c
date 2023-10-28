#include "sort.h"


/**
 * insertion_sort_list - sorts a doubly linked list with
 * insertion sort algorithm
 *
 * @list: list to be sorted
 *
 * Return: noting
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *new, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (new = (*list)->next; new && new->prev; new = new->next)
	{
		for (; new && new->prev && new->n < new->prev->n;
			new = new->prev)
		{
			tmp = new->prev;
			swap(list, tmp, new);
			print_list(*list);
			new = new->next;
		}
	}
}

/**
 * swap - swaps two nodes in a linked list
 *
 * @head: the head node
 * @node1: The first node
 * @node2: the second node
 *
 * Return: void
 */
void swap(listint_t **head, listint_t *node1, listint_t *node2)
{
	listint_t *prev, *next;

	prev = node1->prev;
	next = node2->next;

	if (prev != NULL)
		prev->next = node2;
	else
		*head = node2;
	node1->prev = node2;
	node1->next = next;
	node2->prev = prev;
	node2->next = node1;
	if (next)
		next->prev = node1;
}
