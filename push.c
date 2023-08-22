#include "monty.h"

/**
 *
 *
 *
 */

void push(stack_t **head, unsigned int lNum)
{
	long int int_val;
	char *endptr;

	int_val = strtol(infos.arg, &endptr, 10);
	if (errno != 0 && *endptr != '\0')
	{
		fprintf(stderr, "L%d: usage: push integer\n", lNum);
		fclose(infos.file);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (infos.fifo == 0)
		add_node(head, int_val);
	else
		add_node_end(head, int_val);
}
