#include "monty.h"

/**
 *
 *
 *
 */

void pall(stack_t **head, unsigned int lNum)
{
	stack_t *crnt;
	(void)lNum;

	crnt = *head;
	if (!crnt)
		return;
	while(crnt)
	{
		printf("%d\n", crnt->n);
		crnt = crnt->next;
	}
}
