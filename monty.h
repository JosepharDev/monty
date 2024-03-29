#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int	n;
        struct stack_s	*prev;
        struct stack_s	*next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char	*opcode;
        void	(*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


typedef struct utils_s
{
        FILE	*fd;
        char	*content;
        int	lifi;
        char	*instruct;
}utils_t;
extern utils_t utils;

void	exec(char *content, stack_t **stack, unsigned int line_cntnt, FILE *file);
void    pall(stack_t **head, unsigned int line_content);
void    pint(stack_t **head, unsigned int line_content);
void    pop(stack_t **head, unsigned int line_content);
void    push(stack_t **head, unsigned int line_content);
void    swap(stack_t **head, unsigned int line_content);
void    add_node(stack_t **head, int number);
void    add_queue(stack_t **head, int number);
void    free_struct(stack_t *head);
voidadd(stack_t **head, unsigned int line_content)


#endif
