#include "monty.h"
/**
 * pall - prints the stack
 * @head: stack head
 * @line_content: no used
 * Return: no return
*/
void pall(stack_t **head, unsigned int line_content)
{
	stack_t *h;
	(void)line_content;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
