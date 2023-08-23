#include "monty.h"

/**
 *add - adds the top two elements of the stack.
 *@head: head of the list
 *@lNum: line number
 */

void add(stack_t **head, unsigned int lNum)
{
	stack_t *temp;
	int n_temp;

	if (*head == NULL || !(*head)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", lNum);
		fclose(infos.file);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	n_temp = temp->n + temp->next->n;
	temp->next->n = n_temp;
	*head = temp->next;
	free(temp);
}

/**
 *sub - subs the top two elements of the stack.
 *@head: head of the list
 *@lNum: line number
 */

void sub(stack_t **head, unsigned int lNum)
{
	stack_t *temp;
	int n_temp;

	if (*head == NULL || !(*head)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", lNum);
		fclose(infos.file);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	n_temp = temp->next->n - temp->n;
	temp->next->n = n_temp;
	*head = temp->next;
	free(temp);
}

/**
 *mod - mod the top two elements of the stack.
 *@head: head of the list
 *@lNum: line number
 */

void mod(stack_t **head, unsigned int lNum)
{
	stack_t *temp;
	int n_temp;

	if (*head == NULL || !(*head)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", lNum);
		fclose(infos.file);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", lNum);
		fclose(infos.file);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	n_temp = temp->next->n % temp->n;
	temp->next->n = n_temp;
	*head = temp->next;
	free(temp);

}

/**
 *mul - mul the top two elements of the stack.
 *@head: head of the list
 *@lNum: line number
 */

void mul(stack_t **head, unsigned int lNum)
{
	stack_t *temp;
	int n_temp;

	if (*head == NULL || !(*head)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", lNum);
		fclose(infos.file);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	n_temp = temp->n * temp->next->n;
	temp->next->n = n_temp;
	*head = temp->next;
	free(temp);
}

/**
 *divi - divi the top two elements of the stack.
 *@head: head of the list
 *@lNum: line number
 */

void divi(stack_t **head, unsigned int lNum)
{
	stack_t *temp;
	int n_temp;

	if (*head == NULL || !(*head)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", lNum);
		fclose(infos.file);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", lNum);
		fclose(infos.file);
		free_stack(*head);
		exit(EXIT_FAILURE);

	}
	n_temp = temp->next->n / temp->n;
	temp->next->n = n_temp;
	*head = temp->next;
	free(temp);
}
