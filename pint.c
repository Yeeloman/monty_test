#include "monty.h"

/**
 *pint - prints all the elements of a doubly linked list.
 *@head: head of the list
 *@lNum: line number
 */

void pint(stack_t **head, unsigned int lNum)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", lNum);
		fclose(infos.file);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
