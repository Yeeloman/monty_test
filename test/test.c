#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

#define MONTY_LEN 1024
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 *
 *
 *
 *
 */

typedef struct info_s
{
	char *arg;
	FILE *file;
	unsigned int lNum;
	int fifo;
} info_t;

extern info_t infos;


/*monty.c*/
int main(int ac, char *av[]);
int instruction(char *opcode, stack_t **stack, unsigned int lNum);
void handleOpcode(char *str);
/*push.c*/
void push(stack_t **head, unsigned int lNum);
/*pall.c*/
void pall(stack_t **head, unsigned int lNum);
/*free_stack.c*/
void free_stack(stack_t *head);
/*node_manipulation.c*/
void add_node(stack_t **head, const int n);
void add_node_end(stack_t **head, const int n);

info_t infos = {NULL, NULL, 0, 0};

/**
 *removeExtraSpace - removes extra space
 *@data: shell's data
 */

void handleOpcode(char *str)
{
	int i, j;
	int spaceFound = 0;
	int leadingSpaces = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ')
			break;
		leadingSpaces++;
	}
	for (i = leadingSpaces, j = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ')
		{
			if (!spaceFound)
			{
				str[j++] = ' ';
				spaceFound = 1;
			}
		}
		else
		{
			str[j++] = str[i];
			spaceFound = 0;
		}
	}
	while (j > leadingSpaces && str[j - 1] == ' ')
		j--;
	str[j] = '\0';
}

/**
 *
 *
 *
 */

int instruction(char *opcode, stack_t **stack, unsigned int lNum)
{
	unsigned int i = 0;
	instruction_t opstruct[] = {
		{"push", push},
		{"pall", pall}
	};

	while (opstruct[i].opcode)
	{
		if (strcmp(opcode, opstruct[i].opcode) == 0)
		{
			opstruct[i].f(stack, lNum);
			return (0);
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", lNum, opcode);
	return (1);
}

/**
 *
 *
 *
 *
 */

int main(int ac, char *av[])
{
	FILE *file;
	char line[MONTY_LEN], *opcode;
	stack_t *stack = NULL;
	int n;
    char *filename = "/home/void/projects/monty_test/00.m";
	/*if (ac != 2)
	{
		fprintf(stderr, "USAGE: %s file\n", av[0]);
		exit(EXIT_FAILURE);
	}*/
    
	file = fopen(filename, "r");
	infos.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), file))
	{
		infos.lNum++;
		if (line[0] == '#' || line[0] == '\n')
			continue;
        handleOpcode(line);
        opcode = strtok(line, " \n");
        infos.arg = strtok(NULL, "\n");
		n = instruction(opcode, &stack, infos.lNum);
		if (n == 1)
		{
			free_stack(stack);
			fclose(file);
			exit(EXIT_FAILURE);
		}
	}
	free_stack(stack);
	fclose(file);
	return (EXIT_SUCCESS);
}

/**
 *free_stack - frees a doubly linked list.
 *@head: head of the list
 */

void free_stack(stack_t *head)
{
	stack_t *current, *next;

	current = head;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

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


/**
 *print_dlistint - prints all the elements of a dlistint_t list.
 *@h: head of the list
 *Return: number of nodes
 */

void pall(stack_t **head, unsigned int lNum)
{
    stack_t *current = *head;

    if (!current)
        return ;
    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}


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

