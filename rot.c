#include "monty.h"

/**
 *rotl - rotates the stack to the top.
 *@head: head of the list
 *@lNum: line number
 */

void rotl(stack_t **head, unsigned int lNum)
{
	stack_t *temp, *rot;
	(void)lNum;

	if (!*head || !(*head)->next)
		return;
	temp = *head;
	rot = (*head)->next;
	rot->prev = NULL;
	while (temp->next)
		temp = temp->next;
	temp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = temp;
	*head = rot;
}

/**
 *rotr - rotates the stack to the bottom.
 *@head: head of the list
 *@lNum: line number
 */

void rotr(stack_t **head, unsigned int lNum)
{
	stack_t *temp;
	(void)lNum;

	if (!*head || !(*head)->next)
		return;
	temp = *head;
	while (temp->next)
		temp = temp->next;
	temp->next = *head;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*head)->prev = temp;
	(*head) = temp;

}
