#include "monty.h"
/**
  *sub- sustration
  *@head: stack head
  *@counter: line_number
  *Return: no return
 */
void sub(stack_t **head, unsigned int counter)
{
	stack_t *tmp;
	int tmp2, nodes;

	tmp = *head;
	for (nodes = 0; tmp != NULL; nodes++)
		tmp = tmp->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(utils.fd);
		free(utils.content);
		free_struct(*head);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	tmp2 = tmp->next->n - tmp->n;
	tmp->next->n = tmp2;
	*head = tmp->next;
	free(tmp);
}