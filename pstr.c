#include "monty.h"

/**
 *pstr - prints the string starting at the top of the stack
 *@head: head of the list
 *@lNum: line number
 */

void pstr(stack_t **head, unsigned int lNum)
{
	stack_t *temp;
	(void)lNum;

	if (*head == NULL)
	{
		putchar('\n');
		return;
	}
	temp = *head;
	while (temp)
	{
		if (temp->n <= 0 || temp->n > 127)
			break;
		putchar(temp->n);
		temp = temp->next;
	}
	putchar('\n');
}
