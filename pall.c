#include "monty.h"

/**
 *pall - prints all the elements of a doubly linked list.
 *@h: head of the list
 */

void pall(stack_t **head, unsigned int lNum)
{
	stack_t *current = *head;
	(void)lNum;

	if (!current)
		return;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
