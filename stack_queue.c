#include "monty.h"

/**
 *fstack - sets the format of the data to a stack
 *@head: head of the list
 *@lNum: line number
 */

void fstack(stack_t **head, unsigned int lNum)
{
	(void)head;
	(void)lNum;
	infos.fifo = 0;
}

/**
 *queue - sets the format of the data to a queue
 *@head: head of the list
 *@lNum: line number
 */

void queue(stack_t **head, unsigned int lNum)
{
	(void)head;
	(void)lNum;
	infos.fifo = 1;
}
