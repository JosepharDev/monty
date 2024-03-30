#include "monty.h"

/**
 * add_node - add node to the head stack
 * @head: head of the stack
 * @number: new_value
 * Return: no return
*/
void add_node(stack_t **head, int number)
{

	stack_t *new_node, *tmp;

	tmp = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (tmp)
		tmp->prev = new_node;
	new_node->n = number;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}

/**
 * add_queue - add node to the tail stack
 * @number: new_value
 * @head: head of the stack
 * Return: no return
*/

void add_queue(stack_t **head, int number)
{
	stack_t *new_node, *tmp;

	tmp = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = number;
	new_node->next = NULL;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
	}
	if (!tmp)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		tmp->next = new_node;
		new_node->prev = tmp;
	}
}

/**
* free_struct - frees a doubly linked list
* @head: head of the stack
*/
void free_struct(stack_t *head)
{
	stack_t *tmp;

	tmp = head;
	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
