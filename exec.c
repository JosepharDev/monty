#include "monty.h"

/**
* exec - executes the opcode
* @stack: head linked list - stack
* @line_cntnt: line_content
* @file: poiner to monty file
* @content: line content
* Return: no return
*/

void exec(char *content, stack_t **stack, unsigned int line_cntnt, FILE *file)
{
	instruction_t instruct[] = {
		{"push", push}, {"pall", pall}, {"pint", pint},
		{"pop", pop}, {"swap", swap}, {"add", add},
		{"nop", nop}, {"sub", sub}, {"div", div},
		{"mul", mul}, {"mod", mod}, {"pchar", pchar}
		{"pstr", pstr},
		{NULL, NULL}
		};
	size_t  i = 0;
	char    *tmp;

	tmp = strtok(content, " \n\t");
	if (tmp && tmp[0] == '#')
		return;
	utils.instruct = strtok(NULL, " \n\t");
	while (instruct[i].opcode && tmp)
	{
		if (strcmp(tmp, instruct[i].opcode) == 0)
		{
			instruct[i].f(stack, line_cntnt);
			return;
		}
		i++;
	}
	if (tmp && instruct[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_cntnt, tmp);
		fclose(file);
		/*free(content);*/
		free_struct(*stack);
		exit(EXIT_FAILURE);
	}
}


