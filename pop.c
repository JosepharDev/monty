#include "monty.h"

/**
 * pop - prints the top
 * @head: stack head
 * @line_content: line_number
 * Return: no return
*/

void pop(stack_t **head, unsigned int line_content)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_content);
		fclose(utils.fd);
		free(utils.content);
		free_struct(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}