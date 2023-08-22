#include "monty.h"

/**
 *free_stack - frees a doubly linked list.
 *@head: head of the list
 */

void free_stack(stack_t *head)
{
	stack_t *current, *next;

	current = head;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
