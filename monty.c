#include "monty.h"

info_t infos = {NULL, NULL, 0, 0};

/**
 *handleOpcode - fix the string
 *@str: the string to be checked
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
 *instruction - calls the right function
 *@opcode: the command
 *@stack: head of the list
 *@lNum: line number
 *Return: 0 for success
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
 *main - main entry
 *@ac: arg count
 *@av: arg vector
 *Return: EXIT_SUCCESS
 */

int main(int ac, char *av[])
{
	FILE *file;
	char line[MONTY_LEN], *opcode;
	stack_t *stack = NULL;
	int n;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: %s file\n", av[0]);
		exit(EXIT_FAILURE);
	}

	file = fopen(av[1], "r");
	infos.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
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
			free(opcode);
			fclose(file);
			exit(EXIT_FAILURE);
		}
	}
	free_stack(stack);
	fclose(file);
	return (EXIT_SUCCESS);
}
