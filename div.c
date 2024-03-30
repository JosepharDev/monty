#include "monty.h"
/**
 * div - divides the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void div(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(utils.fd);
		free(utils.content);
		free_struct(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(utils.fd);
		free(utils.content);
		free_struct(*head);
		exit(EXIT_FAILURE);
	}
	tmp = h->next->n / h->n;
	h->next->n = tmp;
	*head = h->next;
	free(h);
}
