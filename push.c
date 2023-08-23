#include "monty.h"

/**
 *
 *
 *
 */

int is_digit(char c)
{
    return (c >= '0' && c <= '9');
}

/**
 *
 *
 *
 */

int is_valid_number(const char *str)
{
    if (*str == '-' || *str == '+')
        str++;

    while (*str)
    {
        if (!is_digit(*str))
            return (0);
        str++;
    }
    return (1);
}

/**
 *push - prints all the elements of a doubly linked list.
 *@head: head of the list
 *@lNum: line number
 */

void push(stack_t **head, unsigned int lNum)
{
	long int int_val;
	char *endptr;

	if (infos.arg == NULL)
    {
        fprintf(stderr, "L%d: usage: push integer\n", lNum);
        fclose(infos.file);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    
	int_val = strtol(infos.arg, &endptr, 10);
	if ((errno ==  EINVAL && int_val == 0) || *endptr != '\0')
	{
		fprintf(stderr, "L%d:  usage: push integer\n", lNum);
		fclose(infos.file);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (infos.fifo == 0)
		add_node(head, int_val);
	else
		add_node_end(head, int_val);
}
