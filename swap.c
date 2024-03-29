#include "monty.h"
/**
 * swap - adds the top two elements of the stack.
 * @head: stack head
 * @line_content: line_number
 * Return: no return
*/
void swap(stack_t **head, unsigned int line_content)
{
	stack_t *h;
	int len = 0, tmp;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_content);
		fclose(utils.fd);
		free(utils.content);
		free_struct(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	tmp = h->n;
	h->n = h->next->n;
	h->next->n = tmp;
}