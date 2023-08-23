#include "monty.h"

/**
 *swap - swaps the last 2 on stack
 *@head: head of the list
 *@lNum: line number
 */

void swap(stack_t **head, unsigned int lNum)
{
	stack_t *temp;
	int n_temp;

	if (*head == NULL || !(*head)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", lNum);
		fclose(infos.file);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	n_temp = temp->n;
	temp->n = temp->next->n;
	temp->next->n = n_temp;
}
