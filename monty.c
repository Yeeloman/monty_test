#include "monty.h"

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
	char *op;
	instruction_t opstruct[] = {
		{"push", push},
		{"pall", pall}
	};

	op = strtok(opcode, " ");
	infos.arg = strtok(NULL, " \n");
	while (opstruct[i].opcode)
	{
		if (strcmp(op, opstruct[i].opcode) == 0)
		{
			opstruct[i].f(stack, lNum);
			return (0);
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", lNum, op);
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
	char line[MONTY_LEN], opcode[MONTY_LEN];
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
		sscanf(line, "%s", opcode);
		if (opcode[0] == '#' || opcode[0] == '\n')
			continue;
		handleOpcode(opcode);
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