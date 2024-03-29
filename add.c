#include "monty.h"
/**
 * add - adds the top two elements of the stack.
 * @head: stack head
 * @line_content: line_number
 * Return: no return
*/
void add(stack_t **head, unsigned int line_content)
{
	stack_t *head2;
	int len = 0, tmp;

	head2 = *head;
	while (head2)
	{
		head2 = head2->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_content);
		fclose(utils.fd);
		free(utils.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	head2 = *head;
	tmp = head2->n + head2->next->n;
	head2->next->n = tmp;
	*head = head2->next;
	free(head2);
}