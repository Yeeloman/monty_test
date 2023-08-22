#include "monty.h"

/**
 *add_node - adds a node at the beginning
 *@head: head of the list
 *@n: data of the node
 *Return: a pointer to the new head
 */

void add_node(stack_t **head, const int n)
{
	stack_t *temp;

	temp = malloc(sizeof(stack_t));
	if (!temp)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	temp->n = n;
	temp->prev = NULL;
	temp->next = *head;
	if (*head)
		(*head)->prev = temp;
	*head = temp;
}

/**
 *add_node_end - adds a nod at the end
 *@head: head of the list
 *@n: data
 *Return: a pointer
 */

void add_node_end(stack_t **head, const int n)
{
	stack_t *temp, *end;

	temp = malloc(sizeof(stack_t));
	if (!temp)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	temp->next = NULL;
	temp->n = n;
	if (!*head)
	{
		temp->prev = NULL;
		*head = temp;
		return;
	}
	end = *head;
	while (end->next)
		end = end->next;
	end->next = temp;
	temp->prev = end;
}
