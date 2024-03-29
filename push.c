#include "monty.h"

/**
 * push - add node to the stack
 * @head: stack head
 * @line_content: line_number
 * Return: no return
*/
void    push(stack_t **head, unsigned int line_content)
{
	int number = 0, j = 0, flag = 0;

	if (utils.instruct)
	{
		if (utils.instruct[0] == '-')
			j--;
		for (; utils.instruct[j] != '\0'; j++)
		{
			if (utils.instruct[j] > 57 || utils.instruct[j] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_content);
			fclose(utils.fd);
			free(utils.instruct);
			free_struct(*head);
			exit(1);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_content);
		fclose(utils.fd);
		free(utils.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	number = atoi(utils.instruct);
	if (utils.lifi == 0)
		add_node(head, number);
	else
		add_queue(head, number); 
}

