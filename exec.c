#include "monty.h"

void exec(char *content, stack_t **stack, unsigned int line_content, FILE *file)
{
    instruction_t instruct[] = {
                {"push", push}, {"pall", pall}, {"pint", pint},
                {"pop", pop},
                {"swap", swap},
				{"add", add},
				{"nop", nop},
				{"sub", sub},
				{"div", div},
				{"mul", mul},
				{"mod", mod},
				{"pchar", pchar},
				{"pstr", pstr},
				{"rotl", rotl},
				{"rotr", rotr},
				{"queue", queue},
				{"stack", stack},
				{NULL, NULL}
				};
    size_t i = 0;
    char *tmp;

    tmp = strtok(content, " \n\t");
    if (tmp && tmp[0] == '#')
        return (0);
    utils.instruct = strtok(NULL, "\n\t");
    while(instruct[i].opcode && tmp)
    {
        if (strcmp(tmp, instruct[i].opcode) == 0)
        {
            instruct[i].f(stack, line_content);
            return (0);
        }
        i++;
    }
    if (tmp && instruct[i].opcode == NULL)
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", line_content, tmp);
		fclose(file);
		free(content);
		free_struct(*stack);
		exit(EXIT_FAILURE);
    }
    return (1);
}