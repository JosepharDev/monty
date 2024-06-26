#include "monty.h"
/**
 * pchar - prints the char at the top of the stack,
 * followed by a new line
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void pchar(stack_t **head, unsigned int counter)
{
	stack_t *h;

	h = *head;
	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		fclose(utils.fd);
		free(utils.content);
		free_struct(*head);
		exit(EXIT_FAILURE);
	}
	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
		fclose(utils.fd);
		free(utils.content);
		free_struct(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h->n);
}
