#include "monty.h"

/**
 * pint - prints the top
 * @head: stack head
 * @line_content: line_number
 * Return: no return
*/

void pint(stack_t **head, unsigned int line_content)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_content);
		fclose(utils.fd);
		free(utils.content);
		free_struct(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}